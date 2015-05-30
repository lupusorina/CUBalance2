/*
 * PID.c
 *
 *  Created on: Mar 28, 2015
 *      Author: sorina2
 */
#include "MPU6050.h"
#include "stdio.h"
#include "TPM0.h"
#include "GPIO1.h"
#include "globals.h"
typedef struct{
	float kp;
	float kd;
	float ki;
	float integral_acc;
	float err_old;
}Pid_params;

float error_calculation()
{
	float  ref_angle = 0.0f;
	
	return ref_angle - MPU6050_Read_Angle();
}

float pid(float err, Pid_params *param)
{
	float err_dif;
	float output;
	
	param->integral_acc = param->integral_acc + err;
	err_dif = param->err_old - err;
	
	output = param->kp * err + param->ki * param->integral_acc + param->kd * err_dif;
	
	param->err_old = err;
	
	return output;
}

void set_motor_speed(float speed)
{
	uint32_t duty_cycle;
	
	//TPM0_C5V = (uint32_t) speed;
	
	if(speed > 0){
		duty_cycle = (uint32_t) speed;
//		
		TPM0_C5V = duty_cycle;
		GPIO1_SetFieldValue(GPIO1_DeviceData, Motor_Direction, 0);
	//	GPIO1_SetFieldBits(GPIO1_DeviceData, Motor_Direction, 0);
	} else {
		duty_cycle = (uint32_t) (-speed);
		GPIO1_SetFieldValue(GPIO1_DeviceData, Motor_Direction, 1);
		
		TPM0_C5V = duty_cycle;
}
	// to do semnul pentru directie
	//PwmLdd1_SetRatio16(PwmLdd1_DeviceData, (uint16_t)speed);
}

void stabilize()
{
	float pid_output; 
	//float pid_to_speed = 10.0f;
	float error_calc;
	
	error_calc  = error_calculation();
	Pid_params param = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
	
	param.kd = KD;
	param.ki = KI;
	param.kp = KP;
	
	
	pid_output = pid(error_calc, &param);
	
	gui_pid_output = pid_output;
	set_motor_speed(pid_output);
	
	//printf("_____________\n");
	//Print Angle
	//printf("A %f \n ", error_calc);
	//printf("Motor Speed %f \n ", pid_output * pid_to_speed);
}
