#include "io.h"
#include "serial.h"
#include "console.h"

void kmain(void) {

	kernel_console_clear();
	kernel_console_print("TEST KERNEL v0.1");
	kernel_console_cursor((short)(0x50 * 25 -1));

	serial_general_setup();
	serial_print(SERIAL_COM1_BASE, "Hello world!\n");
	serial_print_uint(172, 16);

	return;
}
