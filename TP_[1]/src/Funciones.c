/*
 * Funciones.c
 *
 *  Created on: 7 abr. 2022
 *      Author: felbey
 */
#include "Funciones.h"

int calcularPrecioDebito(float precioIngresado, float* precioFinal)
{
	int retorno;
	float bufferResultado;

	retorno = -1;
	if(precioFinal != NULL)
	{
	bufferResultado = precioIngresado - precioIngresado * 0.10;
	*precioFinal = bufferResultado;
	retorno = 0;
	}

	return retorno;
}

int calcularPrecioCredito(float precioIngresado, float* precioFinal)
{
	int retorno;
	float bufferResultado;

	retorno = -1;
	if(precioFinal != NULL)
	{
		bufferResultado = precioIngresado + precioIngresado * 0.25;
		*precioFinal = bufferResultado;
		retorno = 0;
	}

	return retorno;
}

int calcularPrecioBitcoin(float precioIngresado,float bitcoin, float* precioFinal)
{
	int retorno;
	float bufferResultado;

	retorno = -1;

	if(precioFinal != NULL)
	{
		bufferResultado = precioIngresado / bitcoin;
		*precioFinal = bufferResultado;
		retorno = 0;
	}
	return retorno;
}

int calcularPrecioUnitario(float kilometros, float precioIngresado, float* precioFinal)
{
	int retorno;
	float bufferResultado;

	retorno = -1;
	if(precioFinal != NULL)
	{
		bufferResultado = precioIngresado / kilometros;
		*precioFinal = bufferResultado;
		retorno = 0;
	}
	return retorno;
}

int calcularDiferenciaPrecios(float precioAerolineas, float precioLatam, float* diferencia)
{
	int retorno;
	float bufferResultado;

	retorno = -1;
	if(diferencia != NULL)
	{
		if(precioAerolineas > precioLatam)
		{
			bufferResultado = precioAerolineas - precioLatam;
		}
		else
		{
			bufferResultado = precioLatam - precioAerolineas;
		}
		*diferencia = bufferResultado;
		retorno = 0;
	}
	return retorno;
}
