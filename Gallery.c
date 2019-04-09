/*----------------------------------------------------------------------------
 * Name:    PhotoGallery
 * Purpose: 
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

#define __FI        1                      /* Font index 16x24               */
#define __USE_LCD   0										/* Uncomment to use the LCD */

//ITM Stimulus Port definitions for printf //////////////////
#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000

extern void mp3player(void);



/*----------------------------------------------------------------------------
  Main Program
 *----------------------------------------------------------------------------*/
int game1 (void) {
  uint32_t ad_avg = 0;
  uint16_t ad_val = 0, ad_val_ = 0xFFFF;

  LED_Init();                                /* LED Initialization            */
  ADC_Init();                                /* ADC Initialization            */
	KBD_Init();                                /* KBD Initialization            */

#ifdef __USE_LCD
  GLCD_Init();                               /* Initialize graphical LCD (if enabled */

  GLCD_Clear(White);                         /* Clear graphical LCD display   */
  GLCD_SetBackColor(Blue);
  
#endif	

  //SysTick_Config(SystemCoreClock/100);       /* Generate interrupt each 10 ms */

  while (1) {                                /* Loop forever                  */
	for (;;)
			GLCD_SetTextColor(Black);
			GLCD_DisplayString(1, 0, __FI, " Rock, Paper, Scissors");
	
	}
}