#include "Controller.h"


static int modificarHorasTrabajadas (int* pCantidadHorasTrabajadas);

static int modificarSueldo (int* pSueldo);

static int modificarNombre (char pNombre[]);

static int opcionAModificar (int* opcion);

//static int GenerarIdNuevo(void);



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int estado = -1;

    FILE* pFile = fopen(path,"r");

    if(pFile!=NULL)
    {
    	if(parser_EmployeeFromText(pFile, pArrayListEmployee)==0)
    	{
    		estado = 0;
    	}
    	else
    	{
    		puts("error al cargar el archivo en modo TEXTO\n");
    	}

    	fclose(pFile);
    }

	return estado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	{
	    int estado = -1;

	    FILE* pFile = fopen(path,"rb");

	    if(pFile!=NULL)
	    {
	    	if(parser_EmployeeFromBinary(pFile, pArrayListEmployee)==0)
	    	{
	    		estado = 0;
	    	}
	    	else
	    	{
	    		puts("error al cargar el archivo en modo TEXTO\n");
	    	}

	    	fclose(pFile);
	    }

		return estado;
	}
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int estado= -1;
	char nombreAux[256];
	char id[68];
	char horasAux[68];
	char sueldoAux[68];

	int idInt;
	int horasInt;
	int sueldoInt;

	Employee* nuevoEmpleado;

	if(pArrayListEmployee!=NULL)
	{
			if(utn_pedirTexto(nombreAux, 256, 3, "Ingrese en nombre del nuevo Empleado\n", "Error al ingresar el nombre\n")==0)
			{
				if(utn_pedirInt(&horasInt, 1, 10000, 3, "Ingrese horas trabajadas del empleado\n", "Error al ingresar las horas\n")==0)
				{
					if(utn_pedirInt(&sueldoInt, 100, 1000000, 3, "Ingrese el sueldo el empleado: (min 100 / max 1000000)\n", "Error al ingresar el monto del sueldo\n")==0)
					{
						idInt = employee_generarID(pArrayListEmployee);

						if(idInt != -1)
						{
							sprintf(id,"%d",idInt);   // sprintf(VARIABLE CHAR DONDE VAS A METER ESE DATOS * , *%D , VARIABLE QUE QUERES TRANSFORMAR);

							sprintf(horasAux,"%d",horasInt);

							sprintf(sueldoAux,"%d",sueldoInt);

							nuevoEmpleado = employee_newParametros(id,nombreAux,horasAux,sueldoAux); //Setea los valores que ingreso el usuario en un nuevo Empleado.

							if(nuevoEmpleado!=NULL)
							{
								ll_add(pArrayListEmployee, nuevoEmpleado);  //lo agrego en la linkedList.

								estado=0;
							}
						}
					}
				}
			}
	}

	return estado;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
	{
	    int estado = -1;

	    int idIngresado;
	    int opcionElegida;

	    char auxNombre[268];
	    int auxHorasTrabajadas;
	    int auxSueldo;

	    Employee* empleadoAux;

	    if (pArrayListEmployee != NULL)
	    {
	    	if (utn_pedirInt(&idIngresado,0,1500, 3, "Ingrese el ID del empleado que desea modificar\n", "Error al ingresar el ID buscado\n.")==0)
	    	{
	    		if (employee_findById(pArrayListEmployee,idIngresado) != -1)
	    		{
	    			printf("id es: %d\n",idIngresado);

	    			empleadoAux = ll_get(pArrayListEmployee, idIngresado); //obtengo la direccion de memoria del empleado buscado y la guardo en empleadoAux (Employee*)

	    			if (opcionAModificar(&opcionElegida)==0)
						{
							switch (opcionElegida)
							{
								case 1:

									if (modificarNombre(auxNombre)==0)
									{
										if(employee_setNombre(empleadoAux, auxNombre)==0)
										{
											estado=0;
										}
									}

									break;

								case 2:

									if (modificarHorasTrabajadas(&auxHorasTrabajadas)==0)
									{
										if(employee_setHorasTrabajadas(empleadoAux, auxHorasTrabajadas)==0)
										{
											estado=0;
										}
									}

									break;

								case 3:

									if (modificarSueldo(&auxSueldo)==0)
									{
										if(employee_setSueldo(empleadoAux, auxSueldo)==0)
										{
											estado=0;
										}
									}

									break;

							}//fin del switch
						}//fin del if opcion
				}
	    	}
	    }
		return estado;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

	    int estado = -1;

	    int idElegido;

	    Employee* auxEmployee;

	    if(pArrayListEmployee != NULL)
	    {
	        idElegido = utn_pedirInt(&idElegido, 0, 1500, 3, "\n Escoja el id del empleado a ELIMINAR\n", "\n error al escojer un ID valido\n");

	       int indexEncontrado = employee_findById(pArrayListEmployee, idElegido);

	        if(indexEncontrado != -1)
	        {
	        	auxEmployee = ll_get(pArrayListEmployee, indexEncontrado);

	            employee_delete(auxEmployee, pArrayListEmployee, indexEncontrado);

	            estado = 0;
	        }
	    }

	    return estado;
	}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int estado = -1;

	Employee* auxEmploye;

	if(pArrayListEmployee!=NULL)
	{
		int lenList = ll_len(pArrayListEmployee);

		for(int i=0; i<lenList; i++)
		{
			auxEmploye = ll_get(pArrayListEmployee, i);

			if(employee_imprimirEmpleado(auxEmploye)==0)
			{
				estado = 0;
			}
		}
	}

    return estado;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

