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
			"\n\nPrecio Aerolineas: $%.2f"
			"\na) Precio con tarjeta de debito: $%.2f"
			"\nb) Precio con tarjeta de credito: $%.2f"
			"\nc) Precio pagando con Bitcoin: %f BTC"
			"\nd) Precio unitario: $%.2f"
			"\n\nLa diferencia de precio es: $%.2f\n",kilometros, precioLatam,precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario, precioAerolineas,
			precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioAerolineasUnitario, diferenciaPrecios);
}

void menu (float kilometros, float precioAerolineas, float precioLatam)
{
	printf("\n1. Ingresar kilometros: (km = %.2f)", kilometros);
	printf("\n2. Ingresar precio de vuelos"
			"\n- Precio vuelo Aerolineas: %.2f"
			"\n- Precio vuelo Latam: %.2f", precioAerolineas, precioLatam);
	printf("\n3. Calcular todos los costos:"
			"\na) Tarjeta de debito (descuento 10)"
			"\nb) Tarjeta de credito (interes 25)"
			"\nc) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)"
			"\nd) Mostrar precio por km (precio unitario)"
			"\ne) Mostrar diferencia de precio ingresada (Latam - Aerolineas)");
	printf("\n4. Informar resultados"
			"\nLatam:"
			"\na) Precio con tarjeta de debito: "
			"\nb) Precio con tarjeta de credito: "
			"\nc) Precio pagando con Bitcoin: "
			"\nd) Precio unitario: "
			"\nAerolineas:"
			"\na) Precio con tarjeta de debito: "
			"\nb) Precio con tarjeta de credito: "
			"\nc) Precio pagando con Bitcoin: "
			"\nd) Precio unitario: "
			"\nLa diferencia de precio es: ");
	printf("\n5. Carga forzada de datos.");
	printf("\n6. Salir.");
}
