**Target** : Atmega32


**Toolchain** : Atmel studio 6.0


**Simulation tool** :proteus 7.7

**Frequency** : 1MHZ

**Required**:

The hardware of the code as shown in the schematic, contain of one stepper motor four pushbuttons and 4 leds 


The 4 buttons : 


		1-used to switch between half step mode and full step mode for the stepper motor
		
		2-used to change the direction of the stepper motor form right to left and vice versa,
		  every click will change the direcion
		  
		3-increase the speed of the stepper motor
		
		4-decrease the speed of the stepper motor
		
The 4 Leds :

		1-indication for stepper moving right
		
		2-indication for stepper moving Left
		
		3-indication for stepper moving in half step mode
		
		4-indication for stepper moving full step mode
		
all the leds flash with frequency 4hz


the response has to be in real time  



**Implementaion** :

To satisfy the time requirements there is a periodic interrupt every 2 ms that sets or change flags for stepper and led functions.
>( ledFlag_RIGHT(), ledFlag_LEFT, ledFlag_HALF, ledFlag_FULL , Stepper_Flag )

In the led driver there is 5 led function, the first function is used to intiate the port direction for leds 
the other function is reponsible for flashing one led only, however each function when called stops the complement led
because both cannot happen , ex: motor cannot move right and left at the same time so right led and left led cannot flash at the same time.
>(LEDS_Init, LEDS_Flash_RIGHT, LEDS_Flash_LEFT, LEDS_Flash_HALF, LEDS_Flash_FULL)

In the stepper driver there is six functions one to intiate it and the other to move right with full and half step and move left with full and half step
and to stop the stepper.
>(STPR_Init, STPR_MOV_HALFR, STPR_MOV_HALFL, STPR_MOV_FULLR, STPR_MOV_FULLL, STPR_Stop )

The code is implemented using mealy state machine with 4 states move half right, move half left, move full right and move full left.
 written as
> typedef enum state { Half_Right,Full_Right,Half_Left,Full_Left } Mealy_state;

Each state has 4 charatristics first led to flash(right or left) , second lef to flash(full or half), the stepper function(one of the described above)
and finally the next state depending on input	
written as 

>typedef struct {
void (*FunctionPointerStepper)(unsigned char s); /*For stepper motor*/
void (*FunctionPointerLeds1)(void);
void (*FunctionPointerLeds2)(void);
Mealy_state nexState[4]; /*4 states */  
  }StateType;  
  
in the main code the defition of the state machine is
>	 	StateType MealyState[4] ={
>	{		STPR_MOV_HALFR ,LEDS_Flash_RIGHT,LEDS_Flash_HALF  ,{Half_Right ,Full_Right,Half_Left,Full_Left} },
>	{		STPR_MOV_FULLR ,LEDS_Flash_RIGHT,LEDS_Flash_FULL, {Full_Right,Half_Right ,Full_Left, Half_Left } },
>	{		STPR_MOV_HALFL ,LEDS_Flash_LEFT,LEDS_Flash_HALF ,{Half_Left , Full_Left,Half_Right , Full_Right} },
>	{		STPR_MOV_FULLL,LEDS_Flash_LEFT,LEDS_Flash_FULL, {Full_Left ,Half_Left , Full_Right ,Half_Right} },
>	};
>ButtonState = !ButtonData  + 2*(!ButtonData1); //active = 0

The speed of the stepper motor change independently without the state machine, each loop the code checks the speed buttons
The next state is array of four variable because we have four states as we have 2 buttons deciding the next state 
To combine the 2 button to generate numbers from 0 to 3 
>ButtonState = !ButtonData  + 2*(!ButtonData1); //active = 0