//int controller_sortEmployee(LinkedList* pArrayListEmployee)
// {

int controller_sortEmployeeForName(void* pElemento1, void* pElemento2)
{
	   Employee* empleado1 = (Employee*) pElemento1;

	   Employee* empleado2 = (Employee*) pElemento2;

	   char auxNombre1[64];

	   employee_getNombre(empleado1,auxNombre1);

	   char auxNombre2[64];

	   employee_getNombre(empleado2,auxNombre2);

	   int retornoCompare = strcmp(auxNombre1,auxNombre2);

	   if(retornoCompare>0)
	   {
	       return 1; //De mayor a menor.
	   }
	   else if(retornoCompare==0)
	   {
	       return 0; //si son iguales.
	   }
	   else
	   {
	       return -1; //de menor a mayor.
	   }
	}

// }

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
 {

	Employee* pEmpleadoAux;
	int idAux;
	char nombreAux[NOMBRE_LEN];
	int horasAux;
	int sueldoAux;

	int estado=-1;

	FILE* f = fopen(path,"w");

	if(f!=NULL)
	{
		fprintf(f,"id, nombre, horasTrabajadas, sueldo\n");

		for(int i=0; i<ll_len(pArrayListEmployee); i++)
		{
			pEmpleadoAux = ll_get(pArrayListEmployee,i);

			if(pEmpleadoAux!=NULL)
			{
				employee_getId(pEmpleadoAux,&idAux);

				employee_getNombre(pEmpleadoAux,nombreAux);

				employee_getHorasTrabajadas(pEmpleadoAux,&horasAux);

				employee_getSueldo(pEmpleadoAux,&sueldoAux);

				fprintf(f,"%d,%s,%d,%d\n",idAux,nombreAux,horasAux,sueldoAux);

				estado=0;
			}
		}
			fclose(f);
	}
		return estado;
 }

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int estado = -1;

	   if(pArrayListEmployee!=NULL && path!=NULL)
	   {
		   FILE* pFile = fopen(path,"w");

		   if(pFile!=NULL)
		   {
			   estado=0;

			   for(int i=0; i<ll_len(pArrayListEmployee); i++)
			   {
				   fwrite(pArrayListEmployee,sizeof(Employee),1,pFile);
			   }
		   }
		   	   fclose(pFile);
	   }

		return estado;
}




//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//EXTRAS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int opcionAModificar (int* opcion)
{
	int estado = -1;

	int opcionElegida;

	puts("A continuacion, debe escoger que campo desea modificar:\n");
	puts("1. Nombre del empleado:");
	puts("2. Horas trabajadas del empleado.");
	puts("3. Sueldo del empleado.");

	if (utn_pedirInt(&opcionElegida,1,3,3, "\nSeleccion una opcion para modificar:\n", "Error al escojer la opcion")==0)
	{
		 *opcion = opcionElegida; //igualo la opcion que eligieron a la opcion Puntero que voy a mandar.

		 estado = 0;
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


static int modificarNombre (char pNombre[])
{
	int estado = -1;

	char auxNombre[268];

	if (utn_pedirTexto(auxNombre, 268, 3, "Ingrese el nuevo nombre a modificar:\n", "Error al ingresar el nuevo nombre") == 0)
	{
		puts("entre a modificar nombre pedir texto");
		estado = 0;

		strncpy(pNombre, auxNombre, 268);
	}
	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int modificarSueldo (int* pSueldo)
{
	int estado = -1;

	int auxSalario;

	if (utn_pedirInt(&auxSalario,1,100000,3, "Ingrese el nuevo sueldo del empleado:\n", "Error al ingresar el sueldo\n")== 0)
	{
		estado = 0;

		*pSueldo = auxSalario;
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static int modificarHorasTrabajadas (int* horasTrabajadas)
{
	int estado = -1;

	int horasTrabajadasAux;

	if (utn_pedirInt(&horasTrabajadasAux,0, 10000,3, "Ingrese la cantidad de horas trabajadas\n", "Error al ingresar las horas\n")== 0)
	{
		estado = 0;

		*horasTrabajadas = horasTrabajadasAux;
	}
	return estado;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*

 static int GenerarIdNuevo(void)
{
	static int contador=0;

	return contador++;
}

*/
