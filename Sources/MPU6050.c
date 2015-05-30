/*
 * MPU6050.c
 *
 *  Created on: Mar 23, 2015
 *      Author: sorina2
 */

#include "MPU6050.h"
#include "I2C2.h"
#include "math.h" 
#include "globals.h"
#include<stdio.h>
#include<stdlib.h>


static MPU6050_TDataState deviceData;

uint8_t MPU6050_ReadReg(uint8_t addr, uint8_t *data, short dataSize) {
  uint8_t res;
 
  /* Send I2C address plus register address to the I2C bus *without* a stop condition */
  res = I2C2_MasterSendBlock(deviceData.handle, &addr, 1U, LDD_I2C_NO_SEND_STOP);
  if (res!=ERR_OK) {
    return ERR_FAILED;
  }
  while (!deviceData.dataTransmittedFlg) {} /* Wait until data is sent */
  deviceData.dataTransmittedFlg = FALSE;
 
  /* Receive InpData (1 byte) from the I2C bus and generates a stop condition to end transmission */
  res = I2C2_MasterReceiveBlock(deviceData.handle, data, dataSize, LDD_I2C_SEND_STOP);
  if (res!=ERR_OK) {
    return ERR_FAILED;
  }
  while (!deviceData.dataReceivedFlg) {} /* Wait until data is received received */
  deviceData.dataReceivedFlg = FALSE;
  return ERR_OK;
}
 


int16_t MPU6050_WriteReg(int16_t addr, int16_t val) {
  int16_t buf[2], res;
 
  buf[0] = addr;
  buf[1] = val;
  res = I2C2_MasterSendBlock(deviceData.handle, &buf, 2U, LDD_I2C_SEND_STOP); /* Send OutData (3 bytes with address) on the I2C bus and generates not a stop condition to end transmission */
  if (res!=ERR_OK) {
    return ERR_FAILED;
  }
  while (!deviceData.dataTransmittedFlg) {}  /* Wait until date is sent */
  deviceData.dataTransmittedFlg = FALSE;
  return ERR_OK;
}


void MPU6050_Setup(){
	// setup i2c driver
	deviceData.handle = I2C2_Init(&deviceData);
	MPU6050_WriteReg(MPU6050_RA_PWR_MGMT_1,0x00);
	
	//MPU6050_WriteReg(MPU6050_RA_ACCEL_CONFIG, 0xE0);
	//MPU6050_WriteReg(MPU6050_RA_SMPLRT_DIV, 0x07);
	//MPU6050_WriteReg(MPU6050_RA_ACCEL_CONFIG,0x01);
	
	
}

int16_t MPU6050_Get_Acc(uint8_t ACC_REG_H, uint8_t ACC_REG_L){
	uint8_t acc_low, acc_high;
	uint16_t i;
	
	for (i=1 ; i<1000 ; i++){};
	
	MPU6050_ReadReg(ACC_REG_H, &acc_high, 1);
	MPU6050_ReadReg(ACC_REG_L, &acc_low,  1);
	
	int16_t ret = acc_high;
	ret <<= 8; ret |= acc_low;
	return ret;
}



float MPU6050_Read_Angle(){
	int16_t Acc_X, Acc_Y, Acc_Z;
	
	float ACCEL_XANGLE;
	float ACCEL_YANGLE;
	float total_acc;
	float Acc_X_g, Acc_Y_g, Acc_Z_g;
	unsigned char Data;
	MPU6050_ReadReg( MPU6050_RA_WHO_AM_I, &Data, 1);
	
	Acc_X = MPU6050_Get_Acc(MPU6050_RA_ACCEL_XOUT_H, MPU6050_RA_ACCEL_XOUT_L);

	Acc_Y = MPU6050_Get_Acc(MPU6050_RA_ACCEL_YOUT_H, MPU6050_RA_ACCEL_YOUT_L);
	
	Acc_Z = MPU6050_Get_Acc(MPU6050_RA_ACCEL_ZOUT_H, MPU6050_RA_ACCEL_ZOUT_L);
	
	
	ACCEL_XANGLE = 57.295*atan((float)Acc_Y/ sqrt(pow((float)Acc_Z,2)+pow((float)Acc_X,2)));
	ACCEL_YANGLE = 57.295*atan((float)-Acc_X/ sqrt(pow((float)Acc_Z,2)+pow((float)Acc_Y,2)));	

	
	gui_acc_x = Acc_X/16384.0f;
	gui_acc_y = Acc_Y/16384.0f;
	gui_acc_z = Acc_Z/16384.0f;
	total_acc = sqrt(pow(gui_acc_x,2) + pow(gui_acc_y,2) + pow(gui_acc_z,2));
	//printf("\n Total acc %f", total_acc);
	gui_total_acc = total_acc;
	gui_angle = ACCEL_XANGLE;
	return ACCEL_XANGLE;
}



