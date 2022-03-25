#include "interrupt.h"
#include "serial.h"
#include "io.h"

void isr_init() {
	serial_print(SERIAL_COM1_BASE, "ISR setup start\n");
	idt_set(0, (unsigned)interrupt_handler_0, 0x08, 0x8e);
	idt_set(1, (unsigned)interrupt_handler_1, 0x08, 0x8e);
	serial_print(SERIAL_COM1_BASE, "ISR is set\n");
}