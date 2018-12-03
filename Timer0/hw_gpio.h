/*
 * hw_gpio.h
 *
 * Created: 
 *  Author: Sameh Farouk
 */ 


#ifndef HW_GPIO_H_
#define HW_GPIO_H_




#define BASE_A 0X39
#define BASE_B 0X36
#define BASE_C 0X33
#define BASE_D 0x30


#define input_offest 0x00
#define dir_offest 0x01 
#define port_offest 0x02

//-----------------------
//interrupts
//-------------------

#define SET_REGISTER                             0x5F
#define GENERAL_INTERRUPT_CONTROL_REG            0x5B
#define GENERAL_INTERRUPT_FLAG_REG               0x5A
#define MICRO_CONTROLLER_CONTROL_REG             0x55
#define MICRO_CONTROLLER_CONTROL_AND_STATUS_REG  0x54

#endif /* HW_GPIO_H_ */