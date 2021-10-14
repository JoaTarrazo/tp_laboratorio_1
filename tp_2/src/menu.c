/*
 * menu.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Joa
 */
#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include "string.h"
#include "utn_pedirTipo.h"
#include "ArrayEmployees.h"
#include "menu.h"
#define LIBRE 1
#define OCUPADO 0
#define MAX_ARRAY 51
#define LEN_LIST 1000

//PROTOTIPOS STATICS:
static void mostrarCampos (void);
static int selecCampoModificar (int* campoSeleccionado);
static int obtenerSector (int* pEmployeesSector);
static int obtenerSarario (float* pEmployeesSalario);
static int obtenerNombre (char employeesName[]);
static int obtenerApellido (char employeesLastName[]);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/*
  \ brief funcion que engloba las subfunciones para la MODIFICACION: 1. imprime la pantalla, 2. le pide un id al usuario y 3. busca segun su id para luego 4. ingresar a un submenu que pregunta al usuario que campo especifico desea modificar, y por ultimo vuelve a imprimir la pantalla con los cambios realizados.
* \ param puntero del array entidad.
* * \ param tamaño del array entidad.
* \ return VOID
*/
void utn_modificarMenu(Employee* list , int len)
{
	int i;
	for(i=0;i< len ;i++)
	{
		utn_imprimirEmpleados(&list[i]);
	}


	int idElegido; //el id elegido en la funcion pedirIdAlUsuario
	int indexDelId; //indice del array donde esta el ID elegido

	// 1) pedirle al usuario que ingrese un id
	if (utn_pedirIdAlUsuario(&idElegido) == 0)
	{
		// 2) hacer funcion q busque por id (en donde ESTA ocupada la posicion)
		indexDelId = utn_findEmployeeById (list,len,idElegido); // (verificar si LIST lleva &)


				if(indexDelId!=-1)
				{
					//3) llamar a funcion q modifica el sector en especifico
					if(utn_modificarOpciones(&list[indexDelId])==0)
					{
					//4)Mostrar
					utn_imprimirEmpleados(&list[indexDelId]);
					}
				}
				else
				{
					puts("ERROR");
				}

	}
}

/*
  \ brief funcion que realiza, mediante funciones STATIC (para evitar que el cliente deba modificar TODO los campos a la hora de hacer la modificacion) pregunta que campo desea modificar el usuario y lo cambia.
* \ param puntero del array entidad..
* \ return retorna[-1]ERROR o [0]EXITO
*/

int utn_modificarOpciones(Employee* list)
{
	int estado = -1;
	int campoModificado; //1:SECTOR 2:SALARY 3:NAME  4:LASTNAME

	int auxSector;
	float auxSalary;
	char auxName[51];
	char auxLastName[51];

	if (list != NULL)
	{
		if (selecCampoModificar(&campoModificado) == 0)
		{
			estado = 0; //eligio bien entre las opciones 1 y 4
			switch (campoModificado)
			{
				case 1:
					if (obtenerSector(&auxSector) == 0)
					{
						list->sector = auxSector;
					}
					break;
				case 2:
					if (obtenerSarario(&auxSalary) == 0)
					{
						list->salary = auxSalary;
					}
					break;
				case 3:
					if (obtenerNombre(auxName) == 0)
					{
						strncpy(list->name, auxName,sizeof(list->name));
					}
					break;
				case 4:
					if (obtenerApellido(auxLastName) == 0)
					{
						strncpy(list->lastName, auxLastName,sizeof(list->lastName));
					}
					break;
			}
		}
	}
	return estado;
}

/*
  \ brief funcion STATIC que simplemente despliega mediante la subFuncion selecCampoModificar un submenu y le da la opcion al user a elegir cual campo cambiar mediante un getINT.
* \ param puntero que se utiliza para cargar la opcion elegida del usuario hacia fuera de la funcion mediante referencia.
* \ return retorna[-1]ERROR o [0]EXITO
*/
static int selecCampoModificar (int* campoSeleccionado)
{
	int estado = -1;
	int auxCampoSeleccionado;

	mostrarCampos(); //funcion que muestra los campos a modificar:

	if (utn_pedirInt(&auxCampoSeleccionado,1,4,3,"\nElegi una opcion para modificar\n","Error al elegir la opcion") == 0)
	{
		estado = 0;
		*campoSeleccionado = auxCampoSeleccionado;
	}
	else
	{
		puts("Eligio muchas veces una opcion incorrecta, por favor, reintentelo mas tarde");
	}
	return estado;
}

/*
  \ brief funcion STATIC que muestra por printfs un submenu de opciones de campo para modificar posteriormente.
* \ param VOID
* \ return VOID
*/
static void mostrarCampos (void)
{
	printf("\n 1: Sector");
	printf("\n 2: Salario");
	printf("\n 3: Nombre ");
	printf("\n 4: Apellido");
}

/*
  \ brief funcion STATIC que cambia el campo del array entidad SECTOR mediante un getINT.
* \ param puntero del valor ingresado por el usuario para su nuevo sector mediante referencia.
* \ return retorna[-1]ERROR o [0]EXITO
*/
static int obtenerSector (int* pEmployeesSector)
{
	int estado = -1;
	int auxSector;
	if(utn_pedirInt(&auxSector,1,1000,3,"Ingrese su sector","Error") == 0)
	{
		estado = 0;
		*pEmployeesSector = auxSector;
	}
	return estado;
}


