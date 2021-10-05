/*
 * mutex.c
 *
 *  Created on: Nov 19, 2017
 *      Author: envy
 */


/*****************************************************************************
******************************************************************************
*
*   INCLUSION DE LIBRERIRAS 
*
******************************************************************************
*****************************************************************************/

#include "Mutex.h"
#include "task.h"
#include <cpu.h>
#include <stdlib.h>


//#include "queue.h"

/*****************************************************************************
******************************************************************************
*
*   DEFINICION DE CONSTANTES INTERNAS DEL MODULO
*
******************************************************************************
*****************************************************************************/

/*****************************************************************************
******************************************************************************
*
*   DEFINICION DE TIPOS DE DATOS INTERNOS DEL MODULO
*
******************************************************************************
*****************************************************************************/

/*****************************************************************************
******************************************************************************
*
*   DEFINICION DE FUNCIONES INTERNAS DEL MODULO
*
******************************************************************************
*****************************************************************************/

/*****************************************************************************
******************************************************************************
*
*   DEFINICION DE VARIABLES GLOBALES INTERNAS DEL MODULO
*
******************************************************************************
*****************************************************************************/

/*****************************************************************************
******************************************************************************
##############################################################################
#
#   IMPLEMENTACION DE FUNCIONES EXTARNAS DEL MODULO
#
##############################################################################
******************************************************************************
*****************************************************************************/

/*****************************************************************************
*
*   Nombre      : Mutex_Crearte 
*   Descripcion : crear un mutex. 
*                 
*
*   Parametros  : 
*       T_MUTEX_HANDLER_PTR
*
*   Retorno     :
*       res (error).
*
*****************************************************************************/

uc Mutex_Create(T_MUTEX_HANDLER_PTR mutex){
	uc res=0;
	if(mutex != NULL)
	{
		mutex->mutex_status=0; 
		Queue_Create(&mutex->mutex_queue);	// res=Queue_Create(&mutex->coladeesperadelmutex);
		res=1; 								//provisional arreglar Queue_Create
	}
	return res;
}

/*****************************************************************************
*
*   Nombre      : Mutex_Take
*   Descripcion : Una tarea toma el mutex. 
*                 
*
*   Parametros  : 
*       T_MUTEX_HANDLER_PTR
*
*   Retorno     :
*       res (error).
*
*****************************************************************************/

uc Mutex_Take(T_MUTEX_HANDLER_PTR mutex){
	_P_TCB task;
	uc res=0;
	uc call_scheduler=0;
	
	if(mutex != NULL){
	Cpu_DisableInt();//revisar la invocacion de esta variable//Timer_Disable();
		if(mutex->mutex_status)
		{
			task = ActualTask;//obtener la tarea actual//task = metodo getter para obtener el la tarea actual por ahora
			if(task != NULL){
				task->status=suspended;
				Queue_Add(&mutex->mutex_queue,&task->queueelement,task);
				//res=Queue_Add(&mutex->coladeesperadelmutex,&task->elementodecoladeltcb,task);
				call_scheduler=1;
			}
		}
		else
		{
			res=1;
			mutex->mutex_status=1;	
		}
	
		Cpu_EnableInt();				//habilitar interrupciones
		if(call_scheduler) asm(SWI);	//Port_SWI();//llamar a la interrupcion de sofware port_yiel();
	return res;
	}
}
/*****************************************************************************
*
*   Nombre      : Mutex_Give
*   Descripcion : Una tarea de  el mutex. 
*                 
*
*   Parametros  : 
*       T_MUTEX_HANDLER_PTR
*
*   Retorno     :
*       res (error).
*
*****************************************************************************/

uc Mutex_Give (T_MUTEX_HANDLER_PTR mutex)
{
	uc res=0;
	_P_TCB task;
	if (mutex != NULL)         ///voy a liberar mutex 
	{	
		Cpu_DisableInt();
		if (mutex->mutex_status)
		{
			if (Queue_GetCount(&mutex->mutex_queue)) //si hay tarea esperando por mutex
			{
				task = (_P_TCB)Queue_Get(&mutex->mutex_queue);   //saque el primer elemento de la cola y retorneTCB  apuntador tipo v
				if (task!=NULL)
				{
					res = Task_AddReady(task);
				}
			}
			else
			{
			res=0;
			mutex->mutex_status=0;
			}
			Cpu_EnableInt();
			return res;
		}	
		
	}
}
