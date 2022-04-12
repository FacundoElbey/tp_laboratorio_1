/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Elbey Facundo
 Description : Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerolíneas Argentinas para ofrecerlos a sus clientes.
 Se deberá ingresar por cada vuelo los km totales y el precio total del mismo. El objetivo de la aplicación es mostrar las diferentes opciones
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
    precioAerolineas = 0;
	precioLatam = 0;
    flag_1 = 1;
    flag_2 = 1;
    flag_3 = 1;
    do
    {
    	menu(kilometrosIngresados, precioAerolineas, precioLatam);
		if(!utn_getNumero(&opcion,"\nIngrese una opción: ","\nOpcion invalida, reintente: ",1,6,4)){
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
						informe(kilometrosIngresados, precioLatam,precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario, precioAerolineas,
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
						informe(kilometrosIngresados, precioLatam,precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario, precioAerolineas,
								precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioAerolineasUnitario, diferenciaPrecios);
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
