/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : FMSTR1.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : FreeMaster
**     Version     : Component 01.101, Driver 01.05, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-05-28, 18:26, # CodeGen: 68
**     Abstract    :
**          This component encapsulates the FreeMASTER driver. The FreeMASTER
**          driver implements all the features necessary to establish a communication
**          with the FreeMASTER visualization tool.
**     Settings    :
**          Init_SCI                             : 
**
**          Initialization:
**              Driver interrupt mode            : Mixed interrupt and polling mode
**              Communication device             : JTAG
**              Oscilloscope enabled             : yes
**              Recorder enabled                 : yes
**              Recorder buffer length           : 256
**              Application command enabled      : yes
**              Command buffer length            : 16
**              TSA enabled                      : no
**              Read/write memory commands       : yes
**              Read/write variable commands     : no
**              Data buffer length               : 0
**     Contents    :
**         Poll                  - void FMSTR1_Poll(void);
**         Recorder              - void FMSTR1_Recorder(void);
**         TriggerRec            - void FMSTR1_TriggerRec(void);
**         GetAppCmd             - FMSTR_APPCMD_CODE FMSTR1_GetAppCmd(void);
**         GetAppCmdData         - FMSTR_APPCMD_PDATA FMSTR1_GetAppCmdData(FMSTR_SIZE *pDataLen);
**         RegisterAppCmdCall    - FMSTR_BOOL FMSTR1_RegisterAppCmdCall(FMSTR_APPCMD_CODE nAppCmdCode,...
**         AppCmdAck             - void FMSTR1_AppCmdAck(FMSTR_APPCMD_RESULT nResultCode);
**         AppCmdSetResponseData - void FMSTR1_AppCmdSetResponseData(FMSTR_ADDR nResultDataAddr, FMSTR_SIZE...
**
**     (c) Freescale Semiconductor, Inc.
**     2004 All Rights Reserved
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file FMSTR1.c
** @version 01.05
** @brief
**          This component encapsulates the FreeMASTER driver. The FreeMASTER
**          driver implements all the features necessary to establish a communication
**          with the FreeMASTER visualization tool.
*/         
/*!
**  @addtogroup FMSTR1_module FMSTR1 module documentation
**  @{
*/         

/* MODULE FMSTR1. */

#include "FMSTR1.h"

/*
** ===================================================================
**     Method      :  FMSTR1_Init (component FreeMaster)
**
**     Description :
**         Initializes the associated peripheral(s) and the component 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/*
void FMSTR1_Init(void)

**  This method is implemented as a macro. See FMSTR1.h file.  **

*/
/*
** ===================================================================
**     Method      :  FMSTR1_Poll (component FreeMaster)
**     Description :
**         In the poll-driven or short interrupt modes, this function
**         handles the protocol decoding and execution. In the
**         poll-driven mode, this function also handles the SCI
**         communication. In the long interrupt mode, this function
**         compiles as an empty function and may still be called.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void FMSTR1_Poll(void)

**  This method is implemented as a macro. See FMSTR1.h file.  **

*/
/*
** ===================================================================
**     Method      :  FMSTR1_Isr (component FreeMaster)
**
**     Description :
**         Main SCI/JTAG Interrupt handler call. This Interrupt Service 
**         Routine handles the interrupts for the FreeMASTER driver.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
/*
void FMSTR1_Isr(void)

**  This method is implemented as a macro. See FMSTR1.h file.  **

*/
/*
** ===================================================================
**     Method      :  FMSTR1_Recorder (component FreeMaster)
**     Description :
**         Recorder worker routine. This returns quickly if recorder is
**         not running, otherwise it calls quite lengthy recorder
**         routine which does all the recorder work (sampling,
**         triggering). 
**         This method is enabled only if the Recorder property is
**         enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void FMSTR1_Recorder(void)

**  This method is implemented as a macro. See FMSTR1.h file.  **

*/
/*
** ===================================================================
**     Method      :  FMSTR1_TriggerRec (component FreeMaster)
**     Description :
**         Pull the trigger of the recorder. This function starts the
**         post-trigger stop countdown.
**         This method is enabled only if the Recorder property is
**         enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void FMSTR1_TriggerRec(void)

**  This method is implemented as a macro. See FMSTR1.h file.  **

*/
/*
** ===================================================================
**     Method      :  FMSTR1_GetAppCmd (component FreeMaster)
**     Description :
**         Fetch the application command code if one is ready for
**         processing. 
**         This method is enabled only if the Application command
**         property is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Code of the application command which
**                           needs to be processed. In case no command
**                           is pending, this function returns
**                           FMSTR_APPCMDRESULT_NOCMD.
** ===================================================================
*/
/*
FMSTR_APPCMD_CODE FMSTR1_GetAppCmd(void)

**  This method is implemented as a macro. See FMSTR1.h file.  **

*/
/*
** ===================================================================
**     Method      :  FMSTR1_GetAppCmdData (component FreeMaster)
**     Description :
**         Get a pointer to application command data. This function can
**         be used to retrieve the Application Command data, once the
**         application determines the Application Command is pending.
**         This method is enabled only if the Application command
**         property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * pDataLen        - Pointer to a variable which
**                           receives the length of the data available
**                           in the buffer. May be NULL when this
**                           information is not needed.
**     Returns     :
**         ---             - Pointer to application command data.
** ===================================================================
*/
/*
FMSTR_APPCMD_PDATA FMSTR1_GetAppCmdData(FMSTR_SIZE *pDataLen)

**  This method is implemented as a macro. See FMSTR1.h file.  **

*/
/*
** ===================================================================
**     Method      :  FMSTR1_RegisterAppCmdCall (component FreeMaster)
**     Description :
**         Register or unregister application command callback handler.
**         This method is enabled only if the Application command
**         property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         nAppCmdCode     - Application command code
**                           for which the callback is to be registered.
**         pCallbackFunc   - Pointer to a callback
**                           function which is to be registered. Use
**                           NULL to un-register a callback registered
**                           previously with this Application Command.
**     Returns     :
**         ---             - 0 - Error: registering a callback function
**                           for more than defined maximum of app. cmd.
**                           callbacks 
**                           non-zero - OK
** ===================================================================
*/
/*
FMSTR_BOOL FMSTR1_RegisterAppCmdCall(FMSTR_APPCMD_CODE nAppCmdCode, FMSTR_PAPPCMDFUNC pCallbackFunc)

**  This method is implemented as a macro. See FMSTR1.h file.  **

*/
/*
** ===================================================================
**     Method      :  FMSTR1_AppCmdAck (component FreeMaster)
**     Description :
**         This function is used when Application Command processing is
**         finished in the application. The nResultCode passed to this
**         function is returned back to the host and the driver is
**         re-initialized to expect the next Application Command. 
**         This method is enabled only if the Application command
**         property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         nResultCode     - Result code which is to be
**                           returned to the FreeMASTER tool.
**     Returns     : Nothing
** ===================================================================
*/
/*
void FMSTR1_AppCmdAck(FMSTR_APPCMD_RESULT nResultCode)

**  This method is implemented as a macro. See FMSTR1.h file.  **

*/
/*
** ===================================================================
**     Method      :  FMSTR1_AppCmdSetResponseData (component FreeMaster)
**     Description :
**         This function can be used before the Application Command
**         processing is finished, when there are any data to be
**         returned back to the PC.
**         This method is enabled only if the Application command
**         property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         nResultDataAddr - Pointer to data
**                           buffer which is to be copied to the
**                           Application Command data buffer
**         nResultDataLen  - Length of a data to
**                           be copied. Must not exceed the app. cmd.
**                           buffer size.
**     Returns     : Nothing
** ===================================================================
*/
/*
void FMSTR1_AppCmdSetResponseData(FMSTR_ADDR nResultDataAddr, FMSTR_SIZE nResultDataLen)

**  This method is implemented as a macro. See FMSTR1.h file.  **

*/
/* END FMSTR1. */

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
