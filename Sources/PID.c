/*
 * PID.c
 *
 *  Created on: Mar 28, 2015
 *      Author: sorina2
 */
#include "MPU6050.h"
#include "stdio.h"
#include "TPM0.h"

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
	
	if(speed > 0){
		duty_cycle = (uint32_t) speed;
		
		TPM0_C2V = duty_cycle;
		TPM0_C3V = 0;
	} else {
		duty_cycle = (uint32_t) -speed;
		
		TPM0_C2V = 0;
		TPM0_C3V = duty_cycle;
	}
	// to do semnul pentru directie
	//PwmLdd1_SetRatio16(PwmLdd1_DeviceData, (uint16_t)speed);
}

void stabilize()
{
	float pid_output; 
	float pid_to_speed = 100.0f;
	float error_calc;
	
	error_calc  = error_calculation();
	Pid_params param = {1.0f, 0.0f, 0.0f, 0.0f, 0.0f};
	
	pid_output = pid(error_calc, &param);
	
	set_motor_speed(pid_output * pid_to_speed);
	
	//printf("_____________\n");
	printf("%f \n ", error_calc);
	//printf("Motor Speed %f \n ", pid_output * pid_to_speed);
}
