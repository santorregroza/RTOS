/*
 * Types.h
 *
 *  Created on: Oct 16, 2017
 *      Author: envy
 */


// ******************** Extern library ***************************//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#ifndef TYPES_H_
#define TYPES_H_


// **************** Definición de variables del modulo**************** //


/* *****************Char*****************/
#ifndef uc
	typedef unsigned char uc;
#endif
	
#ifndef c
	typedef signed char c;
#endif
		
#ifndef puc
	typedef unsigned char* puc;
#endif
	
#ifndef pc
	typedef signed char* pc;
#endif

#ifndef u16
	typedef unsigned long u16;
#endif
	
/* ****************Float**************** 
//#ifndef uf
//	typedef unsigned float uf;
//#endif
	
#ifndef f
	typedef signed float f;
#endif

#ifndef puf
	typedef unsigned float* puf;
#endif
	
#ifndef pf
	typedef signed float* pf;
#endif  */
	
/* *************Short o int ************* */

#ifndef us
	typedef unsigned short us;
#endif
	
#ifndef c
	typedef signed short s;
#endif
		
#ifndef puc
	typedef unsigned short* pus;
#endif
	
#ifndef pc
	typedef signed short* ps;
#endif
	
/* ***********Double*********************** 

#ifndef ud
	typedef unsigned double ud;
#endif
	
#ifndef d
	typedef signed double d;
#endif
		
#ifndef pud
	typedef unsigned double* pud;
#endif
	
#ifndef pd
	typedef signed double* pd;
#endif
*/
/************Long************************/

#ifndef ul
	typedef unsigned long ul;
#endif
	
#ifndef l
	typedef signed long l;
#endif
		
#ifndef pul
	typedef unsigned long* pul;
#endif
	
#ifndef pl
	typedef signed long* pl;
#endif
	
/**********Void***************************/

#ifndef v
	typedef  void v ;
#endif
	
#ifndef pv
	typedef void* pv ;
#endif
	
typedef  unsigned long (*taskcallback)(unsigned long);
#endif /* TYPES_H_ */
