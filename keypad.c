/*
	標題:		小鍵盤的輸入函數
 	Target:	    89S51  
 	函數描述:	char gotkey(void)
				從4X4小鍵盤輸入資料，傳回0 ~ 15
  
  小鍵盤的連接方式:
   
  1 P20 -----0----1----2----3
             |    |    |    |
  2 P21 -----4----5----6----7
             |    |    |    | 
  3 P22 -----8----9----10---11
             |    |    |    |  
  4 P23 -----12---13---14---15
             |    |    |    |
  5 P24 ---- |    |    |    |
             |    |    |    |
  6 P25 ----------     |    |
                       |    |
  7 P26 ---------------     |   
                            |
  8 P27 --------------------    
*/
#include <REG51.H>
#include "key.h"
#include "count.h"
//code char key_code[]={0x7E,0XBE,0XBD,0XBB,0XDE,0XDD,0XDB,0XEE,
//		       0XED,0XEB,0X7D,0X7B,0XE7,0XD7,0XB7,0X77};
code char key_code[]={0xEE,0xED,0XEB,0XE7,0XDE,0XDD,0XDB,0XD7,
		0XBE,0XBD,0XBB,0XB7,0X7E,0X7D,0X7B,0X77};
code ksp[4]={0x7F,0xBF,0xDF,0xEF};

void delay (void)  {                   /* 時間延遲函數 */
  unsigned char i,j;                  
	for (i=0;i<5;i++)
		for(j=0;j<10;j++)
		;
}
//
//		4X4小鍵盤輸入		
//
char keypad_scan()
{
    char key,i;

    P2=0xF0;
   	while (P2!=0xF0);
      do{
	   if(ctrl()==1)
	   {
		 pwd_fail();
		 return(15);
	   }
       for(i=0;i<=3;i++)
       {        
          P2=ksp[i];
		  show(0,3,0,0);
		  if(ctrl()==1)
		  {
			 pwd_fail();
			 return(15);
		  }
          if(P2!=ksp[i])
          {
             delay();
             key=P2;
             if(key!=ksp[i])
			 {
			 	return(key);
			 }
          }
       }
    } while(1);
}
char keypad_scans()
{
    char key,i;

    P2=0xF0;
   	while (P2!=0xF0);
      do{
       for(i=0;i<=3;i++)
       {   
		  if(ctrl()==1)
		  {
			 pwd_fail();
			 return(15);
		  }     
          P2=ksp[i];
          if(P2!=ksp[i])
          {
             delay();
             key=P2;
             if(key!=ksp[i])
			 {
			 	return(key);
			 }
          }
       }
    } while(1);
}
// 檢查是否有按鍵按下
char gotkey()
{
    char temp,i;
    show(0,3,0,0);
	temp=keypad_scan();
	for (i=0;i<=15;i++) {
	    if(temp==key_code[i]) return(i);
	}
	return(16);
}

char gotkeys()
{
    char temp,i;
	temp=keypad_scans();
	for (i=0;i<=15;i++) {
	    if(temp==key_code[i]) return(i);
	}
	return(16);
}
