/* ###################################################################
**     Filename    : Events.c
**     Project     : SORT
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
** @file Events.c
** @version 01.02
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */


#include "Cpu.h"
#include "Events.h"

extern puc actualstack1;
extern puc Scheduler(puc);

/* User includes (#include below this line is not maintained by Processor Expert) */

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
#pragma INLINE
void Cpu_OnSwINT(void)
{
	savecontext();
	actualstack1=Scheduler(actualstack1);
	restortcontext();
	//asm(RTI);
	//Led_NegVal();
  /* Write your code here ... */
}

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
void Timer_OnInterrupt(void)
{
  /* Write your code here ... */
	//savecontext();
	asm(TSX);
	asm(STHX actualstack1);
	
	actualstack1=Scheduler(actualstack1);
	//ticks algo 
	restortcontext();
	//asm(PULH);
	//LED1_NegVal();
}

/* END Events */

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
