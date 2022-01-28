void kernel_console_clear();
void kernel_console_print();
void kernel_console_cursor();

void kmain(void) {

	kernel_console_clear();
	kernel_console_print("TEST KERNEL v0.1");
	kernel_console_cursor((short)(0x50 * 25 -1));

	return;
}
