/*
 ============================================================================
 Name        : Pruebas.c
 Author      : laura.d.parravicini
 Version     :
 Copyright   : Your copyright notice
 Description : TP1 Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "calculadora.h"


int main(void) {
	setbuf(stdout,NULL);
	int flagA = 0;
	int flagB = 0;
	int flagCalc = 0;
	int opcion = 0;
	int A = 0;
	int B = 0;
	int resultSuma = 0;
	int resultResta = 0;
	float resultDiv = 0;
	int resultMult = 0;
	int resultFact = 0;

	while(opcion != 5){
		menu(A,B,flagA,flagB,flagCalc);
		printf("Ingrese opcion: ");
		__fpurge(stdin);
		scanf("%d",&opcion);
		switch(opcion){
			case 1:
				ingresarA(&A,&flagA);
				break;
			case 2:
				ingresarB(&B,&flagB);
				break;
			case 3:
				resultSuma = suma(A,B);
				resultResta = resta(A,B);
				if(B != 0){
					resultDiv = division(A,B);
				}else{
					printf("No se puede dividir por cero. Reingrese segundo termino.\n\n");
					break;
				}
				resultMult = multip(A,B);
				resultFact = factorial(A);
				if(resultFact == -1) printf("No se puede calcular factorial");

				flagCalc = 1;
				printf("\n- Operaciones calculadas -\n");
				break;
			case 4:
				if(flagCalc == 1) mostrarResult(resultSuma,resultResta,resultDiv,resultMult,resultFact);
				break;
			case 5:
				printf("Salio");
				break;
			default:
				printf("Reingrese opcion\n\n");
				break;
		}
	}
	return EXIT_SUCCESS;
}

