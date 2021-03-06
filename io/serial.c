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

void serial_putc(unsigned short com, char chr) {
	while (1) {
		if (!serial_check_fifo_empty(com)) continue;
		outb(SERIAL_COM1_BASE, chr);
		break;
	}
}

void serial_print(unsigned short com, char *str) {
	char *ptr = str;
	while (1) {
		if (!serial_check_fifo_empty(com)) continue;
		outb(SERIAL_COM1_BASE, *ptr);
		ptr += 1;
		if (*ptr == '\0') break;
	}
	return;
}

void serial_print_uint(unsigned short com, unsigned int data, unsigned int base) {
	
	if (base==0) return;

	char *num_list = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char num_str[11];
	char i, j;

	for (i=0; i<11; i++) num_str[(unsigned int)i] = '\0';
	i=0;
	while ((unsigned int)i!=10) {
		num_str[(unsigned int)i++] = num_list[data%base];
		data /= base;
		if (!data) break;
	}

	j = 0;
	while (num_str[(unsigned int)j] != '\0') j++;

	for (i=0; i<j/2; i++) {
		num_str[(unsigned int)i] += num_str[(unsigned int)j-1-i];
		num_str[(unsigned int)j-1-i] = num_str[(unsigned int)i] - num_str[(unsigned int)j-1-i];
		num_str[(unsigned int)i] -= num_str[(unsigned int)j-1-i];
	}
	
	serial_print(com, num_str);
}

void serial_printf(unsigned short com, char *fmt, ...)
{
	char *fmt_iter = fmt;
	int *args = (int*)&fmt;
	args = args + 1;
	
	while (1) {
		
		if (*fmt_iter == '\0') break;

		if (*fmt_iter != '%') {
			serial_putc(com, *fmt_iter);
			fmt_iter = fmt_iter+1;
			continue;
		}

		fmt_iter = fmt_iter + 1;
		switch (*fmt_iter){

			case 'o':
				serial_print_uint(com, *args, 8);
				break;

			case 'u':
				serial_print_uint(com, *args, 10);
				break;

			case 'x':
			case 'X':
				serial_print_uint(com, *args, 16);
				break;

			case 's':
				serial_print(com, (char*)*args);
				break;

			case 'c':
				serial_putc(com, (char)*args);

			default:
				break;
		}

		fmt_iter = fmt_iter + 1;
		args = args + 1;

	}
}