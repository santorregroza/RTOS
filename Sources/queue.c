/*
 * Queue.c
 *
 *  Created on: Sep 2, 2017
 *      Author: envy
 */

/*****************************************************************************
******************************************************************************
*
*   INCLUSION DE LIBRERIRAS 
*
******************************************************************************
*****************************************************************************/

#include "Queue.h"

/*****************************************************************************
******************************************************************************
*
*   DEFINICION DE CONSTANTES INTERNAS DEL MODULO
*
******************************************************************************
*****************************************************************************/

/*****************************************************************************
******************************************************************************
*
*   DEFINICION DE TIPOS DE DATOS INTERNOS DEL MODULO
*
******************************************************************************
*****************************************************************************/

/*****************************************************************************
******************************************************************************
*
*   DEFINICION DE FUNCIONES INTERNAS DEL MODULO
*
******************************************************************************
*****************************************************************************/

/*****************************************************************************
******************************************************************************
*
*   DEFINICION DE VARIABLES GLOBALES INTERNAS DEL MODULO
*
******************************************************************************
*****************************************************************************/

/*****************************************************************************
******************************************************************************
##############################################################################
#
#   IMPLEMENTACION DE FUNCIONES EXTARNAS DEL MODULO
#
##############################################################################
******************************************************************************
*****************************************************************************/

/*****************************************************************************
*
*   Nombre      : 
*   Descripcion : 
*                 
*
*   Parametros  :
*       Ninguno.
*
*   Retorno     :
*       Ninguno.
*
*****************************************************************************/

v Queue_Create(T_QUEUE_HANDLER_PTR Queue)
{
	if(Queue != NULL)
	{
		Queue->Cabeza = NULL;
		Queue->Cola = NULL;
		Queue->Tama = 0;
	}
}

/*****************************************************************************
*
*   Nombre      : 
*   Descripcion : 
*                 
*
*   Parametros  :
*       Ninguno.
*
*   Retorno     :
*       Ninguno.
*
*****************************************************************************/
T_QUEUE_HANDLER_PTR Queue_CreateDinamic(v)
{
	T_QUEUE_HANDLER_PTR pt = (T_QUEUE_HANDLER_PTR)malloc(sizeof(T_QUEUE_HANDLER));
	if(pt != NULL)
	{
		Queue_Create(pt);
	}
	return pt;
}

/*****************************************************************************
*
*   Nombre      : 
*   Descripcion : 
*                 
*
*   Parametros  :v Queue_Add(T_QUEUE_HANDLER_PTR Queue, T_QUEUE_ELEMENT_PTR Element, pv Data)
*       Ninguno.
*
*   Retorno     :
*       Ninguno.
*
*****************************************************************************/

v Queue_Add(T_QUEUE_HANDLER_PTR Queue, T_QUEUE_ELEMENT_PTR Element, pv Data)
{
	if((Queue != NULL) && (Element != NULL))
	{
		Element->Next = NULL;
		Element->Data = Data;
		if(Queue->Cola == NULL)
		{
			Queue->Cabeza = Element;
			Queue->Cola = Element;
		}
		else
		{
			((T_QUEUE_ELEMENT_PTR)(Queue->Cola))->Next = Element;
			Queue->Cola = Element;
		}
		Queue->Tama++;
	}
}

/*****************************************************************************
*
*   Nombre      : 
*   Descripcion : 
*                 
*
*   Parametros  :
*       Ninguno.
*
*   Retorno     :
*       Ninguno.
*
*****************************************************************************/

v Queue_AddDinamic(T_QUEUE_HANDLER_PTR Queue, pv Data)
{
	T_QUEUE_ELEMENT_PTR Element;
	if(Queue != NULL)
	{
		Element = (T_QUEUE_ELEMENT_PTR)malloc(sizeof(T_QUEUE_ELEMNT));
		if(Element != NULL)
		{
			Queue_Add(Queue, Element, Data);
		}
	}
}

/*****************************************************************************
*
*   Nombre      : 
*   Descripcion : 
*                 
*
*   Parametros  :
*       Ninguno.
*
*   Retorno     :
*       Ninguno.
*
*****************************************************************************/

pv Queue_Top(T_QUEUE_HANDLER_PTR Queue)
{
	pv Data = NULL;
	if(Queue != NULL)
	{
		if(Queue->Cabeza != NULL)
		{
			Data = ((T_QUEUE_ELEMENT_PTR)(Queue->Cabeza))->Data;
		}
	}
	return Data;
}

/*****************************************************************************
*
*   Nombre      : 
*   Descripcion : 
*                 
*
*   Parametros  :
*       Ninguno.
*
*   Retorno     :
*       Ninguno.
*
*****************************************************************************/

pv Queue_Get(T_QUEUE_HANDLER_PTR Queue)
{
	pv Data = NULL;
	if(Queue != NULL)
	{
		if(Queue->Cabeza != NULL)
		{
			Data = ((T_QUEUE_ELEMENT_PTR)(Queue->Cabeza))->Data;
			Queue->Cabeza = ((T_QUEUE_ELEMENT_PTR)(Queue->Cabeza))->Next;
			Queue->Tama--;
			if(Queue->Cabeza == NULL)
			{
				Queue->Cola = NULL;
				Queue->Tama = 0;
			}
		}
	}
	return Data;
}

/*****************************************************************************
*
*   Nombre      : 
*   Descripcion : 
*                 
*
*   Parametros  :
*       Ninguno.
*
*   Retorno     :
*       Ninguno.
*
*****************************************************************************/

pv Queue_GetDinamic(T_QUEUE_HANDLER_PTR Queue){
	pv Data = NULL;
	T_QUEUE_ELEMENT_PTR Element;
	if(Queue != NULL)
	{
		if(Queue->Cabeza != NULL)
		{
			Element = (T_QUEUE_ELEMENT_PTR)(Queue->Cabeza);
			Data = Element->Data;
			Queue->Cabeza = Element->Next;
			Queue->Tama--;
			if(Queue->Cabeza == NULL)
			{
				Queue->Cola = NULL;
				Queue->Tama = 0;
			}
			free(Element);
		}
	}
	return Data;
}

/*****************************************************************************
*
*   Nombre      : 
*   Descripcion : 
*                 
*
*   Parametros  :
*       Ninguno.
*
*   Retorno     :
*       Ninguno.
*
*****************************************************************************/

u16 Queue_GetCount(T_QUEUE_HANDLER_PTR Queue)
{
	if(Queue != NULL)
	{
		return Queue->Tama;
	}
	return 0;
}

