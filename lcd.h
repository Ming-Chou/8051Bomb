/* LCD command */
#define 	TwoLine_8bit	56		// 0x38
#define 	CLEAR 			1		// 0b00000001
#define		CURSOR_HOME		2		// 0b00000010
#define		CURSOR_LEFT		4		// 0b00000100
#define		CURSOR_RIGHT	6		// 0b00000110
#define		CURSOR_OFF		12		// 0b00001100
#define		CURSOR_ON		14		// 0b00001110
#define		CURSOR_BLINK	15		// 0b00001111
#define 	GOTO_LINE_2		192
#define 	GOTO_LINE_1		128

/* LCD control lines */
#define		ENABLE  	1
#define		DISABLE		0
#define		READ		1
#define		WRITE		0
#define		COMMAND		0
#define		DATA		1
#define		rs			P3_5
#define		rw			P3_6
#define		enable		P3_7
sbit P3_7   = 0xB7;
sbit P3_6   = 0xB6;
sbit P3_5   = 0xB5;


void delay100us(unsigned);
void write_LCD_command(unsigned);
void write_LCD_data(unsigned);
void init_LCD(void);
void clear_LCD(void);
void display_LCD_string(char *);
void gotoxy(unsigned,unsigned);
void display_LCD_number(char);



