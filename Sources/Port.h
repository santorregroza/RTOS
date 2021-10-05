/*
 * Port.h
 *
 *  Created on: Oct 21, 2017
 *      Author: envy
 */
//#include "Task.h"

#ifndef PORT_H_
#define PORT_H_

 //void* actualstack;
#include "types.h"


	//revisar
void savecontext(void);
void restortcontext(void);
__interrupt void Tick_OnInterrupt(void);
void start(void);
puc InicializarStack(puc stack,unsigned long tamStack, taskcallback funcion);

#endif /* PORT_H_ */
