#include "keyboard.h"
#include "io.h"

unsigned char read_read_code(void)
{
	return inb(KEYBOARD_DATA_PORT);
}