#ifndef KERNEL_INTERRUPT
#define KERNEL_INTERRUPT

struct cpu_state {
	unsigned int gs;
	unsigned int fs;
	unsigned int es;
	unsigned int ds;
	unsigned int edi;
	unsigned int esi;
	unsigned int ebp;
	unsigned int esp;
	unsigned int ebx;
	unsigned int edx;
	unsigned int ecx;
	unsigned int eax;
	unsigned int num;
	unsigned int err_code;
	unsigned int eip;
	unsigned int cs;
	unsigned int eflags;
	unsigned int useresp;
	unsigned int ss;
} __attribute__((packed));

/**
 * @brief General handler of interrupts.
 * 
 * @param cpu 
 * @param stack 
 * @param interrupt 
 */
void interrupt_handler(struct cpu_state cpu);

struct idt_object
{
	unsigned short offset_low;
	unsigned short selector;
	unsigned char zero;
	unsigned char attributes;
	unsigned short offset_high;
} __attribute__((packed));

struct idt_pointer {
	unsigned short size;
	unsigned int offset;
} __attribute__((packed));

/**
 * @brief Initialize interrupt descriptor table and set all to zero.
 * 
 */
void idt_init();

/**
 * @brief Update interrupt descriptor table.
 * 
 * @param num Index of entry to update.
 * @param offset The 32 bit address in the segment.
 * @param selector The offset in the GDT
 * @param attributes Present, ring level, and size of gate.
 */
void idt_set(unsigned char num, unsigned int offset, unsigned short selector, unsigned char attributes);

/**
 * @brief Load idt address to the processor.
 * 
 */
void idt_load();

extern void interrupt_handler_0();
extern void interrupt_handler_1();

void isr_init();

#endif