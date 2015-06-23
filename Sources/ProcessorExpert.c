/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-03-15, 17:56, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "GPIO1.h"
#include "I2C2.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU2.h"
#include "FMSTR1.h"
#include "UART0.h"
#include "TU4.h"
#include "AD1.h"
#include "AdcLdd1.h"
#include "TPM0.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "MPU6050.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
float gui_acc_x = 0;
float gui_acc_y = 0;
float gui_acc_z = 0;
float gui_total_acc = 0;
float gui_angle = 0;

float gui_pid_output = 0;

//int16_t Acc_X = 0;
//int16_t Acc_Y = 0;
//int16_t Acc_Z = 0;
float KP = 0;
float KD = 0;
float KI = 0;
float gui_gyro_x = 0;
float gui_gyro_y = 0;
float gui_gyro_z = 0;
float gui_k_angle = 0;
float gui_computed_angle = 0;
uint16_t gui_motor_speed = 0;
int16_t gui_servo_position = 1;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  //static int8_t xyz[3];
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  //AD1_Calibrate(TRUE);
  MPU6050_Setup();
  //Calibrate_Gyros();
  /* Write your code here */
   // Enable H-Bridge Port A
  // UART Communication
 //PWM1_SetRatio16(5000);
 //PWM1_SetRatio16(10000);
 //PWM1_SetRatio16(15000);
  //printf("Starting measurements \n");
  

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.2 [05.06]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
