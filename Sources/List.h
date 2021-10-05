/*
 * List.h
 *
 *  Created on: Nov 18, 2017
 *      Author: envy
 */



#ifndef LIST_H_
#define LIST_H_

/*****************************************************************************
LIBRARIES
*****************************************************************************/

#include "types.h"

/*****************************************************************************
CONSTANTS DEFINITION
*****************************************************************************/

/*****************************************************************************
ERRORS DEFINITION
*****************************************************************************/

/*****************************************************************************
DATA TYPES DEFINITION
*****************************************************************************/

typedef struct
{
    pv Head;
    pv Tail;
    uc Size;
}T_LIST_HANDLER, * T_LIST_HANDLER_PTR;

typedef struct
{
    pv Data;
    pv Next;
    uc Position;
}T_LIST_ELEMENT, * T_LIST_ELEMENT_PTR;

/*****************************************************************************
FUNCTIONS DEFINITION
*****************************************************************************/

v List_Create(T_LIST_HANDLER_PTR List);
T_LIST_HANDLER_PTR List_CreateDynamic(v);
v List_Add(T_LIST_HANDLER_PTR List, T_LIST_ELEMENT_PTR Element, pv Data);
v List_AddDynamic(T_LIST_HANDLER_PTR List, pv Data);
pv List_Top(T_LIST_HANDLER_PTR List);
pv List_Get(T_LIST_HANDLER_PTR List, uc Position);
pv List_GetDynamic(T_LIST_HANDLER_PTR List, uc Position);
uc List_GetCount(T_LIST_HANDLER_PTR List);
v List_Destroy(T_LIST_HANDLER_PTR List);



#endif /* LIST_H_ */