void Setup1()
{
    //Sets sample rate to 8000/1+7 = 1000Hz
	MPU6050_WriteReg(  MPU6050_RA_SMPLRT_DIV, 0x07);
    //Disable FSync, 256Hz DLPF
    MPU6050_WriteReg(  MPU6050_RA_CONFIG, 0x00);
    //Disable gyro self tests, scale of 500 degrees/s
    MPU6050_WriteReg(  MPU6050_RA_GYRO_CONFIG, 0b00001000);
    //Disable accel self tests, scale of +-2g, no DHPF
    MPU6050_WriteReg(  MPU6050_RA_ACCEL_CONFIG, 0x00);
    //Freefall threshold of |0mg|
    MPU6050_WriteReg(  MPU6050_RA_FF_THR, 0x00);
    //Freefall duration limit of 0
    MPU6050_WriteReg(  MPU6050_RA_FF_DUR, 0x00);
    //Motion threshold of 0mg
    MPU6050_WriteReg(  MPU6050_RA_MOT_THR, 0x00);
    //Motion duration of 0s
    MPU6050_WriteReg(  MPU6050_RA_MOT_DUR, 0x00);
    //Zero motion threshold
    MPU6050_WriteReg(  MPU6050_RA_ZRMOT_THR, 0x00);
    //Zero motion duration threshold
    MPU6050_WriteReg(  MPU6050_RA_ZRMOT_DUR, 0x00);
    //Disable sensor output to FIFO buffer
    MPU6050_WriteReg(  MPU6050_RA_FIFO_EN, 0x00);
 
    //AUX I2C setup
    //Sets AUX I2C to single master control, plus other config
    MPU6050_WriteReg(  MPU6050_RA_I2C_MST_CTRL, 0x00);
    //Setup AUX I2C slaves
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV0_ADDR, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV0_REG, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV0_CTRL, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV1_ADDR, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV1_REG, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV1_CTRL, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV2_ADDR, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV2_REG, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV2_CTRL, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV3_ADDR, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV3_REG, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV3_CTRL, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV4_ADDR, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV4_REG, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV4_DO, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV4_CTRL, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV4_DI, 0x00);
 
    //MPU6050_RA_I2C_MST_STATUS //Read-only
    //Setup INT pin and AUX I2C pass through
    MPU6050_WriteReg(  MPU6050_RA_INT_PIN_CFG, 0x00);
    //Enable data ready interrupt
    MPU6050_WriteReg(  MPU6050_RA_INT_ENABLE, 0x00);
 
    //MPU6050_RA_DMP_INT_STATUS        //Read-only
    //MPU6050_RA_INT_STATUS 3A        //Read-only
    //MPU6050_RA_ACCEL_XOUT_H         //Read-only
    //MPU6050_RA_ACCEL_XOUT_L         //Read-only
    //MPU6050_RA_ACCEL_YOUT_H         //Read-only
    //MPU6050_RA_ACCEL_YOUT_L         //Read-only
    //MPU6050_RA_ACCEL_ZOUT_H         //Read-only
    //MPU6050_RA_ACCEL_ZOUT_L         //Read-only
    //MPU6050_RA_TEMP_OUT_H         //Read-only
    //MPU6050_RA_TEMP_OUT_L         //Read-only
    //MPU6050_RA_GYRO_XOUT_H         //Read-only
    //MPU6050_RA_GYRO_XOUT_L         //Read-only
    //MPU6050_RA_GYRO_YOUT_H         //Read-only
    //MPU6050_RA_GYRO_YOUT_L         //Read-only
    //MPU6050_RA_GYRO_ZOUT_H         //Read-only
    //MPU6050_RA_GYRO_ZOUT_L         //Read-only
    //MPU6050_RA_EXT_SENS_DATA_00     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_01     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_02     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_03     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_04     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_05     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_06     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_07     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_08     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_09     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_10     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_11     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_12     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_13     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_14     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_15     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_16     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_17     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_18     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_19     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_20     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_21     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_22     //Read-only
    //MPU6050_RA_EXT_SENS_DATA_23     //Read-only
    //MPU6050_RA_MOT_DETECT_STATUS     //Read-only
 
    //Slave out, dont care
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV0_DO, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV1_DO, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV2_DO, 0x00);
    MPU6050_WriteReg(  MPU6050_RA_I2C_SLV3_DO, 0x00);
    //More slave config
    MPU6050_WriteReg(  MPU6050_RA_I2C_MST_DELAY_CTRL, 0x00);
    //Reset sensor signal paths
    MPU6050_WriteReg(  MPU6050_RA_SIGNAL_PATH_RESET, 0x00);
    //Motion detection control
    MPU6050_WriteReg(  MPU6050_RA_MOT_DETECT_CTRL, 0x00);
    //Disables FIFO, AUX I2C, FIFO and I2C reset bits to 0
    MPU6050_WriteReg(  MPU6050_RA_USER_CTRL, 0x00);
    //Sets clock source to gyro reference w/ PLL
    MPU6050_WriteReg(  MPU6050_RA_PWR_MGMT_1, 0b00000010);
    //Controls frequency of wakeups in accel low power mode plus the sensor standby modes
    MPU6050_WriteReg(  MPU6050_RA_PWR_MGMT_2, 0x00);
    //MPU6050_RA_BANK_SEL            //Not in datasheet
    //MPU6050_RA_MEM_START_ADDR        //Not in datasheet
    //MPU6050_RA_MEM_R_W            //Not in datasheet
    //MPU6050_RA_DMP_CFG_1            //Not in datasheet
    //MPU6050_RA_DMP_CFG_2            //Not in datasheet
    //MPU6050_RA_FIFO_COUNTH        //Read-only
    //MPU6050_RA_FIFO_COUNTL        //Read-only
    //Data transfer to and from the FIFO buffer
    MPU6050_WriteReg(  MPU6050_RA_FIFO_R_W, 0x00);
    //MPU6050_RA_WHO_AM_I             //Read-only, I2C address
 
    //printf("\nMPU6050 Setup Complete");
}
