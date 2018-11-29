/*
 * gpio.c
 *
 * Created: 
 *  Author: Sameh Farouk
 */ 
#include "gpio.h"

uint8 pin_dir(uint8 pin ,uint8 base ,uint8 state){
	uint8 check =no_error ;
	
	if(pin>max_pins){
		check=error_happend ;
	}
	if(state==OUTPUT){
		set_pin(pin,base+dir_offest);
	}
	else if(state==INPUT){
		clr_pin(pin,base+dir_offest);
	}
	else{
		check=error_happend ;
	}
	
	return check ;
	
}

uint8 port_dir(uint8 base , uint8 state){
	
	uint8 check= no_error ;
	if(state==OUTPUT){
		set_port(base+dir_offest);
	}
	else if(state==INPUT){
		clr_port(base+dir_offest);
	}
	else{
		check=error_happend ;
	}
	return check ;
	
	}

uint8 write_pin(uint8 pin ,uint8 base ,uint8 val){
	
	uint8 check =no_error ;
	if(pin>max_pins){
		check =error_happend ;
	}
	if(val==1){
		set_pin(pin,base+port_offest);
	}
	else if(val==0){
		clr_pin(pin,base+port_offest);
	}
	else{
		check=error_happend ;
	}
	
	return check ;
}

uint8 write_port(uint8 base ,uint8 val){
	
	uint8 check=no_error ;
	hw_wr_port(base+port_offest,val);
	
	return check ;
}

uint8 read_pin(uint8 pin ,uint8 base ,uint8 *val){
	
	uint8 check =no_error ;
	if(pin>max_pins){
		check =error_happend ;
	}
	*val =(*(volatile uint8 *)base+input_offest)&(1<<pin)>>pin;
	
	return check;
}


uint8 read_port(uint8 base , uint8 *val){
	
	uint8 check=no_error ;
	
	*val=(*(volatile uint8 *)base+input_offest);
	return check ;
}