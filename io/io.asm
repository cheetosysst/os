global outb

; outb - send a byte to an I/O port
; 	address on [esp + 4], mov to dx.
; 	data on [esp + 8], mov to al
outb:
	mov al, [esp + 8]
	mov dx, [esp + 4]
	out dx, al
	ret

global inb

; inb - read a byte from I/O port
; 	address on [esp + 4], mov to dx
inb:
	mov dx, [esp + 4]
	in al, dx
	ret