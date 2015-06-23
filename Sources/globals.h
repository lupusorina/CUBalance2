/*
 * globals.h
 *
 *  Created on: May 26, 2015
 *      Author: sorina2
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <stdint.h>
#define GYRO_SENSITIVITY 131.0f

extern float gui_acc_x;
extern float gui_acc_y;
extern float gui_acc_z;
extern float gui_angle;
extern float gui_total_acc;
extern float KP;
extern float KD;
extern float KI;
extern float gui_pid_output;
extern float gui_k_angle;
extern float gui_computed_angle;
extern float gui_gyro_x;
extern float gui_gyro_y;
extern float gui_gyro_z;
extern int16_t gui_motor_speed;
extern uint16_t gui_servo_position;
//extern int16_t Acc_X, Acc_Y, Acc_Z;
#endif /* GLOBALS_H_ */
