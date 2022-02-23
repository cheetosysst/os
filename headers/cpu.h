#ifndef KERNEL_CPU
#define KERNEL_CPU

#define PIC1_PORT_A 0x20
#define PIC2_PORT_A 0xA0

/* The PIC interrupts have been remapped */
#define PIC1_START_INTERRUPT 0x20
#define PIC2_START_INTERRUPT 0x28
#define PIC2_END_INTERRUPT PIC2_START_INTERRUPT + 7
#define PIC_ACK 0x20

struct cpu_state {
	unsigned int eax;
	unsigned int ebx;
	unsigned int ecx;
	unsigned int edx;
	unsigned int esp;
} __attribute__((packed));

struct stack_state {
	unsigned int error_code;
	unsigned int eix;
	unsigned int cs;
	unsigned int eflag;
} __attribute__((packed));

/**
 * @brief General handler of interrupts.
 * 
 * @param cpu 
 * @param stack 
 * @param interrupt 
 */
void interrupt_handler(struct cpu_state cpu, struct stack_state stack, unsigned int interrupt);

/**
 * @brief Acknowledge interrupts from PIC1 and PIC2.
 * 
 * @param interrupt 
 */
void pic_acknowledge(unsigned int interrupt);

/**
 * @brief Load idt address to the processor.
 * 
 * @param idt_address 
 */
void load_idt(unsigned short idt_address);

void cpu_cli();
void cpu_sti();

#endif