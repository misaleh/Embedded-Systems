/*
 * GPT.c
 * MCAL
 * Created: 06/02/2016 08:55:24 م
 *  Author: Mostafa
 */ 
#include <avr/interrupt.h>
#include <avr/io.h>
void GPT_Init(void)
{	
    TIMSK |= (1 << TOIE0); /* enable overflow interrupt */ 
	TCCR0 = (1<<CS01);

}
void GPT_Stop(void)
{
TCCR0 &= ~(1<<CS00); /*Stop timer  */
TCNT0 = 0; /*Reset the counter */
}
