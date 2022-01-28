global outb

; outb - send a byte to an I/O port
; 	address on [esp + 4], mov to dx.
; 	data on [esp + 8], mov to al
outb:
	mov al, [esp + 8]
	mov dx, [esp + 4]
	out dx, al
	ret

