/*
 * Atmega-1284_ADC.c
 *
 * Created: 25-01-2022 03:28:31 PM
 * Author : ragur
 */ 

#include <avr/io.h>
#define ADC_vect
int main(void)
{
    TCCR0A|=(1<<WGM00);
	TCCR0A|=(1<<WGM01);
	TCCR0B &= ~(1<<WGM02);
  //set PWM mode
  //non-invering mode
	TCCR0A |=(1<<COM0A1);
	TCCR0A &= ~(1<<COM0A0);
 	/*TCCR0A |=(1<<COM0B1);
 	TCCR0A &= ~(1<<COM0B0);*/

  //setting prescaler clock frequency=20MHz reqired frequ=250KHz  20MHz/312KHz=64 so clk/64 prescaler
	TCCR0B |=(1<<CS00);
	TCCR0B |=(1<<CS01);
	TCCR0B &= ~(1<<CS02);
	
	DDRB|=(1<<3);
	

		//ENABLE Global interrupt

ADMUX= 0x00;	 //Set no reference to AVCC ,set input channel as ADC0,clear ADLAR=0 bit, so total 7bits in ADMUX register is cleared equals to zero

ADCSRA |=((1<<ADEN)|(1<<ADATE));	 //Enable ADC and auto trigger

ADCSRA &= ((~(1<<ADPS0)) & (~(1<<ADPS1)));   //Setting frequency prescaler=16
ADCSRA |=(1<<ADPS2) | (1<<ADIE);						// '''''''''''


    while (1) 
    {
		
   }
	
}

ISR(ADC_vect)
{
	OCR0A=ADC;
}