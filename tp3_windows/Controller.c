#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 error y 0 (cero) en caso de exito
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pArchivo;

	pArchivo = fopen(path, "r");

	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		parser_EmployeeFromText(pArchivo, pArrayListEmployee);
		retorno = 0;
	}
	else
	{
		printf("\nError en la carga de este archivo!");
		fclose(pArchivo);
		retorno = -1;
	}

	fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 error y 0 (cero) en caso de exito
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pArchivo;

	pArchivo = fopen(path, "rb");

	if(pArrayListEmployee != NULL && pArchivo != NULL)
	{
		if(parser_EmployeeFromBinary(pArchivo , pArrayListEmployee) == 0)
		{
			retorno = 0;
		}
		else
		{
			fclose(pArchivo);
			retorno = -1;
		}
	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 error y 0 (cero) en caso de exito
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmpleado = NULL;
	int id = -1;
	int auxHorasTrabajadas;
	int auxSueldo;
	int respuesta;
	char nombre[128];
	char horasTrabajadas[100];
	char salario[100];
	char nuevaId[6];

	if(pArrayListEmployee != NULL)
	{
		id = encontrarMaximoId(pArrayListEmployee);
		itoa(id, nuevaId, 10);
			if(!utn_getNombre(nombre, 128,"\nIngrese el nombre del empleado:","\nError!",4) &&
				!utn_getNumero (&auxHorasTrabajadas,"\nIngrese las horas trabajadas del empleado: ", "\n\nERROR!!\n\n",0,1000000,5) &&
				!utn_getNumero (&auxSueldo,"\nIngrese el sueldo del empleado: ", "\n\nERROR!!\n\n",0,1000000,5))
			{
				itoa(auxHorasTrabajadas,horasTrabajadas,10);
				itoa(auxSueldo,salario,10);
				pEmpleado = employee_newParametros(nuevaId,nombre, horasTrabajadas, salario);
				if(!cargarIdMaximo(pArrayListEmployee, id))
				{
					printf("ID: %d", id);
				}
				if(pEmpleado != NULL)
					{
						respuesta = ll_add( pArrayListEmployee, pEmpleado);
						if (respuesta == 0)
						{
							retorno = 0;
						}
					}
			}
	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 error y 0 (cero) en caso de exito
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int len;

	len = ll_len(pArrayListEmployee);
	if(pArrayListEmployee != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			imprimirUnEmpleado(pArrayListEmployee,i);
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 error y 0 (cero) en caso de exito
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int id = -1;
	int indice = -1;
	int opcion;
	char nombre[128];
	char horasTrabajadas[100];
	char salario [100];
	void* pEmpleado = NULL;
	pEmpleado = employee_new();

	if (pArrayListEmployee != NULL && pEmpleado != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		utn_getNumero(&id,"\nIngrese el ID a modificar:", "\nERROR! ID INVÁLIDO.",0,10000,5);
		indice = buscarEmpleado(pArrayListEmployee, id);
		if(indice != -1)
		{
			imprimirUnEmpleado(pArrayListEmployee, indice);
			pEmpleado = ll_get(pArrayListEmployee, indice);
			if(pEmpleado != NULL)
			{
				if(!utn_getNumero(&opcion,"\nSeleccione lo que desea modificar.\n1)Nombre.\n2)Horas trabajadas.\n3)Sueldo.\n4)Salir\nIngrese la opción deseada:", "\nERROR!!!\n",0,5,5))
				{
					switch(opcion)
					{
					case 1:
						if(!utn_getNombre(nombre,128,"\nIngrese el nombre deseado:","\nERROR! Nombre invalido.",5))
						{
							employee_setNombre(pEmpleado, nombre);
							printf("\nEl nombre fue cambiado con exito!\n");
							imprimirUnEmpleado(pArrayListEmployee, indice);
						}
						break;
					case 2:
						if(!PedirString ("\nIngrese las horas trabajadas del empleado:", horasTrabajadas))
						{
							employee_setHorasTrabajadas(pEmpleado, atoi(horasTrabajadas));
							printf("\nLas horas trabajadas fueron cambiadas con exito!\n");
							imprimirUnEmpleado(pArrayListEmployee, indice);
						}
						break;
					case 3:
						if(!PedirString ("\nIngrese el salario del empleado:", salario))
						{
							employee_setSueldo(pEmpleado,atoi(salario));
							printf("\nEl sueldo fue cambiado  con exito!\n");
							imprimirUnEmpleado(pArrayListEmployee, indice);
						}
						break;
					case 4:
						break;
					}
				}
				retorno = 0;
			}
		}

	}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 error y 0 (cero) en caso de exito
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int resultadoBaja;
	int auxIndice = -1;
	int auxId = -1;
	int opcion;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		auxId = PedirEntero("Ingrese el ID del empleado a eliminar:");
		auxIndice = buscarEmpleado(pArrayListEmployee, auxId);

		if(auxIndice != -1)
		{
			imprimirUnEmpleado(pArrayListEmployee, auxIndice);
			if(!utn_getNumero(&opcion,"\n¿Desea eliminar este empleado?\n1)Si.\n2)No.\nIngrese una opción:","\nERROR! Numero invalido",0,3,5))
			{
				switch(opcion)
				{
				case 1:
					resultadoBaja = ll_remove(pArrayListEmployee, auxIndice);
					if (resultadoBaja == 0)
					{
						retorno = 0;
					}
					else
					{
						printf("\nOcurrio un error y no se pudo dar de baja el empleado. Reintentelo");
					}
					break;
				case 2:
					break;
				}
			}

		}
		else
		{
			printf("\nID incorrecto!");
		}

	}
    return retorno;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 error y 0 (cero) en caso de exito
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	int orden;

	if(!utn_getNumero(&opcion,"\n\n¿Por cual elemento desea ordenar?\n1)ID.\n2)Nombre.\n3)Horas trabajadas.\n4)Sueldo.\nIngrese una opcion:","\n\nERROR!!!!!\n\n",0,5,5))
	{
		if(!utn_getNumero(&orden,"\n¿De que manera desea hacerlo?\n1)Ascendente.\n2)Descendente.\nIngrese una opcion:","\n\nERROR!!!\n\n",0,3,5))
		{
			switch(orden)
			{
			case 1:
				orden = 0;
				break;
			case 2:
				orden = 1;
				break;
			}
			switch(opcion)
			{
			case 1:
				if(!ll_sort(pArrayListEmployee, ordenarEmpleadosPorId, orden))
				{
					printf("\nSe ha ordenado la lista de empleados por ID.");
					retorno = 0;
				}
				else
				{
					printf("\nNo se pudo realizar el ordenamiento solicitado.");
				}
				break;
			case 2:
				if(!ll_sort(pArrayListEmployee,ordenarEmpleadosPorNombre,orden))
				{
					printf("\nSe ha ordenado la lista de empleados por sus nombres.");
					retorno = 0;
				}
				else
				{
					printf("\nNo se pudo realizar el ordenamiento solicitado.");
				}
				break;
			case 3:
				if(!ll_sort(pArrayListEmployee,ordenarEmpleadoPorHorasTrabajadas,orden))
				{
					printf("\nSe ha ordenado la lista de empleados por sus Horas Trabajadas.");
					retorno = 0;
				}
				else
				{
					printf("\nNo se pudo realizar el ordenamiento solicitado.");
				}
				break;
			case 4:
				if(!ll_sort(pArrayListEmployee,ordenarEmpleadosPorSueldos,orden))
				{
					printf("\nSe ha ordenado la lista de empleados por sus Horas Trabajadas.");
					retorno = 0;
				}
				else
				{
					printf("\nNo se pudo realizar el ordenamiento solicitado.");
				}
				break;
			}
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 error y 0 (cero) en caso de exito
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int len;
	Employee* pEmpleado = NULL;
	int auxId;
	int auxHorasTrabajadas;
	int auxSueldo;
	char auxNombre[128];
	FILE* pArchivo = NULL;

	pArchivo = fopen(path, "w");
	len = ll_len(pArrayListEmployee);

	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		fprintf(pArchivo, "id,nombre,horasTrabajadas,sueldo\n");
		for(int i = 0;i<len;i++)
		{
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			if(pEmpleado != NULL)
			{
				if(!employee_getId(pEmpleado, &auxId))
				{
					if(!employee_getNombre(pEmpleado, auxNombre))
					{
						if(!employee_getHorasTrabajadas(pEmpleado, &auxHorasTrabajadas))
						{
							if(!employee_getSueldo(pEmpleado, &auxSueldo))
							{
								fprintf(pArchivo,"%d,%s,%d,%d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
							}
						}
					}
				}
			}
		}
		retorno = 0;
	}
	fclose(pArchivo);
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna -1 error y 0 (cero) en caso de exito
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmpleado = NULL;
	int len;
	FILE* pArchivo;

	len = ll_len(pArrayListEmployee);
	pArchivo = fopen(path, "wb");

	if(pArrayListEmployee != NULL && pArchivo != NULL)
	{
		for(int i=0;i<len;i++)
		{
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			if(pEmpleado != NULL)
			{
				fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
			}
		}
		retorno = 0;
	}
	fclose(pArchivo);
    return retorno;
}

