#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "TP2.H"
#include "ArrayEmployees.h"
#define TAMCLIENTES 1001
#define TRUE 1
#define FALSE 0

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int indiceLugarLibre;
	int flagAlta = 0;
	int idEmpleado = 0;
	int idBajaEmpleado;
	int opcionInforme;
	int respuestaOrden;

	Employee listaDeEmpleados[TAMCLIENTES];
	Employee bufferEmpleados[TAMCLIENTES];

	if(initEmployees(listaDeEmpleados, TAMCLIENTES))
	{
		printf("Error en la inicializacion!.\n");
	}


	do
			    {
		        if(utn_getNumero(&opcion, "\nSeleccione una opcion\n1) Altas.\n2) Modificar.\n3) Baja.\n4) Informar.\n5) Salir.\n\nIngrese la opcion: ", "\nNo es una opcion valida\n", 1,5,4) == 0)
		        {
		        	switch(opcion)
					{
						case 1:
							indiceLugarLibre = getEmptyIndex(listaDeEmpleados,TAMCLIENTES);
							if(indiceLugarLibre >= 0 && listaDeEmpleados != NULL && indiceLugarLibre < TAMCLIENTES)
							{
								if(pedirDatosParaElAlta(bufferEmpleados,&idEmpleado, TAMCLIENTES, indiceLugarLibre) == 0)
								{
									listaDeEmpleados[indiceLugarLibre] = bufferEmpleados[indiceLugarLibre];

									if(addEmployee(listaDeEmpleados, TAMCLIENTES, idEmpleado, listaDeEmpleados[indiceLugarLibre].name,listaDeEmpleados[indiceLugarLibre].lastName,listaDeEmpleados[indiceLugarLibre].salary,listaDeEmpleados[indiceLugarLibre].sector) == 0)
									{
										printf("\nEl empleado ha sido dado de alta.\n");
									}
									else
									{
										printf("\nNo hay mas cupos de empleo disponible.");
									}
								}
							}
							flagAlta = 1;
							break;
						case 2:
							if(flagAlta)
							{
								if(modificarEmpleado(listaDeEmpleados, TAMCLIENTES) == 0)
								{
									printf("\nSe pudieron realizar las modificaciones correctamente.\n");
								}
								else
								{
									printf("\nNo se pudieron realizar las modificaciones.\n");
								}
							}
							else
							{
								printf("\nDebe de dar de alta un usuario antes de realizar esta accion.\n");
							}
							break;
						case 3:
							if(flagAlta)
							{
								printEmployees(listaDeEmpleados, TAMCLIENTES);
								if (utn_getNumero(&idBajaEmpleado, "\nIngrese el id del empleado: ", "\nEl id es invalido.", 0, 1000000,2) == 0 &&
									removeEmployee (listaDeEmpleados, TAMCLIENTES, idBajaEmpleado) == 0	)
								{
									printf("\nSe realizo la baja del empleado.\n");
								}
								else
								{
									printf("\nNo se pudo realizar la baja del empleado.\n");
								}
							}
							else
							{
								printf("\nDebe de dar de alta un usuario antes de realizar esta accion.\n");
							}

							break;
						case 4:
							if(flagAlta)
							{
								if(utn_getNumero(&opcionInforme, "\n¿Que desea que se le informe?\n1.Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n2.Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\nIngrese la opcion: ", "Error",1 , 2 , 5) == 0)
								{
									switch(opcionInforme)
								{
								case 1:
									utn_getNumero(&respuestaOrden, "Indique que opcion desea para ordenar.\n1)Para ordenamiento ascendente.\n2)Para ordenamiento descendiente.\n¿Cual prefiere?\n", "\nError!\n", 0, 1, 53);
									if(sortEmployees(listaDeEmpleados, TAMCLIENTES, respuestaOrden) == 0)
									{
										printf("\nEl listado fue ordenado con exito.\n");
										printEmployees(listaDeEmpleados, TAMCLIENTES);
									}
									else
									{
										printf("\nEl listado no pudo ser odenado.\n");
									}
								break;
								case 2:
									if(promedioSalarios (listaDeEmpleados, TAMCLIENTES) == 0)
									{
										printf("\nLos promedios se realizaron correctamente.\n");
									}
									else
									{
										printf("\nLos promedios no puedieron realizarse.\n");
									}
								}
								}
							}
							else
							{
								printf("\nDebe de dar de alta un usuario antes de realizar esta accion.\n");
							}

							break;
						case 5:
							break;
					}

	            }
			    } while (opcion != 5);
	return 0;
	}

