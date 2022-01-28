/*
 * ATMega 1284-led blink.c
 *
 * Created: 22-01-2022 12:23:47 PM
 * Author : ragur
 */ 
#define F_CPU 20000000
#include <util/delay.h>
#include <avr/io.h>

int main() {

	DDRB |= (1<<2);

	while(1) {
	
		PORTB |= (1<<2);

		_delay_ms(500);
		
		PORTB &= ~(1<<2);

		_delay_ms(500);

	}
}
