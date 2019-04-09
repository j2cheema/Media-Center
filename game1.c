//Game file 1
#include <stdio.h>                                  
#include <ctype.h>                    
#include <string.h>       
#include <math.h>
#include <stdbool.h>
#include <RTL.h>
#include "GLCD.h"
#include "KBD.h"
#include "LED.h"
#include "cmsis_os.h"
#include "RTL.H"		// RTX header file
#include "LPC17xx.H"              // LPC17xx definitions           

#define __FI        1                      /* Font index 16x24               */
#define __USE_LCD   0										/* Uncomment to use the LCD */


#define ITM_Port8(n)    (*((volatile unsigned char *)(0xE0000000+4*n)))
#define ITM_Port16(n)   (*((volatile unsigned short*)(0xE0000000+4*n)))
#define ITM_Port32(n)   (*((volatile unsigned long *)(0xE0000000+4*n)))

#define DEMCR           (*((volatile unsigned long *)(0xE000EDFC)))
#define TRCENA          0x01000000


struct __FILE { int handle;  };
FILE __stdout;
FILE __stdin;

int fputc(int ch, FILE *f) {
  if (DEMCR & TRCENA) {
    while (ITM_Port32(0) == 0);
    ITM_Port8(0) = ch;
  }
  return(ch);
}


int game1 (void) {
			
			#ifdef __USE_LCD
			GLCD_Init();                               /* Initialize graphical LCD (if enabled */
			KBD_Init();
			GLCD_Clear(White);                         /* Clear graphical LCD display   */
		  GLCD_SetBackColor(Blue);
			GLCD_SetTextColor(White);
			GLCD_DisplayString(0, 0, __FI, "Rock, paper, Scissors");
			
		
			
			GLCD_SetBackColor(White);
			GLCD_SetTextColor(Blue);
		#endif 
	
	
	

}
