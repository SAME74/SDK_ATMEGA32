/*
 * Timer.c.c
 *
 * Created: 12/3/2018 3:03:27 PM
 * Author : Sameh Farouk
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "timer.h"


void fun(void){
	
	PORTA=0x01 ;
	_delay_ms(100);
	PORTA=0x00;
}


int main(void)
{
	DDRA=0xff;
	TIMER_CONFG f ;
	f.TIMER_MODE=NORMAL ;
	f.PRESCALERS=PRESCALER_1024 ;
	TIMER_INTERRUPT_CHECK d ;
	init_timer0(0x20,&f);
	d.fun_ptr=&fun ;
	d.INTERRUPT_ENABLE=OVERVLOW_INTERRUPT ;
	interrupt_timers(&d);
    sei();
    while (1) 
    {
		


    }
}

