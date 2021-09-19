/*
 * TP1.h
 *
 *  Created on: 18 sep. 2021
 *      Author: river
 */

#ifndef TP1_H_
#define TP1_H_


/// \fn float IngresarNumero(char[])
/// \brief Esta funci�n me permite ingresar un n�mero a mi programa.
///
/// \param El mensaje que va a mostrar la funci�n.
/// \return Va a retornar un n�mero al main.
float IngresarNumero (char []);


/// \fn float CalcularSuma(float, float)
/// \brief Calcular la suma de 2(dos) n�meros.
///
///
/// \param Primer n�mero.
/// \param Segundo n�mero.
/// \return Va a retornar el valor de la sumatoria entre los n�meros ingresados.
float CalcularSuma (float, float);


/// \fn float CalcularResta(float, float)
/// \brief Calcular la resta de 2(dos) n�meros.
///
/// \param Primer n�mero.
/// \param Segundo n�mero.
/// \return Va a retornar el valor de la resta entre los n�meros ingresados.
float CalcularResta (float, float);


/// \fn int CalcularDivision(float*, float, float)
/// \brief  Calcular la divisi�n entre 2(dos) n�meros.
///
/// \param direcci�n de memoria de la variable "resultadoDivision".
/// \param Primer n�mero.
/// \param Segundo n�mero.
/// \return Va a retornar un -1 si no se pudo realizar la divisi�n, o un 0(cero) en caso de hbaer sido posible la realizaci�n de la misma.
int CalcularDivision(float*, float, float);


/// \fn float CalcularMultiplicacion(float, float)
/// \brief Calcular la multiplicaci�n entre 2(dos) n�meros.
///
/// \param Primer n�mero.
/// \param Segundo n�mero.
/// \return Va a retornar el valor de la multiplicaci�n entre los n�meros ingresados.
float CalcularMultiplicacion(float, float);


/// \fn float CalcularFactorial(float)
/// \brief Calcular el factorial de un n�mero
///
/// \param El n�mero que va a ser la base del calculo.
/// \return Va a retornar el valor del factorial.
float CalcularFactorial(float);

#endif /* TP1_H_ */
