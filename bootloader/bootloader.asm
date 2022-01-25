org 0x7c00
bits 16
start: jmp boot

msg db "Welcome to My Operating System!", 0ah, 0dh, 0h

boot:
	cli
	cld
	
	; mov ax, 0x50

	; mov es, ax
	; xor bx, ax

	; mov al, 2	; read 2 sectors
	; mov ch, 0	; track 0
	; mov cl, 2	; sector 2
	; mov dh, 0	; head number
	; mov dl, 0	; drive number

	; mov ah, 0x02	; read sectors from disk
	; int 0x13
	; jmp 0x50: 0x0

	hlt

times 510 - ($-$$) db 0
dw 0xAA55
