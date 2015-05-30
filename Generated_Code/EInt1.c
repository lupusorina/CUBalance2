/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : EInt1.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : ExtInt_LDD
**     Version     : Component 02.154, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-05-30, 15:50, # CodeGen: 72
**     Abstract    :
**         This component, "ExtInt_LDD", provide a low level API 
**         for unified access of external interrupts handling
**         across various device designs.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**          Component name                                 : EInt1
**          Pin                                            : PTD3/SPI0_MISO/UART2_TX/TPM0_CH3/SPI0_MOSI
**          Pin signal                                     : 
**          Generate interrupt on                          : rising edge
**          Interrupt                                      : INT_PORTD
**          Interrupt priority                             : medium priority
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnInterrupt                                : Enabled
**          Threshold level                                : 0
**     Contents    :
**         Init - LDD_TDeviceData* EInt1_Init(LDD_TUserData *UserDataPtr);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file EInt1.c
** @version 01.00
** @brief
**         This component, "ExtInt_LDD", provide a low level API 
**         for unified access of external interrupts handling
**         across various device designs.
**         The component uses one pin which generates interrupt on 
**         selected edge.
*/         
/*!
**  @addtogroup EInt1_module EInt1 module documentation
**  @{
*/         

/* MODULE EInt1. */

#include "Events.h"
#include "EInt1.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct {
  LDD_TUserData *UserData;             /* RTOS device data structure */
} EInt1_TDeviceData, *EInt1_TDeviceDataPtr; /* Device data structure type */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static EInt1_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static EInt1_TDeviceData * INT_PORTD__DEFAULT_RTOS_ISRPARAM;

/*
** ===================================================================
**     Method      :  EInt1_Init (component ExtInt_LDD)
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
LDD_TDeviceData* EInt1_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  EInt1_TDeviceData *DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Store the UserData pointer */
  DeviceDataPrv->UserData = UserDataPtr;
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_PORTD__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* Clear interrupt status flag - w1c */
  PORTD_ISFR = PORT_ISFR_ISF(0x08);                                   
  /* Initialization of Port Control registers */
  /* PORTD_PCR3: ISF=0,IRQC=9,MUX=1 */
  PORTD_PCR3 = (uint32_t)((PORTD_PCR3 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_IRQC(0x06) |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_IRQC(0x09) |
                PORT_PCR_MUX(0x01)
               ));                                  
  /* NVIC_IPR7: PRI_31=0x80 */
  NVIC_IPR7 = (uint32_t)((NVIC_IPR7 & (uint32_t)~(uint32_t)(
               NVIC_IP_PRI_31(0x7F)
              )) | (uint32_t)(
               NVIC_IP_PRI_31(0x80)
              ));                                  
  /* NVIC_ISER: SETENA|=0x80000000 */
  NVIC_ISER |= NVIC_ISER_SETENA(0x80000000);                                   
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_EInt1_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  EInt1_Interrupt (component ExtInt_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(EInt1_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  EInt1_TDeviceDataPtr DeviceDataPrv = INT_PORTD__DEFAULT_RTOS_ISRPARAM;
  /* Clear the interrupt flag */
  PORT_PDD_ClearPinInterruptFlag(EInt1_PORTCONTROL_BASE_ADDRESS, EInt1_PIN_INDEX);
  /* Call OnInterrupt event */
  EInt1_OnInterrupt(DeviceDataPrv->UserData);
}

/* END EInt1. */

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
