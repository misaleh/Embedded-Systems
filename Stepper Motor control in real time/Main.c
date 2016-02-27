/*
 * Stepper.c
 *
 * Created: 06/02/2016 08:54:14 م
 *  Author: Mostafa
 */ 

#include <avr/io.h>
#include "GPT.h"
#include "DIO.h"
#include "Essentials.h"
#include "LEDS.h"
#include "BTN.h"
#include "STPR.h"
#include <avr/interrupt.h> 
#include <util/delay.h>
ISR(TIMER0_OVF_vect)/*every 2ms*/
{ SysTick++ ;
	if((SysTick%64) == 0) /*every 250 ms raise the flag, the problem is that the function may be entered after
	 the 125 count (126 may be) so it will not detect the flash by a simple way*/
	{
		ledFlag_RIGHT =1;
		ledFlag_LEFT = 1;
		ledFlag_HALF = 1;
		ledFlag_FULL = 1;
		Stepper_Flag ++;
	}
}

int main(void)
{
	asm("SEI"); /*Enable Global interrupt */ 
	GPT_Init();
	LEDS_Init();
	BTN_Init();	
	STPR_Init();
	unsigned char currentS = 0; /*  current state  */
	 	StateType MealyState[4] ={
	{		STPR_MOV_HALFR ,LEDS_Flash_RIGHT,LEDS_Flash_HALF  ,{Half_Right ,Full_Right,Half_Left,Full_Left} },
	{		STPR_MOV_FULLR ,LEDS_Flash_RIGHT,LEDS_Flash_FULL, {Full_Right,Half_Right ,Full_Left, Half_Left } },
	{		STPR_MOV_HALFL ,LEDS_Flash_LEFT,LEDS_Flash_HALF ,{Half_Left , Full_Left,Half_Right , Full_Right} },
	{		STPR_MOV_FULLL,LEDS_Flash_LEFT,LEDS_Flash_FULL, {Full_Left ,Half_Left , Full_Right ,Half_Right} },
	};		
    while(1)
    {
		BTN_GetBtnState(BTN_SPEEDDOWN,&ButtonData);
		if(ButtonData == BTN_STATE_ACTIVE)
		{
			speed -- ;
			speed = (speed < 1)?1:speed;
		}	
		BTN_GetBtnState(BTN_SPEEDUP,&ButtonData2);
		if(ButtonData2 == BTN_STATE_ACTIVE)
		{
			speed ++ ;
			speed = (speed > 5)?5:speed;
		}
		BTN_GetBtnState(BTN_Mode,&ButtonData);
		BTN_GetBtnState(BTN_Dir,&ButtonData1);
	    ButtonState = !ButtonData  + 2*(!ButtonData1); //active = 0
		
		(MealyState[currentS]).FunctionPointerStepper(speed);
		(MealyState[currentS]).FunctionPointerLeds1();
		(MealyState[currentS]).FunctionPointerLeds2();
		currentS = (MealyState[currentS]).nexState[ButtonState];

	}		
    
}
