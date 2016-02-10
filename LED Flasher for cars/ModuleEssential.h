/*
 * ModuleEssential.h
 *
 * Created: 05/09/2015 08:48:05 ص
 *  Author: Mostafa
 */ 
#ifndef _MODULEESSENTIAL_H
#define _MODULEESSENTIAL_H



/* Required registers */


//#define DDRD (*(volatile unsigned char *)0x2A)
//#define PORTD (*(volatile unsigned char *)0x2B)
//#define PIND (*(volatile unsigned char *)0x29)

#define SwitchR  0x01
#define SwitchL  0x02
#define SwitchB  0x04
#define SwitchAll  (PIND & 0x07)

#define LEDR    0x03
#define LEDL	0x04



typedef enum state { INIT,FRIGHT,FLEFT,HAZARD ,FRIGHTE,FLEFTE,HAZARDE} State ;
	/* FRIGHTE,FLEFTE,FLEFTE are Entry states for FRIGHT,FLEFT,HAZARD   */

typedef struct {
  void (*OutputFunctionPointer)(unsigned char s);
  State nexState[8]; /*3 switches 8 cases */
  
  }StateType;
  
  




#endif