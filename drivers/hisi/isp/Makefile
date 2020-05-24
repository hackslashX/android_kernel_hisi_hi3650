ifneq ($(TARGET_BUILD_VARIANT),user)
EXTRA_CFLAGS += -DDEBUG_HISI_ISP
ccflags-y := -O2
endif

obj-y    += hisi_atfisp.o hisi_fstcma.o hisi_isp_rproc.o rpmsg_hisi.o rpmsg_sensor.o
ccflags-y := -O2
ifeq ($(CONFIG_HISI_HISTAR_ISP), y)
EXTRA_CFLAGS += -Idrivers/hisi/tzdriver \
                -Idrivers/hisi/load_image \
                -I$(src)/../../../../../../../external/efipartition
ccflags-y := -O2
endif
