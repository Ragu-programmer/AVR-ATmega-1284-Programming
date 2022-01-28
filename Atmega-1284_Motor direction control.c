/*
 * Atmega-1284 motor clock_anti clock rotation.c
 *
 * Created: 23-01-2022 11:01:06 AM
 * Author : ragur
 */ 

#define F_CPU 16000000UL       //define cpu frequency
#include<avr/io.h>
#include<util/delay.h>

int i;        //define variable for comparison
int main(void)
{
	//DDR Data Direction Register
	DDRA |=(1<<0) ;
	DDRA |=(1<<1) ;                       // make PORTA0,1 pin as Output and Rest as input
	PORTA &= ~(1<<1);                // make PORTA1 pin low initially to avoid movement before push button selection
	PORTA &= ~(1<<0); // make PORTA0 pin low initially to avoid movement before push button selection
	
	while(1)
	{
		if(! bit_is_clear(PINA,4)) // check if PORTA4 push button is pressed
		{
			i = 1;               //store status as 1
			PORTA &= ~(1<<1);
			_delay_ms(1000);
		}
		else if (!bit_is_clear(PINA,5))   // check if PORTA5 push button is pressed
		{
			i = 2;                  //store status as 2
			PORTA &= ~(1<<0);
			_delay_ms(1000);
		}
		
		if (i == 1)              // if 1st button is pressed
		{
			PORTA |= (1<<0); //rotate in clockwise direction
			PORTA &= ~(1<<1);
		}
		else if (i == 2)         //if 2nd push button is prssed
		{
			PORTA |= (1<<1); //rotate anticlock wise
			PORTA &= ~(1<<0);
		}
		
	}
}


pull-up, pull-down
debouncing