/*
 * calculadora.h
 * En esta biblioteca se encuentran las funcionalidades asociadas
 * a la calculadora creada para el TP1 Laboratorio 1
 *  Created on: 9 abr. 2021
 *      Author: laura
 */

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

/**
 * @brief  Devuelve la suma de A y B
 *
 * @param A
 * @param B
 * @return Suma de A y B
 */
int suma(int A, int B);

/**
 * @brief Devuelve la resta de A y B
 *
 * @param A
 * @param B
 * @return Resta de A y B
 */
int resta(int A, int B);

/**
 * @brief Devuelve la multiplicacion entre A y B
 *
 * @param A
 * @param B
 * @return Multip de A y B
 */
int multip(int A, int B);

/**
 * @brief Devuelve la division entre A y B
 *
 * @param A
 * @param B
 * @return Division entre A y B
 */
float division(int A, int B);

/**
 * @brief Muestra los resultados obtenidos por pantalla
 *
 * @param suma
 * @param resta
 * @param div
 * @param multip
 * @param fact
 */
void mostrarResult(int suma, int resta, float div, int multip, int fact);

/**
 * @brief Muestra los datos y opciones por pantalla
 *
 * @param A
 * @param B
 * @param flagA
 * @param flagB
 * @param flagCalc
 */
void menu(int A, int B, int flagA, int flagB, int flagCalc);

/**
 * @brief Ingreso del primer operando
 *
 * @param A
 * @param flagA
 */
void ingresarA(int* A, int* flagA);

/**
 * @brief Ingreso del segundo operando
 *
 * @param B
 * @param flagB
 */
void ingresarB(int* B, int* flagB);

/**
 * @brief Devuelve el factorial de un numero
 *
 * @param num
 * @return Factorial de num.
 */
int factorial(int num);

#endif /* CALCULADORA_H_ */
