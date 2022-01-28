/*
 * Atmega-1284 _External interrupt.c
 *
 * Created: 26-01-2022 02:40:47 PM
 * Author : ragur
 */ 

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	EIMSK|=(1<<INT1);			//enabling external INT1 interrupt
	EICRA&= (~(~(1<<ISC10)) & (~(1<<ISC11)));    //setting interrupt request when a logical change
	DDRB|=(1<<2);			//blinking led
	DDRC |=(1<<3);          // interrupt led
	SREG|= (1<<7);					//enabling global interrupt instead of sei();
	
 
    while (1) 
    {
		PORTB|=(1<<2);
		_delay_ms(2000);
		PORTB &= ~(1<<2);
		_delay_ms(2000);
    }
}

ISR(INT1_vect){
	PORTC|=(1<<3);		//interrupt service routine function for external interrupt INT1
}

