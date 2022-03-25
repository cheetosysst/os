#include "cpu.h"
#include "interrupt.h"
#include "io.h"
#include "serial.h"

struct idt_object idt_objects[256];
struct idt_pointer idtp;

void idt_init() {
	serial_print(SERIAL_COM1_BASE, "IDT init start\n");

	idtp.size = (unsigned short)(sizeof(struct idt_object)*256)-1;
	idtp.offset = (unsigned int)&idt_objects;

	char *temp = (char *)idt_objects;
	for (unsigned short i=0; i<sizeof(struct idt_object)*256; i++) temp[i]=0;

	idt_load();

	serial_print(SERIAL_COM1_BASE, "IDT registered\n");
}

void idt_set(unsigned char num, unsigned int offset, unsigned short selector, unsigned char attributes) {
	idt_objects[num].offset_low  =  offset         & 0xFFFFu;
	idt_objects[num].offset_high = (offset >> 16u) & 0xFFFFu;
	idt_objects[num].selector = selector;
	idt_objects[num].zero = 0;
	idt_objects[num].attributes = attributes;
}

void interrupt_handler(struct cpu_state cpu) {
	serial_print(SERIAL_COM1_BASE, "Interrupt!\n");
	serial_printf(SERIAL_COM1_BASE, "cpu%X\n", cpu.eax);
}