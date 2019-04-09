/*----------------------------------------------------------------------------
 * Name:    Blinky.c
 * Purpose: LED Flasher
 * Note(s): __USE_LCD   - enable Output on LCD, uncomment #define in code to use
 *  				for demo (NOT for analysis purposes)
 *----------------------------------------------------------------------------
 * Copyright (c) 2008-2011 Keil - An ARM Company.
 * Name: Anita Tino
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include "LPC17xx.H"                       
#include "GLCD.h"
#include "LED.h"
#include "ADC.h"
#include "KBD.h"


extern unsigned char ball;
extern unsigned char nike;
extern unsigned char logo;


#define __FI        1                      /* Font index 16x24               */
#define __USE_LCD   0										/* Uncomment to use the LCD */

//ITM Stimulus Port definitions for printf //////////////////
#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000

extern int mp3player(void);
int musicOn=0;
void music(){ //---------------------------------------------------------------------------------music Player
	musicOn=0;

				GLCD_Clear(White);
				 GLCD_SetBackColor(Blue);
				 GLCD_SetTextColor(Yellow);
				 GLCD_DisplayString(0, 0, __FI, "  Music Player    ");
				 GLCD_SetTextColor(White);
				 GLCD_DisplayString(1, 0, __FI, "     ");
				 GLCD_DisplayString(2, 0, __FI, "  Enjoy!");
	while(musicOn==0){				 
	mp3player();
if(get_button()==KBD_LEFT){
	musicOn=1;
}		// --------------------------music player line
					
}//wqhile close
}//music close

struct __FILE { int handle;  };
FILE __stdout;
FILE __stdin;
int i=0;
int state =0;// button state in menu
int gameState = 1; // game state
int gameOver=0;

void delay(){ 
	int k =0, count = 0;
	for(k = 0; k < 100000; k++){
					
			}
	for(count = 0; count < 1000000; count++){
					
			}
	
	}// delay function
void upState(){

state++;
if(state>2){
state=0;
}	
delay();
}
void downState(){

state--;
if(state<0){
state=2;
}
delay();
}
void Dstate(){
	if(gameState==10){
		gameState=10;
	}
	if(gameState==7){
		gameState=1;
	}
	if(gameState==8){
		gameState=2;
	}
	if(gameState==9){
		gameState=3;
	}
	else{
		gameState=gameState+3;
	}
}
void Ustate(){
	if(gameState==10){
		gameState=10;
	}
	if(gameState==1){
		gameState=7;
	}
	if(gameState==2){
		gameState=8;
	}
	if(gameState==3){
		gameState=9;
	}
	else{
		gameState=gameState-3;
	}
}
void Lstate(){
	if(gameState==10){
		gameState=6;
	}
	if(gameState==1){
		gameState=3;
	}
	if(gameState==4){
		gameState=6;
	}
	if(gameState==7){
		gameState=9;
	}
	else{
		gameState=gameState-1;
	}
}
void Rstate(){
	if(gameState==10){
		gameState=4;
	}
	if(gameState==3){
		gameState=1;
	}
	if(gameState==6){
		gameState=10;
	}
	if(gameState==9){
		gameState=7;
	}
	else{
		gameState=gameState+1;
	}
}
void get_state(){
if (get_button()==KBD_UP){
			downState();
		}
		if (get_button()==KBD_DOWN){
			
			upState();
		}
		
}
void getGameState(){
    if (get_button()==KBD_UP){
			Ustate();
		}
		if (get_button()==KBD_DOWN){
			
			Dstate();
		}
		if (get_button()==KBD_LEFT){
			Lstate();
		}
		if (get_button()==KBD_RIGHT){
			
			Rstate();
		}
		
}

int fputc(int ch, FILE *f) {
  if (DEMCR & TRCENA) {
    while (ITM_Port32(0) == 0);
    ITM_Port8(0) = ch;
  }
  return(ch);
}
/////////////////////////////////////////////////////////

char text[10];

//Use to trace the pot values in Debug
uint16_t ADC_Dbg;

