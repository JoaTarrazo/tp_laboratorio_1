/*
 ============================================================================
 Name        : TP_2.c
 Author      : Joaquin Tarrazo
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico N°:2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"
#include "utn_pedirTipo.h"
#include "ArrayEmployees.h"
#include "menu.h"
#define LEN_LIST 1000

int main(void)
{
	setbuf(stdout, NULL);

Employee arrayList[LEN_LIST]; //ARRAY LIST PRINCIPAL.

utn_initEmployees(arrayList, LEN_LIST);

if(utn_mainMenu(arrayList , LEN_LIST)!=0)
{
	puts("ERROR, por favor, revise los datos ingresados!");
}

	return EXIT_SUCCESS;
}


/*int lugarLibre;

utn_menu(arrayList, LEN_LIST); //opciones: 1, 2 , 3 y 4

opcion 1: ALTA:

 lugarLibre= utn_findEmpty(arrayList, LEN_LIST);

 if(lugarLibre!=-1)
{
	utn_addEmployee(&arrayList[lugarLibre]);
}

*/
