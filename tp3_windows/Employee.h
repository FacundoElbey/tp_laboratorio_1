#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new(); //constructor
Employee* employee_newParametros(char*,char*,char*, char*);
void employee_delete(Employee* this); //para liberarlo

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int cargarIdMaximo(LinkedList*, int);
int encontrarMaximoId(LinkedList*);
void imprimirUnEmpleado(LinkedList*, int);
int buscarEmpleado(LinkedList*, int);
int ordenarEmpleadosPorId(void*, void*);
int ordenarEmpleadosPorNombre(void*, void*);
int ordenarEmpleadoPorHorasTrabajadas(void*, void*);
int ordenarEmpleadosPorSueldos(void*, void*);

#endif // employee_H_INCLUDED
