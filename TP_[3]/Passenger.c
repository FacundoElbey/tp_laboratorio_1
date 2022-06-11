#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* pasajero = (Passenger*) malloc(sizeof(Passenger));
	return pasajero;
}

Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* codigoVueloStr, char* tipoPasajeroStr, char* precioStr, char* statusFlightStr)
{
	Passenger* onePassenger = Passenger_new();

	if(onePassenger != NULL && !Passenger_setId(onePassenger, atoi(idStr)) &&
			!Passenger_setNombre(onePassenger, nombreStr) && !Passenger_setApellido(onePassenger, apellidoStr) &&
			!Passenger_setCodigoVuelo(onePassenger, codigoVueloStr) && !Passenger_setTipoPasajero(onePassenger, atoi(tipoPasajeroStr)) &&
			!Passenger_setPrecio(onePassenger, atof(precioStr)) && !Passenger_setEstadoVuelo(onePassenger, statusFlightStr))
	{
	}
	else
	{
		Passenger_delete(onePassenger);
	}
	return onePassenger;
}

void Passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;

	if(this != NULL && id != -1)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strcpy(this->apellido, apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;

	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;

	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;

	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;

	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;

	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->statusFlight, estadoVuelo);
		retorno = 0;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;

	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(estadoVuelo, this->statusFlight);
		retorno = 0;
	}
	return retorno;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
int cargarIdMaximo(LinkedList* pArrayListPassenger, int id)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

	pArchivo = fopen("ID.txt", "w");
	if(pArchivo != NULL && pArrayListPassenger != NULL)
	{
		fprintf(pArchivo,"%d", id);
		retorno = 0;
	}
	fclose(pArchivo);
	return retorno;
}

int encontrarMaximoId(LinkedList* pArrayListPassenger)
{
	FILE* pArchivo = NULL;
	int idMaximo;
	char auxId[100];

	pArchivo = fopen("ID.txt", "r");

	if(pArchivo != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pArchivo,"%s", auxId);
		idMaximo = atoi(auxId);
		idMaximo++;
	}
	fclose(pArchivo);
	return idMaximo;
}

void printOnePassenger(Passenger* passenger, int indice)
{
	int auxId;
	char auxName[NOMBRE_LEN];
	char auxLastName[NOMBRE_LEN];
	float auxPrice;
	int auxTypePassenger;
	char auxFlyCode[16];
	char auxStatusFlight[NOMBRE_LEN];

	if(passenger != NULL && !Passenger_getId(passenger, &auxId) && !Passenger_getNombre(passenger, auxName) &&
		!Passenger_getApellido(passenger, auxLastName) && !Passenger_getPrecio(passenger, &auxPrice) &&
		!Passenger_getTipoPasajero(passenger, &auxTypePassenger) && !Passenger_getCodigoVuelo(passenger, auxFlyCode) &&
		!Passenger_getEstadoVuelo(passenger, auxStatusFlight))
		{
			printf("\nID: %d - Nombre: %s - Apellido: %s - Precio: %.2f - Tipo  de pasajero: %d - Codigo de vuelo: %s - Estado del vuelo: %s",
					auxId, auxName, auxLastName, auxPrice, auxTypePassenger, auxFlyCode, auxStatusFlight);
		}
}

int buscarPassenger(LinkedList* pArrayListPassenger, int id)
{
	Passenger* pPassenger;
	int retorno = -1;
	int len = ll_len(pArrayListPassenger);
	int auxId = -1;

	if(pArrayListPassenger != NULL && len >= 0)
	{
		for(int i=0; i<len; i++)
		{
			pPassenger = (Passenger*) ll_get(pArrayListPassenger , i);
			if(pPassenger != NULL)
			{
				if(!Passenger_getId(pPassenger, &auxId) && id == auxId)
				{
					retorno = i;
					break;
				}
			}
		}
	}
	return retorno;
}

int ordenarPasajerosPorId(void* pasajero1, void* pasajero2)
{
	int retorno = 0;
	int pasajero1Id;
	int pasajero2Id;

	if(pasajero1 != NULL && pasajero2 != NULL &&
		!Passenger_getId(pasajero1, &pasajero1Id) && !Passenger_getId(pasajero2, &pasajero2Id))
	{
		if(pasajero1Id<pasajero2Id)
		{
			retorno = 1;
		}
		else if(pasajero1Id>pasajero2Id)
		{
			retorno = -1;
		}
	}
	return retorno;
}

int ordenarPasajerosPorNombre(void* pasajero1, void* pasajero2)
{
	int retorno = 0;
	char pasajero1Nombre[NOMBRE_LEN];
	char pasajero2Nombre[NOMBRE_LEN];

	if(pasajero1 != NULL && pasajero2 != NULL &&
		!Passenger_getNombre(pasajero1,pasajero1Nombre) && !Passenger_getNombre(pasajero2,pasajero2Nombre))
	{
		retorno = strcmp (pasajero2,pasajero1);
	}
	return retorno;
}

int ordenarPasajerosPorApellido(void* pasajero1, void* pasajero2)
{
	int retorno = 0;
	char pasajero1Apellido[NOMBRE_LEN];
	char pasajero2Apellido[NOMBRE_LEN];

	if(pasajero1 != NULL && pasajero2 != NULL &&
		!Passenger_getApellido(pasajero1,pasajero1Apellido) && !Passenger_getApellido(pasajero2,pasajero2Apellido))
	{
		retorno = strcmp (pasajero2,pasajero1);
	}
	return retorno;
}

int ordenarPassengerPorPrecio(void* pasajero1, void* pasajero2)
{
	int retorno = 0;
	float pasajero1Precio;
	float pasajero2Precio;

	if (pasajero1 != NULL && pasajero2 != NULL &&
		!Passenger_getPrecio(pasajero1, &pasajero1Precio) && !Passenger_getPrecio(pasajero2, &pasajero2Precio) &&
		pasajero1Precio<pasajero2Precio)
	{
		retorno = 1;
	}
	else if(pasajero1Precio>pasajero2Precio)
	{
		retorno = -1;
	}
	return retorno;
}

int ordenarPasajerosPorEstadoVuelo(void* pasajero1, void* pasajero2)
{
	int retorno = 0;
	char pasajero1Estado[NOMBRE_LEN];
	char pasajero2Estado[NOMBRE_LEN];

	if(pasajero1 != NULL && pasajero2 != NULL &&
		!Passenger_getEstadoVuelo(pasajero1,pasajero1Estado) && !Passenger_getEstadoVuelo(pasajero2,pasajero2Estado))
	{
		retorno = strcmp (pasajero2,pasajero1);
	}
	return retorno;
}
