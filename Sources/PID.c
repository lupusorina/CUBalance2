/*
 * PID.c
 *
 *  Created on: Mar 28, 2015
 *      Author: sorina2
 */
#include <math.h>

#include "MPU6050.h"
#include "stdio.h"
#include "TPM0.h"
#include "GPIO1.h"
#include "GPIO2.h"
#include "globals.h"
typedef struct{
	float kp;  																//proportional  coefficient
	float kd;																//differential coefficient	
	float ki;																//integral coefficient		
	float integral_acc;														//acumulator to calculating the integral
	float err_old;															//reminder for calculating the differential										
}Pid_params;		

float error_calculation()
{
	float k_angle = 0;														// a proportional coeficient to combine acc and gyro data    
	float  ref_angle = 0.0f;
	k_angle = gui_k_angle; 													// assigned value for GUI  				
	gui_computed_angle  = Average_Angle() - k_angle * Get_Gyro_Rates(); 	

	return ref_angle - gui_computed_angle - 1.027 ;

		
}

float pid(float err, Pid_params *param)										// PID algorithm
{
	float err_dif;
	float output;
	
	param->integral_acc = param->integral_acc + err;
	err_dif = err - param->err_old;
	
	output = param->kp * err + param->ki * param->integral_acc + param->kd * err_dif;
	
	gui_old_error = param->err_old;
	param->err_old = err;
	
	return output;
}

void set_motor_speed(float speed)											//Algorithm to control the motor speed and direction
{
	uint32_t duty_cycle;
	
	//TPM0_C5V = (uint32_t) speed;
	
	if(speed >= 0){															
			duty_cycle = (uint32_t) speed;
			TPM0_C5V = duty_cycle;
			GPIO1_SetFieldValue(GPIO1_DeviceData, Motor_Direction, 0);
			//	GPIO1_SetFieldBits(GPIO1_DeviceData, Motor_Direction, 0);
		} else {
			duty_cycle = (uint32_t) (-speed);
			GPIO1_SetFieldValue(GPIO1_DeviceData, Motor_Direction, 1);
			TPM0_C5V = duty_cycle;
		}
}

Pid_params param = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

void stabilize()														// main
{
//	float pid_output; 
//	float error_calc = error_calculation();
//	
////	float tacc = fabs(gui_total_acc);
////	if (tacc < 0.8 || tacc > 1.2)
////		return;
//	
	uint16_t motor_speed = 0;
//	static float vel = 0.0f;
//	
	AD1_Measure(TRUE);
	AD1_GetValue16(&motor_speed);
	gui_motor_speed = 0.18*(motor_speed - 32657) - 36;
//	
////	if (fabs(vel) > 3000) {
////		vel = 0;
////		set_motor_speed(vel);
////		return;
////	}
//		
//	param.kd = KD;														// parameters controlled by GUI 
//	param.ki = KI;
//	param.kp = KP;	
//	
//	pid_output = pid(error_calc, &param);	
//	gui_pid_output = pid_output;
//	
//	gui_vel = vel;
//	//if ((gui_computed_angle < treshold_angle) && (gui_computed_angle >(-treshold_angle))){ 
//	//		GPIO2_SetFieldValue(GPIO2_DeviceData,Motor_Enable,0);
//	//} else {
//	//		GPIO2_SetFieldValue(GPIO2_DeviceData,Motor_Enable,1);
//	vel += pid_output * (global_threshold + 1) / 100;
	set_motor_speed(gui_manual_velocity);
	//}

}
