#include "io.h"
#include "serial.h"
#include "console.h"
#include "segments.h"
#include "interrupt.h"
#include "keyboard.h"

void kmain(void) {
	serial_general_setup();

	gdt_entries_init();

	kernel_console_clear();
	kernel_console_print("TEST KERNEL v0.1");
	kernel_console_cursor((short)(0x50 * 25 -1));

	idt_init();
	isr_init();

	while(1);

	// char temp;
	// while (1) {
	// 	temp = read_read_code();
	// 	if (temp != (char)0xfa) serial_printf(SERIAL_COM1_BASE, "=%X", read_read_code());
	// }

	return;
}
