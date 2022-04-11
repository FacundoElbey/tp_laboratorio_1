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

void informe(float kilometros,float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBitcoin,
		float precioLatamUnitario, float precioAerolineas, float precioAerolineasDebito, float precioAerolineasCredito, float precioAerolineasBitcoin,
		float precioAerolineasUnitario, float diferenciaPrecios)
{
	printf("\nKMs Ingresados: %.2f"
			"\n\nPrecio Latam: $%.2f"
			"\na) Precio con tarjeta de debito: $%.2f"
			"\nb) Precio con tarjeta de credito: $%.2f"
			"\nc) Precio pagando con Bitcoin: %f BTC"
			"\nd) Precio unitario: $%.2f"
			"\n\n Precio Aerolineas: $%.2f"
			"\na) Precio con tarjeta de debito: $%.2f"
			"\nb) Precio con tarjeta de credito: $%.2f"
			"\nc) Precio pagando con Bitcoin: %f BTC"
			"\nd) Precio unitario: $%.2f"
			"\n\nLa diferencia de precio es: $%.2f\n",kilometros, precioLatam,precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario, precioAerolineas,
			precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioAerolineasUnitario, diferenciaPrecios);
}
