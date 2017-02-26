#include <REG51.H>
#include <lcd.h>

char code int2charLCD[]="0123456789";
	
void write_LCD_command(unsigned command)
{
	rw=WRITE;
	rs=COMMAND;
	enable=ENABLE;
	P1=command;
	delay100us(20);
	enable=DISABLE;
	rw=1;
}
void write_LCD_data(unsigned LCDdata)
{
	rw=WRITE;
	rs=DATA;
	enable=ENABLE;
	P1=LCDdata;
	delay100us(20);
	enable=DISABLE;
	rw=1;
}
void init_LCD(void)
{
	write_LCD_command(TwoLine_8bit);// 0x38  	
	write_LCD_command(CURSOR_OFF);	// 0x0C
	write_LCD_command(CURSOR_RIGHT);// 0x06
}
void clear_LCD()
{
	write_LCD_command(CLEAR);	
	write_LCD_command(CURSOR_HOME);	
}
void display_LCD_string(char *p)
{
	while(*p)
	{
		write_LCD_data(*p);
		p++;
	}
}
void display_LCD_number(char number)
{
	unsigned char x,y;
	x=number/10;
	y=number-10*x;
	write_LCD_data(int2charLCD[x]);
	write_LCD_data(int2charLCD[y]);
}
void gotoxy(unsigned x,unsigned y)
{
	if(x==1)  
		write_LCD_command(GOTO_LINE_1+y);
	else
    	write_LCD_command(GOTO_LINE_2+y);
}