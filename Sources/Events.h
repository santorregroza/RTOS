/* ###################################################################
**     Filename    : Events.h
**     Project     : SORT1
**     Processor   : MC9S08QE128CLK
**     Component   : Events
**     Version     : Driver 01.02
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2017-10-21, 13:37, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.02
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */
#include "port.h"

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Led.h"
#include "Timer.h"
#include "LED1.h"
#include "SeriaAsincrono.h"
#include "Motor1.h"
#include "SM1.h"

//#include "Port.c"

void Cpu_OnSwINT(void);
/*
** ===================================================================
**     Event       :  Cpu_OnSwINT (module Events)
**
**     Component   :  Cpu [MC9S08QE128_80]
**     Description :
**         This event is called when the SWI interrupt had occurred.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

//void Tick_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  Timer_OnInterrupt (module Events)
**
**     Component   :  Timer [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void Timer_OnInterrupt(void);
/*
** ===================================================================
**     Event       :  Timer_OnInterrupt (module Events)
**
**     Component   :  Timer [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the component is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SM1_OnRxChar(void);
/*
** ===================================================================
**     Event       :  SM1_OnRxChar (module Events)
**
**     Component   :  SM1 [SynchroMaster]
**     Description :
**         This event is called after a correct character is received.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**         
**         [ Version specific information for Freescale HCS08 and RS08
**         and HCS12 and HCS12X and ColdFireV1 derivatives ] 
**         The <Bidirectional mode> property setting doesn't affect
**         this event. For more information please see <Bidirectional
**         mode behavior> paragraph.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SM1_OnTxChar(void);
/*
** ===================================================================
**     Event       :  SM1_OnTxChar (module Events)
**
**     Component   :  SM1 [SynchroMaster]
**     Description :
**         This event is called after a character is transmitted.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

void SM1_OnError(void);
/*
** ===================================================================
**     Event       :  SM1_OnError (module Events)
**
**     Component   :  SM1 [SynchroMaster]
**     Description :
**         This event is called when a channel error (not the error
**         returned by a given method) occurs. The errors can be read
**         using <GetError> method.
**         The event is available only when the <Interrupt
**         service/event> property is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */
#endif /* __Events_H*/

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
