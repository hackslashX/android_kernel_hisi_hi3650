/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Copyright (C) 2019-2020 Sultan Alsawaf <sultan@kerneltoast.com>.
 */
#ifndef _SIMPLE_LMK_H_
#define _SIMPLE_LMK_H_

struct mm_struct;

#ifdef CONFIG_ANDROID_SIMPLE_LMK
void simple_lmk_mm_freed(struct mm_struct *mm);
#ifdef CONFIG_ANDROID_SIMPLE_LMK_EXTENDED
int simple_lmk_calculate_adj(int adj, char *comm);
#endif
#else
static inline void simple_lmk_mm_freed(struct mm_struct *mm)
{
}
#ifdef CONFIG_ANDROID_SIMPLE_LMK_EXTENDED
int simple_lmk_calculate_adj(int adj, char *comm) {
	return adj;
}
#endif
#endif

#endif /* _SIMPLE_LMK_H_ */
