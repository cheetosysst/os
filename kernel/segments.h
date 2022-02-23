#ifndef KERNEL_SEGMENTS
#define KERNEL_SEGMENTS

struct gdt_object {
	unsigned short limit_low;
	unsigned short base_low;
	unsigned char  base_mid;
	unsigned char  access;
	unsigned char  flags_limit;
	unsigned char  base_high;
} __attribute__((packed));
typedef struct gdt_object gdt_object;

struct gdt_table {
	unsigned short size;
	unsigned int   base;
} __attribute__((packed));
typedef struct gdt_table gdt_table;

void gdt_entries_init();

void gdt_flush(unsigned int table);

void gdt_encode(gdt_object *target, unsigned int base, unsigned int limit, unsigned char access, unsigned char flags);

#endif