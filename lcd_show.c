#include <REG51.H>
#include "lcd.h"


void pwd_show (int aaa, int bbb)  
{
  init_LCD();
  clear_LCD();

  gotoxy(1,1);
  display_LCD_number(aaa);

  gotoxy(1,4);
  display_LCD_string("~");

  if(bbb==100)
  {
    gotoxy(1,6);
    display_LCD_number(10);
    gotoxy(1,7);
    display_LCD_number(00);
  }
  else
  {
    gotoxy(1,6);
    display_LCD_number(bbb);
  }
}

void pwd_success (void)
{
  init_LCD();
  clear_LCD();

  gotoxy(1,1);
  display_LCD_string("Successful ^^");
}


void pwd_fail (void)  
{
  init_LCD();
  clear_LCD();

  gotoxy(1,1);
  display_LCD_string("*Bomb  Bomb* = =");
}

