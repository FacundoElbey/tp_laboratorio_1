#include "Employee.h"

/***
 * \fn Employee employee_new*()
 * \brief  Constructor de un empleado
 *
 * \return retorna un puntero a la dirección de memoria dónde se va a encontrar este empleado
 */
Employee* employee_new()
{
	Employee* nuevoEmpleado;
	nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

	return nuevoEmpleado;
}
/***
 * \fn Employee employee_newParametros*(char*, char*, char*, char*)
 * \brief Esta funcion valida todos los datos y utiliza los setter para asignarle esos valores al empleado
 *
 * \param idStr Id que se le va a asignar al nuevo empleado
 * \param nombreStr Nombre que se le va a asignar al nuevo empleado
 * \param horasTrabajadasStr Horas trabajadas que se le van a asignar al nuevo empleado
 * \param sueldoStr Salario que se le va a asignar al nuevo empleado
 * \return retorna un puntero a la dirección de memoria dónde se va a encontrar este empleado
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* empleado = employee_new();

	Employee* auxEmpleado = employee_new();

	if(empleado != NULL && auxEmpleado != NULL)
	{
		if(employee_setId(auxEmpleado, atoi(idStr)) == 0) //employee_setId(empleado, atoi(idStr));
			{
				if(employee_setNombre(auxEmpleado,nombreStr) == 0) // employee_setNombre(empleado,nombreStr);
				{
					if(employee_setHorasTrabajadas(auxEmpleado, atoi(horasTrabajadasStr)) == 0) //employee_setHorasTrabajadas(empleado, horasTrabajadasStr);
					{
						if(employee_setSueldo(auxEmpleado, atoi(sueldoStr)) == 0) //employee_setSueldo(empleado, sueldoStr);
						{
							employee_setId(empleado, atoi(idStr));
							employee_setNombre(empleado,nombreStr);
							employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr));
							employee_setSueldo(empleado, atoi(sueldoStr));
							employee_delete(auxEmpleado);
						}
					}
				}
			}
	}
	else
	{
		printf("\nError en la carga del empleado!");
		employee_delete(auxEmpleado);
	}
	return empleado;
}

/***
 * \fn void employee_delete(Employee*)
 * \brief libera el puntero que apuntaba hacia esa direccion de memoria
 *
 * \param this puntero haciia el empleado
 */
void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

/***
 * \fn int employee_setId(Employee*, int)
 * \brief  Valida y settea el ID al empleado correspondiente
 *
 * \param this puntero hacia el empleado
 * \param id el id que fue validado en el new parametros.
 * \return retorna 0 en caso de exito y -1 en caso de error
 */
int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if (this != NULL && id >= 0 && id < 10000)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

/***
 * \fn int employee_getId(Employee*, int*)
 * \brief devuelve al puntero *id que se le pasa, el id del empleado que esta en la direccion de memoria que se le pasa
 *
 * \param this puntero hacia el empleado
 * \param id el id del empleado
 * \return retorna 0 en caso de exito y -1 en caso de error
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

/***
 * \fn int employee_setNombre(Employee*, char*)
 * \brief  El nombre que le es pasado lo guarda en el empleado que también le es pasado como parametro
 *
 * \param this puntero al empleado
 * \param nombre puntero al nombre
 * \return retorna 0 en caso de exito y -1 en caso de error
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	int len;
	len = strlen(nombre);

	if( this != NULL && nombre != NULL && len > 0)
	{
		strncpy(this->nombre, nombre, 128);
		retorno = 0;
	}
	return retorno;
}

/***
 * \fn int employee_getNombre(Employee*, char*)
 * \brief Se copia el nombre del empleado a la variable a la cual apunta el puntero char* que nos pasan
 *
 * \param this puntero al empleado
 * \param nombre puntero al nombre
 * \return retorna 0 en caso de exito y -1 en caso de error
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	int len;
	len = strlen(nombre);

	if(this != NULL && nombre != NULL && len>0)
	{
		strncpy(nombre, this->nombre, 128);
		retorno = 0;
	}
	return retorno;
}

/***
 * \fn int employee_setHorasTrabajadas(Employee*, int)
 * \brief las horas trabajadas que le son pasadas la guarda en el empleado que también se le es pasado como parametro
 *
 * \param this puntero al empleado
 * \param horasTrabajadas entero con la cantidad de horas trabajadas
 * \return retorna 0 en caso de exito y -1 en caso de error
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/***
 * \fn int employee_getHorasTrabajadas(Employee*, int*)
 * \brief Copia las horas trabajas que estan cargadas en el empleado a la variable a la cual apunta el puntero int*
 *
 * \param this puntero al empleado
 * \param horasTrabajadas puntero al cual copiaremos las horas trabajadas
 * \return retorna 0 en caso de exito y -1 en caso de error
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if(this != NULL && horasTrabajadas != NULL && horasTrabajadas > 0)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

/***
 * \fn int employee_setSueldo(Employee*, int)
 * \brief el sueldo que le es pasado lo guarda en el empleado que también se le es pasado como parametro
 *
 * \param this puntero al empleado
 * \param sueldo valor del sueldo del empleado
 * \return retorna 0 en caso de exito y -1 en caso de error
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

/***
 * \fn int employee_getSueldo(Employee*, int*)
 * \brief Copia el sueldo que esta cargado en el empleado a la variable a la cual apunta el puntero int*
 *
 * \param this puntero al empleado
 * \param sueldo puntero al cual copiaremos el sueldo
 * \return retorna 0 en caso de exito y -1 en caso de error
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL && sueldo > 0)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

/***
 * \fn int cargarIdMaximo(LinkedList*, int)
 * \brief Carga el id de mayor valor que se dio de alta
 *
 * \param pArrayListEmployee La lista de empleados
 * \param id Ultimo id que se dio de alta, por ende el mayor
 * \return retorna 0 en caso de exito y -1 en caso de error
 */
