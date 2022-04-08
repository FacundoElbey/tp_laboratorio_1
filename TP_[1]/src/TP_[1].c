/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Elbey Facundo
 Description : Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas para ofrecerlos a sus clientes.
 Se deber� ingresar por cada vuelo los km totales y el precio total del mismo. El objetivo de la aplicaci�n es mostrar las diferentes opciones
 de pagos a sus clientes.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Funciones.h"
#define BITCOIN 4606954.55

int main(void) {

	setbuf(stdout, NULL);
    int opcion;
    float kilometrosIngresados;
    float precioAerolineas;
    float precioLatam;
    float precioLatamDebito;
    float precioAerolineasDebito;
    float precioLatamCredito;
    float precioAerolineasCredito;
    float precioLatamBitcoin;
    float precioAerolineasBitcoin;
    float precioLatamUnitario;
    float precioAerolineasUnitario;
    float diferenciaPrecios;
    int flag_1;
    int flag_2;
    int flag_3;

    kilometrosIngresados = 0;
    flag_1 = 1;
    flag_2 = 1;
    flag_3 = 1;
    do
    {
			printf("\n1. Ingresar kilometros: (km = %.2f)", kilometrosIngresados);
			printf("\n2. Ingresar precio de vuelos"
					"\n- Precio vuelo Aerolineas: %.2f"
					"\n- Precio vuelo Latam: %.2f", precioAerolineas, precioLatam);
			printf("\n3. Calcular todos los costos:"
					"\na) Tarjeta de debito (descuento 10%)"
					"\nb) Tarjeta de credito (interes 25%)"
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
			if(!utn_getNumero(&opcion,"\nIngrese una opci�n: ","\nOpcion invalida, reintente: ",1,6,4)){
				switch(opcion)
				{
					case 1:
						if(utn_getNumeroFlotante(&kilometrosIngresados, "\nIngrese los kilometros: ","\nRANGO INVALIDO!!!\nReingrese los kilometros: ",0,99999999,5) != 0)
						{
							printf("\nSe produjo un error en la carga de los kilometros. Reinicie le programa.");
							break;
						}
						flag_1 = 0;
						break;

					case 2:
						if(!utn_getNumeroFlotante(&precioAerolineas,"\nIngrese el precio del vuelo en Aerolineas: ","\nERROR, reingrese el precio: ",0,99999999,5))
						{
							if(utn_getNumeroFlotante(&precioLatam,"\nIngrese el precio del vuelo en Latam: ","\nERROR, reingrese el precio: ",0,99999999,5) != 0)
							{
								printf("\nSe produjo un error en la carga de los precios. Reinicie le programa.");
								break;
							}
						}
						flag_2 = 0;
						break;

					case 3:

						if(!flag_1 && !flag_2)
						{
							if (!calcularPrecioDebito(precioLatam, &precioLatamDebito) && !calcularPrecioDebito(precioAerolineas, &precioAerolineasDebito) && !calcularPrecioCredito(precioLatam, &precioLatamCredito)
								&& !calcularPrecioCredito(precioAerolineas, &precioAerolineasCredito) && !calcularPrecioBitcoin(precioLatam, BITCOIN, &precioLatamBitcoin) &&
								!calcularPrecioBitcoin(precioAerolineas, BITCOIN, &precioAerolineasBitcoin) && !calcularPrecioUnitario(kilometrosIngresados, precioLatam, &precioLatamUnitario) &&
								!calcularPrecioUnitario(kilometrosIngresados, precioAerolineas, &precioAerolineasUnitario) && !calcularDiferenciaPrecios(precioAerolineas, precioLatam, &diferenciaPrecios))
							{
								printf("\nSe realizo con exito el calculo de los costos!!\n");
								flag_3 = 0;
							}
						}
						else
						{
							printf("\nAntes de realizar el calculo de los costos, ingrese el valor de los vuelos y los kilometros!!\n");
						}
						break;
					case 4:
						if(!flag_3)
						{
							printf("\n4.\nLatam:"
									"\na) Precio con tarjeta de debito: $%.2f"
									"\nb) Precio con tarjeta de credito: $%.2f"
									"\nc) Precio pagando con Bitcoin: %f BTC"
									"\nd) Precio unitario: $%.2f"
									"\nAerolineas:"
									"\na) Precio con tarjeta de debito: $%.2f"
									"\nb) Precio con tarjeta de credito: $%.2f"
									"\nc) Precio pagando con Bitcoin: %f BTC"
									"\nd) Precio unitario: $%.2f"
									"\nLa diferencia de precio es: $%.2f",precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario,
									precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioAerolineasUnitario, diferenciaPrecios);
						}
						else
						{
							printf("\nAntes de informar los costos, debe calcularlos con la opcion 3!\n");
						}
						break;

					case 5:
						kilometrosIngresados = 7090;
						precioAerolineas = 1335000.66;
						precioLatam = 1350000.76;
						if (!calcularPrecioDebito(precioLatam, &precioLatamDebito) && !calcularPrecioDebito(precioAerolineas, &precioAerolineasDebito) && !calcularPrecioCredito(precioLatam, &precioLatamCredito)
							&& !calcularPrecioCredito(precioAerolineas, &precioAerolineasCredito) && !calcularPrecioBitcoin(precioLatam, BITCOIN, &precioLatamBitcoin) &&
							!calcularPrecioBitcoin(precioAerolineas, BITCOIN, &precioAerolineasBitcoin) && !calcularPrecioUnitario(kilometrosIngresados, precioLatam, &precioLatamUnitario) &&
							!calcularPrecioUnitario(kilometrosIngresados, precioAerolineas, &precioAerolineasUnitario) && !calcularDiferenciaPrecios(precioAerolineas, precioLatam, &diferenciaPrecios))
						{
							printf("\nSe realizo con exito el calculo de los costos!!\n");
							flag_1 = 0;
							flag_2 = 0;
							flag_3 = 0;
						}
						break;
					case 6:
						break;
				}
			}
    } while (opcion != 6);

	return EXIT_SUCCESS;
}
