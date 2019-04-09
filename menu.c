#include <LPC17xx.H>                    /* NXP LPC17xx definitions            */
#include "string.h"
#include "GLCD.h"
#include "LED.h"


void menu(){                                                                           ////////////////                                 /////////// MENU
	LED_Init();                                /* LED Initialization            */
  ADC_Init();                                /* ADC Initialization            */
	KBD_Init();                                /* KBD Initialization            */


  GLCD_Init();                               /* Initialize graphical LCD (if enabled */

  GLCD_Clear(White);                         /* Clear graphical LCD display   */
  GLCD_SetBackColor(Blue);
  GLCD_SetTextColor(Yellow);
  GLCD_DisplayString(0, 0, __FI, "  COE718 Kabir   ");
	GLCD_SetTextColor(White);
  GLCD_DisplayString(1, 0, __FI, "  Media Player Menu   ");
  GLCD_DisplayString(2, 0, __FI, "  Joystcick to Toggle");
	//GLCD_DisplayString(3, 0, __FI, "            ");
  GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
  GLCD_DisplayString(6, 0, __FI, "Photo Gallery   ");
	GLCD_DisplayString(7, 0, __FI, "MP3");
	GLCD_DisplayString(8, 0, __FI, "Game");
	
		
	while(1){
		
		get_state();
	switch (state){
		case 0:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(6, 13, __FI, "<-");
			GLCD_DisplayString(7, 3, __FI, "  ");
			GLCD_DisplayString(8, 4, __FI, "  ");
			GLCD_DisplayString(9, 0, __FI, "0");
			delay();
			break;
			case 1:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(6, 13, __FI, "  ");
			GLCD_DisplayString(7, 3, __FI, "<-");
			GLCD_DisplayString(8, 4, __FI, "  ");
			GLCD_DisplayString(9, 0, __FI, "1");
			delay();
			break;
			case 2:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(6, 13, __FI, "  ");
			GLCD_DisplayString(7, 3, __FI, "  ");
			GLCD_DisplayString(8, 4, __FI, "<-");
			GLCD_DisplayString(9, 0, __FI, "2");
			delay();
			break;
	}//switch close
	if (get_button()==KBD_SELECT){
		break;
		
	}
	
	delay();
}//while close
	if(state==2){
				board();
		}
}//menu method close