int cargarIdMaximo(LinkedList* pArrayListEmployee, int id)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

	pArchivo = fopen("ID.txt", "w");
	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		fprintf(pArchivo,"%d", id);
		retorno = 0;
	}
	fclose(pArchivo);
	return retorno;
}

/***
 * \fn int encontrarMaximoId(LinkedList*)
 * \brief Lee el archivo con el ID maximo y le suma 1, y ese id es el que se le da al nuevo usuario
 *
 * \param pArrayListEmployee La lista de empleados
 * \return retorna el id maximo
 */
int encontrarMaximoId(LinkedList* pArrayListEmployee)
{
	FILE* pArchivo = NULL;
	int idMaximo;
	char auxId[100];

	pArchivo = fopen("ID.txt", "r");

	if(pArchivo != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pArchivo,"%s", auxId);
		idMaximo = atoi(auxId);
		idMaximo++;
	}
	fclose(pArchivo);
	return idMaximo;
}

/***
 * \fn void imprimirUnEmpleado(LinkedList*, int)
 * \brief Imprime el empleado que le es pedido
 *
 * \param pArrayListEmployee La lista de empleados
 * \param id id del empleado a imprimir
 */
void imprimirUnEmpleado(LinkedList* pArrayListEmployee, int id)
{
	Employee *pEmpleado;
	int auxId;
	int auxHorasTrabajadas;
	int auxSalario;
	char auxNombre [128];

	if(pArrayListEmployee != NULL)
	{
		pEmpleado = ll_get(pArrayListEmployee, id);
		if(pEmpleado != NULL)
		{
			if(!employee_getId(pEmpleado, &auxId))
			{
				if(!employee_getNombre(pEmpleado, auxNombre))
				{
					if(!employee_getHorasTrabajadas(pEmpleado, &auxHorasTrabajadas))
					{
						if(!employee_getSueldo(pEmpleado, &auxSalario))
						{
							employee_getId(pEmpleado, &auxId);
							employee_getNombre(pEmpleado, auxNombre);
							employee_getHorasTrabajadas(pEmpleado, &auxHorasTrabajadas);
							employee_getSueldo(pEmpleado, &auxSalario);
							printf("ID: %d - Nombre: %s - Horas trabajadas: %d - Sueldo: %d\n", auxId, auxNombre, auxHorasTrabajadas, auxSalario);
						}
					}
				}
			}
		}
	}
}

/***
 * \fn int buscarEmpleado(LinkedList*, int)
 * \brief Se va a buscar un empleado con el id que se le es pasado a la funcion
 *
 * \param pArrayListEmployee La lista de empleados
 * \param id el campo por el cual se va a buscar al empleado
 * \return retorna el indice de dicho empleado
 */
