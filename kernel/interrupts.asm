; interrupt.asm
[bits 32]
extern interrupt_handler

%macro no_error_code_interrupt_handler 1
global interrupt_handler_%1
interrupt_handler_%1:
	cli
	push byte 0					; Push error code
	push byte %1					; Interrupt number
	jmp common_interrupt_handler	; Jump to common handler
%endmacro

%macro error_code_interrupt_handler 1
global interrupt_handler_%1
interrupt_handler_%1:
	cli
	push byte %1
	jmp common_interrupt_handler
%endmacro

common_interrupt_handler:
	pusha
	push ds
	push es
	push fs
	push gs
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov eax, esp
	push eax
	mov eax, interrupt_handler
	call eax
	add esp, 4
	pop gs
	pop fs
	pop es
	pop ds
	popa
	add esp, 8
	iret

no_error_code_interrupt_handler 0
no_error_code_interrupt_handler 1

error_code_interrupt_handler 7

global idt_load
extern idtp
idt_load:
	lidt [idtp]
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
