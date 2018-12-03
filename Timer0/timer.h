/*
 * timer.h
 *
 * Created: 12/3/2018 5:10:11 PM
 *  Author: Sameh Farouk
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "common.h"
#include "hw_timer.h"
#include "types.h"

typedef enum{
	
	NORMAL , CTC,PWM ,FAST_PWM 
	
	}timer_mod;


typedef enum{
	
	OVERVLOW_INTERRUPT , OUTPUT_CAPTURE_INTERRUPT
	}ENABLE_INTTERPUT;
	
	typedef enum{
		NO_CLK_SOURCE ,
		NO_PRESCALER ,
		PRESCALER_8 ,
		PRESCALER_64 ,
		PRESCALER_256 ,
		PRESCALER_1024 ,
		EXTERNAL_CLK_FALL_EDGE,
		EXTERNAL_CLK_RAISE_EDGE	
		}prescaler;


typedef struct  
{
	timer_mod TIMER_MODE;
	prescaler PRESCALERS ;
}TIMER_CONFG;

typedef struct{
		ENABLE_INTTERPUT INTERRUPT_ENABLE ;
		void (*fun_ptr)(void);
	}TIMER_INTERRUPT_CHECK;
	
	

void init_timer0(uint8 val,TIMER_CONFG *obj) ;
void interrupt_timers(TIMER_INTERRUPT_CHECK *j);



#endif /* TIMER_H_ */