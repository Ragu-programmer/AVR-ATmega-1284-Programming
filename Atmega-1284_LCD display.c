/*
 * Atmega-1284_LCD-interfacing.c
 *
 * Created: 24-01-2022 12:09:02 PM
 * Author : ragur
 */ 

#include <avr/io.h>
#include<util/delay.h>

void lcd_data(unsigned char data)
{
	PORTC=data;
	PORTD|=(1<<2); //RS=1
	PORTD &= ~(1<<3); //RW=0
	PORTD|=(1<<4);  //Enable=1
	_delay_ms(10);  //delay 10mS
	PORTD &= ~(1<<4);  //Enable=0
}

void lcd_cmd(unsigned char command)
{
	PORTC=command;
	PORTD &= ~(1<<2); //RS=0
	PORTD &= ~(1<<3); //RW=0
	PORTD|=(1<<4);  //Enable=1
	_delay_ms(10);
	PORTD &= ~(1<<4);
}

void lcd_string(const unsigned char *str,unsigned char length)
{
	char i=0;
	for (i=0;i<length;i++)
	{
		lcd_data(str[i]);
	}
}
	
void lcd_initialize()
{	
	lcd_cmd(0x38);
	lcd_cmd(0x06);
	lcd_cmd(0x0C);	
	lcd_cmd(0x01);
}

	int main(void)
{ 
	DDRC=0xFF;
	DDRD|= (1<<2)|(1<<3)|(1<<4);
	lcd_initialize();

    while (1) 
    {
		lcd_cmd(0x80);				//0x80, 0xC0, 0x94, 0xD4 for 1st,2nd,3rd,4th line of lcd
		lcd_string("RAGURAM K",9);
		_delay_ms(500);
		lcd_cmd(0xC0);				
		lcd_string("20BMC034",8);
    }
}

