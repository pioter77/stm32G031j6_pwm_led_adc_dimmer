/*
 * control.c
 *
 *  Created on: Sep 15, 2021
 *      Author: x300
 */

#include "control.h"

t_System_timebase SYS_TIMEBASE={
	.system_1ms_tick=0,
};

t_Process_params PROCESS_PARAMS={
		.adc_eoc_count=0,
		.rotary_sens_val=0,
		.light_sens_val=0,
};


void system_ctrl(void)
{
//	if(tick1ms)
//	{
//		//do control stuff here
//		tick1ms=0;
//	}
	PROCESS_PARAMS.pwm_timer_fill= PROCESS_PARAMS.rotary_sens_val/4095.0*(1280.0-1.0);
}
