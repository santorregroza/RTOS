/*
 * Task.c
 *
 *  Created on: Oct 21, 2017
 *      Author: envy
 */

//#include	"Types.h"
#include	"Task.h"
#include "Port.h"
#include "LED1.h"

//#include 	"queue.h"
 T_QUEUE_HANDLER MainQueue;

void InactiveTask(void) {
	while (1){
		asm(NOP);
	//LED1_NegVal();
	}
}

v RTOS_Init(v)
{
	Queue_Create(&MainQueue);
}

puc Scheduler(puc Stack) {
	pc retorno = 0x00;
	
	//void *ActualTask;
	if (ActualTask != NULL ) 
	{
		ActualTask->stackcurrent = Stack; //no sé
		if (ActualTask->status ==running)
		{
			ActualTask->status =ready;
			if (ActualTask != &TCB_InactiveTask) 
				Queue_Add( &MainQueue,&ActualTask->queueelement, (pv) ActualTask);
		}
	}
		
	if(Queue_GetCount(&MainQueue) > 0)
	{
		ActualTask = Queue_Get(&MainQueue); //
		ActualTask->status =running;		//
		return ActualTask->stackcurrent;	//
	}
	ActualTask = &TCB_InactiveTask;
	ActualTask->status =running;
	return ActualTask->stackcurrent;
}

v TaskBuilder(_P_TCB _TCB_TASK, us ID, puc TaskName, ul TamStack,puc Stack, taskcallback Cback) {
	puc puntero;
	//if( ((v)_TCB_TASK != NULL) && ((v)Stack !=NULL) && ((v)Cback !=NULL)  )
	//{
	/*
	_TCB_TASK->queueelement->Data=_TCB_TASK;
	_TCB_TASK->queueelement->Next=_TCB_TASK->queueelement;
		*/
	
	_TCB_TASK->sinzestack = TamStack; 
	_TCB_TASK->status =ready ;
	_TCB_TASK->stackadd = Stack;
	_TCB_TASK->id = ID;
	_TCB_TASK->priority1 = 1;
	_TCB_TASK->name = TaskName;
	_TCB_TASK->callback = Cback;
	     //pc InicializarStack(pc stack,unsigned long tamStack, taskcallback funcion){
	puntero = InicializarStack(Stack, TamStack, Cback);
	if (puntero != NULL ) {
		_TCB_TASK->stackcurrent = puntero;//aca esta 
	}
	Queue_Add(&MainQueue,&_TCB_TASK->queueelement,(pv)_TCB_TASK);
	//}
}

