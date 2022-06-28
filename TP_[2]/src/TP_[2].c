/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include "Biblioteca.h"
#define CANT 2000

int main(void) {
    setbuf(stdout, NULL);
	int opcion;
	int flagAlta = 1;
	int flagCarga = 1;

    Passenger listaPasajeros[CANT];

    if(!initPassengers(listaPasajeros, CANT))
    {
		do
		{
			menu();
			if(!utn_getNumero(&opcion,"\nIngrese una opcion: ","\n¡¡ERROR!!\n",1,6,5))
			{
				switch(opcion)
				{
				case 1:
						if(!uploadPassenger(listaPasajeros, CANT))
						{
							printf("\nSe dio de alta al pasajero de manera correcta.\n");
							flagAlta = 0;
						}
						else
						{
							printf("\nSe produjo un error en la carga.\n");
						}
					break;
				case 2:
					if(!flagAlta)
					{
						if(!modificarPasajero(listaPasajeros, CANT))
						{
							printf("\nSe realizaron las modificaciones.\n");
						}
						else
						{
							printf("\nEl ID no corresponde a un pasajero dado de alta.\n");
						}
					}
					else
					{
						printf("\nAntes de modificar un pasajero debe darlo de alta!");
					}
					break;
				case 3:
					if(!flagAlta)
					{
						if(!bajaPasajero(listaPasajeros, CANT))
						{
							printf("\nSe dio de baja al pasajero");
						}
						else
						{
							printf("\nEl ID no corresponde a un pasajero dado de alta");
						}
					}
					else
					{
						printf("\nAntes de modificar un pasajero debe darlo de alta!");
					}
					break;
				case 4:
					if(!flagAlta)
					{
						menuInformes(listaPasajeros, CANT);
					}
					else
					{
						printf("\nAntes de pedir un informe debe dar de alta!");
					}
					break;
				case 5:
					if(flagCarga)
					{
						hardCodeoPasajero(listaPasajeros, CANT);
						printf("\nLa carga forzada se realizo con exito!\n");
						flagAlta = 0;
						flagCarga = 0;
					}
					else
					{
						printf("\nYa realizo la carga.");
					}
					break;
				case 6:
					break;
				}
			}

		}while(opcion != 6);
    }

	return EXIT_SUCCESS;
}
