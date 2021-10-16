#include <stdio.h>
#include <string.h>
#include "TP2.H"
#include "ArrayEmployees.h"
#define TAM 1000
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

	Employee listaDeEmpleados[TAM];
	Employee bufferEmpleados[TAM];

	if(initEmployees(listaDeEmpleados, TAM))
	{
		printf("Error en la inicializaci�n!.\n");
	}


	do
			    {
			fflush(stdin);
		        if(utn_getNumero(&opcion, "\nSeleccione una opci�n\n1) Altas.\n2) Modificar.\n3) Baja.\n4) Informar.\n5) Salir.\n\nIngrese la opci�n: ", "\nNo es una opci�n v�lida\n", 1,5,4) == 0)
		        {
		            switch(opcion)
		            {
		                case 1:
		                	indiceLugarLibre = getEmptyIndex(listaDeEmpleados,TAM);
		    				if(indiceLugarLibre >= 0 && listaDeEmpleados != NULL && indiceLugarLibre < TAM)
		    				{
		    					if(pedirDatosParaElAlta(bufferEmpleados,&idEmpleado, TAM, indiceLugarLibre) == 0)
		    					{
		    						listaDeEmpleados[indiceLugarLibre] = bufferEmpleados[indiceLugarLibre];

		    						if(addEmployee(listaDeEmpleados, TAM, idEmpleado, listaDeEmpleados[indiceLugarLibre].name,listaDeEmpleados[indiceLugarLibre].lastName,listaDeEmpleados[indiceLugarLibre].salary,listaDeEmpleados[indiceLugarLibre].sector) == 0)
		    						{
		    							printf("\nEl empleado ha sido dado de alta.\n");
		    						}
		    						else
		    						{
		    							printf("\nNo hay m�s cupos de empleo disponible.");
		    						}
		    					}
		    				}
		                	flagAlta = 1;
		                    break;
		                case 2:
		                	if(flagAlta)
		                	{
		                		if(modificarEmpleado(listaDeEmpleados, TAM) == 0)
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
		                		printf("\nDebe de dar de alta un usuario antes de realizar esta acci�n.\n");
		                	}
		                    break;
		                case 3:
		                	if(flagAlta)
		                	{
		                		printEmployees(listaDeEmpleados, TAM);
		                		if (utn_getNumero(&idBajaEmpleado, "\nIngrese el id del empleado: ", "\nEl id es inv�lido.", 0, 1000000,2) == 0 &&
		                			removeEmployee (listaDeEmpleados, TAM, idBajaEmpleado) == 0	)
		                		{
		                			printf("\nSe realiz� la baja del empleado.\n");
		                		}
		                		else
		                		{
		                			printf("\nNo se pudo realizar la baja del empleado.\n");
		                		}
		                	}
		                	else
		                	{
		                		printf("\nDebe de dar de alta un usuario antes de realizar esta acci�n.\n");
		                	}

		                    break;
		                case 4:
		                	if(flagAlta)
		                	{
		                		if(utn_getNumero(&opcionInforme, "\n�Qu� desea que se le informe?\n1.Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.\n2.Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.\nIngrese la opci�n: ", "Error",1 , 2 , 5) == 0)
		                		{
		                			switch(opcionInforme)
		                		{
		                		case 1:
		                			utn_getNumero(&respuestaOrden, "Indique que opci�n desea para ordenar.\n1)Para ordenamiento ascendente.\n2)Para ordenamiento descendiente.\n�Cu�l prefiere?\n", "\nError!\n", 0, 1, 53);
									if(sortEmployees(listaDeEmpleados, TAM, respuestaOrden) == 0)
									{
										printf("\nEl listado fue ordenado con �xito.\n");
										printEmployees(listaDeEmpleados, TAM);
									}
									else
									{
										printf("\nEl listado no pudo ser odenado.\n");
									}
		                		break;
		                		case 2:
		                			if(promedioSalarios (listaDeEmpleados, TAM) == 0)
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
		                		printf("\nDebe de dar de alta un usuario antes de realizar esta acci�n.\n");
		                	}

		                    break;
		                case 5:
		                    break;
		            }
	             }
			    } while (opcion != 5);
	return 0;
	}

