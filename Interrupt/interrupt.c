/*
 * gpio.c
 *
 * Created: 
 *  Author: Sameh Farouk
 */ 
#include "gpio.h"
#include <avr/interrupt.h>


//----------------------------------
static void (*int0_interrupt)(void);  /* catch fun address and pass it to ISR fun */
static void (*int1_interrupt)(void);
static void (*int2_interrupt)(void);
//---------------------------------



void init_INT0_interrupt(gpio_interrupt * obj){
	
	int0_interrupt =obj->interruptFuncptr ;
	set_pin(6,GENERAL_INTERRUPT_CONTROL_REG);
	
	if (obj->interruptsnsecontrol==LOW_LEVLE)
	{
		clr_pin(0,MICRO_CONTROLLER_CONTROL_REG);
		clr_pin(1,MICRO_CONTROLLER_CONTROL_REG);

	}
	
	else if (obj->interruptsnsecontrol==BOTH_EDGE)
	{
		set_pin(0,MICRO_CONTROLLER_CONTROL_REG);
		clr_pin(1,MICRO_CONTROLLER_CONTROL_REG);

	}
	
	else if (obj->interruptsnsecontrol==FALL_EDGE)
	{
		clr_pin(0,MICRO_CONTROLLER_CONTROL_REG);
		set_pin(1,MICRO_CONTROLLER_CONTROL_REG);

	}
	else if (obj->interruptsnsecontrol==RASING_EDGE)
	{
		set_pin(0,MICRO_CONTROLLER_CONTROL_REG);
		set_pin(1,MICRO_CONTROLLER_CONTROL_REG);

	}
}
	
	//------------------------------------------------
	void init_INT1_interrupt(gpio_interrupt * obj){
		
		int1_interrupt =obj->interruptFuncptr ;
		set_pin(7,GENERAL_INTERRUPT_CONTROL_REG);
		
		if (obj->interruptsnsecontrol==LOW_LEVLE)
		{
			clr_pin(2,MICRO_CONTROLLER_CONTROL_REG);
			clr_pin(3,MICRO_CONTROLLER_CONTROL_REG);

		}
		
		else if (obj->interruptsnsecontrol==BOTH_EDGE)
		{
			set_pin(2,MICRO_CONTROLLER_CONTROL_REG);
			clr_pin(3,MICRO_CONTROLLER_CONTROL_REG);

		}
		
		else if (obj->interruptsnsecontrol==FALL_EDGE)
		{
			clr_pin(2,MICRO_CONTROLLER_CONTROL_REG);
			set_pin(3,MICRO_CONTROLLER_CONTROL_REG);

		}
		else if (obj->interruptsnsecontrol==RASING_EDGE)
		{
			set_pin(2,MICRO_CONTROLLER_CONTROL_REG);
			set_pin(3,MICRO_CONTROLLER_CONTROL_REG);

		}
	}
		
		//----------------------------------------------------
		void init_INT2_interrupt(gpio_interrupt * obj){
			
			int2_interrupt =obj->interruptFuncptr ;
			set_pin(5,GENERAL_INTERRUPT_CONTROL_REG);
			
			
			if (obj->interruptsnsecontrol==FALL_EDGE)
			{
				clr_pin(6,MICRO_CONTROLLER_CONTROL_AND_STATUS_REG);
				
			}
			else if (obj->interruptsnsecontrol==RASING_EDGE)
			{
				set_pin(6,MICRO_CONTROLLER_CONTROL_AND_STATUS_REG);

			}
			
		}
			//---------------------------------------------------------
				void init_glopal_interrupt(gpio_interrupt *obj){
					
					
					if (obj->extrnal_interrupt==TINT0)
					{
						init_INT0_interrupt(obj);
					}
					else if (obj->extrnal_interrupt==TINT1)
					{
						init_INT1_interrupt(obj);
					}
					else if (obj->extrnal_interrupt==TINT2)
					{
						init_INT2_interrupt(obj);
					}
				
					
				}
					
				
				ISR(INT0_vect){
					
					(*int0_interrupt)();
					
				}
					
				ISR(INT1_vect){
					
	        	(*int1_interrupt)();

				}
				
				ISR(INT2_vect){
					
			   (*int2_interrupt)();
	
					
				}
					
					
					
				

	
	
	
	
	
	
