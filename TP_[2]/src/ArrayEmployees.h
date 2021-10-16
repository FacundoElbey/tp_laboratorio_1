#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TP2.H"
#define TAM 1000
#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

int getEmptyIndex(Employee*,int);
int pedirDatosParaElAlta(Employee*, int*,int, int);
int addEmployee(Employee* , int , int , char[],char[],float,int);
int initEmployees(Employee* , int );
int printEmployees(Employee*, int);
int printEmployee (Employee*);
int findEmployeeById(Employee*, int, int);
int removeEmployee(Employee* , int , int );
int modificarEmpleado (Employee*, int);
int sortEmployees(Employee*, int, int);
int promedioSalarios (Employee*, int);


#endif /* ARRAYEMPLOYEES_H_ */
