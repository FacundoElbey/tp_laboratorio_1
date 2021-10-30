#include "TP2.H"
#include "ArrayEmployees.h"

/***
 * \fn int getEmptyIndex(Employee*, int)
 * \brief Busca un ID automicaticamente y lo devuelve
 *
 * \param listaEmpleados el array de empleados
 * \param tam la cantidad de empleados
 * \return retorna -1 como error y sino retorna el ID
 */
int getEmptyIndex(Employee* plistaEmpleados,int tam)
{
	int retorno = -1;
	int i;
	if(plistaEmpleados != NULL && tam > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(plistaEmpleados[i].isEmpty == TRUE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

/****
 * \fn int pedirDatosParaElAlta(Employee*, int*, int, int)
 * \brief En esta funciòn vamos a pedir y validar todo los datos necesarios para el alta de un usuario
 *
 * \param buffer Empleados es el array auxiliar con el cual tomo los datos
 * \param id el id que es generada en otra funciòn
 * \param tam el tamaño del array
 * \param indice el indice del array (la posicion)
 * \return retorna -1 en caso de error y 0 en caso de exito
 */
int pedirDatosParaElAlta(Employee* bufferEmpleados, int* id, int tam, int indice)
{
	int retorno = -1;

	if(bufferEmpleados != NULL && indice < tam)
	{
		retorno = 0;
		utn_getNombre(bufferEmpleados[indice].name, 51, "\nIngrese el nombre del empleado: ", "\nNombre inválido.",2);
		utn_getNombre(bufferEmpleados[indice].lastName, 51, "\nIngrese el apellido del empleado: ", "\nApellido inválido",2);
		utn_getNumeroFlotante(&bufferEmpleados[indice].salary,"\nIngrese el salario del empleado: ","\nEl salario es inválido, intente de nuevo.",0.01,10000000,2);
		utn_getNumero(&bufferEmpleados[indice].sector, "\nIngrese el sector del trabajador: ", "El sector es inválido", 0, 1000000,2);
		bufferEmpleados[indice].id = *id;
		*id = *id + 1;
	}
	return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
**/
int addEmployee(Employee* pListaDeEmpleados, int tam, int id, char name[],char lastName[],float salary,int sector) //BIEN HECHA YA
{
	int retorno = -1;
	if(pListaDeEmpleados != NULL && id != 0)
	{
		retorno = 0;
		pListaDeEmpleados[id].isEmpty = FALSE;
	}
	return retorno;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* pListaEmpleados, int tam)
{
	int retorno =  -1;
	int i;
	if(pListaEmpleados != NULL && tam > 0)
	{
		setbuf(stdout, NULL);
		retorno = 0;
		for(i=0; i<tam; i++)
		{
			pListaEmpleados[i].isEmpty = TRUE;
		}
	}
	return retorno;
}

/***
 * \fn int printEmployee(Employee*)
 * \brief imprime 1 elemento del array
 *
 * \param pEmpleado puntero del array
 * \return retorna -1 en caso de error y 0 en caso de exito
 */
int printEmployee (Employee* pEmpleado)
{
	int retorno = -1;

	if(pEmpleado != NULL && pEmpleado->isEmpty == FALSE)
	{
		retorno = 0;
		printf("\nID: %d - NOMBRE: %s - APELLIDO: %s - SALARIO: $%.2f - SECTOR: %d", pEmpleado->id, pEmpleado->name, pEmpleado->lastName, pEmpleado->salary, pEmpleado->sector);
	}
	return retorno;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* pListaEmpleados, int tam)
{
	int retorno = -1;

	for (int i = 0; i < tam ; i++)
	{
		if(pListaEmpleados[i].isEmpty == FALSE)
		{
			printEmployee(&pListaEmpleados[i]);
		}
	}

	return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/

int findEmployeeById(Employee* listaEmpleados, int longitud, int idTrabajador)
{
	int retorno = -1;

    for(int i = 0 ; i < longitud ; i++)
    {
        if(listaEmpleados[i].id == idTrabajador)
        {
        	printEmployee(&listaEmpleados[i]);
            retorno = 0;
        }
    }
    return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/

int removeEmployee(Employee* listaEmpleados, int tam, int id) //BIEN HECHO
{
	int retorno = -1;

    for(int i = 0 ; i < tam ; i++)
    {

      if(listaEmpleados[i].isEmpty != TRUE && listaEmpleados[i].id == id)
      {

         listaEmpleados[i].isEmpty = TRUE;
         retorno = 0;
         break;
      }
    }

    return retorno;
}
/***
 * \fn int modificarEmpleado(Employee*, int)
 * \brief Esta funciòn nos permite modificar cualquier dato del array a traves del ID
 *
 * \param listaEmpleados array de empleados
 * \param tam tamaño del array
 * \return retorna -1 en caso de error y 0 en caso de exito
 */
int modificarEmpleado (Employee* pListaEmpleados, int tam)
{
	int retorno = -1;
	int IdEmpleado;
	int respuesta;

	printEmployees(pListaEmpleados, tam);

	utn_getNumero(&IdEmpleado, "\nIngrese el ID del empleado a modificar: ", "\nError.", 0 , 10000,4);


      for(int i = 0 ; i < tam ; i++){

        if(pListaEmpleados[i].isEmpty != TRUE && pListaEmpleados[i].id == IdEmpleado)
        {
        	retorno = 0;
        	do
        	{
        		if(utn_getNumero(&respuesta, "Ingrese lo que desea cambiar.\n1)Nombre.\n2)Apellido.\n3)Salario.\n4)Sector.\n5)Nada más.\nIngrese una opción: ", "\nNo es una opción válida\n", 1,5,4) == 0)
        		{
        			switch(respuesta)
        			{
        			case 1:
        				utn_getNombre(pListaEmpleados[i].name, 51, "\nIngrese el nombre del empleado: ", "\nNombre invalido.",2);
        				break;
        			case 2:
        				utn_getNombre(pListaEmpleados[i].lastName, 51, "\nIngrese el apellido del empleado: ", "\nApellido invalido.",2);
        				break;
        			case 3:
        				utn_getNumeroFlotante(&pListaEmpleados[i].salary,"\nIngrese el salario del empleado: ","\nEl salario es invalido, intente de nuevo.",0.01,10000000,2);
        				break;
        			case 4:
        				utn_getNumero(&pListaEmpleados[i].sector, "\nIngrese el sector del trabajador: ", "El sector es invalido", 0, 1000000,2);
        				break;
        			case 5:
        				break;
        			}
        		}

        	} while (respuesta != 5);
        }
      }
      return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* listaEmpleados, int tam, int orden)
{
	int retorno = -1;
	Employee buffer;

	if (listaEmpleados != NULL && tam > 0)
	{
		  for(int i=0;i<tam-1;i++)
		  {
			  if (orden == 1)
			  {
				  if(strncmp(listaEmpleados[i].lastName, listaEmpleados[i-1].lastName, 51) > 0 || (strncmp(listaEmpleados[i].lastName, listaEmpleados[i-1].lastName, 51) == 0 && listaEmpleados[i].sector > listaEmpleados[i-1].sector))
			  	  {
				  retorno = 0;
				  buffer = listaEmpleados[i];
				  listaEmpleados[i] = listaEmpleados[i+1];
				  listaEmpleados[i+1] = buffer;
			  	  }
			  }
			  else if (orden == 0)
			  {
				  if(strncmp(listaEmpleados[i].lastName, listaEmpleados[i-1].lastName, 51) < 0 || (strncmp(listaEmpleados[i].lastName, listaEmpleados[i-1].lastName, 51) == 0 && listaEmpleados[i].sector < listaEmpleados[i-1].sector))
				  {
					  retorno = 0;
					  buffer = listaEmpleados[i];
					  listaEmpleados[i] = listaEmpleados[i+1];
					  listaEmpleados[i+1] = buffer;
				  }
			  }

		  tam--;
		  }
	}

	return retorno;
}


int promedioSalarios (Employee* listaEmpleados, int tam)
{
	int retorno = -1;
	float salarioPromedio;
	float salarioTotal = 0;
	int canPersonas = 0;
	int acumuladorSalarioAlto = 0;
	int i;
	int j;

	for(i=0;i<tam;i++)
	{
		retorno = 0;

		if(listaEmpleados[i].isEmpty == FALSE)
		{
			salarioTotal = salarioTotal + listaEmpleados[i].salary;
			canPersonas++;
		}
	}

	salarioPromedio = salarioTotal / canPersonas;

	for(j=0;j<tam;j++)
	{
		if(listaEmpleados[j].isEmpty == FALSE)
		{
			if(listaEmpleados[j].salary > salarioPromedio)
			{
			acumuladorSalarioAlto++;
			}
		}
	}

	printf("\nEl salario total es: %.2f\nEl salario promedio es: %.2f\nLas personas que tienen un salario mayor al promedio son: %d\n", salarioTotal, salarioPromedio, acumuladorSalarioAlto);

	return retorno;
}


