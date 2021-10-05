#ifndef TASK_H_
#define TASK_H_

// ******************** Extern library ***************************//

//#include "Types.h"
#include "queue.h"
#include "port.h"

// ******************** Definición de variables de modulo**********//

// **************Task Status************//
//			typedef unsigned long (*taskcallback)(unsigned long); en typesdef
typedef enum {
	running = 0 /*0*/, 
	suspended, 
	ready  /*2*/
} _STATUS_TASK;

//**************Tasks Control Block *************//
typedef struct {
	_STATUS_TASK status;
	//int status;
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
	taskcallback callback;
//elemento de fila ultimo tercio;

} _TCB, * _P_TCB; /*holaa*/

extern _P_TCB ActualTask; //revisar si es pointer
extern ps actualstack1;
//extern pc actualstack1;  //revis
extern _TCB TCB_InactiveTask;

puc Scheduler(puc Stack);
void InactiveTask(void);

v RTOS_Init(v);
v TaskBuilder(_P_TCB _TCB_TASK, us ID, puc TaskName, unsigned long TamStack, puc Stack, taskcallback Cback);

extern uc Stack_InactiveTask[128];

#endif /* TASK_H_ */
