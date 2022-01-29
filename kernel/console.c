#include "io.h"
#include "console.h"

static char *kernel_console_address = (char *) 0xb8000;

void kernel_console_cursor (unsigned short pos) {
	outb(FB_COMMAND_PORT, FB_COMMAND_HIGH);
	outb(FB_DATA_PORT, (pos>>8) & 0x00FF);
	outb(FB_COMMAND_PORT, FB_COMMAND_LOW);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

void kernel_console_clear() {

	unsigned int i = 0;
	while(i < 80 * 25 * 2) {
		kernel_console_address[i] = ' ';
		kernel_console_address[i+1] = 0x0a; 		
		i += 2;
	}
}

void kernel_console_print(char *str) {

	unsigned int i = 0;
	unsigned int j = 0;

	while(str[j] != '\0') {
		kernel_console_address[i] = str[j];
		kernel_console_address[i+1] = 0x0a;
		++j;
		i = i + 2;
	}
}