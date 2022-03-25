#ifndef KERNEL_CPU
#define KERNEL_CPU

#define PIC1_PORT_A 0x20
#define PIC2_PORT_A 0xA0

/* The PIC interrupts have been remapped */
#define PIC1_START_INTERRUPT 0x20
#define PIC2_START_INTERRUPT 0x28
#define PIC2_END_INTERRUPT PIC2_START_INTERRUPT + 7
#define PIC_ACK 0x20

/**
 * @brief Acknowledge interrupts from PIC1 and PIC2.
 * 
 * @param interrupt 
 */
void pic_acknowledge(unsigned int interrupt);

#endif