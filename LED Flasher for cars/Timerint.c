/*
 * Timerint.c
 *
 * Created: 06/09/2015 09:46:21 ص
 *  Author: Mostafa
 */ 
#include <avr/interrupt.h>
#include <avr/io.h>
#include "Timerint.h"

void timer0_init(void)
{
	
	TCCR0=0x03;
	/*  normal operation 
		64 prescaler
		no output compare
	*/
		
    TIMSK=0x01;
	/* enable overflow interrupt */ 
	/* there will be a timer interrupt every 16.32 ms */
	asm("SEI"); /*  enable global interrupts */
}