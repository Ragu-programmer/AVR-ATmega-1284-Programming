/*
 * Atmega-1284(LED Patterns).c
 *
 * Created: 27-01-2022 09:32:21 AM
 * Author : ragur
 */ 


#include <avr/io.h>
#include <util/delay.h>

int buttonPushCounter;
int lastButtonState;
int buttonState;




int main(void)
{
	DDRB=0xFF;
	DDRC&=~(1<<1);
	int i,j;


	while (1)
	{
		buttonState=!(PINC&(1<<1));
		if (buttonState != lastButtonState) {
			if (buttonState==0) {
				buttonPushCounter++;
			}
			lastButtonState = buttonState;
		}
		if(buttonPushCounter==1)									//PATTERN 1
		{
		PORTB|=(1<<0)|(1<<2)|(1<<4)|(1<<6);
		_delay_ms(300);
		PORTB &= ~((~(1<<0)) & (~(1<<2)) & (~(1<<4)) & (~(1<<6)));
		_delay_ms(1000);
		PORTB|=(1<<1)|(1<<3)|(1<<5)|(1<<7);
		_delay_ms(300);
		PORTB &= ~((~(1<<1)) & (~(1<<3)) & (~(1<<5)) & (~(1<<7)));
		_delay_ms(1000);
		}
		if(buttonPushCounter==2)								    //PATTERN 2
		{
		for (i=8;i>=0;i--)
		{
			PORTB|=(1<<i);
			_delay_ms(500);
			PORTB&= ~(1<<i);
		}

		}
		if(buttonPushCounter==3)									//PATTERN 3
		{
			PORTB|=(1<<0)|(1<<7);
			_delay_ms(800);
			PORTB &= (~(1<<0)) & (~(1<<7));
			
			PORTB|=(1<<1)|(1<<6);
			_delay_ms(800);
			PORTB &= (~(1<<1)) & (~(1<<6));
			
			PORTB|=(1<<2)|(1<<5);
			_delay_ms(800);
			PORTB &= (~(1<<2)) & (~(1<<5));
			
			PORTB|=(1<<3)|(1<<4);
			_delay_ms(800);
			PORTB &= (~(1<<3)) & (~(1<<4));
		}
		if(buttonPushCounter==4)									//PATTERN 4
		{
		PORTB|=(1<<0)|(1<<7);
		_delay_ms(800);
		PORTB &= (~(1<<0)) & (~(1<<7));
		
		PORTB|=(1<<1)|(1<<6);
		_delay_ms(800);
		PORTB &= (~(1<<1)) & (~(1<<6));
		
		PORTB|=(1<<2)|(1<<5);
		_delay_ms(800);
		PORTB &= (~(1<<2)) & (~(1<<5));
	
		PORTB|=(1<<3)|(1<<4);
		_delay_ms(800);
		PORTB &= (~(1<<3)) & (~(1<<4));
		
		PORTB|=(1<<2)|(1<<5);
		_delay_ms(800);
		PORTB &= (~(1<<2)) & (~(1<<5));
		
		PORTB|=(1<<1)|(1<<6);
		_delay_ms(800);
		PORTB &= (~(1<<1)) & (~(1<<6));
		
		PORTB|=(1<<0)|(1<<7);
		_delay_ms(800);
		PORTB &= (~(1<<0)) & (~(1<<7));
		}
		if(buttonPushCounter==5)									//PATTERN 5
		{
				for (i=8;i>=0;i--)
				{
					PORTB|=(1<<i);
					_delay_ms(500);
					PORTB&= ~(1<<i);
				}
				for (j=0;j<=8;j++)
				{
					PORTB|=(1<<j);
					_delay_ms(500);
					PORTB&= ~(1<<j);
				}
		}
		if(buttonPushCounter==6)									//PATTERN 6
		{
				for (i=8;i>=0;i--)
				{
					PORTB|=(1<<i);
					_delay_ms(500);
				}
				for (i=8;i>=0;i--)
				{
					PORTB&= ~(1<<i);
					_delay_ms(500);
					
				}
		}
		if(buttonPushCounter==7)									//PATTERN 7
		{
				for (i=8;i>=0;i--)
				{
					PORTB|=(1<<i);
					_delay_ms(500);
				}
				_delay_ms(1000);
				for (i=0;i<=8;i++)
				{
					PORTB&= ~(1<<i);
					_delay_ms(500);
					
				}
		}
		
		
		

	
	}

}