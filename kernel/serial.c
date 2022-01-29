#include "io.h"
#include "serial.h"

void serial_general_setup() {
	serial_configure_baud_rate(
		SERIAL_COM1_BASE,
		1
	);
	serial_configure_line(
		SERIAL_COM1_BASE
	);
	serial_configure_fifo(
		SERIAL_COM1_BASE
	);
	return;
}

void serial_configure_baud_rate(unsigned short com, unsigned short divisor) {
	outb(
		SERIAL_LINE_COMMAND_PORT(com),
		SERIAL_LINE_ENABLE_DLAB
	);

	outb(
		SERIAL_DATA_PORT(com),
		(divisor >> 8) & 0x00FF
	);

	outb(
		SERIAL_DATA_PORT(com),
		divisor & 0x00FF
	);
}

void serial_configure_line(unsigned short com) {
	outb(
		SERIAL_LINE_COMMAND_PORT(com),
		0x03
	);
}

void serial_configure_fifo(unsigned short com) {
	outb(SERIAL_FIFO_COMMAND_PORT(com), 0x37);
	return;
}

int serial_check_fifo_empty(unsigned int com) {
	return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

void serial_print(unsigned short com, char str[]) {
	char *ptr = str;
	while (1) {
		if (!serial_check_fifo_empty(com)) continue;
		outb(SERIAL_COM1_BASE, *ptr);
		ptr += 1;
		if (*ptr == '\0') break;
	}
	return;
}
