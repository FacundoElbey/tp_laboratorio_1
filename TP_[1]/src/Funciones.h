/*
 * Funciones.h
 *
 *  Created on: 7 abr. 2022
 *      Author: felbey
 */
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
/// @fn int calcularPrecioDebito(float, float*)
/// @brief Calcula el precio final si se pagasé con tarjeta de débito
///
/// @param el precio de lista
/// @param un puntero a donde guardaremos el precio final
/// @return retorna -1 en caso de error y 0 (cero) en caso de éxito
int calcularPrecioDebito(float, float*);

/// @fn int calcularPrecioCredito(float, float*)
/// @brief Calcula el precio final con el recargo que tendría al abonar con tarjeta de crédito
///
/// @param el precio de lista
/// @param un puntero a donde guardaremos el precio final
/// @return retorna -1 en caso de error y 0 (cero) en caso de éxito
int calcularPrecioCredito(float, float*);

/// @fn int calcularPrecioBitcoin(float, float, float*)
/// @brief  Calcula el precio final si se pagasé en Bitcoin
///
/// @param el precio de lista
/// @param el precio que tenga el bitcoin en ese momento
/// @param un puntero a donde guardaremos el precio final
/// @return retorna -1 en caso de error y 0 (cero) en caso de éxito
int calcularPrecioBitcoin(float,float, float*);

/// @fn int calcularPrecioUnitario(float, float, float*)
/// @brief Calcula el precio por KM recorrido
///
/// @param Kilometros que se van a recorrer
/// @param el precio de lista
/// @param un puntero a donde guardaremos el precio final
/// @return retorna -1 en caso de error y 0 (cero) en caso de éxito
int calcularPrecioUnitario(float, float, float*);

/// @fn int calcularDiferenciaPrecios(float, float, float*)
/// @brief Calcula la diferencia entre el precio de Aerolineas y el precio de Latam
///
/// @param precio de aerolineas
/// @param precio de Latam
/// @param un puntero donde guardaremos la diferencia de estos precios
/// @return retorna -1 en caso de error y 0 (cero) en caso de éxito
int calcularDiferenciaPrecios(float, float, float*);

/// @fn void informe(float, float, float, float, float, float, float, float, float, float, float, float)
/// @brief Informa al usuario todas las cuentas que se realiaron cuando este lo solicite
///
/// @param Kiloetros recorridos
/// @param el precio de lista de Latam
/// @param el precio de Latam pagando con débito
/// @param el precio de Latam pagando con crédito
/// @param el precio de Latam pagando con Bitcoin
/// @param el precio de Latam por kilometro recorrido
/// @param el precio de lista de Aerolineas
/// @param el precio de Aerolineas pagando con débito
/// @param el precio de Aerolineas pagando con crédito
/// @param el precio de Aerolineas pagando con Bitcoin
/// @param el precio de Aerolineas por kilometro recorrido
/// @param La diferencia de precios entre el vuelo de Latam y el de Aerolineas
void informe(float, float, float, float, float, float, float, float, float, float, float, float);

/// @fn void menu(float, float, float)
/// @brief muestra el menu de opciones general de nuestro programa
///
/// @param Los kilometros recorridos
/// @param precio de aerolinas
/// @param precio de Latam
void menu (float, float, float);

#endif /* FUNCIONES_H_ */
