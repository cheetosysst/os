; interrupt.asm

; Note: Original tutorial pushes a the registers one-by-one, I'm lazy so used pushad and popad instead, but then I wrote this comment, which makes the whole point typing less stuff meaningless.

extern interrupt_handler

%macro no_error_code_interrupt_handler 1
global interrupt_handler_%1
interrupt_handler_%1:
	push dword 0					; Push error code
	push dword %1					; Interrupt number
	jmp common_interrupt_handler	; Jump to common handler
%endmacro

%macro error_code_interrupt_handler 1
global interrupt_handler_%1
interrupt_handler_%1:
	push dword %1
	jmp common_interrupt_handler
%endmacro

common_interrupt_handler:
	pushad
	call interrupt_handler

	popad
	add esp, 8
	iret

no_error_code_interrupt_handler 0
no_error_code_interrupt_handler 1
no_error_code_interrupt_handler 2
no_error_code_interrupt_handler 3
no_error_code_interrupt_handler 4
no_error_code_interrupt_handler 5
no_error_code_interrupt_handler 6
error_code_interrupt_handler    7
no_error_code_interrupt_handler 8
error_code_interrupt_handler    9
error_code_interrupt_handler    10
error_code_interrupt_handler    11
error_code_interrupt_handler    12
error_code_interrupt_handler    13
error_code_interrupt_handler    14
no_error_code_interrupt_handler 15
error_code_interrupt_handler    16

global load_idt
load_idt:
	mov eax, [esp+4]
	lidt [eax]
	ret

global cpu_cli
cpu_cli:
	cli
	ret

global cpu_sti
cpu_sti:
	sti
	ret

gdtr dw 0
	 dd 0

global gdt_flush:
gdt_flush:
	mov eax, [esp + 4]
	lgdt [eax]
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:.flush
.flush:
	ret
