#include "segments.h"
#include "io.h"
#include "cpu.h"
#include "serial.h"

gdt_object gdt_objects[6];
gdt_table table;

void gdt_entries_init() {

	serial_print(SERIAL_COM1_BASE, "GDT setup start.\n");

	table.size = (sizeof(gdt_object)*5)-1;
	table.base = (unsigned int)&gdt_objects;

	gdt_encode(&gdt_objects[0], 0, 0, 0, 0);
	gdt_encode(&gdt_objects[1], 0, 0xfffff, 0x9a, 0xcf);
	gdt_encode(&gdt_objects[2], 0, 0xfffff, 0x92, 0xcf);
	gdt_encode(&gdt_objects[3], 0, 0xfffff, 0xfa, 0xcf);
	gdt_encode(&gdt_objects[4], 0, 0xfffff, 0xf2, 0xcf);
	gdt_encode(&gdt_objects[5], 0xffffffff, 0xfffff, 0xe9, 0x0f);

	gdt_flush((unsigned int)&table);
	serial_printf(SERIAL_COM1_BASE, "GDT flushed\n");
}

/**
 * Intel x86 IDT layout
 * ====================
 * Intel's x86 IDT layout can be a litle messy, hard to understand.
 * The layout was originally designed for 8086 and 80286 CPUs, and
 * lator expanded for 80386.
 * 
 * Here is a visualized version of the IDT layout.
 * 
 * /===================================================\
 * |     07     |     06     |     05     |     04     |
 * | 63------56 | 55------48 | 47------40 | 39------32 |
 * |    Base    | Flag/Limit |   Access   |    Base    |
 * |===================================================|
 * |     03     |     02     |     01     |     00     |
 * | 31------24 | 23------16 | 15------08 | 07------00 |
 * |    Base    |    Base    |   Limit    |   Limit    |
 * \===================================================/
 * 
 * See more at https://wiki.osdev.org/GDT
 */

/**
 * @brief Encode target with provided gdt source object.
 * 
 * @param target 
 * @param source 
 */
void gdt_encode(gdt_object *target, unsigned int base, unsigned int limit, unsigned char access, unsigned char flags) {
	
	if (limit > 0xFFFFF) {
		serial_printf(SERIAL_COM1_BASE, "GDT source limit error.\nlimit: %X\nbase: %X\n", limit, base);
		return;
	}

	target->base_low    =  base         & 0xFFFF; // Lower  word of the base address.
	target->base_mid    = (base >> 16)  & 0xFF;   // Middle byte of the base address.
	target->base_high   = (base >> 24)  & 0xFF;   // Higher byte of the base address.

	target->limit_low   =  limit        & 0xFFFF; // Lower  word of the limit.
	target->flags_limit = (limit >> 16) & 0x0F;   // Higher byte of the limit.

	target->access = access;
 
	target->flags_limit |= (flags) & 0xF0;
}