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
#include "List.h"
//#include "Port.c"
//#include "stdlib.h"
//#include "types.h"
#include "Port.h"
#include "Task.h"

#include "list.h"
#include "Mutex.h"
/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Led.h"
#include "Timer.h"
#include "LED1.h"
#include "SeriaAsincrono.h"
#include "Motor1.h"
#include "SM1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

T_MUTEX_HANDLER Mutex_LED;

void Tarea1(void);
void Tarea2(void);
void Tarea3(void);
void Tarea4(void);
void TX_TransmitirBloque(char[]);



_TCB TCB_Tarea4;
_TCB TCB_Tarea3;
_TCB TCB_Tarea2;
_TCB TCB_Tarea1;



uc Stack_Tarea1[500];
uc Stack_Tarea2[128];
uc Stack_Tarea3[128];
uc Stack_Tarea4[128];

/*tarea Spi*/
void Spitarea(void);
uc Stack_Spitarea[128];
_TCB TCB_Spitarea;

/***********************/

uc Stack_InactiveTask[128];
_TCB TCB_InactiveTask;

_P_TCB ActualTask=NULL;


puc actualstack1=NULL;

//temporal cambiar por el mutex

byte velocidad;
byte direccion;
byte rango;


void main(void){
	/* Write your local variable definition here */
	
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/

	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	Cpu_DisableInt();
	RTOS_Init();

	for (;;) {
		
		Mutex_Create(&Mutex_LED);
		//TaskBuilder(&TCB_Tarea1,1,"Tarea1",(ul)500,Stack_Tarea1,Tarea1);
		TaskBuilder(&TCB_Tarea2,2,"Tarea2",128,Stack_Tarea2,Tarea2);
		TaskBuilder(&TCB_Tarea3,3,"Tarea3",128,Stack_Tarea3,Tarea3);
		TaskBuilder(&TCB_Tarea4,4,"Tarea4",128,Stack_Tarea4,Tarea4);
	//	TaskBuilder(&TCB_Spitarea,5,"TareaSpi",128,tack_Spitarea);
		TaskBuilder(&TCB_InactiveTask,0,"Tarea Inactiva",128,Stack_InactiveTask,InactiveTask);
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
	/*
	word txcount[4];
	byte j=7;
	uc cadena[]="****************CONTROL DE ROBOT*******************\n\r\n\r\n\r";
	uc cadena1[]="1.Rango de velocidades\n\r";
	uc cadena2[]="2.Dirección del motor\n\r";
	uc cadena3[]="3.Velocidad del motor\n\r";
	uc datorecivido;
	for(;;){
	TX_TransmitirBloque(cadena);
	TX_TransmitirBloque(cadena1);
	TX_TransmitirBloque(cadena2);
	TX_TransmitirBloque(cadena3);
	while (!SCI1S1_RDRF){};
	j=SeriaAsincrono_RecvChar(&datorecivido);
	if(datorecivido=='1'){
		TX_TransmitirBloque("***********Rango de velocidades***********\n\r");
		while (!SCI1S1_RDRF){};
		j=SeriaAsincrono_RecvChar(&rango);
		(void)SeriaAsincrono_SendChar(rango);
		while(!SCI1S1_TC){};
	}
	if(datorecivido=='2'){
		TX_TransmitirBloque("***********Direccion***********\n\r");
		while (!SCI1S1_RDRF){};
		j=SeriaAsincrono_RecvChar(&direccion);
		(void)SeriaAsincrono_SendChar(direccion);
		while(!SCI1S1_TC){};
	}
	if(datorecivido=='3')
	{
		TX_TransmitirBloque("***********Velocidad***********\n\r");
		while (!SCI1S1_RDRF){};
		j=SeriaAsincrono_RecvChar(&velocidad);
		(void)SeriaAsincrono_SendChar(velocidad);
		while(!SCI1S1_TC){};
	}
	}
	*/
	for(;;){
	LED1_ClrVal();
	Cpu_Delay100US(10000);
	LED1_SetVal();
	Cpu_Delay100US(10000);
	}
}	
	


void Tarea2(void){
	uc i;
	for(;;){
		Mutex_Take(&Mutex_LED);
		for(i = 0; i<10; i++){
			Led_ClrVal();
			Cpu_Delay100US(5000);
			Led_SetVal();
			//Motor1_PutVal(velocidad);
			Cpu_Delay100US(5000);
		}
		(v)Mutex_Give(&Mutex_LED);
	}
}

void Tarea3(void){
	uc i;
	for(;;){
		Mutex_Take(&Mutex_LED);
		for(i = 0; i<25; i++){
			Led_ClrVal();
			Cpu_Delay100US(2000);
			Led_SetVal();
			//Motor1_PutVal(velocidad);
			Cpu_Delay100US(2000);
		}
		(v)Mutex_Give(&Mutex_LED);
	}
}

void Tarea4(void){
	uc i;
	for(;;){
		Mutex_Take(&Mutex_LED);
		for(i = 0; i<50; i++){
			Led_ClrVal();
			Cpu_Delay100US(1000);
			Led_SetVal();
			//Motor1_PutVal(velocidad);
			Cpu_Delay100US(1000);
		}
		(v)Mutex_Give(&Mutex_LED);
	}
}

void TX_TransmitirBloque(char cadena[]){
	int i=0;
	for (i=0;i<strlen(cadena);i++){
		(void)SeriaAsincrono_SendChar(cadena[i]);
		while(!SCI1S1_TC){};
	}
	return;
}

void Spitarea(void){
	for(;;){
		
	//SM1_SendChar(0b0);

	}
}
