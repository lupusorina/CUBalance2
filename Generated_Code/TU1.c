/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : TU1.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : TimerUnit_LDD
**     Version     : Component 01.156, Driver 01.10, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-03-15, 18:38, # CodeGen: 4
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : TU1
**          Module name                                    : TPM0
**          Counter                                        : TPM0_CNT
**          Counter direction                              : Up
**          Counter width                                  : 16 bits
**          Value type                                     : uint16_t
**          Input clock source                             : Internal
**            Counter frequency                            : Auto select
**          Counter restart                                : On-match
**            Period device                                : TPM0_MOD
**            Period                                       : 5 ms
**            Interrupt                                    : Disabled
**          Channel list                                   : 1
**            Channel 0                                    : 
**              Mode                                       : Compare
**                Compare                                  : TPM0_C2V
**                Offset                                   : 4 ms
**                Output on compare                        : Set
**                  Output on overrun                      : Clear
**                  Initial state                          : Low
**                  Output pin                             : PTC3/LLWU_P7/UART1_RX/TPM0_CH2/CLKOUTa
**                  Output pin signal                      : 
**                Interrupt                                : Disabled
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnCounterRestart                           : Disabled
**              OnChannel0                                 : Disabled
**              OnChannel1                                 : Disabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init               - LDD_TDeviceData* TU1_Init(LDD_TUserData *UserDataPtr);
**         GetPeriodTicks     - LDD_TError TU1_GetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, TU1_TValueType...
**         GetCounterValue    - TU1_TValueType TU1_GetCounterValue(LDD_TDeviceData *DeviceDataPtr);
**         SetOffsetTicks     - LDD_TError TU1_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**         GetOffsetTicks     - LDD_TError TU1_GetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**         SelectOutputAction - LDD_TError TU1_SelectOutputAction(LDD_TDeviceData *DeviceDataPtr, uint8_t...
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file TU1.c
** @version 01.10
** @brief
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
*/         
/*!
**  @addtogroup TU1_module TU1 module documentation
**  @{
*/         

/* MODULE TU1. */

#include "TU1.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

#ifdef __cplusplus
extern "C" {
#endif 

/* List of channels used by component */
static const uint8_t ChannelDevice[TU1_NUMBER_OF_CHANNELS] = {0x02U};

/* Table of channels mode / 0 - compare mode, 1 - capture mode */
static const uint8_t ChannelMode[TU1_NUMBER_OF_CHANNELS] = {0x00U};


typedef struct {
  uint8_t InitCntr;                    /* Number of initialization */
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} TU1_TDeviceData;

typedef TU1_TDeviceData *TU1_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static TU1_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;

#define AVAILABLE_PIN_MASK (LDD_TPinMask)(TU1_CHANNEL_0_PIN)
#define LAST_CHANNEL 0x00U

/* Internal method prototypes */
/*
** ===================================================================
**     Method      :  TU1_Init (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property <"Enable in init. code"> is set to "yes" value then
**         the device is also enabled (see the description of the
**         <Enable> method). In this case the <Enable> method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the <Deinit>
**         must be called first.
**     @param
**         UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     @return
**                         - Pointer to the dynamically allocated private
**                           structure or NULL if there was an error.
*/
/* ===================================================================*/
LDD_TDeviceData* TU1_Init(LDD_TUserData *UserDataPtr)
{
  TU1_TDeviceData *DeviceDataPrv;

  if (PE_LDD_DeviceDataList[PE_LDD_COMPONENT_TU1_ID] == NULL) {
    /* Allocate device structure */
    /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
    DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
    DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
    DeviceDataPrv->InitCntr = 1U;      /* First initialization */
  }
  else {
    /* Memory is already allocated */
    DeviceDataPrv = PE_LDD_DeviceDataList[PE_LDD_COMPONENT_TU1_ID];
    DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
    DeviceDataPrv->InitCntr++;         /* Increment counter of initialization */
    return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
  }
  /* SIM_SCGC6: TPM0=1 */
  SIM_SCGC6 |= SIM_SCGC6_TPM0_MASK;                                   
  /* TPM0_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,DMA=0,TOF=0,TOIE=0,CPWMS=0,CMOD=0,PS=0 */
  TPM0_SC = (TPM_SC_CMOD(0x00) | TPM_SC_PS(0x00)); /* Clear status and control register */
  /* TPM0_CNT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COUNT=0 */
  TPM0_CNT = TPM_CNT_COUNT(0x00);      /* Reset counter register */
  /* TPM0_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  TPM0_C0SC = 0x00U;                   /* Clear channel status and control register */
  /* TPM0_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  TPM0_C1SC = 0x00U;                   /* Clear channel status and control register */
  /* TPM0_C2SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  TPM0_C2SC = 0x00U;                   /* Clear channel status and control register */
  /* TPM0_C3SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  TPM0_C3SC = 0x00U;                   /* Clear channel status and control register */
  /* TPM0_C4SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  TPM0_C4SC = 0x00U;                   /* Clear channel status and control register */
  /* TPM0_C5SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,DMA=0 */
  TPM0_C5SC = 0x00U;                   /* Clear channel status and control register */
  /* TPM0_MOD: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,MOD=0xCCCC */
  TPM0_MOD = TPM_MOD_MOD(0xCCCC);      /* Set up modulo register */
  /* TPM0_C2SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=1,MSA=0,ELSB=1,ELSA=1,??=0,DMA=0 */
  TPM0_C2SC = (TPM_CnSC_MSB_MASK | TPM_CnSC_ELSB_MASK | TPM_CnSC_ELSA_MASK); /* Set up channel status and control register */
  /* TPM0_C2V: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,VAL=0xA3D7 */
  TPM0_C2V = TPM_CnV_VAL(0xA3D7);      /* Set up channel value register */
  /* PORTC_PCR3: ISF=0,MUX=4 */
  PORTC_PCR3 = (uint32_t)((PORTC_PCR3 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_MUX(0x03)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x04)
               ));                                  
  /* TPM0_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,DMA=0,TOF=0,TOIE=0,CPWMS=0,CMOD=1,PS=1 */
  TPM0_SC = (TPM_SC_CMOD(0x01) | TPM_SC_PS(0x01)); /* Set up status and control register */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_TU1_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

/*
** ===================================================================
**     Method      :  TU1_GetPeriodTicks (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Returns the number of counter ticks before re-initialization.
**         See also method <SetPeriodTicks>. This method is available
**         only if the property <"Counter restart"> is switched to
**         'on-match' value.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         TicksPtr        - Pointer to return value of the
**                           number of counter ticks before
**                           re-initialization
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU1_GetPeriodTicks(LDD_TDeviceData *DeviceDataPtr, TU1_TValueType *TicksPtr)
{
  uint16_t tmp;

  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  tmp = (uint16_t)(TPM_PDD_ReadModuloReg(TPM0_BASE_PTR));
  *TicksPtr = (TU1_TValueType)++tmp;
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  TU1_GetCounterValue (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Returns the content of counter register. This method can be
**         used both if counter is enabled and if counter is disabled.
**         The method is not available if HW doesn't allow reading of
**         the counter.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @return
**                         - Counter value (number of counted ticks).
*/
/* ===================================================================*/
TU1_TValueType TU1_GetCounterValue(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  return (TU1_TValueType)TPM_PDD_ReadCounterReg(TPM0_BASE_PTR);
}

/*
** ===================================================================
**     Method      :  TU1_SetOffsetTicks (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Sets the new offset value to channel specified by the
**         parameter ChannelIdx. It is user responsibility to use value
**         below selected period. This method is available when at
**         least one channel is configured.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         ChannelIdx      - Index of the component
**                           channel.
**     @param
**         Ticks           - Number of counter ticks to compare
**                           match.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range.
**                           ERR_NOTAVAIL -  The compare mode is not
**                           selected for selected channel
**                           ERR_PARAM_TICKS - Ticks parameter is out of
**                           possible range.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU1_SetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, TU1_TValueType Ticks)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Parameter test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (ChannelIdx > LAST_CHANNEL) {     /* Is the channel index out of range? */
    return ERR_PARAM_INDEX;            /* If yes then error */
  }
  if ((ChannelMode[ChannelIdx]) != 0U) { /* Is the channel in compare mode? */
    return ERR_NOTAVAIL;               /* If not then error */
  }
  TPM_PDD_WriteChannelValueReg(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], (uint16_t)Ticks);
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  TU1_GetOffsetTicks (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Returns the number of counter ticks to compare match channel
**         specified by the parameter ChannelIdx. See also method
**         <SetOffsetTicks>. This method is available when at least one
**         channel is configured.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         ChannelIdx      - Index of the component
**                           channel.
**     @param
**         TicksPtr        - Pointer to return value of the
**                           number of counter ticks to compare match.
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range.
**                           ERR_NOTAVAIL -  The compare mode is not
**                           selected for selected channel.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU1_GetOffsetTicks(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, TU1_TValueType *TicksPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Parameter test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (ChannelIdx > LAST_CHANNEL) {     /* Is the channel index out of range? */
    return ERR_PARAM_INDEX;            /* If yes then error */
  }
  if ((ChannelMode[ChannelIdx]) != 0U) { /* Is the channel in compare mode? */
    return ERR_NOTAVAIL;               /* If not then error */
  }
  *TicksPtr = (TU1_TValueType)(TPM_PDD_ReadChannelValueReg(TPM0_BASE_PTR, ChannelDevice[ChannelIdx]));
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  TU1_SelectOutputAction (component TimerUnit_LDD)
*/
/*!
**     @brief
**         Sets the type of compare match and counter overflow action
**         on channel output. This method is available when at least
**         one channel is configured.
**     @param
**         DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     @param
**         ChannelIdx      - Index of the component
**                           channel.
**     @param
**         CompareAction   - Select output action
**                           on compare match
**     @param
**         CounterAction   - Select output action
**                           on counter overflow
**     @return
**                         - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_PARAM_INDEX - ChannelIdx parameter is
**                           out of possible range
**                           ERR_NOTAVAIL -  Action is not possible on
**                           selected channel or counter. Supported
**                           combinations are HW specific.
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
*/
/* ===================================================================*/
LDD_TError TU1_SelectOutputAction(LDD_TDeviceData *DeviceDataPtr, uint8_t ChannelIdx, LDD_TimerUnit_TOutAction CompareAction, LDD_TimerUnit_TOutAction CounterAction)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Parameter test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (ChannelIdx > LAST_CHANNEL) {     /* Is the channel index out of range? */
    return ERR_PARAM_INDEX;            /* If yes then error */
  }
  if ((ChannelMode[ChannelIdx]) != 0U) { /* Is the channel in compare mode? */
    return ERR_NOTAVAIL;               /* If not then error */
  }
  switch (CounterAction) {
    case OUTPUT_NONE:
      TPM_PDD_SelectChannelMode(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], TPM_PDD_OUTPUT_TOGGLE);
      switch (CompareAction) {
        case OUTPUT_NONE:
          TPM_PDD_SelectChannelEdgeLevel(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], TPM_PDD_EDGE_NONE);
          break;
        case OUTPUT_TOGGLE:
          TPM_PDD_SelectChannelEdgeLevel(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], TPM_PDD_EDGE_RISING);
          break;
        case OUTPUT_CLEAR:
          TPM_PDD_SelectChannelEdgeLevel(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], TPM_PDD_EDGE_FALLING);
          break;
        case OUTPUT_SET:
          TPM_PDD_SelectChannelEdgeLevel(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], TPM_PDD_EDGE_BOTH);
          break;
        default:
          return ERR_NOTAVAIL;
      }
      break;
    case OUTPUT_CLEAR:
      if (CompareAction != OUTPUT_SET) {
        return ERR_NOTAVAIL;
      }
      TPM_PDD_SelectChannelMode(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], TPM_PDD_OUTPUT_CLEAR);
      TPM_PDD_SelectChannelEdgeLevel(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], TPM_PDD_EDGE_BOTH);
      break;
    case OUTPUT_SET:
      if (CompareAction != OUTPUT_CLEAR) {
        return ERR_NOTAVAIL;
      }
      TPM_PDD_SelectChannelMode(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], TPM_PDD_OUTPUT_SET);
      TPM_PDD_SelectChannelEdgeLevel(TPM0_BASE_PTR, ChannelDevice[ChannelIdx], TPM_PDD_EDGE_FALLING);
      break;
    default:
      return ERR_NOTAVAIL;
  }
  return ERR_OK;                       /* OK */
}

/* END TU1. */

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