/* Import external variables from IRQ.c file                                  */
extern uint8_t  clock_ms;
 void gallery(){         // ----------------------------------------------------------------------------------Gallery function GLCD_Bitmap (  0,   0, 100,  100,(unsigned char*)  ball);
 LED_Init();                                /* LED Initialization            */
  ADC_Init();                                /* ADC Initialization            */
	KBD_Init();                                /* KBD Initialization            */


  GLCD_Init();                               /* Initialize graphical LCD (if enabled */

  GLCD_Clear(White);                         /* Clear graphical LCD display   */
  GLCD_SetBackColor(Blue);
  GLCD_SetTextColor(Yellow);
  GLCD_DisplayString(0, 0, __FI, " Gallery menu   ");
	GLCD_SetTextColor(White);
  //GLCD_DisplayString(1, 0, __FI, "  Media Player Menu   ");
  GLCD_DisplayString(1, 0, __FI, "  Joystcick to Toggle");
	//GLCD_DisplayString(3, 0, __FI, "            ");
  GLCD_SetBackColor(White);
  GLCD_SetTextColor(Blue);
  GLCD_DisplayString(6, 0, __FI, "Nike Symbol");
	GLCD_DisplayString(7, 0, __FI, "Soccer ball");
	GLCD_DisplayString(8, 0, __FI, "Logo");
	
		
	while(1){
		
		get_state();
	switch (state){
		case 0:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(6, 11, __FI, "<-");
			GLCD_DisplayString(7, 11, __FI, "  ");
			GLCD_DisplayString(8, 4, __FI, "  ");
			GLCD_DisplayString(9, 0, __FI, "0 ");
			delay();
			break;
			case 1:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(6, 11, __FI, "  ");
			GLCD_DisplayString(7, 11, __FI, "<-");
			GLCD_DisplayString(8, 4, __FI, "  ");
			GLCD_DisplayString(9, 0, __FI, "1");
			delay();
			break;
			case 2:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(6, 11, __FI, "  ");
			GLCD_DisplayString(7, 11, __FI, "  ");
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
	switch(state){
		case 0:
			GLCD_Clear(White);
			GLCD_Bitmap (  0,   0, 320,  240,(unsigned char*)  nike);
		delay();delay();delay();delay();
			break;
		case 1:
			 GLCD_Clear(White);
			GLCD_Bitmap (  0,   0, 320,  240,(unsigned char*)  ball);
		delay();delay();delay();delay();
		break;

		case 2:
			 GLCD_Clear(White);		
			GLCD_Bitmap (  0,   0, 320,  240,(unsigned char*)  logo);	
			delay();delay();delay();delay();
			break;
	}
	}// gallery function close
  

 
 char square[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
 void resetSquare(){
	 for(i=0; i<9 ;i++){
			square[i]=' ';
	 }
	 i=0;
 }
void board(){																																									//---------------board() 
	LED_Init();                                /* LED Initialization            */
  ADC_Init();                                /* ADC Initialization            */
	KBD_Init();                                /* KBD Initialization            */


			GLCD_Init();
	GLCD_Clear(White);                         /* Clear graphical LCD display   */
  GLCD_SetBackColor(White);
  GLCD_SetTextColor(Red);
	    GLCD_DisplayString(4, 14, __FI, "MENU");
	GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 3, __FI, "|"); //row column 
			GLCD_DisplayString(6, 3, __FI, "|");
			GLCD_DisplayString(7, 3, __FI, "|");
			GLCD_DisplayString(5, 3, __FI, "|");
			GLCD_DisplayString(8, 3, __FI, "|");
			
			
			GLCD_DisplayString(4, 6, __FI, "|");
			GLCD_DisplayString(6, 6, __FI, "|");
			GLCD_DisplayString(7, 6, __FI, "|");
			GLCD_DisplayString(5, 6, __FI, "|");
			GLCD_DisplayString(8, 6, __FI, "|");
			
			GLCD_DisplayString(7, 1, __FI, "-");
			GLCD_DisplayString(7, 2, __FI, "-");
			GLCD_DisplayString(7, 4, __FI, "-");
			GLCD_DisplayString(7, 5, __FI, "-");			
			GLCD_DisplayString(7, 7, __FI, "-");
			GLCD_DisplayString(7, 8, __FI, "-");
			
			GLCD_DisplayString(5, 1, __FI, "-");
			GLCD_DisplayString(5, 2, __FI, "-");
			GLCD_DisplayString(5, 4, __FI, "-");
			GLCD_DisplayString(5, 5, __FI, "-");			
			GLCD_DisplayString(5, 7, __FI, "-");
			GLCD_DisplayString(5, 8, __FI, "-");
			
			GLCD_DisplayChar(4, 1, __FI, square[0]);
			GLCD_DisplayChar(4, 4, __FI, square[1]);
			GLCD_DisplayChar(4, 7, __FI, square[2]);
			GLCD_DisplayChar(6, 1, __FI, square[3]);
			GLCD_DisplayChar(6, 4, __FI, square[4]);
			GLCD_DisplayChar(6, 7, __FI, square[5]);
			GLCD_DisplayChar(8, 1, __FI, square[6]);
			GLCD_DisplayChar(8, 4, __FI, square[7]);
			GLCD_DisplayChar(8, 7, __FI, square[8]);
}
void checkWin(){																																				////check win function ( )
		if((square[0]=='X')&& (square[1]=='X') && (square[2]=='X')){
			delay();
			gameOver=1;
		}
		else if((square[0]=='X') && (square[3]=='X') && (square[6]=='X')){
			delay();
			gameOver=1;
		}
		else if((square[3]=='X') && (square[4]=='X') && (square[5]=='X')){
			delay();
			gameOver=1;
		}
		else if((square[6]=='X') && (square[7]=='X') && (square[8]=='X')){
			delay();
			gameOver=1;
		}
		else if((square[1]=='X') && (square[4]=='X') && (square[7]=='X')){
			delay();
			gameOver=1;
		}
		else if((square[2]=='X') && (square[5]=='X') && (square[8]=='X')){
			delay();
			gameOver=1;
		}
		else if((square[2]=='X') && (square[4]=='X') && (square[6]=='X')){
			delay();
			gameOver=1;
		}
		
		else if((square[0]=='0') && (square[1]=='0') && (square[2]=='0')){
			delay();
			gameOver=1;
		}
		else if((square[0]=='0')&& (square[3]=='0') && (square[6]=='0')){
			delay();
			gameOver=1;
		}
		else if((square[3]=='0')&& (square[4]=='0') && (square[5]=='0')){
			delay();
			gameOver=1;
		}
		else if((square[6]=='0')&& (square[7]=='0') && (square[8]=='0')){
			delay();
			gameOver=1;
		}
		else if((square[1]=='0')&& (square[4]=='0') && (square[7]=='0')){
			delay();
			gameOver=1;
		}
		else if((square[2]=='0')&& (square[5]=='0') && (square[8]=='0')){
			gameOver=1;
		}
		else if((square[2]=='0')&& (square[4]=='0') && (square[6]=='0')){
			delay();
			gameOver=1;
		}
		else if((square[0]=='0')&& (square[4]=='0')&& (square[8]=='0')){
			delay();
			gameOver=1;
		}
		
}//close of checkWin()
void user1(){																																						//-----user1() 
	
	LED_Init();                                /* LED Initialization            */
  ADC_Init();                                /* ADC Initialization            */
	KBD_Init();                                /* KBD Initialization            */

	board();
  GLCD_Init();
	GLCD_SetTextColor(Red);
	GLCD_DisplayString(1, 0, __FI, "Player 1 Turn X");
	GLCD_DisplayString(0, 0, __FI, "Tic-Tac-Toe");
	while(1){
	getGameState();
	
	switch (gameState){
			case 1:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, "<");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "1 ");
			delay();
			break;
			case 2:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, "<");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "2 ");
			delay();
			break;
			case 3:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, "<");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "3 ");
			delay();
			break;
			case 4:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, "<");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "4 ");
			delay();
			break;
			case 5:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, "<");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "5 ");
			delay();
			break;
			case 6:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, "<");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "6 ");
			delay();
			break;
			case 7:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, "<");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "7 ");
			delay();
			break;
			case 8:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, "<");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "8 ");
			delay();
			break;
			case 9:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, "<");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "9 ");
			delay();
			break;
			case 10:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, "<");
			GLCD_DisplayString(9, 0, __FI, "10");
			delay();
			break;
			
	}//switch close
	if (get_button()==KBD_SELECT){
		break;
	}
	delay();
}//while close
	switch(gameState){
		case 1:
			square[0]= 'X';
		break;
		case 2:
			square[1]= 'X';
		break;
		case 3:
			square[2]= 'X';
		break;
		case 4:
			square[3]= 'X';
		break;
		case 5:
			square[4]= 'X';
		break;
		case 6:
			square[5]= 'X';
		break;
		case 7:
			square[6]= 'X';
		break;
		case 8:
			square[7]= 'X';
		break;
		case 9:
			square[8]= 'X';
		break;
		case 10:
				gameOver=1;
		break;
	}//select switch close
	checkWin();
	}//user1() close
