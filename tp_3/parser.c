#include <stdio.h>
#include <stdlib.h>

#include "parser.h"



/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int estado = -1;

	char idAux[168];
	char nombreAux[268];
	char horasTrabajadasAux[168];
	char sueldoAux[168];

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
	                   // 1 , Lou , 120 , 10000\n
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux);  //PÁRA LEER LA PRIMERA LINEA.

		do{

			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux)>3)
			{
				Employee* pEmpleado = employee_newParametros(idAux, nombreAux, horasTrabajadasAux, sueldoAux);

				if(pEmpleado!=NULL)
				{
					ll_add(pArrayListEmployee, pEmpleado);
					//puts("estoy en el bucle");
					estado = 0;
					//break; //DEJO EL BREAK XQ SE BUGEA Y NUNCA TERMINA EL BUCLE DOWHILE, EL FEOF NUNCA SE CUMPLE Y ANTES FUNCIONABA.
				}
				else
				{
					estado=-1;
					break;
				}
			}

		}while(!feof(pFile));

		puts("sali del bucle");
	}

    return estado;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	    int estado = -1;

		Employee* auxpEmployee;

		if (pFile != NULL && pArrayListEmployee != NULL)
		{
			do
			{
				auxpEmployee = employee_new();

				if (auxpEmployee != NULL)
				{
						if (fread (auxpEmployee, sizeof (Employee),1,pFile)==1)
						{
							ll_add(pArrayListEmployee, auxpEmployee);

							estado = 0;
						}
						else
						{
							estado=-1;
							break;
						}
				}

			}while (feof (pFile)==0);
		}

	    return estado;;
	}


