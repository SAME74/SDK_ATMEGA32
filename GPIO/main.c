/*
 * GPIO.c.c
 *
 * Created: 
 * Author : Sameh Farouk
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "gpio.h"

#define MIN 0
int main(void)
{
    port_dir(BASE_A,1);
    while (1) 
    {
		write_pin(1,BASE_A,1);
		_delay_ms(100);
		write_pin(1,BASE_A,0) ;
		_delay_ms(100) ;
    }
}

