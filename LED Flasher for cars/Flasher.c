/*
 * Assignment1.c
 *
 * Created: 05/09/2015 08:45:28 ص
 *  Author: Mostafa
 */ 


#include <avr/io.h>
#include "ModuleEssential.h"
#include  "essential.h"
#include "DataTypes.h"
#include "LedControl.h"
#include <avr/interrupt.h>
#include "Timerint.h"

void init(void);
volatile u8 mail = 0 ;
ISR(TIMER0_OVF_vect)/* interrupt every 16ms */
{
 mail ++ ;
 
}

int main(void)
{
/*  pin 0 for Right switch 
	pin 1 for Left switch
	pin 2 for both(hazard) switch
*/

	init(); /* uc init */
	timer0_init(); /* timer init */
	u8 currentS = 0; /*  current state  */
	StateType Flasher[7] =  
	{
	{	FlashNone,  {INIT, FRIGHTE,FLEFTE ,FRIGHTE,HAZARDE,HAZARDE,HAZARDE,HAZARDE} },		/* INIT */
	{	FlashRight, {INIT, FRIGHT,FLEFTE ,FRIGHT,HAZARDE,HAZARDE,HAZARDE,HAZARDE} },		/* FRIGHT */
	{	FlashLeft, {INIT, FRIGHTE,FLEFT ,FLEFT,HAZARDE,HAZARDE,HAZARDE,HAZARDE} },		/* FLEFT */
	{   FlashBoth,  { INIT, FRIGHTE,FLEFTE ,FRIGHTE,HAZARD,FRIGHTE,FLEFTE,FRIGHTE  } },  /* HAZARD */
	{	FlashRightE, {INIT, FRIGHT,FLEFTE ,FRIGHT,HAZARDE,HAZARDE,HAZARDE,HAZARDE} },	    /* FRIGHTE */
	{	FlashLeftE, {INIT, FRIGHTE,FLEFT ,FLEFT,HAZARDE,HAZARDE,HAZARDE,HAZARDE} },		/* FLEFTE */
	{   FlashBothE,  { INIT, FRIGHTE,FLEFTE ,FRIGHTE,HAZARD,FRIGHTE,FLEFTE,FRIGHTE  } },	/* HAZARDE*/
		
	
	} ;
	
    while(1)
    {
	
	(Flasher[currentS].OutputFunctionPointer)(SwitchAll); /* calls the function the flash the led with parameter of the caller state  */
	currentS = Flasher[currentS].nexState[SwitchAll];  /* the next state depends on the inputs */
	
    }
	 return 0;
}

void init(void)
{
	DDRD |= (1 << LEDR); /* Led R output */
	DDRD |= (1 << LEDL);	/* Led L output */
}