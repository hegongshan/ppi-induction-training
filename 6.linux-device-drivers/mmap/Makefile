ifneq ($(KERNELRELEASE),)
	obj-m := mmap_driver.o
else
	KERNELDIR ?= /home/hegongshan/rpmbuild/BUILD/kernel-3.10.0-1160.el7/linux-3.10.0-1160.el7.x86_64
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	rm -rf *.o *.mod.c *.mod.o *.ko
endif

