/*
 * TP1.h
 *
 *  Created on: 18 sep. 2021
 *      Author: river
 */

#ifndef TP1_H_
#define TP1_H_


/// \fn float IngresarNumero(char[])
/// \brief Esta función me permite ingresar un número a mi programa.
///
/// \param El mensaje que va a mostrar la función.
/// \return Va a retornar un número al main.
float IngresarNumero (char []);


/// \fn float CalcularSuma(float, float)
/// \brief Calcular la suma de 2(dos) números.
///
///
/// \param Primer número.
/// \param Segundo número.
/// \return Va a retornar el valor de la sumatoria entre los números ingresados.
float CalcularSuma (float, float);


/// \fn float CalcularResta(float, float)
/// \brief Calcular la resta de 2(dos) números.
///
/// \param Primer número.
/// \param Segundo número.
/// \return Va a retornar el valor de la resta entre los números ingresados.
float CalcularResta (float, float);


/// \fn int CalcularDivision(float*, float, float)
/// \brief  Calcular la división entre 2(dos) números.
///
/// \param dirección de memoria de la variable "resultadoDivision".
/// \param Primer número.
/// \param Segundo número.
/// \return Va a retornar un -1 si no se pudo realizar la división, o un 0(cero) en caso de hbaer sido posible la realización de la misma.
int CalcularDivision(float*, float, float);


/// \fn float CalcularMultiplicacion(float, float)
/// \brief Calcular la multiplicación entre 2(dos) números.
///
/// \param Primer número.
/// \param Segundo número.
/// \return Va a retornar el valor de la multiplicación entre los números ingresados.
float CalcularMultiplicacion(float, float);


/// \fn float CalcularFactorial(float)
/// \brief Calcular el factorial de un número
///
/// \param El número que va a ser la base del calculo.
/// \return Va a retornar el valor del factorial.
float CalcularFactorial(float);

#endif /* TP1_H_ */
