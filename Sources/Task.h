#ifndef TASK_H_
#define TASK_H_

// ******************** Extern library ***************************//

//#include "Types.h"
#include "queue.h"
#include "List.h"
#include "port.h"
#include "stdlib.h"


// ******************** Definición de variables de modulo**********//


typedef enum {
	running = 0 /*0*/, 
	suspended, 
	ready  /*2*/
} _STATUS_TASK;



//**************Tasks Control Block *************//
typedef struct {
	_STATUS_TASK status;
	
	puc name;
	us id;
	us priority1; 		//Ultimo tercio
//	us				priority2;
	ul sinzestack;		//Tamaño del stack
	puc stackcurrent; 	//Ubicación actual del stack de la tarea;
	puc stackadd;		//Ubicación propia del Stack
	us timesleep;		//tiempo que debe estar dormida una tarea
//	void			awaitingevent;	//ultimo tercio
	T_QUEUE_ELEMNT queueelement;
	T_LIST_ELEMENT listElement;
	taskcallback callback;
//elemento de fila ultimo tercio;

} _TCB, * _P_TCB;





/*FUNCIONES*/
puc Scheduler(puc Stack);
void InactiveTask(void);
void Task_Star(void);

v RTOS_Init(v);
v TaskBuilder(_P_TCB _TCB_TASK, us ID, puc TaskName, unsigned long TamStack, puc Stack, taskcallback Cback);

uc Task_AddReady(_P_TCB task);
///**************************************************//

extern _P_TCB ActualTask; 
extern puc actualstack1;
extern uc Stack_InactiveTask[128];
extern _TCB TCB_InactiveTask;

#endif /* TASK_H_ */
