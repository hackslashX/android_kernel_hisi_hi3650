/*
 * drivers/power/process.c - Functions for starting/stopping processes on
 *                           suspend transitions.
 *
 * Originally from swsusp.
 */


#undef DEBUG

#include <linux/interrupt.h>
#include <linux/oom.h>
#include <linux/suspend.h>
#include <linux/module.h>
#include <linux/syscalls.h>
#include <linux/freezer.h>
#include <linux/delay.h>
#include <linux/workqueue.h>
#include <linux/kmod.h>
#include <trace/events/power.h>
#include <linux/wakeup_reason.h>
#include <linux/cpuset.h>

/*
 * Timeout for stopping processes
 */
unsigned int __read_mostly freeze_timeout_msecs = 10 * MSEC_PER_SEC;

static int try_to_freeze_tasks(bool user_only)
{
	struct task_struct *g, *p;
	unsigned long end_time;
	unsigned int todo;
	bool wq_busy = false;
	struct timeval start, end;
	u64 elapsed_msecs64;
	unsigned int elapsed_msecs;
	bool wakeup = false;
	int sleep_usecs = USEC_PER_MSEC;
#ifdef CONFIG_PM_SLEEP
	char suspend_abort[MAX_SUSPEND_ABORT_LEN];
#endif

	do_gettimeofday(&start);

	end_time = jiffies + msecs_to_jiffies(freeze_timeout_msecs);

	if (!user_only)
		freeze_workqueues_begin();

	while (true) {
		todo = 0;
		read_lock(&tasklist_lock);
		for_each_process_thread(g, p) {
			if (p == current || !freeze_task(p))
				continue;

			if (!freezer_should_skip(p))
				todo++;
		}
		read_unlock(&tasklist_lock);

		if (!user_only) {
			wq_busy = freeze_workqueues_busy();
			todo += wq_busy;
		}

		if (!todo || time_after(jiffies, end_time))
			break;

		if (pm_wakeup_pending()) {
#ifdef CONFIG_PM_SLEEP
			pm_get_active_wakeup_sources(suspend_abort,
				MAX_SUSPEND_ABORT_LEN);
			log_suspend_abort_reason(suspend_abort);
#endif
			wakeup = true;
			break;
		}

		/*
		 * We need to retry, but first give the freezing tasks some
		 * time to enter the refrigerator.  Start with an initial
		 * 1 ms sleep followed by exponential backoff until 8 ms.
		 */
		usleep_range(sleep_usecs / 2, sleep_usecs);
		if (sleep_usecs < 8 * USEC_PER_MSEC)
			sleep_usecs *= 2;
	}

	do_gettimeofday(&end);
	elapsed_msecs64 = timeval_to_ns(&end) - timeval_to_ns(&start);
	do_div(elapsed_msecs64, NSEC_PER_MSEC);
	elapsed_msecs = elapsed_msecs64;

	if (wakeup) {
		pr_cont("\n");
		pr_err("Freezing of tasks aborted after %d.%03d seconds",
		       elapsed_msecs / 1000, elapsed_msecs % 1000);
	} else if (todo) {
		pr_cont("\n");
#ifdef CONFIG_HW_PTM
		pr_err("Freezing of tasks %s after %d.%03d seconds"
		       " (%d tasks refusing to freeze, wq_busy=%d):\n",
				wakeup ? "aborted" : "failed",
				elapsed_msecs / 1000, elapsed_msecs % 1000,
				todo - wq_busy, wq_busy);
#else
		pr_err("Freezing of tasks failed after %d.%03d seconds"
		       " (%d tasks refusing to freeze, wq_busy=%d):\n",
		       elapsed_msecs / 1000, elapsed_msecs % 1000,
		       todo - wq_busy, wq_busy);
#endif

			read_lock(&tasklist_lock);
			for_each_process_thread(g, p) {
				if (p != current && !freezer_should_skip(p)
				    && freezing(p) && !frozen(p))
					sched_show_task(p);
			}
			read_unlock(&tasklist_lock);
	} else {
		pr_debug("(elapsed %d.%03d seconds) ", elapsed_msecs / 1000,
			elapsed_msecs % 1000);
	}

	return todo ? -EBUSY : 0;
}

/**
 * freeze_processes - Signal user space processes to enter the refrigerator.
 * The current thread will not be frozen.  The same process that calls
 * freeze_processes must later call thaw_processes.
 *
 * On success, returns 0.  On failure, -errno and system is fully thawed.
 */