int buscarEmpleado(LinkedList* pArrayListEmployee, int id)
{
	Employee* pEmpleado;
	int retorno = -1;
	int len;
	int auxId = -1;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		for(int i=0; i<len; i++)
		{
			pEmpleado = (Employee*) ll_get(pArrayListEmployee , i);
			if(pEmpleado != NULL)
			{
				employee_getId(pEmpleado, &auxId);
				if(!employee_getId(pEmpleado, &auxId))
				{
					if(id == auxId)
					{
						retorno = i;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

/***
 * \fn int ordenarEmpleadosPorId(void*, void*)
 * \brief Compara empleados y devuelve un valor dependiendo de cual sea el empleado con mayor id
 *
 * \param empleado1 primer empleado a comparar
 * \param empleado2 segundo empleado a comparar
 * \return devuelve 1 si el ID del segunod empleado es mayor, si el ID del primero es mayor se devuelve -1
 */
int ordenarEmpleadosPorId(void* empleado1, void* empleado2)
{
	int retorno = 0;
	int empleado1Id;
	int empleado2Id;

	employee_getId(empleado1, &empleado1Id);
	employee_getId(empleado2, &empleado2Id);

	if(empleado1 != NULL && empleado2 != NULL)
	{
		if(empleado1Id<empleado2Id)
		{
			retorno = 1;
		}
		else if(empleado1Id>empleado2Id)
		{
			retorno = -1;
		}
	}
	return retorno;
}

/***
 * \fn int ordenarEmpleadosPorNombre(void*, void*)
 * \brief Compara el nombre de los empleados y devuelve un valor dependiendo de cual es mayor
 *
 * \param empleado1 primer empleado a comparar
 * \param empleado2 segundo empleado a comparar
 * \return devuelve un valor menor a 0 si el empleado 1 es menor a empleado , si el empleado2 es menor al empleado1 devuelve un mayor a, y si son iguales devuelve 0.
 */
int ordenarEmpleadosPorNombre(void* empleado1, void* empleado2)
{
	int retorno = 0;
	char empleado1Nombre[128];
	char empleado2Nombre[128];

	employee_getNombre(empleado1,empleado1Nombre);
	employee_getNombre(empleado2,empleado2Nombre);

	if(empleado1 != NULL && empleado2 != NULL)
	{
		retorno = strcmp (empleado2,empleado1);
	}
	return retorno;
}

/***
 * \fn int ordenarEmpleadoPorHorasTrabajadas(void*, void*)
 * \brief Compara las horas trabajadas de los empleados y devuelve un valor dependiendo de cual es mayor
 *
 * \param empleado1 primer empleado a comparar
 * \param empleado2 segundo empleado a comparar
 * \return devuelve 1 si las horas trabajadas del segundo empleado son mayor, si las horas trabajadas del primero son mayores se devuelve -1
 */
int ordenarEmpleadoPorHorasTrabajadas(void* empleado1, void* empleado2)
{
	int retorno = 0;
	int empleado1Horas;
	int empleado2Horas;

	if(empleado1 != NULL && empleado2 != NULL)
	{
		employee_getHorasTrabajadas(empleado1, &empleado1Horas);
		employee_getHorasTrabajadas(empleado2, &empleado2Horas);
		if (empleado1<empleado2)
		{
			retorno = 1;
		}
		else if (empleado1>empleado2)
		{
			retorno = -1;
		}
		else if (empleado1 == empleado2)
		{
			retorno = 0;
		}
	}
	return retorno;
}

/***
 * \fn int ordenarEmpleadosPorSueldos(void*, void*)
 * \brief Compara el sueldo de los empleados y devuelve un valor dependiendo de cual es mayor
 *
 * \param empleado1 primer empleado a comparar
 * \param empleado2 segundo empleado a comparar
 * \return devuelve 1 si el sueldo del segundo empleado es mayor, si el sueldo del primero es mayor se devuelve -1 y si son iguales se devuelve 0
 */
int ordenarEmpleadosPorSueldos(void* empleado1, void* empleado2)
{
	int retorno = 0;
	int empleado1Sueldo;
	int empleado2Sueldo;

	if (empleado1 != NULL && empleado2 != NULL)
	{
		employee_getSueldo(empleado1, &empleado1Sueldo);
		employee_getSueldo(empleado2, &empleado2Sueldo);

		if(empleado1Sueldo<empleado2Sueldo)
		{
			retorno = 1;
		}
		else if(empleado1Sueldo>empleado2Sueldo)
		{
			retorno = -1;
		}
		else if(empleado1Sueldo==empleado2Sueldo)
		{
			retorno = 0;
		}
	}
	return retorno;
}
