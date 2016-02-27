/*
 * LEDS.c
 *
 * Created: 08/02/2016 02:45:41 ص
 *  Author: Mostafa
 */ 
#include "DIO.h"
#include "LEDS.h"
extern unsigned char SysTick;
extern unsigned char  ledFlag_RIGHT;
extern unsigned char  ledFlag_LEFT ;
extern unsigned char  ledFlag_HALF;
extern unsigned char  ledFlag_FULL;
void LEDS_Init(void)
{
	 DIO_vidWritePortDirection(PB,0xFF,0xFF);
	
}
void LEDS_Flash_RIGHT(void)
{
		if((ledFlag_RIGHT))
	{
		DIO_vidWritePortData(PB,LED_Left,0); 
		ledFlag_RIGHT =0;
		DIO_vidTogglePortData(PB,LED_Right); /*toggle led every 250 ms*/
	}
}
void LEDS_Flash_LEFT(void)
{
		if( (ledFlag_LEFT) )
	{
		DIO_vidWritePortData(PB,LED_Right,0);
		ledFlag_LEFT  = 0; /*there is a hazard at the first flash only */
		DIO_vidTogglePortData(PB,LED_Left); /*toggle led every 250 ms*/
	}
}
void LEDS_Flash_HALF(void)
{
		if(ledFlag_HALF)
	{
		DIO_vidWritePortData(PB,LED_Full,0);
		ledFlag_HALF = 0; /*there is a hazard at the first flash only */
		DIO_vidTogglePortData(PB,LED_Half); /*toggle led every 250 ms*/
	}
}
void LEDS_Flash_FULL(void)
{
		if(ledFlag_FULL)
	{
		DIO_vidWritePortData(PB,LED_Half,0);
		ledFlag_FULL = 0; /*there is a hazard at the first flash only */
		DIO_vidTogglePortData(PB,LED_Full); /*toggle led every 250 ms*/
	}
}

void LEDS_Stop(unsigned char led) 
{
	DIO_vidWritePortData(PB,led,0);
}