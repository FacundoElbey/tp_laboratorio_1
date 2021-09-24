/*
 * TP1.c
 *
 *  Created on: 18 sep. 2021
 *      Author: river
 */
#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include <stdlib.h>


int ValidarDatoIngresado (const char* fm, void* pNum)
{
    int ch;
    /* Si scanf devuelve 0, no cumplió con el formato especificado. */
    if(!scanf(fm, pNum))
    {
        /* En esta parte del programa limpio el búfer del teclado para que la próxima llamada de scanf pause el programa*/

        while((ch = getchar()) != '\n' && ch != EOF);
        return 1;
    }

    /* Verifica sí el búfer quedó con datos residuales. */

    if(getchar() != '\n')
    {
        /* Limpio el búfer del teclado. */
        while((ch = getchar()) != '\n' && ch != EOF);
        return 1;
    }
    return 0;
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

int CalcularFactorial(float* pResultadoFactorial, float num)
{
	float resultado;
	float numAuxiliar;
	int control;

	resultado = 1;

	if(num >= 0)
	{
		for (numAuxiliar = num; numAuxiliar > 0; numAuxiliar-- )
		{
			resultado = resultado * numAuxiliar;
		}

		control = 1;
	}
	else
	{
		control = 0;
	}

	*pResultadoFactorial = resultado;

	return control;
}
