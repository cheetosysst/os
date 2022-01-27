BUILD_DIR=../build/kernel

ASM_SRCS = $(wildcard *.asm)
C_SRCS = $(wildcard *.c)
# H_SRCS = $(wildcard *.h)
ASM_OBJS = $(patsubst %.asm, $(BUILD_DIR)/%.o, $(ASM_SRCS))
C_OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(C_SRCS))
OS_OBJS = $(ASM_OBJS) $(C_OBJS)
$(info $$OS_OBJS is [${OS_OBJS}])

all: $(OS_OBJS)
	ld -m elf_i386 -T kernel.ld -o $(BUILD_DIR)/kernel $(OS_OBJS)

$(BUILD_DIR)/%.o: %.asm
	nasm -f elf32 $< -o $@

$(BUILD_DIR)/%.o: %.c
	gcc -m32 -c $< -o $@ -g -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror

clean:
	rm -rf $(BUILD_DIR)/*
