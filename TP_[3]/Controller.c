#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pArchivo = fopen(path, "r");

	if(pArchivo != NULL && pArrayListPassenger != NULL && !parser_PassengerFromText(pArchivo, pArrayListPassenger))
	{
		retorno = 0;
	}
	else
	{
		printf("\n\nError en la carga de este archivo!");
	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	FILE* pArchivo = fopen(path, "rb");

	if(pArrayListPassenger != NULL && pArchivo != NULL && !parser_PassengerFromBinary(pArchivo , pArrayListPassenger))
	{
		retorno = 0;
	}
	else
	{
		printf("\n\nError en la carga de este archivo!");
	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pPassenger = NULL;
	int indice = -1;
	int auxId = -1;
	char name[NOMBRE_LEN];
	char lastName[NOMBRE_LEN];
	char price[16];
	char flyCode[16];
	char typePassenger[16];
	char statusFlight[NOMBRE_LEN];
	char id[8];

	if(pArrayListPassenger != NULL)
	{
		auxId = encontrarMaximoId(pArrayListPassenger);
		itoa(auxId, id, 10);
		if(!utn_getNombre(name, NOMBRE_LEN, "\nIngrese el nombre del pasajero: ", "\nError!\n",3) &&
				!utn_getNombre(lastName, NOMBRE_LEN, "\nIngrese el apellido del pasajero: ", "\nError!\n",3) &&
				!PedirString("\nIngrese el precio del pasaje: ",price) && !PedirString("\nIngrese el codigo de vuelo: ",flyCode) &&
				!PedirString("\nIngrese el tipo de pasajero(1-FirstClass. 2-ExecutiveClass 3-EconomyClass): ",typePassenger) &&
				!PedirString("\nIngrese el estado de vuelo: ",statusFlight))
		{
			pPassenger = Passenger_newParametros(id, name, lastName, flyCode, typePassenger, price, statusFlight);
			if(pPassenger != NULL && !cargarIdMaximo(pArrayListPassenger, auxId) && !ll_add(pArrayListPassenger, pPassenger))
			{
				indice = buscarPassenger(pArrayListPassenger, auxId);
				printOnePassenger(pPassenger, indice);
				retorno = 0;
			}
		}
	}
    return retorno;
}

/** \brief Listar pasajeros
 *
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int len;
	Passenger* pPassenger;

	len = ll_len(pArrayListPassenger);
	if(pArrayListPassenger != NULL)
	{
		for(int i=0;i<len;i++)
		{
			pPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			printOnePassenger(pPassenger,i);
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pPassenger;
	int id = -1;
	int indice = -1;
	int opcion;
	char name[NOMBRE_LEN];
	char lastName[NOMBRE_LEN];
	float price;
	int typePassenger;
	char flyCode[16];
	char statusFlight[NOMBRE_LEN];

	if (pArrayListPassenger != NULL && !controller_ListPassenger(pArrayListPassenger) &&
			!utn_getNumero(&id,"\nIngrese el ID a modificar:", "\nERROR!",0,10000,5))
	{
		indice = buscarPassenger(pArrayListPassenger, id);
		pPassenger = (Passenger*) ll_get(pArrayListPassenger, indice);
		if(pPassenger != NULL)
		{
			printOnePassenger(pPassenger, indice);

			if(!utn_getNumero(&opcion,"\n\nSeleccione lo que desea modificar.\n1)Nombre.\n2)Apellido.\n3)Precio.\n4)Tipo de pasajero.\n5)Codigo de vuelo.\n6)Estado del vuelo.\n7)Salir.\n\nIngrese la opción deseada:", "\nERROR!!!\n",1,7,5))
			{
						switch(opcion)
						{
						case 1:
							if(!utn_getNombre(name,50,"\nIngrese el nombre: ","\nERROR!",5))
							{
								Passenger_setNombre(pPassenger, name);
								printf("\nEl nombre fue cambiado con exito!\n");
							}
							break;
						case 2:
							if(!utn_getNombre(lastName,50,"\nIngrese el apellido: ","\nERROR!",5))
							{
								Passenger_setApellido(pPassenger, lastName);
								printf("\nEl apellido fue cambiado con exito!\n");
							}
							break;
						case 3:
							if(!utn_getNumeroFlotante(&price,"\nIngrese el precio: ","\nERROR!",1,999999,5))
							{
								Passenger_setPrecio(pPassenger, price);
								printf("\nEl precio fue cambiado con exito!\n");
							}
							break;
						case 4:
							if(!utn_getNumero(&typePassenger,"\nIngrese el tipo de pasajero que es(1-TURISTA\t2-EJECUTIVO): ","\nERROR!",1,2,5))
							{
								Passenger_setTipoPasajero(pPassenger, typePassenger);
								printf("\nEl tipo de pasajero fue cambiado con exito!\n");
							}
							break;
						case 5:
							if(!PedirString ("\nIngrese el codigo de vuelo:", flyCode))
							{
								Passenger_setCodigoVuelo(pPassenger,flyCode);
								printf("\nEl codigo de vuelo fue cambiado  con exito!\n");
							}
							break;
						case 6:
							if(!PedirString ("\nIngrese el estado de vuelo:", statusFlight))
							{
								Passenger_setEstadoVuelo(pPassenger,statusFlight);
								printf("\nEl estado de vuelo fue cambiado  con exito!\n");
							}
							break;
						case 7:
							break;
						}
						printOnePassenger(pPassenger, indice);
						retorno = 0;
				}
			}
		}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pPassenger;
	int auxIndice = -1;
	int auxId = -1;
	int opcion;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		utn_getNumero(&auxId, "\nIngrese el ID del empleado a eliminar: ", "\nError",0,10000,4);
		auxIndice = buscarPassenger(pArrayListPassenger, auxId);
		pPassenger = (Passenger*) ll_get(pArrayListPassenger, auxIndice);
		if(pPassenger != NULL)
		{
			printOnePassenger(pPassenger, auxIndice);
			if(!utn_getNumero(&opcion,"\n¿Desea eliminar este pasajero?\n1)Si.\n2)No.\nIngrese una opcion:","\nERROR!",1,2,3))
			{
				switch(opcion)
				{
				case 1:
					if(!ll_remove(pArrayListPassenger, auxIndice))
					{
						retorno = 0;
					}
					break;
				case 2:
					retorno = 0;
					break;
				}
			}
		}
	}
    return retorno;
}



/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int orden;
	int opcion;

	if(!utn_getNumero(&opcion,"\n\n¿Por cual elemento desea ordenar?\n1)ID.\n2)Nombre.\n3)Apellido.\n4)Precio.\n5)Estado de vuelo.\n6)Salir.\n\nIngrese una opcion:","\n\nERROR!!\n\n",1,6,5) &&
		!utn_getNumero(&orden,"\n¿De que manera desea hacerlo?\n0-Ascendente.\n1-Descendente.\n\nIngrese una opcion:","\n\nERROR!!\n\n",0,1,5))
	{
		switch(opcion)
		{
		case 1:
			if(!ll_sort(pArrayListPassenger, ordenarPasajerosPorId, orden))
			{
				printf("\nSe ha ordenado la lista de pasajeros por ID.");
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo realizar el ordenamiento solicitado.");
			}
			break;
		case 2:
			if(!ll_sort(pArrayListPassenger,ordenarPasajerosPorNombre,orden))
			{
				printf("\nSe ha ordenado la lista de pasajeros por sus nombres.");
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo realizar el ordenamiento solicitado.");
			}
			break;
		case 3:
			if(!ll_sort(pArrayListPassenger,ordenarPasajerosPorApellido,orden))
			{
				printf("\nSe ha ordenado la lista de pasajeros por sus apellido.");
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo realizar el ordenamiento solicitado.");
			}
			break;
		case 4:
			if(!ll_sort(pArrayListPassenger,ordenarPassengerPorPrecio,orden))
			{
				printf("\nSe ha ordenado la lista de pasajeros por el costo de su pasaje.");
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo realizar el ordenamiento solicitado.");
			}
			break;
		case 5:
			if(!ll_sort(pArrayListPassenger,ordenarPasajerosPorEstadoVuelo,orden))
			{
				printf("\nSe ha ordenado la lista de pasajeros por su estado de vuelo.");
				retorno = 0;
			}
			else
			{
				printf("\nNo se pudo realizar el ordenamiento solicitado.");
			}
			break;
		case 6:
			break;
		}
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int len = ll_len(pArrayListPassenger);
	int auxId;
	char auxName[NOMBRE_LEN];
	char auxLastName[NOMBRE_LEN];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[16];
	char auxStatusFlight[NOMBRE_LEN];
	Passenger* pPassenger = NULL;
	FILE* pArchivo = fopen(path, "w");

	if(pArchivo != NULL && pArrayListPassenger != NULL)
	{
		fprintf(pArchivo, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(int i=0;i<len;i++)
		{
			pPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			if(pPassenger != NULL && !Passenger_getId(pPassenger, &auxId) &&
				!Passenger_getNombre(pPassenger, auxName) && !Passenger_getCodigoVuelo(pPassenger, auxFlyCode) &&
				!Passenger_getTipoPasajero(pPassenger, &auxTypePassenger) && !Passenger_getPrecio(pPassenger, &auxPrice) &&
				!Passenger_getEstadoVuelo(pPassenger, auxStatusFlight))
			{
				Passenger_getApellido(pPassenger, auxLastName);
				fprintf(pArchivo,"%d,%s,%s,%.2f,%s,%d,%s\n", auxId, auxName, auxLastName, auxPrice, auxFlyCode, auxTypePassenger, auxStatusFlight);
			}
		}
		retorno = 0;
	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int len;
	Passenger* pPassenger = NULL;
	FILE* pArchivo;

	len = ll_len(pArrayListPassenger);
	pArchivo = fopen(path, "wb");

	if(pArrayListPassenger != NULL && pArchivo != NULL)
	{
		for(int i=0;i<len;i++)
		{
			pPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
			if(pPassenger != NULL)
			{
				fwrite(pPassenger,sizeof(Passenger),1,pArchivo);
			}
		}
		retorno = 0;
	}
	fclose(pArchivo);
    return retorno;
}

