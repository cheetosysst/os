bits 32

KERNEL_STACK_SIZE equ 8192

section .text
	align 4
	dd 0x1BADB002
	dd 0x00
	dd - (0x1BADB002 + 0x00)

global start
extern kmain

start:
	cli
	mov esp, stack_space+KERNEL_STACK_SIZE
	call kmain
	hlt

section .bss

stack_space:
	resb KERNEL_STACK_SIZE