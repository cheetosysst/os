#ifndef CONSOLE_LIB
#define CONSOLE_LIB

#define FB_COMMAND_PORT 0x3d4
#define FB_DATA_PORT 0x3d5
#define FB_COMMAND_HIGH 14
#define FB_COMMAND_LOW 15

/**
 * @brief Set kernel console cursor to a specific point
 * 
 * @param pos 
 */
void kernel_console_cursor();

/**
 * @brief Clear the whole kernel console.
 * 
 */
void kernel_console_clear();

/**
 * @brief Print to kernel console.
 * 
 * @param str 
 */
void kernel_console_print();

#endif