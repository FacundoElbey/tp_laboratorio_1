#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Biblioteca.h"
#define NOMBRE_LEN 50

typedef struct
{
	int id;
	char nombre[NOMBRE_LEN];
	char apellido[NOMBRE_LEN];
	float precio;
	int tipoPasajero;
	char codigoVuelo[16];
	char statusFlight[NOMBRE_LEN];
}Passenger;

Passenger* Passenger_new();//++
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* codigoVueloStr, char* tipoPasajeroStr, char* precioStr, char* statusFlightStr);//++
void Passenger_delete(Passenger* this);//++

int Passenger_setId(Passenger* this,int id);//++
int Passenger_getId(Passenger* this,int* id);//++

int Passenger_setNombre(Passenger* this,char* nombre);//++
int Passenger_getNombre(Passenger* this,char* nombre);//++

int Passenger_setApellido(Passenger* this,char* apellido);//++
int Passenger_getApellido(Passenger* this,char* apellido);//++

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);//++
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);//++

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);//++
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);//++

int Passenger_setPrecio(Passenger* this,float precio);//++
int Passenger_getPrecio(Passenger* this,float* precio);//++

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);//++
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);//++

int cargarIdMaximo(LinkedList* pArrayListPassenger, int id);//++
int encontrarMaximoId(LinkedList* pArrayListPassenger);//++
void printOnePassenger(Passenger* Pasajero, int indice);//++
int buscarPassenger(LinkedList* pArrayListPassenger, int id);//++
int ordenarPasajerosPorId(void* pasajero1, void* pasajero2);//++
int ordenarPasajerosPorNombre(void* pasajero1, void* pasajero2);//++
int ordenarPasajerosPorApellido(void* pasajero1, void* pasajero2);//++
int ordenarPassengerPorPrecio(void* pasajero1, void* pasajero2);//++
int ordenarPasajerosPorEstadoVuelo(void* pasajero1, void* pasajero2);//++
#endif /* PASSENGER_H_ */
