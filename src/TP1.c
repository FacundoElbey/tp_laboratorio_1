/*
 * TP1.c
 *
 *  Created on: 18 sep. 2021
 *      Author: river
 */
#include <stdio.h>
#include <stdlib.h>

float IngresarNumero (char mensaje[])
{
	float numeroIngresado;

	printf (mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}

float CalcularSuma (float num1, float num2)
{
	float resultado;

	resultado = num1 + num2;

	return resultado;
}

float CalcularResta (float num1, float num2)
{
	float resultado;

	resultado = num1 - num2;

	return resultado;
}

int CalcularDivision(float* pResultadoDivision,float num1, float num2)
{
	float resultado;
	int retorno;

	retorno = -1;

	if (pResultadoDivision != NULL && num2 != 0)
	{
	resultado = num1 / num2;
	*pResultadoDivision = resultado;
	retorno = 0;
	}

	return retorno;
}

float CalcularMultiplicacion(float num1, float num2)
{
	float resultado;

	resultado = num1 * num2;

	return resultado;
}

float CalcularFactorial(float num)
{
	float resultado;
	float numAuxiliar;

	resultado = 1;

	for (numAuxiliar = num; numAuxiliar > 0; numAuxiliar-- )
	{
		resultado = resultado * numAuxiliar;
	}

	return resultado;
}
