/*
 * ArrayEmployees.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Joa
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"
#include "utn_pedirTipo.h"
#include "menu.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ESTRUCTURAS:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//Tengo un error en el menu.c a la hora de crear la entidad " struct Employee", si la creo en este ArrayEmployees.h me tira error en el menu.c, pero si la coloco en el menu.h no me tira mas error !!!???

//por eso defini la struct en el menu.h !!! (perdon)


//__________________________________________________________________________________________________________________________________
//PROTOTIPOS:
//__________________________________________________________________________________________________________________________________


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ALTA:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_initEmployees(Employee* list, int len);


int utn_addEmployee(Employee* list);


int utn_findEmpty(Employee list[],int len);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//MODIFICACION:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_imprimirEmpleados(Employee* pList);

int utn_pedirIdAlUsuario(int* id);

int utn_findEmployeeById(Employee* pList, int len,int id);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//BAJA:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_removeEmployee(Employee* list, int len, int id);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_sortEmployees(Employee* list, int limiteLen);

int utn_promedioSalarios(Employee* list, int len);




#endif /* ARRAYEMPLOYEES_H_ */
