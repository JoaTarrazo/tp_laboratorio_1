
#include "menu.h"

//PROTOTIPOS STATICS:



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int menu_mainMenu(LinkedList* list) //FUNCION PRINCIPAL DEL MENU:
{

int opcionIngresadaPorUser;
int estado= -1;

int flagCase1=-1;
int flagCase2=-1;
int flagCase3=-1;

	do{

		puts("\n-------------BIENVENIDO-------------\n");

		puts("\n-----Sistema de menu: por favor elija una opcion:------\n");

		puts("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto). \n");
		puts("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
		puts("3. Alta de empleado.\n");
		puts("4. Modificar datos de empleado.\n");
		puts("5. Baja de empleado\n");
		puts("6. Listar empleados\n");
		puts("7. Ordenar empleados\n");
		puts("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
		puts("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
		puts("10. SALIR\n");

		if(utn_pedirInt(&opcionIngresadaPorUser, 1, 10, 3, "Escoja una opcion del menu:\n", "ERROR AL INGRESAR LA OPCION")==0)
		{
			estado=0;

			switch(opcionIngresadaPorUser)
			{
				case 1:  //1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).

					if(controller_loadFromText("data.csv",list)==0)
					{
						puts("datos cargados desde el archivo en modo TEXTO correctamente");
					}
					else
					{
						puts("error al cargar los datos del archivo en modo TEXTO");
					}

					flagCase1=0;

					break;

				case 2:  //2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).

					if(controller_loadFromBinary("data.bin", list)==0)
					{
						puts("datos cargados desde el archivo en modo BINARIO correctamente");
					}
					else
					{
						puts("error al cargar los datos del archivo en modo BINARIO");
					}

					flagCase2=0;

					break;

				case 3:  //3. Alta de empleado

					if(controller_addEmployee(list)==0)
					{
						puts("Alta realizada con exito");
					}
					else
					{
						puts("Error al hacer el alta de empleado");
					}

					flagCase3=0;

					break;

				case 4: // 4. Modificar datos de empleado

					if(flagCase1 == 0 || flagCase2==0 || flagCase3==0)
					{
						if(controller_editEmployee(list)==0)
						{
							puts("modificacion realizada con exito\n");
						}
						else
						{
							puts("Error al realizar la modificacion de un empleado.\n");
						}
					}
					else
					{
						puts("no hay Empleados para modificar.");
					}

					break;

				case 5: //5. Baja de empleado

					if(flagCase1 == 0 || flagCase2==0 || flagCase3==0)
					{
						if(controller_ListEmployee(list)==0)
						{
							if(controller_removeEmployee(list)==0)
							{
								puts("baja realizada con exito\n");
							}
							else
							{
								puts("error al realizar la baja\n");
							}
						}
					}
					else
					{
						puts("no hay Empleados dar de baja.");
					}

					break;

				case 6: //6. Listar empleados

					if(controller_ListEmployee(list)!=0)
					{
						puts("Error, no hay empleados para listar.\n");
					}

					break;

				case 7:   //7. Ordenar empleados

					if(flagCase1 == 0 || flagCase2==0 || flagCase3==0)  // int lenList = ll_list(list)  if(lenList>0){}
					{
						if(controller_sortEmployeeForName(list)!= -1)
						{
							if(controller_ListEmployee(list)==0)
							{
								puts("Lista ordenada por nombre completada!\n");
							}
						}
						else
						{
							puts("no hay Empleados o modificaciones para ordenar.");
						}
					}

					break;

				case 8:   //8. Guardar los datos de los empleados en el archivo data.csv (modo texto)

					if(flagCase1 == 0 || flagCase2==0 || flagCase3==0)
					{
						if(controller_saveAsText("data.txt", list)==0)
						{
							puts("Empleados guardados en el archivo de forma de TEXTO correctamente");
						}
						else
						{
							puts("Error al guardar el archivo");
						}
					}
					else
					{
						puts("no hay Empleados o modificaciones para guardar en modo TEXTO.");
					}

					break;

				case 9:   //9. Guardar los datos de los empleados en el archivo data.csv (modo binario).

					if(flagCase1 == 0 || flagCase2==0 || flagCase3==0)
					{
						if(controller_saveAsBinary("data.bin", list)==0)
						{
							puts("Empleados guardados en el archivo de forma BINARIA correctamente");
						}
						else
						{
							puts("Error al guardar el archivo");
						}
					}
					else
					{
						puts("no hay Empleados o modificaciones para guardar en modo BINARIO.");
					}

					break;

				case 10:  // bye bye!

					puts("bye byee!\n");
					break;

			}         //final del switch
		}            //final if para elegir opcion

		}while(opcionIngresadaPorUser!=10);

	return estado;
}

