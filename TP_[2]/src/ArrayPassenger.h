/*
 * ArrayPassenger.h
 *
 *  Created on: 26 abr. 2022
 *      Author: river
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Biblioteca.h"
#define TRUE 0
#define FALSE 1
#define ACTIVO 2
#define CANCELADO 3
#define NOMBRE_LEN 51

typedef struct
{
	int id;
	char name[NOMBRE_LEN];
	char lastName[NOMBRE_LEN];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

int initPassengers(Passenger list[], int len);
int hardCodeoPasajero(Passenger list[], int len);
int findEmptyIndex(Passenger list[], int len);
int addPassenger(Passenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);
int uploadPassenger(Passenger list[], int len);
int printOnePassenger (Passenger* list);
int printPassenger(Passenger* list, int len);
int findPassengerById(Passenger list[], int len, int id);
int modificarPasajero(Passenger list[], int len);
int removePassenger(Passenger list[], int len, int id);
int bajaPasajero(Passenger list[], int len);
int sortPassengers(Passenger* list, int len, int order);
int sortPassengersByCode(Passenger* list, int len);
void opcionesInformes();
int totalPrecioPasajes (Passenger list[], int len, int* acumulador);
int promedioPrecioPasajes(Passenger list[], int len, int precioTotal, int* precioPromedio);
int precioMayorAlPromedio(Passenger list[], int len, int precioPromedio, int* acumulador);
int menuInformes(Passenger list[], int len);

#endif /* ARRAYPASSENGER_H_ */
