#include "io.h"

void kernel_console_clear();
void kernel_console_print();
void kernel_console_cursor();

void serial_general_setup();
int serial_check_fifo_empty(unsigned int com);
void serial_print(unsigned short com, char str[]);

void kmain(void) {

	kernel_console_clear();
	kernel_console_print("TEST KERNEL v0.1");
	kernel_console_cursor((short)(0x50 * 25 -1));

	serial_general_setup();
	// outb(0x3f8, (unsigned char)'a');
	serial_print(SERIAL_COM1_BASE, "Hello world!");

	return;
}
