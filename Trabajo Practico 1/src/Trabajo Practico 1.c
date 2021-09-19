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
				operadorA = IngresarNumero ("Ingrese el primer operador por favor:");
			break;
			case 2:
				operadorB = IngresarNumero("Ingrese el segundo operador por favor:");
			break;
			case 3:
				resultadoSuma = CalcularSuma(operadorA, operadorB);
				resultadoResta = CalcularResta(operadorA, operadorB);
				respuestaDivision = CalcularDivision(&resultadoDivision, operadorA, operadorB);
				resultadoMultiplicacion = CalcularMultiplicacion(operadorA, operadorB);
				resultadoFactorialA = CalcularFactorial(operadorA);
				resultadoFactorialB = CalcularFactorial(operadorB);
			break;
			case 4:
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
				printf("El factorial de %.2f es: %.2f y El factorial de %.2f es: %.2f.\n", operadorA, resultadoFactorialA, operadorB, resultadoFactorialB);
			break;
			case 5:
			break;
		}

	}while(opcion!=5);

	return 0;
}
