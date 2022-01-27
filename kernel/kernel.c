void kernel_console_clear();
void kernel_console_print();

void kmain(void) {

	kernel_console_clear();
	kernel_console_print("TEST KERNEL v0.1");

	return;
}
