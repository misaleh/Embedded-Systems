/*
 * LEDS.h
 *
 * Created: 08/02/2016 02:45:59 ص
 *  Author: Mostafa
 */ 


#ifndef LEDS_H_
#define LEDS_H_
#define LED_Half 0x01
#define LED_Full 0x02
#define LED_Right 0x04
#define LED_Left  0x08
#define LED_ON  0x01
#define LED_OFF 0x00

void LEDS_Init(void);
void LEDS_Flash_RIGHT(void); 
void LEDS_Flash_LEFT(void); 
void LEDS_Flash_HALF(void); 
void LEDS_Flash_FULL(void); 
void LEDS_Stop(unsigned char led); 


#endif /* LEDS_H_ */