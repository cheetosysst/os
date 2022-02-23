#ifndef SERIAL_LIB
#define SERIAL_LIB

// Serial configuration and init

/**
 * @brief Initailize the serial COM1 port.
 * 
 */
void serial_general_setup();

/**
 * @brief Set serial baud rate
 * 
 * @param com COM port number.
 * @param divisor Divisor to divide default speed 115200 bits/sec.
 */
void serial_configure_baud_rate(unsigned short com, unsigned short divisor);

/**
 * @brief Default serial line configuration. No parity, one stop bit, break control disabled.
 * 
 * @param com Address of the com port.
 */
void serial_configure_line(unsigned short com);


/**
 * @brief Default configuration of serial FIFO.
 * 
 * @param com Address of the com port.
 */
void serial_configure_fifo(unsigned short com);


/**
 * @brief Check whether serial com's buffer FIFO queue is empty.
 * 
 * @param com Address of the com port.
 * @return int 
 */
int serial_check_fifo_empty(unsigned int com);

/**
 * @brief Prints a single ascii charactor to serial port.
 * 
 * @param com 
 * @param chr 
 */
void serial_putc(unsigned short com, char chr);

/**
 * @brief Print a string through to serial com port.
 * 
 * @param com 
 * @param str 
 */
void serial_print(unsigned short com, char str[]);

/**
 * @brief Print formated string to serial port.
 * 
 * @param fmt 
 * @param arg 
 */
void serial_printf(unsigned short com, char *fmt, ...);

/**
 * @brief Prints a unsigned int.
 * 
 * @param data 
 * @param base 
 */
void serial_print_uint(unsigned short com, unsigned int data, unsigned int base);

#endif