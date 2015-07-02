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

float filter_angle()
{
	float angle = MPU6050_Read_Angle();
	
	return (0.9*(angle + Get_Gyro_Rates()*(1/100)) - 0.1*gui_total_acc);
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
int32_t filter_pos_motor = 0;
float	motor_hist[4] = {0, 0, 0, 0};

float Average_Motor_Speed()
{
	float sum = 0;
	uint8_t j;
	uint16_t motor_speed = 0;
	float computed_speed = 0;
	
	AD1_Measure(TRUE);
	AD1_GetValue16(&motor_speed);
	computed_speed = 0.18*(motor_speed - 32657) - 36;
		
	motor_hist[filter_pos_motor] = computed_speed;
	filter_pos_motor++;
	
	if (filter_pos_motor == 4) 
		filter_pos_motor = 0;
	
	for (j = 0; j < 4; j++)
		sum = sum + motor_hist[j];
	return sum / 4;
}

int32_t filter_pos_gyro = 0;
float	gyro_hist[4] = {0, 0, 0, 0};

float Average_Gyro()
{
	float sum = 0;
	uint8_t j;
	
	gyro_hist[filter_pos_gyro] = Get_Gyro_Rates();
	filter_pos_gyro++;
	
	if (filter_pos_gyro == 4) 
		filter_pos_gyro = 0;
	
	for (j = 0; j < 4; j++)
		sum = sum + gyro_hist[j];
	return sum / 4;
}



void stabilize()														// main
{
	
	//uint16_t motor_speed = 0;
	float vel = 0.0f;
	
	
	// set LQR coefficients
	param.kd = KD;														// parameters controlled by GUI 
	param.ki = KI;
	param.kp = KP;	
	

	gui_motor_speed = Average_Motor_Speed();
	gui_gyro_z = Average_Gyro();
	
	gui_filter_angle = 0.98*(gui_filter_angle + gui_gyro_z/100) + 0.02 * MPU6050_Read_Angle();
	
	vel = param.kp * gui_filter_angle + param.kd * gui_gyro_z + param.ki * gui_motor_speed; 
	gui_vel = vel;
	set_motor_speed(vel);
	
	//if ((gui_computed_angle < treshold_angle) && (gui_computed_angle >(-treshold_angle)))
	//	set_motor_speed(600);	
	//vel += pid_output * (global_threshold + 1) / 100;
	//if (vel > 3000) vel = 3000;
	//set_motor_speed(vel);


}
