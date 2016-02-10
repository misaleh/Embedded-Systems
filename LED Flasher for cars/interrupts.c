/*
 * interrupts.c
 *
 * Created: 05/09/2015 03:48:09 م
 *  Author: Mostafa
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "EINT.h"
static PfType Fn0Ptr,Fn1Ptr,Fn2Ptr;
void EINT_Init(PfType Int0Fn,PfType Int1Fn,PfType Int2Fn)
{
	/*Set the interrupt sense control of*/
	/*Int0 : any change*/
	/*int1 : Falling Edge*/
	/*int 2 : Rising EDgE*/
	MCUCR |=  0x09;
	MCUCSR |= 0x40;

	/*Clear Flags*/
	TIFR &= ~ 0xE0;

	/*Enable Local Interrupts*/
	GICR |= 0xE0;

	/*Set the Pointer variables with the callback functions addresses*/
	Fn0Ptr = Int0Fn;
	Fn1Ptr = Int1Fn;
	Fn2Ptr = Int2Fn;
	
	
}
