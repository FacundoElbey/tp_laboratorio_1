#include "Employee.h"

Employee* employee_new()
{
	Employee* nuevoEmpleado;

	nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

	return nuevoEmpleado;
}

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

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

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
