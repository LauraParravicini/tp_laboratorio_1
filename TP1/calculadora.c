/*
 * calculadora.c
 *
 *  Created on: 9 abr. 2021
 *      Author: laura
 */

#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

void ingresarA(int* A, int* flagA){
	printf("\n 1) Ingrese primer operando: ");
	scanf("%d",A);
	(*flagA) = 1;
}

void ingresarB(int* B, int* flagB){
	printf("\n 2) Ingrese segundo operando: ");
	scanf("%d",B);
	(*flagB) = 1;
}

void menu(int A, int B, int flagA, int flagB, int flagCalc){
	printf("\n------ Bienvenida -----\n");

	printf("1) Ingrese primer operando A = ");
	flagA ? printf("%d\n",A) : printf("x\n");
	printf("2) Ingrese segundo operando B = ");
	flagB ? printf("%d\n",B) : printf("y\n");

	if(flagA && flagB){
		printf("3) Calcular todas las operaciones\n");
	}

	if(flagCalc){
		printf("4) Informar resultados\n");
	}
	printf("5) Salir\n");
}

void mostrarResult(int suma, int resta, float div, int multip, int fact){
	printf("\n-- Resultados --\n");
	printf("- Suma: %d\n",suma);
	printf("- Resta: %.d\n",resta);
	printf("- Division: %.2f\n",div);
	printf("- Multiplicacion: %d\n",multip);
	fact != -1 ? printf("- Factorial de A: %d\n",fact) : printf("- Factorial de A: No se pudo calcular") ;

}

int factorial(int num){
	if(num < 0){
		return -1;
	}
	if(num == 1 || num == 0){
		return 1;
	}
	return num*(factorial(num-1));
}

int suma(int A, int B){
	return A+B;
}

int resta(int A, int B){
	return A-B;
}

int multip(int A, int B){
	return A*B;
}

float division(int A, int B){
	float result = (float)A/B;
	return result;
}

