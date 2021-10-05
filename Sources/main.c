/* ###################################################################
 **     Filename    : main.c
 **     Project     : SORT
 **     Processor   : MC9S08QE128CLK
 **     Version     : Driver 01.12
 **     Compiler    : CodeWarrior HCS08 C Compiler
 **     Date/Time   : 2017-10-21, 13:37, # CodeGen: 0
 **     Abstract    :
 **         Main module.
 **         This module contains user's application code.
 **     Settings    :
 **     Contents    :
 **         No public methods
 **
 ** ###################################################################*/
/*!
 ** @file main.c
 ** @version 01.12
 ** @brief
 **         Main module.
 **         This module contains user's application code.
 */
/*!
 **  @addtogroup main_module main module documentation
 **  @{
 */
/* MODULE main */

/*****************************************************************************
 ******************************************************************************
 *
 *   INCLUSION DE LIBRERIRAS 
 *
 ******************************************************************************
 *****************************************************************************/

#include "Queue.h"
//#include "Port.c"
//#include "stdlib.h"
//#include "types.h"
#include "Port.h"
#include "Task.h"

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Led.h"
#include "Timer.h"
#include "LED1.h"
#include "SeriaAsincrono.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

void Tarea1(void);
void Tarea2(void);

_P_TCB ActualTask=NULL;
//_P_TCB TCB_Tarea1;
_TCB TCB_Tarea2;
_TCB TCB_Tarea1;
uc Stack_Tarea1[128];
uc Stack_Tarea2[128];
_TCB TCB_InactiveTask; //revisar si es pointer
uc Stack_InactiveTask[128];
ps actualstack1=NULL;

void main(void){
	/* Write your local variable definition here */
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/

	
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	Cpu_DisableInt();
	RTOS_Init();

	for (;;) {
		//Cpu_OnSwINT();
		//asm(SWI);

		//crear tareas

		//
		//tarea inactiva crear
		TaskBuilder(&TCB_Tarea1,1,"Tarea1",(ul)128,Stack_Tarea1,Tarea1);
		//actualstack1= TCB_Tarea1 -> stackcurrent;
		TaskBuilder(&TCB_Tarea2,2,"Tarea2",128,Stack_Tarea2,Tarea2);
		TaskBuilder(&TCB_InactiveTask,0,"tarea inactiva",128,Stack_InactiveTask,InactiveTask);
		Cpu_EnableInt();
		start();
	}
	

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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

void Tarea1(void){
	for(;;){
		LED1_ClrVal();
		Cpu_Delay100US(10000);
		LED1_SetVal();
		Cpu_Delay100US(10000);
	}
}
void Tarea2(void){
	for(;;){
		Led_ClrVal();
		Cpu_Delay100US(5000);
		Led_SetVal();
		Cpu_Delay100US(5000);
	}
}

