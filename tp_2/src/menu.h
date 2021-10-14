/*
 * menu.h
 *
 *  Created on: 12 oct. 2021
 *      Author: Joa
 */

#ifndef MENU_H_
#define MENU_H_
#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"
#include "utn_pedirTipo.h"
#include "ArrayEmployees.h"
#define LIBRE 1
#define OCUPADO 0
#define MAX_ARRAY 51

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

void utn_modificarMenu(Employee* list , int len);

int utn_modificarOpciones(Employee* list);

int utn_mainMenu(Employee* list, int len);

#endif /* MENU_H_ */
