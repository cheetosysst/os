static char *kernel_console_address = (char *) 0xb8000;

// typedef struct kernel_console_line {
// 	char texts[80];
// 	struct kernel_console_line *next;
// } kernel_console_line;

// typedef struct kernel_console {
// 	kernel_console_line *head;
// 	kernel_console_line *rear;
// } kernel_console;

// kernel_console *kernel_console_init();
void kernel_console_clear();
void kernel_console_print();

// kernel_console *kernel_console_init() {
// 	kernel_console *temp_console = (kernel_console *) malloc(sizeof(kernel_console));
// }

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