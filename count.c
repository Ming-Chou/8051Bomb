/* 	���D:		�C�q�˼� 60��
 	����:		1.0
 	�{���y�z:	�ϥ�8051 ��Port 1�s����|���C�q��ܾ��A
				�˼Ʈɶ�60��A�ɶ�����h�Ȱ��A
				�o�|���C�q��ܾ��N��ܥX 60 �� 0�C
*/

#include <REG51.H>
#include "lcd.h"
#include "lcd_show.h"
#define TIMER0_COUNT 0xFC18	/* 10000h-((12,000,000/(12*FREQ)) */
code seven_seg[10] = {0X00, 0X01, 0X02, 0X03, 0X04, 0X05, 0X06, 0X07, 0X08, 0X09};
code scan[4]={0XE0,0XD0,0xB0,0x70};
unsigned char counter[4]={0,3,0,0};  // �ɶ��]�w
unsigned char i=0;
int	timer0_tick;
static int Control=0;

void T0_int(void) interrupt 1
{
  TR0=0;
  TL0=(TIMER0_COUNT & 0x00FF);
  TH0=(TIMER0_COUNT >> 8);
  TR0=1;

  P0 = seven_seg[counter[i]] | scan[i];
  i++;
  if(i==4) i=0;
  timer0_tick++;
  
  if(counter[0]==0 && counter[1]==0 && counter[2]==0 &&counter[3]==0) 
  {     
    Control=1;
    //pwd_fail();
  }

  if (timer0_tick==1000 && Control==0) {
      timer0_tick=0;
/*---------------------�ɶ��˼ơA�C�q�˼�-----------------------------*/
      counter[0]--;		 			
      if (counter[0]==-1) {			
	  	  counter[0]=9;				
		  counter[1]--;				
		  if (counter[1]==-1) {		
		      counter[1]=9;			
			  counter[2]--;
			  if (counter[2]==-1) {	
			   	  counter[2]=9;		
				  counter[3]--;			
				  if(counter[3]==-1) { 
				     counter[3]=9; 
			      }
		      }
	      }
      }
  }  
}
	
int ctrl(void)
{
    return Control;
}
	
static void timer0_initialize(void)
{
  EA=0;   
  timer0_tick=0;
  TR0=0;
  TMOD &= 0XF0;
  TMOD |=0x01;
  TL0=(TIMER0_COUNT & 0x00FF);
  TH0=(TIMER0_COUNT >> 8);
  PT0=0;
  ET0=1;
  TR0=1;
  EA=1;
}
    
void count (void)  {

  timer0_initialize();
  //while (1);                         /* Loop forever */
}


