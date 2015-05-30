/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : freemaster_cfggen.h
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Version     : Component 01.101, Driver 01.05, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2015-05-28, 18:26, # CodeGen: 68
**     Abstract    :
**          This component encapsulates the FreeMASTER driver. The FreeMASTER
**          driver implements all the features necessary to establish a communication
**          with the FreeMASTER visualization tool.
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file freemaster_cfggen.h                                                  
** @version 01.05
** @brief
**          This component encapsulates the FreeMASTER driver. The FreeMASTER
**          driver implements all the features necessary to establish a communication
**          with the FreeMASTER visualization tool.
*/         
/*!
**  @addtogroup freemaster_cfggen_module freemaster_cfggen module documentation
**  @{
*/         

/* Select interrupt or poll-driven serial communication */
#define FMSTR_LONG_INTR         0x00
#define FMSTR_SHORT_INTR        0x01   /* SCI FIFO-queuing done in interrupt */
#define FMSTR_POLL_DRIVEN       0x00

/* SCI communication */
#define FMSTR_DISABLE           0x00   /* FreeMASTER is enabled */
#define FMSTR_USE_SCI           0x01   /* Use SCI interface */
#define FMSTR_SCI_BASE          0x4006A000 /* SCI Base address is same as SCI Baud Rate register address */
#define FMSTR_USE_MSCAN         0x00   /* Disables MSCAN interface */
#define FMSTR_USE_FLEXCAN       0x00   /* Disables FLEXCAN interface */
#define FMSTR_USE_USB_CDC       0x00   /* Disables USB CDC communication interface */
#define FMSTR_USE_PDBDM         0x00   /* Disables Packet Driven BDM communication interface */

/* FreeMaster communication buffer */
#define FMSTR_COMM_BUFFER_SIZE  0x00   /* Input/output communication buffer size */
#define FMSTR_COMM_RQUEUE_SIZE  0x20   /* Receive FIFO queue size (use with FMSTR_SHORT_INTR only) */

/* Application command support */
#define FMSTR_USE_APPCMD        0x01   /* Application commands support enabled */
#define FMSTR_APPCMD_BUFF_SIZE  0x10   /* Application command buffer size */
#define FMSTR_MAX_APPCMD_CALLS  0x00   /* How many app.cmd callbacks? (0=disable) */

/* Oscilloscope support */
#define FMSTR_USE_SCOPE         0x01   /* Scope enabled */
#define FMSTR_MAX_SCOPE_VARS    0x08   /* Max. number of scope variables (2..8) */

/* Recorder support */
#define FMSTR_USE_RECORDER      0x01   /* Recorder support enabled */
//#define FMSTR_REC_BUFF_SIZE     0x0100 /* Recorder buffer size */
//#define FMSTR_REC_OWNBUFF       0x00   /* User-allocated rec. buffer is not used */
//#define FMSTR_REC_FARBUFF       0x00   /* Buffer is not putted in "fardata" section */
#define FMSTR_MAX_REC_VARS      0x08   /* Max. number of recorder variables (2..8) */
//#define FMSTR_REC_TIMEBASE      FMSTR_REC_BASE_SECONDS(0) /* Recorder timebase */

/* Target-side addressing support */
//#define FMSTR_USE_TSA           0x00   /* Disable TSA functionality */
//#define FMSTR_USE_TSA_SAFETY    0x00   /* Disable access to TSA variables only */
//#define FMSTR_USE_TSA_INROM     0x00   /* TSA tables are not declared as const */

//#define FMSTR_USE_READMEM       0x01   /* Enable read memory commands */
//#define FMSTR_USE_WRITEMEM      0x01   /* Enable write memory commands */
//#define FMSTR_USE_WRITEMEMMASK  0x01   /* Enable masked write memory commands */

//#define FMSTR_USE_READVAR       0x00   /* Disable read variable fast commands */
//#define FMSTR_USE_WRITEVAR      0x00   /* Disable write variable fast commands */
//#define FMSTR_USE_WRITEVARMASK  0x00   /* Disable write variable bits fast commands */

/* SFIO support */
//#define FMSTR_USE_SFIO          0x00   /* SFIO support disabled */


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
