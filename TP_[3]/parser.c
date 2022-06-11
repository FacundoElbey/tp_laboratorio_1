#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int l = 0;
	Passenger* auxPassenger = Passenger_new();
	char auxId[AUX_LEN];
	char auxName[AUX_LEN];
	char auxLlastName[AUX_LEN];
	char auxPrice[AUX_LEN];
	char auxFlycode[AUX_LEN];//
	char auxTypePassenger[AUX_LEN];
	char auxStatusFlight[AUX_LEN];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		 l =fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxName, auxLlastName, auxPrice, auxFlycode, auxTypePassenger, auxStatusFlight); //voy a leer los titulos
		while(!feof(pFile))
		{
			l = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxName, auxLlastName, auxPrice, auxFlycode, auxTypePassenger, auxStatusFlight); //leemos los pasajeros
			if(l == 7 && auxPassenger != NULL && esNumerica(auxId, AUX_LEN) && esSoloLetras(auxName) && esSoloLetras(auxLlastName) &&
					esFlotante(auxPrice)  && esNumerica(auxTypePassenger, AUX_LEN) && esSoloLetras(auxStatusFlight))
			{
				auxPassenger = Passenger_newParametros(auxId, auxName, auxLlastName, auxFlycode, auxTypePassenger, auxPrice, auxStatusFlight);
				if(auxPassenger != NULL && !ll_add(pArrayListPassenger, auxPassenger))
				{
					retorno = 0;
				}
			}
			else
			{
				break;
			}
		}
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	if(pArrayListPassenger != NULL)
	{
		do
			{
				Passenger* pPassenger = Passenger_new();
				if(pPassenger != NULL && fread(pPassenger, sizeof(Passenger), 1, pFile) == 1)
				{
					ll_add(pArrayListPassenger, pPassenger);
					retorno = 0;
				}
				else
				{
					break;
				}
			}while(!feof(pFile));
	}
    return retorno;
}

