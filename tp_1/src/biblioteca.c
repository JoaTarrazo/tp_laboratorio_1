/*
 * biblioteca.c
 *
 *  Created on: 19 sep. 2021
 *      Author: Joaquin Tarrazo.
 */

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief: Funcion que pide un float y valida en la misma funcion mediante un bucle que el numero ingresado este bien a traves de la salida del scanf.
//param: Puntero del numero a ingresar.
//return: No hay retorno (void)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pedirFloat(float* punteroNumero)
{
	int estadoScanf=0; //por defecto MAL.
	float buffer;

	puts("ingrese un numero:");
	fflush(stdin);
	estadoScanf = scanf("%f",&buffer);  //si da 0 es xq el scanf no convirtio lo ingresado en float(MAL) si es 1 pudo(BIEN)

	while(estadoScanf!=1)
	{
		puts("ERROR al ingresar el numero, por favor, vuelva a intentarlo.");
		fflush(stdin);
		estadoScanf = scanf("%f",&buffer);
	}
	*punteroNumero=buffer;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief: Funcion que suma 2 numeros y devuelve el resultado a traves de un puntero.
//param: Numero ingresado.
//param: Numero a sumar.
//param: puntero del resultado de la suma de numero uno y numero dos.
//return: No hay retorno (void)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void funcionSumar(float numeroUno, float numeroDos, float* punteroResultado)
{
	*punteroResultado= numeroUno + numeroDos;  //no hay errores posibles.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief: Funcion que resta 2 numeros y devuelve el resultado a traves de un puntero.
//param: Numero ingresado.
//param: Numero a restar.
//param: puntero del resultado de la resta entre numero uno y numero dos.
//return: No hay retorno (void)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void funcionRestar(float numeroUno, float numeroDos, float* punteroResultado)
{
	*punteroResultado= numeroUno - numeroDos; //no hay errores posibles.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief: Funcion que multiplica 2 numeros y devuelve el resultado a traves de un puntero.
//param: Numero ingresado.
//param: Numero a multiplicar
//param: puntero del resultado de la multiplicacion entre numero uno y numero dos.
//return: No hay retorno (void)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void funcionMultiplicar(float numeroUno, float numeroDos, float* punteroResultado)
{
	*punteroResultado= numeroUno * numeroDos; //no hay errores posibles.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief: Funcion que divide dos numeros y guarda el resultado mendiante un puntero, retorna un estado en base a si el numero dos es un 0 (no se puede dividir)
//param: Numero ingresado.
//param: Divisor.
//param: Puntero del resultado de la division entre numero uno y numero dos.
//return: Estado de la funcionDividir, en caso que sea 0, es xq se pudo dividir con exito, si el -1, es xq el segundo numero es 0 (ERROR infinito)
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int funcionDividir(float numeroUno, float numeroDos, float* punteroResultado)
{
	int estado= -1; //MAL

	if(numeroDos!=0)
	{
		*punteroResultado= numeroUno / numeroDos;
		estado=0;
	}
	return estado; //retorno el estado de si se puede dividir o el divisor es 0.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//brief: Funcion que calcula el !Factorial de un numero validando antes que el numero sea mayor a 0, o en caso que sea 0 el resultado sera 1.
//param: Numero ingresado.
//param: Puntero del resultado del factorial del numero ingresado.
//return: Estado de la funcionFactorial, en caso que sea -1, es xq el numero es negativo (no se puede calcular) si es 0, es xq se pudo calcular.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int funcionFactorial(float numero, float* punteroResultado)
{
	int i;
	int factorial = 1;
	int estado= -1; //MAL por defecto.

	if(numero>0) //valido que no sea 0 el numero xq no se puede.
	{

		for(i = 1; i<=numero; i++)
		{
			factorial = factorial * i;
		}

		estado=0; //BIEN.

		*punteroResultado= factorial; //cargo el dato en el puntero.
	}
	else
	{
		if(numero==0) //matematicamente da 1.
		{
			*punteroResultado = 1;
			estado=0; //BIEN.
		}
	}

	return estado;  //depende el estado (-1 o 0) voy a mostrar el resultado o mostrar un mensaje de error (MAIN).
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
