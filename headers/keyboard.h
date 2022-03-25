#ifndef KERNEL_KEYBOARD
#define KERNEL_KEYBOARD

#define KEYBOARD_DATA_PORT 0x60

unsigned char read_keycode(void);

#endif