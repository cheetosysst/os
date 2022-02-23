#include "cpu.h"
#include "io.h"
#include "serial.h"

void interrupt_handler(struct cpu_state cpu, struct stack_state stack, unsigned int interrupt) {
	serial_print(SERIAL_COM1_BASE, "Interrupt ");
	serial_print_uint(SERIAL_COM1_BASE, interrupt, 10);
	serial_print(SERIAL_COM1_BASE, " called \n");

	serial_print(SERIAL_COM1_BASE, "eax: ");
	serial_print_uint(SERIAL_COM1_BASE, cpu.eax, 16);
	serial_print(SERIAL_COM1_BASE, "\n");

	serial_print(SERIAL_COM1_BASE, "ebx: ");
	serial_print_uint(SERIAL_COM1_BASE, cpu.ebx, 16);
	serial_print(SERIAL_COM1_BASE, "\n");

	serial_print(SERIAL_COM1_BASE, "ecx: ");
	serial_print_uint(SERIAL_COM1_BASE, cpu.ecx, 16);
	serial_print(SERIAL_COM1_BASE, "\n");

	serial_print(SERIAL_COM1_BASE, "edx: ");
	serial_print_uint(SERIAL_COM1_BASE, cpu.edx, 16);
	serial_print(SERIAL_COM1_BASE, "\n");

	serial_print(SERIAL_COM1_BASE, "esp: ");
	serial_print_uint(SERIAL_COM1_BASE, cpu.esp, 16);
	serial_print(SERIAL_COM1_BASE, "\n");

	serial_print(SERIAL_COM1_BASE, "stack eix: ");
	serial_print_uint(SERIAL_COM1_BASE, stack.eix, 16);
	serial_print(SERIAL_COM1_BASE, "\n");
}

void pic_acknowledge(unsigned int interrupt) {
	if (interrupt < PIC1_START_INTERRUPT || interrupt > PIC2_END_INTERRUPT) return;

	if (interrupt < PIC2_START_INTERRUPT)
		outb(PIC1_PORT_A, PIC_ACK);
	else
		outb(PIC2_PORT_A, PIC_ACK);
}