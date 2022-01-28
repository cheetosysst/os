#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

/**
 * @brief Write 1 byte of data to a specific address.
 * 
 * @param port The address of the target port.
 * @param data Data to write to the port.
 */
void outb(unsigned short port, unsigned char data);

#endif