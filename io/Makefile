BUILD_DIR=../build/io
HEADER_DIR=../headers

CC = gcc
AS = nasm
LD = ld

ASM_SRCS = $(wildcard *.asm)
C_SRCS = $(wildcard *.c)
ASM_OBJS = $(patsubst %.asm, $(BUILD_DIR)/%.o, $(ASM_SRCS))
C_OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(C_SRCS))
OS_OBJS = $(ASM_OBJS) $(C_OBJS)

CFLAGS = -I $(HEADER_DIR) -g -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror

all: $(OS_OBJS)

$(BUILD_DIR)/%.o: %.asm
	$(AS) -f elf32 -F dwarf -g $< -o $@

$(BUILD_DIR)/%.o: %.c
	$(CC) -m32 -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)/*
