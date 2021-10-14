/*
 * ArrayEmployees.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Joa
 */

#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"
#include "utn_pedirTipo.h"
#include "ArrayEmployees.h"
#define LIBRE 1
#define OCUPADO 0
#define MAX_ARRAY 51
//PROTOTIPOS STATICS:

static int GenerarIdNuevo(void);


//__________________________________________________________________________________________________________________________________
//CODIGOS:
//__________________________________________________________________________________________________________________________________



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PRIMER PASO:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que inicializa el array de entidad y modifica el campo ISEMPTY en 1, que significa que esta libre para usar.
* \ param puntero del array entidad.
* * \ param tamaño del puntero array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int utn_initEmployees(Employee* list, int len)
{
	int estado= -1;

	int i;

	if(list!=NULL && len>0)
	{
		estado=0;

		for(i=0;i<len;i++)
		{
			list[i].isEmpty=LIBRE; //libre
		}
	}

	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ALTA:[findEmpty,addEmployee(con arrayList[return de findEmpty],GenerarIdNuevo(dentro del ADD) LISTO LISTO PEOLA
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que busca, a traves de un for que recorre el array de entidad, las posiciones ISEMPTY iguales a 1 (libres)
* \ param puntero del array entidad.
* * \ param tamaño del puntero array entidad.
* \ return retorna[-1]ERROR o la direccion de memoria del primer array con posicion libre que encuentre.
*/

int utn_findEmpty(Employee list[],int len)
{
	int i;
	int indexLibre=-1;
if (list!=NULL && len>0)
{
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty==LIBRE)//vacio
		{
			indexLibre =i;
			break;
		}
	}
 }
	return indexLibre; //retorno la posicion libre
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que le pide los datos al usuario y los carga, mediante auxiliares que si pasan el testeo y dan todo OK, se igualan a los campos reales del puntero ARRAY entidad.
* \ param puntero del array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int utn_addEmployee(Employee* list)
{
	int retorno=-1;
	float auxSalary;
	int auxSector;
	char auxName[MAX_ARRAY];
	char auxLastName[MAX_ARRAY];

	if(list!=NULL)
		{
			if(utn_pedirTexto(auxName, MAX_ARRAY,3, "Ingrese se nombre\n", "Error\n")==0)
			{
				if(utn_pedirTexto(auxLastName,MAX_ARRAY,3,"ingrese su apellido\n ","error")==0)
				{
					if(utn_pedirFloat(&auxSalary,1,200000,3,"ingrese su sueldo\n","error\n" )==0)
					{
						if(utn_pedirInt(&auxSector,1,150,3,"Ingrese su sector\n","error\n")==0)
						{
							list->salary = auxSalary;
							list->sector =auxSector;
							list->id=GenerarIdNuevo();
							strncpy(list->name,auxName,sizeof(list->name));
							strncpy(list->lastName,auxLastName,sizeof(list->lastName));
							list->isEmpty=0;
							retorno=0; // bien
						}
					}
				}
			}
		}
	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que genera mediante un contador que incrementa, un ID nuevo y unico.
* \ param VOID
* \ return retorna el valor del contador (el id)
*/

static int GenerarIdNuevo(void)
{
	static int contador=0;

	return contador++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//3 MODIFICACION [utn_imprimirPantalla, pedirID(utn_pedirInt), utn_findEmployeeById, utn_menu(subMenu Switch para elegir que campo modificar),ADDEmployee, utn_imprimirPantalla]
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que imprime las posiciones del array que ESTEN OCUPADAS, osea que su ISEMPTY sea igual a 0.
* \ param puntero del array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int utn_imprimirEmpleados(Employee* pList)
{
	int estado;

	if(pList->isEmpty ==OCUPADO)
	{
		printf("\n ID: %d-  NOMBRE: %s-  APELLIDO: %s-  SECTOR: %d-  SALARIO: %f-  \n",pList->id,pList->name,pList->lastName,pList->sector,pList->salary);

		estado = 0;
	}
	else
	{
		estado = -1;
	}
	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que, mediante la funcion input de pedir INT, le pide un ID al usuario, el cual luego, mediante otra funcion, buscara a un cliente con ese ID ingresado.
* \ param puntero del id donde quiero guardar el ID que ingrese el usuario.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int utn_pedirIdAlUsuario(int* id)
{
	int idAux;
	int estado=-1;

	if(utn_pedirInt(&idAux,0,1000,3,"ingrese el ID a buscar\n","ERROR\n")==0)
	{
		estado=0;
		*id=idAux;
	}
	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que busca un empleado especifico dentro del array mediante su campo de ID ingresado en la funcion de pedir id al usuario.
* \ param puntero del array entidad.
* \ param tamaño del array.
* \param id que ingreso el usuario en la anterior funcion.
* \ return retorna[-1]ERROR o RETORNA EL INDICE de donde el for encontro al id que coincide con el id del campo del array entidad.
*/

int utn_findEmployeeById(Employee* pList, int len, int id)
{
	int estado= -1;
	int i;

	if(pList!=NULL && len>0 && id>0)
	{
		for(i=0;i<len;i++)
		{
			if(pList[i].id==id && pList[i].isEmpty==OCUPADO)
			{
				estado = i; //igualo el estado a la posicion donde se encontro el ID y despues lo retorno.
				break;
			}
		}
	}
	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//BAJA:[utn_imprimirPantalla, PedirId(utn_pedirInt), utn_findEmployeeById, funcionBajaLogica, utn_imprimirPantalla]
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que realiza la baja de un empleado, accediendo a su indice mediante la igualacion del ID de la funcion findEmployeeById, y le cambia al campo ISEMPTY el valor a 1 (libre nuevamente)
* \ param puntero del array entidad.
* * \ param tamaño del array entidad.
* * \ param id ingresado por el usuario para buscar al cliente a dar de baja.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int utn_removeEmployee(Employee* list, int len, int id)
{
	int estado= -1;

	int indiceDelIdEncontrado;

	indiceDelIdEncontrado = utn_findEmployeeById(list,len,id);

	if(indiceDelIdEncontrado!=-1)
	{
		estado=0;

		list[indiceDelIdEncontrado].isEmpty=1; //vacio
	}
	else
	{
		puts("error al buscar el ID");
	}

	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AUXILIARES:
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que ORDENA a los empleados dados de ALTA en el array, segun su apellido y/o (en caso de que coincida el apellido) por su sector, mediante la funcion "strncmp" y el swap correspondiente segun la condicion.
* \ param puntero del array entidad.
* * \ param tamaño del array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int utn_sortEmployees(Employee* list, int limiteLen)
{
		int estado= -1;
		Employee listAux;
		int auxComt;
		int flagSwap;
		if(list != NULL && limiteLen>=0)

			do
			{
				flagSwap=0;

				for(int i=0; i<(limiteLen-1); i++)
				{
					auxComt = strncmp(list[i].lastName, list[i+1].lastName, MAX_ARRAY);

					if(auxComt > 0 ||(auxComt==0 && list[i].sector < list[i+1].sector))
					{
						flagSwap = 1; //cambio

						listAux = list[i]; //guardo el valor a cambiar

						list[i] = list[i+1]; //hago el cambio

						list[i+1] = listAux; //2da parte del cambio

						estado=0; //OK
					}
				}

				limiteLen--;

			}while(flagSwap);

		return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  \ brief funcion que: acumula el salario total de los empleados, calcula el promedio de esos salarios, y calcula que salario supera el promedio calculado.
* \ param puntero del array entidad.
* * \ param tamaño del array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int utn_promedioSalarios(Employee* list, int len)
{
	int estado=-1;

	 int contadorDeSalarios=0;
	 float acumuladorDeSalarios=0;
	 float promedio=0;
	 int contadorAdinerados=0;

	 if(list != NULL && len>=0)
	 {
		 for(int i=0; i<len; i++)
		 {
			 if(list[i].isEmpty==OCUPADO)
			 {
				contadorDeSalarios++;
				acumuladorDeSalarios=acumuladorDeSalarios+list[i].salary;
				estado=0; //OK
			 }
		 }
	 }

	 promedio=acumuladorDeSalarios / contadorDeSalarios; //una vez cargado el promedio, pregunto por los salarios que lo superen.

	 for(int e=0; e < len ; e++)
	 {

		 if(list[e].salary > promedio && list[e].isEmpty==OCUPADO)
	 				{
	 					contadorAdinerados++;
	 				}
	 }

	 printf("\nEl total de salarios es: %f\n",acumuladorDeSalarios);
	 printf("\nEl promedio de salarios es: %f\n",promedio);
	 printf("\nla cantidad de empleados que tienen un salario que supera el promedio es de: %d\n\n",contadorAdinerados);

	return estado;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
