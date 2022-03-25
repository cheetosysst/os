#include "keyboard.h"
#include "io.h"

char key_state = 0;

unsigned char read_keycode(void)
{
	char key_code = inb(KEYBOARD_DATA_PORT);
	// if (keycode)
	return key_code;
}