void user2(){																																						//-----user2() 
	
	LED_Init();                                /* LED Initialization            */
  ADC_Init();                                /* ADC Initialization            */
	KBD_Init();                                /* KBD Initialization            */

	board();
	
  GLCD_Init();
	GLCD_SetTextColor(Red);
	GLCD_DisplayString(1, 0, __FI, "Player 2 Turn 0");
	GLCD_DisplayString(0, 0, __FI, "Tic-Tac-Toe");
	while(1){
	getGameState();
	
	switch (gameState){
			case 1:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, "<");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "1 ");
			
			break;
			case 2:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, "<");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "2 ");
		
			break;
			case 3:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, "<");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "3 ");
			
			break;
			case 4:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, "<");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "4 ");
			
			break;
			case 5:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, "<");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "5 ");
			
			break;
			case 6:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, "<");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "6 ");
		
			break;
			case 7:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, "<");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "7 ");
		
			break;
			case 8:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, "<");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "8 ");
		
			break;
			case 9:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, "<");
			GLCD_DisplayString(4, 18, __FI, " ");
			GLCD_DisplayString(9, 0, __FI, "9 ");
			
			break;
			case 10:
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(4, 2, __FI, " ");
			GLCD_DisplayString(4, 5, __FI, " ");
			GLCD_DisplayString(4, 8, __FI, " ");
			GLCD_DisplayString(6, 2, __FI, " ");
			GLCD_DisplayString(6, 5, __FI, " ");
			GLCD_DisplayString(6, 8, __FI, " ");
			GLCD_DisplayString(8, 2, __FI, " ");
			GLCD_DisplayString(8, 5, __FI, " ");
			GLCD_DisplayString(8, 8, __FI, " ");
			GLCD_DisplayString(4, 18, __FI, "<");
			GLCD_DisplayString(9, 0, __FI, "10");
			
			break;
			
	}//switch close
	if (get_button()==KBD_SELECT){
		break;
	}
	delay();
}//while close
	switch(gameState){
		case 1:
			square[0]= '0';
		break;
		case 2:
			square[1]= '0';
		break;
		case 3:
			square[2]= '0';
		break;
		case 4:
			square[3]= '0';
		break;
		case 5:
			square[4]= '0';
		break;
		case 6:
			square[5]= '0';
		break;
		case 7:
			square[6]= '0';
		break;
		case 8:
			square[7]= '0';
		break;
		case 9:
			square[8]= '0';
		break;
		case 10:
				gameOver=1;
		break;
		
	}//select switch close
	checkWin();
	}//user2() close

