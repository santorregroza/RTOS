/*
 * list.c
 *
 *  Created on: Nov 19, 2017
 *      Author: envy
 */
/*
 * lists.c
 *
 *  Created on: Oct 7, 2017
 *      Author: Santiago
 */


/*****************************************************************************
LIBRARIES
*****************************************************************************/

#include "List.h"

/*****************************************************************************
CONSTANTS DEFINITION
*****************************************************************************/

/*****************************************************************************
DATA TYPES DEFINITION
*****************************************************************************/

/*****************************************************************************
FUNCTIONS DEFINITION
*****************************************************************************/

/*****************************************************************************
GLOBAL VARIABLES DEFINITION
*****************************************************************************/

/*****************************************************************************
##############################################################################
FUNCTIONS IMPLEMENTATION
##############################################################################
*****************************************************************************/

/*****************************************************************************
 * Create a list statically
*****************************************************************************/

v List_Create(T_LIST_HANDLER_PTR List)
{
    if(List != NULL)
    {
        List->Head = NULL;
        List->Size = 0;
    }
}

/*****************************************************************************
 * Create a list dynamically
*****************************************************************************/

T_LIST_HANDLER_PTR List_CreateDynamic(v)
{
    T_LIST_HANDLER_PTR pt = (T_LIST_HANDLER_PTR)malloc(sizeof(T_LIST_HANDLER));
    if(pt != NULL)
    {
        List_Create(pt);
    }
    return pt;
}

/*****************************************************************************
 * Add element to the list statically
*****************************************************************************/

v List_Add(T_LIST_HANDLER_PTR List, T_LIST_ELEMENT_PTR Element, pv Data)
{
    if((List != NULL) && (Element != NULL))
    {
        Element->Next = NULL;
        Element->Data = Data;
        
        if(List->Head == NULL)
        {
            List->Head = Element;
            List->Tail = Element;
            Element->Position = 1;
        }
        else
        {
            ((T_LIST_ELEMENT_PTR)(List->Tail))->Next = Element;
            List->Tail = Element;
            Element->Position++;
        }
        List->Size++;
    }
}

/*****************************************************************************
 * Add element to the list dynamically
*****************************************************************************/

v List_AddDynamic(T_LIST_HANDLER_PTR List, pv Data)
{
    T_LIST_ELEMENT_PTR Element;
    if(List != NULL)
    {
        Element = (T_LIST_ELEMENT_PTR)malloc(sizeof(T_LIST_ELEMENT));
        if(Element != NULL)
        {
            List_Add(List, Element, Data);
        }
    }
}

/*****************************************************************************
 * See element on top of the list
*****************************************************************************/

pv List_Top(T_LIST_HANDLER_PTR List)
{
    pv Data = NULL;
    if(List != NULL)
    {
        if(List->Head != NULL)
        {
            Data = ((T_LIST_ELEMENT_PTR)(List->Head))->Data;
        }
    }
    return Data;
}

/*****************************************************************************
 * Retrieve and delete element in any place in the list
*****************************************************************************/

pv List_Get(T_LIST_HANDLER_PTR List, uc Position)
{
    pv Data = NULL;
    pv Current = NULL;
    uc cont = 0;

    if (Position < 0){
        return Data;
    }

    if(List != NULL)
    {
        if(List->Head != NULL && Position !=0 &&  Position > List->Size)                                             //POSICIÓN EMPIEZA EN 1 Asociado a Size
        {
            Current = List->Head;
            if (Position == 1){                                                                                      //Caso especial para cuando solo se quiere acceder al primer elemento en la lista
                Data = ((T_LIST_ELEMENT_PTR)Current)->Data;                                                          //Asignar a Data el dato en el elemento 1
                List->Head = ((T_LIST_ELEMENT_PTR)Current)->Next;                                                    //A la cabeza de la lista se le asigna el elemento siguiente
                List->Size--;
            }
            else{
                for (cont = 1; cont < Position - 1; cont++){
                    Current = ((T_LIST_ELEMENT_PTR)Current)->Next;                                                   //Recorrer la lista desde el elemento 1 hasta el elemento anterior a la posición solicitada
                }
                Data = ((T_LIST_ELEMENT_PTR)((T_LIST_ELEMENT_PTR)Current)->Next)->Data;                              //A Data se asigna el dato del elemento siguiente al último elemento que se recorrió en la lista
                ((T_LIST_ELEMENT_PTR)Current)->Next = ((T_LIST_ELEMENT_PTR)((T_LIST_ELEMENT_PTR)Current)->Next)->Next;
                List->Size--;
            }
            if(List->Head == NULL)
            {
                List->Size = 0;
            }
        }
    }
    return Data;
}

/*****************************************************************************
 * Retrieve and delete element in any place in the list, and free memory
*****************************************************************************/

pv List_GetDynamic(T_LIST_HANDLER_PTR List, uc Position)
{
    pv Data = NULL;
    T_LIST_ELEMENT_PTR Current;
    T_LIST_ELEMENT_PTR Elemento;
    uc cont = 0;

    if (Position < 0){
        return Data;
    }

    if(List != NULL)
    {
        if(List->Head != NULL && Position !=0 &&  Position > List->Size)                                             //POSICIÓN EMPIEZA EN 1 Asociado a Size
        {
            Current = (T_LIST_ELEMENT_PTR)(List->Head);
            if (Position == 1){                                                                                      //Caso especial para cuando solo se quiere acceder al primer elemento en la lista
                Data = Current->Data;                                                                                //Asignar a Data el dato en el elemento 1
                List->Head = Current->Next;                                                                          //A la cabeza de la lista se le asigna el elemento siguiente
                List->Size--;
                free(Current);
            }
            else{
                for (cont = 1; cont < Position - 1; cont++){
                    Current = Current->Next;                                                                         //Recorrer la lista desde el elemento 1 hasta el elemento anterior a la posición solicitada
                }
                //***
                Data = ((T_LIST_ELEMENT_PTR)(Current->Next))->Data;                                                  //A Data se asigna el dato del elemento siguiente al último elemento que se recorrió en la lista
                Elemento = Current;
                Current->Next = ((T_LIST_ELEMENT_PTR)(Current->Next))->Next;
                List->Size--;
                free((T_LIST_ELEMENT_PTR)(Elemento->Next));
            }
            if(List->Head == NULL)
            {
                List->Size = 0;
            }
        }
    }
    return Data;
}

/*****************************************************************************
 * Retrieve list size
*****************************************************************************/

uc List_GetCount(T_LIST_HANDLER_PTR List)
{
    if(List != NULL)
    {
        return List->Size;
    }
    return 0;
}

