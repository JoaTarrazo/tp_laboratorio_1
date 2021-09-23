/*
 ============================================================================
 Name        : tp_1.c
 Author      : Joaquin Tarrazo
 Version     :
 Copyright   :
 Description : Trabajo practico N°: 01.
 ============================================================================
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
2 Cómo realizar y entregar el trabajo práctico
El trabajo práctico deberá ser entregado en el repositorio de GIT correspondiente al TP1 de la
materia.
El mismo consistirá en el proyecto de CodeBlocks con el programa funcionando y comentado,
respetando las reglas de estilo de la cátedra. La compilación no deberá arrojar mensajes de
error ni de warnings.
El proyecto deberá contar con la biblioteca descripta en la sección número dos, y se deberá
hacer uso de dichas funciones para resolver la lógica del programa
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h" //agrego mi header de bibliotecas al main para poder invocarlas.

int main(void)
{

	setbuf(stdout,NULL);

	//menu:

	int opcionMenu;

	//numeros a calcular:

	float numeroUno;
	float numeroDos;

	//resultados:

	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float resultadoFactorialUno;
	float resultadoFactorialDos;

	//estados de las funciones:

	int estadoDivision;
	int estadoFactorialUno;
	int estadoFactorialDos;

	int flagNumeroUno= -1; //NO SE INGRESO.
	int flagNumeroDos= -1; //NO SE INGRESO.
	int flagCaseTres= -1; //NO HAY NUMEROS PARA REALIZAR ECUACIONES.

	do{

		puts("Hola usuario, por favor, elija una opcion: \n\n 1. ingresar numero uno\n 2. ingresar numero dos\n 3. Calcular las operaciones.\n 4. Mostrar los resultados!\n 5. Salir.");
		scanf("%d",&opcionMenu);
		switch(opcionMenu)
		{

			case 1: //ingresar primer numero.
			{
				pedirFloat(&numeroUno);
				flagNumeroUno = 0; // SE INGRESO.
				break;
			}
			case 2:  //ingresar segundo numero.
			{
				do
				{
					if(flagNumeroUno==0)
					{
						pedirFloat(&numeroDos);
						flagNumeroDos=0; //SE INGRESO.
					}
					else
					{
						puts("\n no ingreso el primer numero, por favor, ingreselo y a continuacion ingrese el SEGUNDO numero:\n");
						pedirFloat(&numeroUno);
						flagNumeroUno=0;
					}

				}while(flagNumeroDos!=0); //bucle hasta que ambas opciones (1 y 2) esten ingresadas.
					break;
			}
			case 3:  //realizar operaciones (sin mostrar resultado)
			{
				if(flagNumeroUno == 0 && flagNumeroDos == 0)
				{
					puts("\n Calculando.....Listo!\n");
					funcionSumar(numeroUno, numeroDos, &resultadoSuma);
					funcionRestar(numeroUno, numeroDos, &resultadoResta);
					funcionMultiplicar(numeroUno, numeroDos, &resultadoMultiplicacion);
					estadoDivision = funcionDividir(numeroUno, numeroDos, &resultadoDivision); //RETURN guardada en estadoDivision.
					estadoFactorialUno = funcionFactorial((int)numeroUno,&resultadoFactorialUno);
					estadoFactorialDos = funcionFactorial((int)numeroDos, &resultadoFactorialDos);
					flagCaseTres= 0; //HAY DATOS PARA IMPRIMIR EN EL CASE 4.
				}
				else
				{
					if(flagNumeroUno == -1 && flagNumeroDos == -1)
					{
						puts("\n Olvido ingresar AMBOS NUMEROS.\n");
					}
					else
					{
						if(flagNumeroUno == -1 && flagNumeroDos == 0)
						{
							puts("\n Olvido ingresar el numero UNO. \n");
						}
						else
						{
							if(flagNumeroUno == 0 && flagNumeroDos == -1)
							{
							puts("\n Olvido ingresar el numero DOS.\n");
							}
						}
					}
				}
				break;
			}
			case 4:  //mostrar los resultados.
			{
				if(flagCaseTres==0) //Salio todo bien en los pasos posteriores.
				{

					puts("\n IMPRIMIENDO RESULTADOS:\n");

					printf("\n El resultado de la suma de %.2f + %.2f, es %.2f \n", numeroUno, numeroDos, resultadoSuma);

					printf("\n El resultado de la resta de %.2f - %.2f, es %.2f \n", numeroUno, numeroDos, resultadoResta);

					printf("\n El resultado de la multiplicacion de %.2f x %.2f, es %.2f \n", numeroUno, numeroDos, resultadoMultiplicacion);

					if(estadoDivision == 0) //si salio bien:
					{
						printf("\n El resultado de la division de %.2f / %.2f, es %.2f \n", numeroUno, numeroDos, resultadoDivision);
					}
					else //si numero DOS es 0:
					{
						puts("\n INFINITO ERROR, no se puede dividir por 0 \n");
					}

					if(estadoFactorialUno == 0) //si se pudo factorear:
					{
						printf("\n El resultado del factorial de !%d es: %d \n", (int)numeroUno, (int)resultadoFactorialUno);
					}
					else //si el numero es menor a 0:
					{
						puts("\n no se puede factorear con numeros negativos.\n");
					}
					if(estadoFactorialDos == 0) //si se pudo factorear:
					{
						printf("\n El resultado del factorial de !%d es: %d \n", (int)numeroDos, (int)resultadoFactorialDos);
					}
					else //si el numero es menor a 0:
					{
						puts("\n no se puede factorear con numeros negativos.\n");
					}
				}
				else //si la flagCaseTres es -1, es porque nunca se pudieron realizar las operaciones.
				{
					puts("\n Ocurrio un error, no hay numeros para realizar las operaciones o no realizo las operaciones en el paso TRES!!!\n");
				}

				break;
			}
			case 5:  //Salir.
			{
				break;
			}
			default: //No eligio una opcion entre 1 y 5.
			{
				puts("Opcion incorrecta, vuelva a intentarlo.");
			}

		} //final del switch

	}while(opcionMenu!=5);

	return EXIT_SUCCESS;
}
