
#include "Employee.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//ABM:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Employee* employee_new()
{
	Employee* punteroAuxEmployee=(Employee*)malloc(sizeof(Employee));

	return punteroAuxEmployee;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{

	Employee* punteroAuxEmployee;

	if(esNumerica(idStr)==0 && nombreStr!=NULL && esNumerica(horasTrabajadasStr)==0 && esNumerica(sueldoStr)==0)
	{
		int auxId;
		int auxHorasTrabajadas;
		int auxSueldo;

		auxId = atoi(idStr);
		auxHorasTrabajadas = atoi(horasTrabajadasStr);
		auxSueldo = atoi(sueldoStr);

		punteroAuxEmployee = employee_new();

		if(punteroAuxEmployee!=NULL)
		{
			if(employee_setId(punteroAuxEmployee, auxId)==0)
			{
				if(employee_setNombre(punteroAuxEmployee, nombreStr)==0)
				{
					if(employee_setHorasTrabajadas(punteroAuxEmployee, auxHorasTrabajadas)==0)
					{
						if(employee_setSueldo(punteroAuxEmployee, auxSueldo)==0)
						{

						}
					}
				}
			}
		}
	}
		return punteroAuxEmployee;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_delete(Employee* this,LinkedList* linkedList,int index)
{

	int estado = -1;

	   if(this != NULL && linkedList != NULL && ll_len(linkedList) > 0 && index >= 0)
	   {
	       free(this);

	       ll_remove(linkedList, index);

	       puts("Empleado eliminado correctamente");

	       estado = 0;
	   }

	   return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_findById(LinkedList* pList,int id)
{
	int retorno=-1;
	int iLargo;
	int i;
	if(id>=0 && pList!=NULL)
	{
		iLargo=ll_len(pList);  //preguntar largo

		for(i=0;i<iLargo;i++)
		{
			Employee* aux=ll_get(pList, i);

			if(id==aux->id)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_generarID(LinkedList* this)
{
	int id;
	int lenList;
	int estado= -1;

	if(this!=NULL)
	{
		lenList = ll_len(this);

		id = lenList ++;

		estado = id;
	}
		return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_imprimirEmpleado(Employee* this)
{
	int estado = -1;

	int id;
	char nombre[268];
	int horasTrabajadas;
	int sueldo;

	if(this!=NULL)
	{
		if(employee_getId(this, &id)==0)
		{
			if(employee_getNombre(this, nombre)==0)
			{
				if(employee_getHorasTrabajadas(this, &horasTrabajadas)==0)
				{
					if(employee_getSueldo(this, &sueldo)==0)
					{
						estado = 0;
						printf("\n ID: %d   -  Nombre: %s  -   Horas trabajadas: %d   -     Sueldo: %d   -\n",id, nombre, horasTrabajadas, sueldo);
					}
				}
			}
		}
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_sortEmployeeForName(void* pElemento1, void* pElemento2)
{
	int valor;

	   Employee* empleado1 = (Employee*) pElemento1;

	   Employee* empleado2 = (Employee*) pElemento2;

	   char auxNombre1[64];
	   char auxNombre2[64];

	   puts("entre en la funcion");

	   if(employee_getNombre(empleado1,auxNombre1)!=-1)
	   {	puts("entre al primer get");
		  if(employee_getNombre(empleado2,auxNombre2)!=-1)
		   {	puts("entre al segundo get"); //NO ENTRA AL SEGUNDO PUTS.
			   valor = strcmp(auxNombre1,auxNombre2);
			   printf("entre al if");
		   }
	   }

	return valor;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SETTERS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_setId(Employee* this,int id)
{
	int estado = -1;

	char auxId[28];

	sprintf (auxId, "%d", id); // sprintf(VARIABLE CHAR DONDE VAS A METER ESE DATOS * , *%D , VARIABLE QUE QUERES TRANSFORMAR);

	if (this != NULL && id >=0)
	{
		if (esNumerica(auxId) == 0)
		{
			estado = 0;

			this->id = atoi(auxId);
		}
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_setNombre(Employee* this,char* nombre)
{
	int estado=-1;

	if(this!=NULL && nombre!=NULL)
	{
		if(esTexto(nombre)==0)
		{
			estado=0;

			strncpy(this->nombre, nombre, NOMBRE_LEN);
		}
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int estado=-1;

	char auxHorasTrabajadas[28];

	sprintf(auxHorasTrabajadas, "%d", horasTrabajadas);

	if(this!=NULL && horasTrabajadas>=0)

		if(esNumerica(auxHorasTrabajadas)==0)
		{
			estado=0;

			this->horasTrabajadas = atoi(auxHorasTrabajadas);
		}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_setSueldo(Employee* this,int sueldo)
{
	int estado=-1;

	char auxSueldo[268];

	sprintf(auxSueldo, "%d", sueldo);

	if(this!=NULL && sueldo>=0)
	{
		if(esNumerica(auxSueldo)==0)
		{
			estado=0;

			this->sueldo = atoi(auxSueldo);
		}
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//GETTERS:
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_getId(Employee* this, int* id)
{
	int estado=-1;

	if(this!=NULL && id!=NULL)
	{
		estado=0;

		*id = this->id;
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_getNombre(Employee* this,char* nombre)
{
	int estado=-1;

	if(this!=NULL && nombre!= NULL)
	{
		estado=0;

		strncpy(nombre, this->nombre, NOMBRE_LEN);
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int estado=-1;

	if(this!=NULL && horasTrabajadas!=NULL)
	{
		estado=0;
		*horasTrabajadas = this->horasTrabajadas;
	}

	return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int employee_getSueldo(Employee* this,int* sueldo)
{
	int estado = -1;

	if (this != NULL && sueldo != NULL)
	{
		estado = 0;
		*sueldo = this->sueldo;
	}

		return estado;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

