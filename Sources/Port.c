/*
 * Port.c
 *
 *  Created on: Oct 21, 2017
 *      Author: envy
 */

#include "Port.h"
#include "PE_Types.h"
#include "IO_Map.h"
//#include "Task.h"

extern ps actualstack1;
extern pc Scheduler(pc);

#pragma INLINE
void savecontext(void){
	//asm(RTI);
	
	//	PSHH //++++
		asm(TSX);
		asm(STHX actualstack1);
	//}
}
	
#pragma INLINE
void restortcontext(void){
	//asm{
		asm(LDHX	actualstack1);
		asm(TXS);
	//	PULH //++++
	//}
}

__interrupt void Tick_OnInterrupt(void)
{
  /* Write your code here ... */
	//savecontext();
	asm(TSX);
  	asm(STHX actualstack1);
	setReg8Bits(RTCSC, 0x80U);           /* Reset real-time counter request flag */ 
	actualstack1=Scheduler(actualstack1);
	//ticks algo 
	restortcontext();
	//asm(PULH);
	//LED1_NegVal();
}

void start(void){  //inicializar el sistema operativo 
	 
	actualstack1=Scheduler(actualstack1);
	restortcontext();
	asm(PULH);
	asm(RTI);
}

puc InicializarStack(puc stack,unsigned long tamStack, taskcallback funcion){
	puc actualstack = stack;
	unsigned long pt= (unsigned long)funcion;
	actualstack += (tamStack-1) ; 					//aparta el tamaño del stack en el stack 
	*actualstack = (c)(pt & 0x00FF);  				//mascara para el apuntador de la función 
	actualstack--; 									//decrementamos el stack
	*actualstack = (c)((pt>>8) & 0x00ff);  			//guardar la otra parte del callback 
	actualstack--;									//De aqui en adelente para el contexto inicial
	*actualstack = 0;
	actualstack--;
	*actualstack = 0;
	actualstack--;
	*actualstack = 0x60; 							//ver el CCR
	actualstack--;
	 *actualstack = 0;
	 return actualstack;
	/*stack += (tamStack-1) ; 					//aparta el tamaño del stack en el stack 
		*stack = (c)(pt & 0x00FF);  				//mascara para el apuntador de la función 
		stack--; 									//decrementamos el stack
		*stack = (c)((pt>>8) & 0x00ff);  			//guardar la otra parte del callback 
		stack--;									//De aqui en adelente para el contexto inicial
		*stack = 0;
		stack--;
		*stack = 0;
		stack--;
		*stack = 0x60; 							//ver el CCR
		stack--;
		 *stack = 0;
	return stack;*/
}

