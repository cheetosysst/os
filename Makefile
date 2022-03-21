BUILD_DIR=build
DISK_IMG=disk.img

COMPONENT_DIRS = kernel io console

C_SOURCES = $(foreach dir, $(COMPONENT_DIRS), $(wildcard $(dir)/*.c))
ASM_SOURCES = $(foreach dir, $(COMPONENT_DIRS), $(wildcard $(dir)/*.asm))
BIN_OBJECTS=$(patsubst %.c, $(BUILD_DIR)/%.o, $(C_SOURCES)) $(patsubst %.asm, $(BUILD_DIR)/%.o, $(ASM_SOURCES))
KERNEL=$(BUILD_DIR)/kernel_bin
$(info this $(ASM_SOURCES))
all: os
	qemu-system-i386 -machine q35 -m 512M -kernel $(KERNEL) -serial stdio

.PHONY: os $(COMPONENT_DIRS)

os: $(COMPONENT_DIRS)
	$(LD) -m elf_i386 -T linker.ld -o $(KERNEL) $(BIN_OBJECTS)

$(COMPONENT_DIRS):
	mkdir -p $(BUILD_DIR)/$@
	make -C $@

clean:
	rm -r $(BUILD_DIR)/*

debug:
	qemu-system-i386 -machine q35 -kernel $(KERNEL) -gdb tcp::26000 -S -serial stdio

gdb:
	gdb --command=gdb.txt 