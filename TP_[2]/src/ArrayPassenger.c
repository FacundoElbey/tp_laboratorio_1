/*
 * ArrayPassenger.c
 *
 *  Created on: 26 abr. 2022
 *      Author: river
 */

#include "ArrayPassenger.h"

static int idIncremental = 4;
static int obtenerID();

static int obtenerID()
{
	idIncremental++;
	return idIncremental;
}

int initPassengers(Passenger list[], int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}

int hardCodeoPasajero(Passenger list[], int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		Passenger listaPasajeros[5]={{0, "Facundo", "Elbey", 168264.28, "AAC250", 1, ACTIVO, FALSE},
				{1, "Valeria", "Soledad", 145398.31, "BTC987", 2, ACTIVO, FALSE}, {2, "Carla", "Lastra", 120357.22, "AAC250", 2, ACTIVO, FALSE},
				{3, "Hugo", "Cesar", 230285.98, "TYC654", 1, CANCELADO, FALSE}, {4, "Harry", "Martin", 365472.28, "NAR935", 2, CANCELADO, FALSE}};

		for(i=0; i<5; i++)
		{
			list[i] = listaPasajeros[i];
		}
		retorno = 0;
	}
	return retorno;
}

int findEmptyIndex(Passenger list[], int len)
{
    int indice = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int addPassenger(Passenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{
    int retorno = -1;
	int indice;

	indice = findEmptyIndex(list, len);

	if(list != NULL && len > 0 && indice != -1)
	{
		list[indice].statusFlight = ACTIVO;
		list[indice].isEmpty = FALSE;
		retorno = 0;
	}
	return retorno;
}

int uploadPassenger(Passenger list[], int len)
{
		int retorno = -1;
	    int indice;
	    indice = findEmptyIndex(list, len);

		if(list != NULL && len > 0 && indice != -1)
		{
			if(!utn_getNombre(list[indice].name, NOMBRE_LEN,"\nIngrese su nombre: ","\n¡Error!\n",3) &&
			!utn_getNombre(list[indice].lastName, NOMBRE_LEN,"\nIngrese su apellido: ","\n¡Error!\n",3) &&
			!utn_getNumeroFlotante(&list[indice].price,"\nIngrese el precio del vuelo: ","\n¡Error!\n",1,9999999,3) &&
			!utn_getNumero(&list[indice].typePassenger,"\nIngrese que tipo de pasajero es(1 para Primera Clase o 2 para Clase Turista): ","\n¡Error!\n",1,2,6) &&
			!PedirString("\nIngrese el codigo de vuelo: ", list[indice].flycode))
			{
			    list[indice].id = obtenerID();
			    addPassenger(list, len, list->id, list->name, list->lastName, list->price, list->typePassenger, list->flycode);
	            retorno = 0;
			}
		}
		return retorno;
}

int printOnePassenger (Passenger* list)
{
	int retorno = -1;
	setbuf(stdout, NULL);

	if(list != NULL && list->isEmpty == FALSE)
	{
		retorno = 0;
		printf("\nID: %d - NOMBRE: %s - APELLIDO: %s - PRECIO VUELO: $%.2f - TIPO DE PASAJERO: %d - CODIGO DE VUELO: %s - ESTADO DE VUELO: %d", list->id, list->name, list->lastName, list->price, list->typePassenger, list->flycode, list->statusFlight);
	}
	return retorno;
}

int printPassenger(Passenger* list, int len)
{
	int retorno = -1;

	for (int i=0; i<len;i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			printOnePassenger(&list[i]);
			retorno = 0;
		}
	}

	return retorno;
}

int findPassengerById(Passenger list[], int len, int id)
{
	int indice = -1;
	int i;

	if(list != NULL && len > 0 && id > -1)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty == FALSE)
			{
				indice = i;
			}
		}
	}
	return indice;
}

int modificarPasajero(Passenger list[], int len)
{
	int retorno = -1;
	int idPasajero;
	int opcion;

	if(!printPassenger(list, len) &&
	!utn_getNumero(&idPasajero,"\n\nIngrese el ID que desea modificar: ","\nError!!\n",0,len,4))
		{
		for(int i=0; i<len ; i++){
		        if(list[i].isEmpty == FALSE && list[i].id == idPasajero)
		        {
		        	do
		        	{
					if(utn_getNumero(&opcion, "\n\tMenu de modificaciones.\n\n1)Nombre.\n2)Apellido.\n3)Precio.\n4)Tipo de pasajero.\n5)El codigo de vuelo.\n6)Nada mas\n\nIngrese una opcion: ", "\nNo es una opcion valida\n", 1,6,4) == 0)
					{
						switch(opcion)
						{
						case 1:
							if(!utn_getNombre(list[i].name, 51, "\nIngrese el nombre del pasajero: ", "\nNombre invalido.",2))
							{
								printf("\nSe cambio el nombre correctamente");
							}
							break;
						case 2:
							if(!utn_getNombre(list[i].lastName, 51, "\nIngrese el apellido del pasajero: ", "\nApellido invalido.",2))
							{
								printf("\nSe cambio el apellido correctamente");
							}
							break;
						case 3:
							if(!utn_getNumeroFlotante(&list[i].price,"\nIngrese el precio del boleto: ","\nEl precio es invalido, intente de nuevo.",0.01,10000000,2))
							{
								printf("\nSe cambio el precio correctamente");
							}
							break;
						case 4:
							if(!utn_getNumero(&list[i].typePassenger, "\nIngrese el tipo de pasajero: ", "El tipo es invalido", 0, 3,2))
							{
								printf("\nSe cambio el tipo de pasajero correctamente");
							}
							break;
						case 5:
							if(!PedirString("\nIngrese el codigo de vuelo: ", list[i].flycode))
							{
								printf("\nSe cambio el codigo de vuelo correctamente");
							}
							break;
						case 6:
							break;
						}
					}
		        	} while (opcion != 6);
		        	retorno = 0;
		        }
		      }
		}
	return retorno;
}

