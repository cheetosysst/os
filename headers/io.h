#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

#define SERIAL_COM1_BASE                0x3F8
#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5) 	
#define SERIAL_LINE_ENABLE_DLAB         0x80       // Tell the serial port to expect the high 8 bits, and then the lower 8 bits.

/**
 * @brief Write 1 byte of data to a specific address.
 * 
 * @param port The address of the target port.
 * @param data Data to write to the port.
 */
void outb(unsigned short port, unsigned char data);

/**
 * @brief Read 1 byte from provided address.
 * 
 * @param port Memory address of the target port.
 * @return unsigned char 
 */
unsigned char inb(unsigned short port);

#endif