int freeze_processes(void)
{
	int error;

	error = __usermodehelper_disable(UMH_FREEZING);
	if (error)
		return error;

	/* Make sure this task doesn't get frozen */
	current->flags |= PF_SUSPEND_TASK;

	if (!pm_freezing)
		atomic_inc(&system_freezing_cnt);

	pm_wakeup_clear();
	pr_debug("Freezing user space processes ... ");
	pm_freezing = true;
	error = try_to_freeze_tasks(true);
	if (!error) {
		__usermodehelper_set_disable_depth(UMH_DISABLED);
		pr_debug("done.");
	}
	pr_debug("\n");
	BUG_ON(in_atomic());

	/*
	 * Now that the whole userspace is frozen we need to disbale
	 * the OOM killer to disallow any further interference with
	 * killable tasks.
	 */
	if (!error && !oom_killer_disable())
		error = -EBUSY;


	/*
	 * There is a hard to fix race between oom_reaper kernel thread
	 * and oom_killer_disable. oom_reaper calls exit_oom_victim
	 * before the victim reaches exit_mm so try to freeze all the tasks
	 * again and catch such a left over task.
	 */
	if (!error) {
		pr_info("Double checking all user space processes after OOM killer disable... ");
		error = try_to_freeze_tasks(true);
		pr_cont("\n");
	}



	if (error)
		thaw_processes();
	return error;
}

/**
 * freeze_kernel_threads - Make freezable kernel threads go to the refrigerator.
 *
 * On success, returns 0.  On failure, -errno and only the kernel threads are
 * thawed, so as to give a chance to the caller to do additional cleanups
 * (if any) before thawing the userspace tasks. So, it is the responsibility
 * of the caller to thaw the userspace tasks, when the time is right.
 */
int freeze_kernel_threads(void)
{
	int error;

	pr_debug("Freezing remaining freezable tasks ... ");

	pm_nosig_freezing = true;
	error = try_to_freeze_tasks(false);
	if (!error)
		pr_debug("done.");

	pr_debug("\n");
	BUG_ON(in_atomic());

	if (error)
		thaw_kernel_threads();
	return error;
}

#ifdef CONFIG_QUICK_THAW_FINGERPRINTD
void thaw_fingerprintd(void)
{
	struct task_struct *p;

	pm_freezing = false;
	pm_nosig_freezing = false;

	read_lock(&tasklist_lock);
	for_each_process(p) {
		if (!memcmp(p->comm, "fingerprintd", 13)) {
			__thaw_task(p);
			break;
		}
	}
	read_unlock(&tasklist_lock);

	pm_freezing = true;
	pm_nosig_freezing = true;
}
#endif

void thaw_processes(void)
{
	struct task_struct *g, *p;
	struct task_struct *curr = current;

	trace_suspend_resume(TPS("thaw_processes"), 0, true);
	if (pm_freezing)
		atomic_dec(&system_freezing_cnt);
	pm_freezing = false;
	pm_nosig_freezing = false;

	oom_killer_enable();

	pr_debug("Restarting tasks ... ");

	__usermodehelper_set_disable_depth(UMH_FREEZING);
	thaw_workqueues();

	cpuset_wait_for_hotplug();

	read_lock(&tasklist_lock);
	for_each_process_thread(g, p) {
		/* No other threads should have PF_SUSPEND_TASK set */
		WARN_ON((p != curr) && (p->flags & PF_SUSPEND_TASK));
		__thaw_task(p);
	}
	read_unlock(&tasklist_lock);

	WARN_ON(!(curr->flags & PF_SUSPEND_TASK));
	curr->flags &= ~PF_SUSPEND_TASK;

	usermodehelper_enable();

	schedule();
	pr_debug("done.\n");
	trace_suspend_resume(TPS("thaw_processes"), 0, false);
}

void thaw_kernel_threads(void)
{
	struct task_struct *g, *p;

	pm_nosig_freezing = false;
	pr_info("Restarting kernel threads ... ");

	thaw_workqueues();

	read_lock(&tasklist_lock);
	for_each_process_thread(g, p) {
		if (p->flags & (PF_KTHREAD | PF_WQ_WORKER))
			__thaw_task(p);
	}
	read_unlock(&tasklist_lock);

	schedule();
	pr_debug("done.\n");
}
