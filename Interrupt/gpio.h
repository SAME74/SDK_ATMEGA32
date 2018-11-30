/*
 * gpio.h
 *
 * Created: //
 *  Author: Sameh Farouk
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include "hw_gpio.h"
#include "types.h"
#include "common.h"

#define input_port 0x00
#define output_port 0xff 

#define no_error 0
#define error_happend 1

#define pin_0 0
#define pin_1 1
#define pin_2 2
#define pin_3 3
#define pin_4 4
#define pin_5 5
#define pin_6 6
#define pin_7 7


#define max_pins 7

     typedef enum{
	
	TINT0=0 , TINT1 ,TINT2
	
    }extrnal_interrupts;

     typedef enum{
	
	LOW_LEVLE=0 ,BOTH_EDGE ,FALL_EDGE ,RASING_EDGE
	
	}interrupts_sense_control;
	
	typedef struct  
	{
		extrnal_interrupts extrnal_interrupt;
		interrupts_sense_control interruptsnsecontrol;
		void(*interruptFuncptr)(void);
		
	}gpio_interrupt;


    uint8 pin_dir(uint8 pin ,uint8 base ,uint8 state);
	uint8 port_dir(uint8 base , uint8 state) ;
	uint8 write_port(uint8 base ,uint8 val) ;
	uint8 write_pin(uint8 pin ,uint8 base ,uint8 val) ;
	uint8 read_port(uint8 base , uint8 *val) ;
	uint8 read_pin(uint8 pin ,uint8 base ,uint8 *val) ;
	
	
	void init_glopal_interrupt(gpio_interrupt *obj) ;
	
	
	
	


#endif /* GPIO_H_ */