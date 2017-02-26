void delay100us(unsigned char n)
{
#pragma asm
more:	mov		R3,#48
		djnz	R3,$
		djnz	R7,more
#pragma endasm
}