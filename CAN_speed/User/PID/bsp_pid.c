#include "bsp_can.h"

int16_t error_sum;
int16_t last_error;
int16_t error_defference;
int16_t pid_cla(int8_t p, int8_t i, int8_t d, int16_t set, int16_t get)
{
	
    uint16_t error = (set - get);
	
    error_sum += error;
	
		if(error_sum>=2000)error_sum=2000;
		else if(error_sum<=-2000)error_sum=-2000;
		
	error_defference=error-last_error;
	last_error=error;
	
	return p*error+i*error_sum+d*error_defference;
}

