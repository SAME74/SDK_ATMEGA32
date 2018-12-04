/*
 * timer.c
 *
 * Created: 
 *  Author: Sameh Farouk
 */ 

#include "timer.h"
#include <avr/interrupt.h>

void (*interrupt_overflow)(void) ;
void (*inrterrupt_output_capture)(void);

void init_timer0(TIMER_CONFG *obj){
	
	if(obj->TIMER_MODE==NORMAL){
		clr_pin(3,BASE_TIMER_0+time_control_0);
		clr_pin(6,BASE_TIMER_0+time_control_0);
	}
	else if(obj->TIMER_MODE==CTC){
		set_pin(3,BASE_TIMER_0+time_control_0);
		clr_pin(6,BASE_TIMER_0+time_control_0);
		
	}
	
	else if(obj->TIMER_MODE==PWM){
			clr_pin(3,BASE_TIMER_0+time_control_0);
			set_pin(6,BASE_TIMER_0+time_control_0);
	}
	else if(obj->TIMER_MODE==FAST_PWM){
			set_pin(3,BASE_TIMER_0+time_control_0);
			set_pin(6,BASE_TIMER_0+time_control_0);
		}	
	
	
	if (obj->PRESCALERS==NO_CLK_SOURCE)
	{
	clr_pin(0,BASE_TIMER_0+time_control_0);
	clr_pin(1,BASE_TIMER_0+time_control_0);
	clr_pin(2,BASE_TIMER_0+time_control_0);
	}
	
		else if (obj->PRESCALERS==NO_PRESCALER)
		{
			set_pin(0,BASE_TIMER_0+time_control_0);
			clr_pin(1,BASE_TIMER_0+time_control_0);
			clr_pin(2,BASE_TIMER_0+time_control_0);
		}
		else if (obj->PRESCALERS==PRESCALER_8)
			{
				clr_pin(0,BASE_TIMER_0+time_control_0);
				set_pin(1,BASE_TIMER_0+time_control_0);
				clr_pin(2,BASE_TIMER_0+time_control_0);
			}
			
		else if (obj->PRESCALERS==PRESCALER_64)
				{
					set_pin(0,BASE_TIMER_0+time_control_0);
					set_pin(1,BASE_TIMER_0+time_control_0);
					clr_pin(2,BASE_TIMER_0+time_control_0);
				}
				
			else if (obj->PRESCALERS==PRESCALER_256)
			{
				clr_pin(0,BASE_TIMER_0+time_control_0);
				clr_pin(1,BASE_TIMER_0+time_control_0);
				set_pin(2,BASE_TIMER_0+time_control_0);
			}
		
		else if (obj->PRESCALERS==PRESCALER_1024)
		{
			set_pin(0,BASE_TIMER_0+time_control_0);
			clr_pin(1,BASE_TIMER_0+time_control_0);
			set_pin(2,BASE_TIMER_0+time_control_0);
		}
		
		else if (obj->PRESCALERS==EXTERNAL_CLK_FALL_EDGE)
		{
			clr_pin(0,BASE_TIMER_0+time_control_0);
			set_pin(1,BASE_TIMER_0+time_control_0);
			set_pin(2,BASE_TIMER_0+time_control_0);
		}
		
		else if (obj->PRESCALERS==EXTERNAL_CLK_RAISE_EDGE)
		{
			set_pin(0,BASE_TIMER_0+time_control_0);
			set_pin(1,BASE_TIMER_0+time_control_0);
			set_pin(2,BASE_TIMER_0+time_control_0);
		}	

							
}


void write_to_count_reg(uint8 val){
	hw_wr_port(BASE_TIMER_0+time_counter_0,val);
}

void write_to_capture_reg(uint8 val){
	
	hw_wr_port(BASE_TIMER_0+time_output_capture_0,val);
}

void interrupt_timers(TIMER_INTERRUPT_CHECK *j){
	if (j->INTERRUPT_ENABLE==OVERVLOW_INTERRUPT)
	{
	set_pin(0,timer_interrupt_mask);
	interrupt_overflow = j->fun_ptr;
	}
	else if (j->INTERRUPT_ENABLE==OUTPUT_CAPTURE_INTERRUPT)
	{
	set_pin(1,timer_interrupt_mask);
	inrterrupt_output_capture = j->fun_ptr;
}
}



ISR(TIMER0_OVF_vect){
	
	(*interrupt_overflow)();
	
}


ISR(TIMER0_COMP_vect){
	
	(*inrterrupt_output_capture)();
}
	
	