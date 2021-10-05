/*
 * Port.h
 *
 *  Created on: Oct 21, 2017
 *      Author: envy
 */
//#include "Task.h"

#ifndef PORT_H_
#define PORT_H_


#include "types.h"



void savecontext(void);
void restortcontext(void);
__interrupt void Tick_OnInterrupt(void);
__interrupt void Cpu_OnSWI(void);
void start(void);
puc InicializarStack(puc stack,unsigned long tamStack, taskcallback funcion);

#endif /* PORT_H_ */
