/*
 * control.h
 *
 *  Created on: Sep 15, 2021
 *      Author: x300
 */

#ifndef INC_CONTROL_H_
#define INC_CONTROL_H_
#include "main.h"
typedef struct t_system_timebase{
	_Bool system_1ms_tick;
}t_System_timebase;

typedef struct t_process_params{
	unsigned short isLightControlOn			:1;		//flag that determines wheather light control mode is active
	unsigned short isPwmOutputOn			:1;		//flag for enabling power on mosfet gate pin
	unsigned short isDeviceOn				:1;		//flag for turning on the device in selected mode after button was pressed and device goes from standby mode
	unsigned short dummy1					:1;
	uint16_t light_sens_val;				//raw light intesivity readout from adc		(first EOC)
	uint16_t rotary_sens_val;				//raw potentiometer rotation readout from adc (second EOC)
	uint16_t rotary_sens_offset;			//adc value below which rotary raw readout is forced to 0 (potentiometer when full off still shows some value)
	_Bool adc_eoc_count;					//if 0 save readout to light if 1 save readout to potentiometer, negate at each EOC, start with 0
	uint16_t pwm_timer_fill;				//pwm capture compare value set based on light readouts if flag active
	//pvd detection:
//	uint8_t pvd_val;
	//light hystheresis
	uint16_t light_lower_thrshld;			//hystheresis lower level threshold value
	uint16_t light_upper_thrshld;			//hystheresis upper level threshold value
	uint16_t light_thrshld_deadarea;		//deadarea for hystheresis switching based on light readouts

}t_Process_params;
extern t_System_timebase SYS_TIMEBASE;	//struct for holding timing ticks
extern t_Process_params PROCESS_PARAMS;				//struct for holding process variables


void system_ctrl(void);		//function that refreshes cotnrolled parameters after timer tick occured (currently every 1ms)

#endif /* INC_CONTROL_H_ */