int removePassenger(Passenger list[], int len, int id)
{
	int retorno = -1;
	int indiceBorrar;

	if(list != NULL && len > 0 && id > -1)
	{
		indiceBorrar = findPassengerById(list, len, id);
		list[indiceBorrar].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}

int bajaPasajero(Passenger list[], int len)
{
	int retorno = -1;
	int idBorrar;

	if(list != NULL && len > 0)
	{
		printPassenger(list, len);
		if(!utn_getNumero(&idBorrar,"\nIngrese el ID de la persona que desea dar de baja: ","\nERROR!\n",0,2000,5) &&
				!removePassenger(list, len, idBorrar))
		{
			retorno = 0;
		}
	}

	return retorno;
}

int sortPassengers(Passenger list[], int len, int order)
{
	int retorno = -1;
	Passenger buffer;
	int i;
	int j;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
			if(order == 1 && (strncmp(list[i].lastName, list[j].lastName, 51) > 0 ||
				(strncmp(list[i].lastName, list[j].lastName, 51) == 0 &&
				list[i].typePassenger > list[j].typePassenger)))
			{
				buffer = list[i];
				list[i] = list[j];
				list[j] = buffer;

			}
			else if (order == 0 && (strncmp(list[i].lastName, list[j].lastName, 51) < 0 ||
					(strncmp(list[i].lastName, list[j].lastName, 51) == 0 &&
					list[i].typePassenger < list[j].typePassenger)))
			{
				buffer = list[i];
				list[i] = list[j];
				list[j] = buffer;
			}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int sortPassengersByCode(Passenger* list, int len)
{
	int retorno = -1;
	Passenger buffer;
	int i;
	int j;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len-1; i++)
		{
			for(j=i+1; j<len; j++)
			{
			if((strncmp(list[i].flycode, list[j].flycode, 10) > 0 ||
				(strncmp(list[i].flycode, list[j].flycode, 10) == 0 && list[i].statusFlight > list[j].statusFlight)))
			{
				buffer = list[i];
				list[i] = list[j];
				list[j] = buffer;

			}
			}
		}
		retorno = 0;
	}
	return retorno;
}

void opcionesInformes()
{
	printf("\n\n\tMenu de informes"
			"\n1. Listado de pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero."
			"\n2. Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio."
			"\n3. Listado de pasajeros por Codigo de vuelo y estado de vuelo Activo."
			"\n4. Salir.\n");
}

int totalPrecioPasajes (Passenger list[], int len, int* acumulador)
{
	int retorno = -1;
	int i;
	int bufferAcumulador = 0;

	if(list != NULL && acumulador != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				bufferAcumulador = bufferAcumulador + list[i].price;
			}
		}
		*acumulador = bufferAcumulador;
		retorno = 0;
	}
	return retorno;
}

int promedioPrecioPasajes(Passenger list[], int len, int precioTotal, int* precioPromedio)
{
	int retorno = -1;
	int bufferPromedio;
	int contador = 0;
	int i;

	if(list != NULL && len > 0 && precioTotal > 0 && precioPromedio != NULL)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				contador++;
			}
		}
		bufferPromedio = precioTotal / contador;
		*precioPromedio = bufferPromedio;
		retorno = 0;
	}
	return retorno;
}

int precioMayorAlPromedio(Passenger list[], int len, int precioPromedio, int* acumulador)
{
	int retorno = -1;
	int i;
	int bufferAcumulador = 0;

	if(list != NULL && acumulador != NULL && precioPromedio > 0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].price > precioPromedio)
			{
				bufferAcumulador++;
			}
		}
		*acumulador = bufferAcumulador;
		retorno = 0;
	}
	return retorno;
}
int menuInformes(Passenger list[], int len)
{
	int retorno = -1;
	int opcion;
	int opcionOrdenamiento;
	int totalPrecio= 0;
	int precioPromedio;
	int precioSobrePromedio = 0;

	if(list != NULL && len > 0)
	{
		do
		{
			opcionesInformes();
			utn_getNumero(&opcion,"\nIngrese una opcion: ","\nError!!",1,4,4);
			switch(opcion)
			{
				case 1:
					if(!utn_getNumero(&opcionOrdenamiento,"\nIngrese una opcion de ordenamiento(1 ascendente - 0 descendente): ","\nError!!",0,1,4) &&
							!sortPassengers(list, len, opcionOrdenamiento))
					{
						printPassenger(list, len);
					}
					break;
				case 2:
					if(!totalPrecioPasajes(list, len, &totalPrecio) &&
						!promedioPrecioPasajes(list, len, totalPrecio, &precioPromedio) &&
						!precioMayorAlPromedio(list, len, precioPromedio, &precioSobrePromedio))
					{
						printf("\El precio total de los pasajes es: %d", totalPrecio);
						printf("\nEl promedio del precio por pasaje es: %d", precioPromedio);
						printf("\nLa cantidad de pasajes que superan el precio promedio es: %d", precioSobrePromedio);
					}
					break;
				case 3:
					if(!sortPassengersByCode(list, len))
					{
						printPassenger(list, len);
					}
					break;
				case 4:
					break;
			}
		}while(opcion != 4);
		retorno = 0;
	}

	return retorno;
}
