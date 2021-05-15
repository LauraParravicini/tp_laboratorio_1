/*
 * utn.h
 *
 *  Created on: 11 may. 2021
 *      Author: laura
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <string.h>
#ifndef UTN_H_
#define UTN_H_

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int utn_getFecha(int* dia,int* mes, int* anio, char* mensaje, char* msjeError,int reintentos);
int utn_getFloat(char * cadena);
int getFloat (float *numeroIngresado, char* mensaje, char* mensajeError);
int isValidName(char* stringRecibido);
int utn_getName(char* msg, char* msgError, int min, int max, int reintentos, char* resultado);
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);
#endif /* UTN_H_ */
