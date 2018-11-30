/*
 * common.h
 *
 * Created: 
 *  Author: Sameh Farouk
 */ 


#ifndef COMMON_H_
#define COMMON_H_


#define set_port(reg) ((*(volatile uint8 *)(reg)) = 0xff)
#define set_pin(pin,reg) ((*(volatile uint8 *)(reg))|=(1<<pin))

#define clr_port(reg) ((*(volatile uint8 *)(reg))=0x00)
#define clr_pin(pin,reg) ((*(volatile uint8 *)(reg))&=~(1<<pin))

#define hw_wr_port(reg,val) ((*(volatile uint8 *)(reg))=val)

#endif /* COMMON_H_ */