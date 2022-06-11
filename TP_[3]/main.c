/****************************************************
 Alumno: Elbey Facundo Damian.
*****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "Biblioteca.h"


int main()
{
	setbuf(stdout, NULL);
    int opcion = 0;
    int flagAlta = 1;
    int flagArchivo = 1;
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	menu();
    	utn_getNumero(&opcion,"\n\nIngrese la opcion deseada: ","\nERROR!\n",1,10,5);
        switch(opcion)
        {
            case 1:
                if(flagArchivo && !controller_loadFromText("data.csv",listaPasajeros) && !controller_ListPassenger(listaPasajeros))
                {
                	flagAlta = 0;
                	flagArchivo = 0;
                }
                else
                {
                	printf("\nSolo puede cargar el archivo una vez!");
                }
                break;
            case 2:
            	if(flagArchivo && !controller_loadFromBinary("data.bin",listaPasajeros) && !controller_ListPassenger(listaPasajeros))
            	{
            		flagAlta = 0;
            		flagArchivo = 0;
            	}
            	else
            	{
            		printf("\nSolo puede cargar el archivo una vez!");
            	}
            	break;
            case 3:
            	if(!controller_addPassenger(listaPasajeros))
            	{
            		flagAlta = 0;
            	}
            	else
            	{
            		printf("\nNo se puedo realizar el alta.");
            	}
            	break;
            case 4:
            	if(!flagAlta && !controller_editPassenger(listaPasajeros))
            	{
            		printf("\n\nSe realizaron los cambios con exito!");
            	}
            	else
            	{
            		printf("\nAntes debe dar de alta un pasajero");
            	}
            	break;
            case 5:
            	if(!flagAlta && !controller_removePassenger(listaPasajeros))
            	{
            		printf("\nLa baja se realizaro correctamente!");
            	}
            	else
            	{
            		printf("\nAntes debe dar de alta un pasajero");
            	}
            	break;
            case 6:
            	if(!flagAlta && !controller_ListPassenger(listaPasajeros))
            	{
            	}
            	else
            	{
            		printf("\nAntes debe dar de alta un pasajero");
            	}
            	break;
            case 7:
            	if(!flagAlta && !controller_sortPassenger(listaPasajeros) && !controller_ListPassenger(listaPasajeros))
            	{
            		printf("\n\n¡¡Fin del listado!!");
            	}
            	else
            	{
            		printf("\nAntes debe dar de alta un pasajero");
            	}
            	break;
            case 8:
            	if(!controller_saveAsText("data.csv",listaPasajeros))
            	{
            		printf("\nSe han guardado: %d pasajeros en modo texto.", ll_len(listaPasajeros));
            	}
            	else
            	{
            		printf("\nOcurrio un error al guardar los pasajeros en modo texto.");
            	}
            	break;
            case 9:
            	if(!controller_saveAsBinary("data.bin",listaPasajeros))
            	{
            		printf("\nSe han guardado: %d pasajeros en modo binario.", ll_len(listaPasajeros));
            	}
            	else
            	{
            		printf("\nOcurrio un error al guardar los pasajeros en modo binario.");
            	}
            	break;
            case 10:
            	break;
        }
    }while(opcion != 10);
    return 0;
}

