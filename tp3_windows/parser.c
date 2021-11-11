#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	Employee *auxEmployee = employee_new();
	int retorno = -1;
	char auxId[100];
	char auxNombre[100];
	char auxHorasTrabajadas[100];
	char auxSueldo[100];
	int l = 0;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		l = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo); //voy a leer los titulos
		while (!feof(pFile)) {
			l = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo); //lee el arhivo completo
			if (l == 4) {
				if (auxEmployee != NULL) {
					if (esNumerica(auxId, 100) && esSoloLetras(auxNombre) &&
							esNumerica(auxHorasTrabajadas, 100)  && esNumerica(auxSueldo, 100)) {
						auxEmployee = employee_newParametros(auxId, auxNombre,
								auxHorasTrabajadas, auxSueldo);
						if (auxEmployee != NULL) {
							ll_add(pArrayListEmployee, auxEmployee);
							retorno = 0;
						}
					}
				}
			} else {
				break;
			}
		}
	}
	fclose(pFile);
	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	Employee auxEmployee;
	int leidos = 0;

	if (pArrayListEmployee != NULL) {
		leidos = fread(&auxEmployee, sizeof(Employee), 1, pFile);
		while (!feof(pFile)) {
			Employee *pEmployee = employee_new();
			if (pEmployee != NULL) {
				employee_setId(pEmployee, auxEmployee.id);
				employee_setNombre(pEmployee, auxEmployee.nombre);
				employee_setHorasTrabajadas(pEmployee,
						auxEmployee.horasTrabajadas);
				employee_setSueldo(pEmployee, auxEmployee.sueldo);
				if (leidos == 1) {
					ll_add(pArrayListEmployee, pEmployee);
					fread(&auxEmployee, sizeof(Employee), 1, pFile);
					retorno = 0;
				} else {
					if (!feof(pFile)) {
						printf("\nError en la carga del archivo en Binario.");
						retorno = -1;
					}
				}
			}
		}
	}

	fclose(pFile);
	return retorno;
}
