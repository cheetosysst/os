BUILD_DIR=build
DISK_IMG=disk.img
KERNEL=$(BUILD_DIR)/kernel/kernel

all: os
	qemu-system-i386 -machine q35 -kernel $(KERNEL) -serial stdio

.PHONY: kernel

os:
	make -C kernel

clean:
	make -C bootloader clean
	make -C os clean

debug:
	qemu-system-i386 -machine q35 -kernel $(KERNEL) -gdb tcp::26000 -S

gdb:
	gdb --command=gdb.txt 