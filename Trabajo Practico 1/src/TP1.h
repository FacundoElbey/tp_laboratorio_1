/*
 * TP1.h
 *
 *  Created on: 18 sep. 2021
 *      Author: river
 */

#ifndef TP1_H_
#define TP1_H_


/// \fn int ValidarDatoIngresado(const char*, void*)
/// \brief Esta funci�nm me permite validar los datos que ingrese el usuario, para que solo me reconozca numeros.
///
///
/// \param La primer variable es para validar el tipo de dato.
/// \param El puntero que me lleva al n�mero (en este caso el operador A o B).
/// \return
int ValidarDatoIngresado (const char*, void*);

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

/// \fn int CalcularFactorial(float*, float)
/// \brief Lo que hace esta funci�n es calcular el factorial del operador que se env�a y cargarlo a trav�s del puntero en la variable que le corresponde.
///
/// \param pResultadoFactorial puntero del resultado del factorial
/// \param num operador ingresado
/// \return un int para poder validar si es negativo o no el factorial.
int CalcularFactorial(float* pResultadoFactorial, float num);

#endif /* TP1_H_ */
