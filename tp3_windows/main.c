#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "LinkedList.h"
#include "Controller.h"

int main()
{
	setbuf(stdout, NULL);
    int option;
    int flagAltas = 0;
    int len;
    LinkedList* listaEmpleados;
    listaEmpleados = ll_newLinkedList();

    do{
    	if(utn_getNumero(&option,"\nSeleccione una opcion.\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n3. Alta de empleado.\n4. Modificar datos de empleado.\n5. Baja de empleado.\n6. Listar empleados.\n7. Ordenar empleados.\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir.\nIngrese una opción:", "Error!!!", 0, 10, 3) == 0)
    	{
        switch(option)
        {
            case 1:
            	if(flagAltas == 0)
            	{
					if(controller_loadFromText("data.csv",listaEmpleados) == 0)
					{
						len = ll_len(listaEmpleados);
						printf("\nSe puedieron cargar %d empleados del archivo en modo texto.\n", len);
						flagAltas = 1;
					}
					else
					{
						printf("\nError. No se puedieron cargar los empleados del archivo en modo texto.\n");
					}
            	}
            	else
            	{
            		printf("\nEl archivo puede cargarse una sola vez!\n");
            	}
                break;
            case 2:
            	if(flagAltas == 0)
            	{
            	if(controller_loadFromBinary("data.bin",listaEmpleados) == 0)
            	{
            		len = ll_len(listaEmpleados);
            		printf("\nSe puedieron cargar %d empleados del archivo en modo binario.\n\n", len);
            		flagAltas = 1;
            	}
            	else
            	{
            		printf("\nError. No se puedieron cargar los empleados del archivo en modo binario.\n");
            	}
            	}
            	else
            	{
            		printf("\nEl archivo puede cargarse una sola vez!\n");
            	}
            	break;
            case 3:
            	if (flagAltas)
            	{
            		if(controller_addEmployee(listaEmpleados) == 0)
            		{
            			printf("\nSe dio de alta el empleado!\n");
            		}
            		else
            		{
            			printf("\nERROR!. No se dio de alta el empleado.\n");
            		}
            	}
            	else
            	{
            		printf("\nPrimero cargue los Empleados desde el archivo de texto o el archivo binario por favor.\n");
            	}
            	break;
            case 4:
            	if(controller_editEmployee(listaEmpleados) != 0)
            	{
            		printf("\nError al modificar el empleado!");
            	}
            	break;
            case 5:
            	if(flagAltas)
            	{
					if(!controller_removeEmployee(listaEmpleados))
					{
						printf("\nLa baja del empleado fue exitosa.");
					}
					else
					{
						printf("\nLa baja del empleado no pudo realizarse.");
					}
            	}
            	else
            	{
            		printf("\nAntes de dar de baja un empleado, debe haber alguno dado de alta.");
            	}
            	break;
            case 6:
            	if (flagAltas)
            	{
            		if(!controller_ListEmployee(listaEmpleados))
            		{
            			printf("\nEstos son todos los empleados enlistados");
            		}
            		else
            		{
            			printf("\nNo pudo mostrarse la lista de empleados.");
            		}
            	}
            	else
            	{
            		printf("\nAntes de mostrar empleados, debe darlos de alta.");
            	}
            	break;
            case 7:
            	if(!controller_ListEmployee(listaEmpleados))
            	{
            		controller_sortEmployee(listaEmpleados);
            	}
            	break;
            case 8:
            	if(!controller_saveAsText("data.csv",listaEmpleados))
            	{
            		printf("\nSe han guardado: %d empleados en modo texto.", ll_len(listaEmpleados));
            	}
            	else
            	{
            		printf("\nOcurrio un error al guardar los empleados en modo texto.");
            	}
            	break;
            case 9:
            	if(!controller_saveAsBinary("data.bin",listaEmpleados))
            	{
            		printf("\nSe han guardado: %d empleados en modo binario.", ll_len(listaEmpleados));
            	}
            	else
            	{
            		printf("\nOcurrio un error al guardar los empleados en modo binario.");
            	}
            	break;
            case 10:
            	break;

        	}
    	}
    }while(option != 10);

    return 0;
}