/*
  \ brief funcion STATIC que cambia el campo del array entidad SALARY mediante un getINT.
* \ param puntero del valor ingresado por el usuario para su nuevo salario mediante referencia.
* \ return retorna[-1]ERROR o [0]EXITO
*/
static int obtenerSarario (float* pEmployeesSalario)
{
	int estado = -1;
	float auxSalary;

	if (utn_pedirFloat(&auxSalary, 1, 10000, 3,"Ingrese su salario", "Error")== 0)
	{
		estado = 0;
		*pEmployeesSalario = auxSalary;
	}
	return estado;
}
/*
  \ brief funcion STATIC que cambia el campo del array entidad NAME mediante un getINT.
* \ param puntero del valor ingresado por el usuario para su nuevo nombre mediante referencia.
* \ return retorna[-1]ERROR o [0]EXITO
*/
static int obtenerNombre (char employeesName[])
{
	int estado = -1;
	char auxName[51];


	if(utn_pedirTexto(auxName, sizeof(auxName),3, "ingrese su nombre", "Error") == 0)
	{
		estado=0;

		strncpy(employeesName, auxName,51);
	}
	return estado;
}
/*
  \ brief funcion STATIC que cambia el campo del array entidad LAST NAME mediante un getINT.
* \ param puntero del valor ingresado por el usuario para su nuevo lastName mediante referencia.
* \ return retorna[-1]ERROR o [0]EXITO
*/
static int obtenerApellido (char employeesLastName[])
{
	int estado = -1;
	char auxLastName[51];

	if (utn_pedirTexto(auxLastName, sizeof(auxLastName),3,"ingrese su apellido", "Error") == 0)
	{
		estado = 0;
		strncpy(employeesLastName, auxLastName,51);
	}
	return estado;
}

/*
  \ brief funcion PRINCIPAL que, ENGLOBA todas las demas funciones, 1. muestra el menu. 2. pide al usuario que ingrese una opcion. 3. mediante un switch organiza y hace que el programa funcione segun la opcion ingresada por el user.
* \ param puntero del array entidad.
* * \ param tamaño del array entidad.
* \ return retorna[-1]ERROR o [0]EXITO
*/

int utn_mainMenu(Employee* list, int len) //FUNCION PRINCIPAL DEL MENU:
{

	int estado=-1;
	int opcionIngresadaPorUser;

	int flagAlta=-1;

	//int flagModificar=-1;

	//int flagBaja=-1;


	int posicionLibreEncontrada;
	int indexAModificar;
	int idElegidoPorUser;

	int idElegidoPorUserDos;
	int indexABajar;

	do{

		puts("-----BIENVENIDO-----");
		puts("---Sistema de menu: por favor elija una opcion:---");
		puts("1. ALTA de un empleado.");
		puts("2. MODIFICAR un empleado.");
		puts("3. BAJA de un empleado.");
		puts("4. INFORMAR: listado de empleados y promedio de sueldos.");
		puts("5. SALIR.");

		if(utn_pedirInt(&opcionIngresadaPorUser, 1, 5, 3, "Escoja una opcion del menu:\n", "ERROR AL INGRESAR LA OPCION")==0)
		{
			estado=0;

			switch(opcionIngresadaPorUser)
			{
				case 1:

					posicionLibreEncontrada = utn_findEmpty(list,len);

					utn_addEmployee(&list[posicionLibreEncontrada]);

					flagAlta=0;

					break;

				case 2:

				if(flagAlta==0)
				{
						for(int i=0; i<len; i++)
						{
							utn_imprimirEmpleados(&list[i]); //recorro y muestro el array, con & para acceder a la direccion de cada posicion de i.
						}

					if(utn_pedirIdAlUsuario(&idElegidoPorUser)!=-1)
					{
						indexAModificar = utn_findEmployeeById(list, len, idElegidoPorUser);//funcion me retorna el indice a modificar segun su id

							if(indexAModificar!= -1)
							{
								utn_modificarMenu(list , len);

								utn_imprimirEmpleados(&list [indexAModificar]);
							}
					}
				}

					break;

				case 3:

					if(flagAlta==0)
					{
						for(int i=0; i<len;i++)
						{
							utn_imprimirEmpleados(&list[i]);
						}

						if(utn_pedirIdAlUsuario(&idElegidoPorUserDos)!=-1)
						{
							indexABajar = utn_findEmployeeById(list, len, idElegidoPorUserDos);

							if(indexABajar!= -1)
							{
								if(utn_removeEmployee(list, len, indexABajar)!=-1)
								{
									puts("Baja realizada con EXITO");
								}
							}
						}
					}
					break;

				case 4:

					if(flagAlta==0)
					{
						if(utn_sortEmployees(list, len)==0)
						{
							for(int indice=0; indice<len; indice++)
							{
								utn_imprimirEmpleados(&list[indice]);
							}
						}

						if(utn_promedioSalarios(list, len)!=0)
						{
							puts("error, no hay datos para calcular los promedios");
						}
					}

					break;

				case 5:

					puts("bye bye!!");
					break;
			}
		}

		}while(opcionIngresadaPorUser!=5);

	return estado;
}

