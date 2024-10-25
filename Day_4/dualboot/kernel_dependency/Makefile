obj-m := independent.o dependent.o

modules:
	make -C /usr/src/linux-headers-$(shell uname -r) M=$(PWD) $@

clean:
	make -C /usr/src/linux-headers-$(shell uname -r) M=$(PWD) $@
