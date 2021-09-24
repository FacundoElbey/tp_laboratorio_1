/*
 ============================================================================
 Name        : Trabajo Práctico 1.c
 Author      : Elbey Facundo Damian.
 Version     :
 Copyright   : Your copyright notice
 Description : Desarrollo del Trabajo Práctico número 1.
 ============================================================================
 */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "TP1.h"


int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	float operadorA;
	float operadorB;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	int respuestaDivision;
	float resultadoMultiplicacion;
	float resultadoFactorialA;
	float resultadoFactorialB;
	int respuestaFactorialA;
	int respuestaFactorialB;
	int flagCase3;
	int flagCaseOperadorA;
	int flagCaseOperadorB;

	flagCase3 = 0;
	flagCaseOperadorA = 0;
	flagCaseOperadorB = 0;

	operadorA = 0;
	operadorB = 0;


	do
	{
		printf("\n1. Ingresar primer operando (A=%.2f).\n", operadorA);
		printf("2. Ingresar segundo operando (B=%.2f).\n", operadorB);
		printf("3. Calcular todas las operaciones.\n");
		printf("4. Informar resultados.\n");
		printf("5. Salir\n");
		printf("\nIngrese una opcion: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:

				 do
				    {
				        printf("Ingrese el primer operador: ");

				    }while(ValidarDatoIngresado("%f", &operadorA));

				 flagCaseOperadorA = 1;

			break;
			case 2:

				 do
				    {
				        printf("Ingrese el segundo operador: ");

				    }while(ValidarDatoIngresado("%f", &operadorB));

				 flagCaseOperadorB = 1;

			break;
			case 3:

				if(flagCaseOperadorA == 1 && flagCaseOperadorB == 1)
				{
				resultadoSuma = CalcularSuma(operadorA, operadorB);
				resultadoResta = CalcularResta(operadorA, operadorB);
				respuestaDivision = CalcularDivision(&resultadoDivision, operadorA, operadorB);
				resultadoMultiplicacion = CalcularMultiplicacion(operadorA, operadorB);
				respuestaFactorialA = CalcularFactorial(&resultadoFactorialA, operadorA);
				respuestaFactorialB = CalcularFactorial(&resultadoFactorialB, operadorB);

				flagCase3 = 1;

			break;
				}
				else{
					printf("Debe ingresar los dos primeros operadores antes de realizar los cálculos.\n");
				}
				break;
			case 4:

				if (flagCase3 == 1)
				{
				printf("El resultado de %.2f+%.2f es: %.2f.\n",operadorA, operadorB, resultadoSuma);
				printf("El resultado de %.2f-%.2f es: %.2f.\n", operadorA, operadorB, resultadoResta);
				if (respuestaDivision == 0)
				{
					printf("El resultado de %.2f/%.2f es: %f.\n", operadorA, operadorB, resultadoDivision);
				}
				else
				{
					printf("No es posible dividir por cero (0).\n");
				}
				printf("El resultado de %.2f*%.2f es: %.2f.\n", operadorA, operadorB, resultadoMultiplicacion);

				if(respuestaFactorialA == 0 && respuestaFactorialB == 1)
				{
					printf("El factorial de %.2f no puede realizarce porque es negativo y El factorial de %.2f es: %.2f.\n", operadorA, operadorB, resultadoFactorialB);
				}
				else if (respuestaFactorialA == 1 && respuestaFactorialB == 0)
				{
					printf("El factorial de %.2f es: %.2f y El factorial de %.2f no puede realizarce porque es negativo.\n", operadorA, resultadoFactorialA, operadorB);
				}
				else if(respuestaFactorialA == 0 && respuestaFactorialB == 0)
				{
					printf("No puede realizarce ninguno de los dos factoriales porque ambos valores son negativos.\n");
				}
				else
				{
				printf("El factorial de %.2f es: %.2f y El factorial de %.2f es: %.2f.\n", operadorA, resultadoFactorialA, operadorB, resultadoFactorialB);
				}

			break;
				}
				else {
					printf("Debe ingresar primero la opción 3, para poder utilizar la 4.\n");
				}
				break;
			case 5:
			break;
		}

	}while(opcion!=5);

	return 0;
}
