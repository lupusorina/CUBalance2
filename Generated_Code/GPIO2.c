/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : GPIO2.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : GPIO_LDD
**     Version     : Component 01.128, Driver 01.06, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-06-24, 19:46, # CodeGen: 111
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : GPIO2
**          Port                                           : PTB
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 100
**          Interrupt service/event                        : Disabled
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : Motor_Enable
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTB8/EXTRG_IN
**                  Pin signal                             : 
**                  Initial pin direction                  : Output
**                    Initial output state                 : 0
**                  Initial pin event                      : Disabled
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Disabled
**     Contents    :
**         Init            - LDD_TDeviceData* GPIO2_Init(LDD_TUserData *UserDataPtr);
**         SetFieldValue   - void GPIO2_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         GetFieldValue   - GPIO2_TFieldValue GPIO2_GetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         ClearFieldBits  - void GPIO2_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldBits    - void GPIO2_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         ToggleFieldBits - void GPIO2_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file GPIO2.c
** @version 01.06
** @brief
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
*/         
/*!
**  @addtogroup GPIO2_module GPIO2 module documentation
**  @{
*/         

/* MODULE GPIO2. */

#include "GPIO2.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
  LDD_TUserData *UserData;             /* RTOS device data structure */
} GPIO2_TDeviceData, *GPIO2_TDeviceDataPtr; /* Device data structure type */
/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static GPIO2_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/*
** ===================================================================
**     Method      :  GPIO2_Init (component GPIO_LDD)
*/
/*!
**     @brief
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     @param
**         UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* GPIO2_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  GPIO2_TDeviceData *DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Save RTOS Device structure */
  DeviceDataPrv->UserData = UserDataPtr; /* Store the RTOS device structure */
  /* GPIOB_PDOR: PDO&=~0x0100 */
  GPIOB_PDOR &= (uint32_t)~(uint32_t)(GPIO_PDOR_PDO(0x0100));                                   
  /* GPIOB_PDDR: PDD|=0x0100 */
  GPIOB_PDDR |= GPIO_PDDR_PDD(0x0100);                                   
  /* Initialization of Port Control registers */
  /* PORTB_PCR8: ISF=0,MUX=1 */
  PORTB_PCR8 = (uint32_t)((PORTB_PCR8 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));                                  
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_GPIO2_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  GPIO2_SetFieldValue (component GPIO_LDD)
*/
/*!
**     @brief
**         This method sets the output data value of the specified bit
**         field.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     @param
**         Value           - Aligned data value to writting to the
**                           specified bit field. The bit 0 corresponds
**                           with the pin which has index 0 within the
**                           given bit field, the bit 1 corresponds with
**                           the pin which has index 1 within the given
**                           bit field, etc.
*/
/* ===================================================================*/
void GPIO2_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO2_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case Motor_Enable: {               /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(GPIO2_MODULE_BASE_ADDRESS,
        (
          GPIO_PDD_GetPortDataOutput(GPIO2_MODULE_BASE_ADDRESS)
          & ((GPIO2_TPortValue)(~((GPIO2_TPortValue)GPIO2_Motor_Enable_MASK)))
        )
        | (
          ((GPIO2_TPortValue)(Value << GPIO2_Motor_Enable_START_BIT))
          & ((GPIO2_TPortValue)GPIO2_Motor_Enable_MASK)
        )
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO2_GetFieldValue (component GPIO_LDD)
*/
/*!
**     @brief
**         This method returns the current input data of the specified
**         field.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to reading. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     @return
**                         - Aligned current port input value masked for
**                           allocated pins of the field. The bit 0
**                           corresponds with the pin which has index 0
**                           within the given bit field, the bit 1
**                           corresponds with the pin which has index 1
**                           within the given bit field, etc.
*/
/* ===================================================================*/
GPIO2_TFieldValue GPIO2_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case Motor_Enable: {               /* bit field #0 */
      return
        (GPIO2_TFieldValue)(
          (
            GPIO_PDD_GetPortDataInput(GPIO2_MODULE_BASE_ADDRESS)
            & (GPIO2_TPortValue)GPIO2_Motor_Enable_MASK
          )
          >> GPIO2_Motor_Enable_START_BIT
        );
    }
    default:
      break;                           /* Invalid BitField is not treated, result is undefined */
  } /* switch (Field) */
  return (GPIO2_TFieldValue)0U;
}

/*
** ===================================================================
**     Method      :  GPIO2_ClearFieldBits (component GPIO_LDD)
*/
/*!
**     @brief
**         This method drives the specified bits of the specified bit
**         field to the inactive level.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     @param
**         Mask            - Aligned mask of bits to setting the
**                           inactive level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
*/
/* ===================================================================*/
void GPIO2_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO2_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case Motor_Enable: {               /* bit field #0 */
      GPIO_PDD_ClearPortDataOutputMask(GPIO2_MODULE_BASE_ADDRESS,
        ((GPIO2_TPortValue)GPIO2_Motor_Enable_MASK)
        & ((GPIO2_TPortValue)(Mask << GPIO2_Motor_Enable_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO2_SetFieldBits (component GPIO_LDD)
*/
/*!
**     @brief
**         This method drives the specified bits of the specified bit
**         field to the active level.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     @param
**         Mask            - Aligned mask of bits to setting the
**                           active level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
*/
/* ===================================================================*/
void GPIO2_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO2_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case Motor_Enable: {               /* bit field #0 */
      GPIO_PDD_SetPortDataOutputMask(GPIO2_MODULE_BASE_ADDRESS,
        ((GPIO2_TPortValue)GPIO2_Motor_Enable_MASK)
        & ((GPIO2_TPortValue)(Mask << GPIO2_Motor_Enable_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  GPIO2_ToggleFieldBits (component GPIO_LDD)
*/
/*!
**     @brief
**         This method inverts the specified bits of the specified bit
**         field to other level.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     @param
**         Mask            - Aligned mask of bits to inverting the
**                           current level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
*/
/* ===================================================================*/
void GPIO2_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, GPIO2_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case Motor_Enable: {               /* bit field #0 */
      GPIO_PDD_TogglePortDataOutputMask(GPIO2_MODULE_BASE_ADDRESS,
        ((GPIO2_TPortValue)GPIO2_Motor_Enable_MASK)
        & ((GPIO2_TPortValue)(Mask << GPIO2_Motor_Enable_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/* END GPIO2. */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
