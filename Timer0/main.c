/*
 * Timer.c.c
 *
 * Created: 12/3/2018 3:03:27 PM
 * Author : Sameh Farouk
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "timer.h"

void fun(void);
int main(void)
{
	DDRB=0xff; //Flashing LED
TIMER_INTERRUPT_CHECK f;

	//Setup Timer: use overflow interrupt.
interrupt_timers(&f);

	 write_to_count_reg(200);//15624
sei();
TIMER_CONFG s;
s.TIMER_MODE=NORMAL ;
s.PRESCALERS=NO_PRESCALER;
init_timer0(&s);
f.INTERRUPT_ENABLE=OVERVLOW_INTERRUPT;
f.fun_ptr=&fun;
	 // Enable global interrupts??
	
	//TCCR1B |= ((1 << CS10) | (1 << CS11)); // Set up timer at Fcpu/64 ??

	PORTB=0x00;
	
	while (1)
	{
	}//end while
}//end main

void fun(void)
{	//Timer is on:
		PORTB=0x01;
		_delay_ms(100);
		PORTB=0x00;
		_delay_ms(100); //turn on LED
	write_to_count_reg(200) ;
}
