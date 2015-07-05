/*
 * globals.h
 *
 *  Created on: May 26, 2015
 *      Author: sorina2
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_
#include <stdint.h>
#define GYRO_SENSITIVITY 250.0/32768.0   //250/32768

extern float gui_acc_x;
extern float gui_acc_y;
extern float gui_acc_z;
extern float gui_angle;
extern float gui_total_acc;
extern float KP;
extern float KD;
extern float KI;
extern float gui_pid_output;
extern float gui_angle_offset;
extern float gui_computed_angle;
extern float gui_gyro_x;
extern float gui_gyro_y;
extern float gui_gyro_z;
extern float gui_motor_speed;
extern uint16_t gui_servo_position;
extern uint16_t global_threshold;
extern float treshold_angle;
extern float gui_vel;
extern float gui_old_error;
extern float gui_manual_velocity;
extern float gui_filter_angle;
//extern int16_t Acc_X, Acc_Y, Acc_Z;
#endif /* GLOBALS_H_ */