void game(){ // ------------------------------------------------------------------------------- game()
	LED_Init();                                /* LED Initialization            */
  ADC_Init();                                /* ADC Initialization            */
	KBD_Init();                                /* KBD Initialization            */

	while(gameOver==0){
		if (gameOver==0){
		user1();		
		checkWin();
		}
		if(gameOver==0){
		user2();
		checkWin();
		}
	}
	GLCD_Clear(White);                         /* Clear graphical LCD display   */
  GLCD_SetBackColor(Blue);
  GLCD_SetTextColor(Yellow);
  GLCD_DisplayString(5, 10, __FI, "GAME OVER");
	delay();
	delay();
	delay();
}
void menu(){                                                                           ////////////////                                 /////////// MENU
	LED_Init();                                /* LED Initialization            */
  ADC_Init();                                /* ADC Initialization            */
	KBD_Init();                                /* KBD Initialization            */


  GLCD_Init();                               /* Initialize graphical LCD (if enabled */

  GLCD_Clear(White);                         /* Clear graphical LCD display   */
  GLCD_SetBackColor(Blue);
  GLCD_SetTextColor(Yellow);
  GLCD_DisplayString(0, 0, __FI, "  COE718 Kabir    ");
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
			GLCD_DisplayString(9, 0, __FI, "0 ");
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
	switch(state){
		case 0:
			gallery();
			break;
		case 1:
		
		music();
		
		break;			
		case 2:
				game();
			break;
	}
}//menu method close

/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
 

int main (void) {
 while(1){
			gameOver=0;
			resetSquare();
			menu();
 }
}
