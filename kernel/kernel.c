#include "io.h"
#include "serial.h"
#include "console.h"
#include "segments.h"

void kmain(void) {
	serial_general_setup();

	gdt_entries_init();

	kernel_console_clear();
	kernel_console_print("TEST KERNEL v0.1");
	kernel_console_cursor((short)(0x50 * 25 -1));

	serial_printf(SERIAL_COM1_BASE, "%u %X %o %s %c\n", 172, 172, 172, "hello", '$');

	return;
}
