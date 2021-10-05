/*
 * Port.c
 *
 *  Created on: Oct 21, 2017
 *      Author: envy
 */

#include "Port.h"
#include "PE_Types.h"
#include "IO_Map.h"


extern puc actualstack1;
extern puc Scheduler(puc);

#pragma INLINE
void savecontext(void){
	asm(TSX);
	asm(STHX actualstack1);
	
}
	
#pragma INLINE
void restortcontext(void){
	
	asm(LDHX	actualstack1);
	asm(TXS);
	
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
}

__interrupt void Cpu_OnSWI(void)
{
	savecontext();
	actualstack1=Scheduler(actualstack1);
	restortcontext();
	//asm(RTI);
	//Led_NegVal();
  /* Write your code here ... */
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
}

