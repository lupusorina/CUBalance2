/*
 * MPU6050.c
 *
 *  Created on: Mar 23, 2015
 *      Author: sorina2
 */

#include "MPU6050.h"
 
void MPU6050_Test_I2C()
{
    unsigned char Data = 0x00;
    LDByteReadI2C(MPU6050_ADDRESS, MPU6050_RA_WHO_AM_I, &Data, 1);
 
    if(Data == 0x68)
    {
        printf("\nI2C Read Test Passed, MPU6050 Address: 0x%x", Data);
    }
    else
    {
        printf("ERROR: I2C Read Test Failed, Stopping");
        while(1){}    
    }    
}
