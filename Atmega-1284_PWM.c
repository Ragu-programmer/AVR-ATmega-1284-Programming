/*
 * Atmega-1284_PWM config.c
 *
 * Created: 25-01-2022 09:54:54 AM
 * Author : ragur
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 20000000
int main(void)
{
	int i,j,z;
	
   
  
	TCCR0A|=(1<<WGM00) | (1<<WGM01);				//set mode of the timer as 'Fast PWM'
	TCCR0B &= ~(1<<WGM02);			

  
	TCCR0A |=(1<<COM0A1);			  //set PWM mode
	TCCR0A &= ~(1<<COM0A0);			//non-invering mode
 	/*TCCR0A |=(1<<COM0B1);
 	TCCR0A &= ~(1<<COM0B0);*/

	TCCR0B |=(1<<CS00);				//setting prescaler clock frequency=20MHz required frequ=250KHz  20MHz/312KHz=64 so clk/64 prescaler
	TCCR0B |=(1<<CS01);
	TCCR0B &= ~(1<<CS02);
  //config O/P pin as output
  
	/*DDRB |=(1<<3)|(1<<4);
	*/
    while (1) 
    {
		for(i=0;i<1024;i++)			//dim to bright
		{
			OCR0A=i;
			_delay_ms(25);
		}
		_delay_ms(3000);
		
	/*	for(i=1024;i>0;i--)      //bright to dim
		{
			OCR0A=i;
			_delay_ms(25);
		}
	_delay_ms(2000);
	*/

	/*for(j=1024;j>70;j--)
	{
		OCR0B=j;
		_delay_ms(25);
	}
	_delay_ms(2000);
	
	for(z=1024;z>0;z--)
	{
		OCR1A=z;
		_delay_ms(100);
	}
	_delay_ms(2000);
*/
    }
}

