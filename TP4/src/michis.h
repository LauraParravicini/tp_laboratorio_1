#ifndef MICHIS_H_INCLUDED
#define MICHIS_H_INCLUDED
#include <stdio.h>
#include "../inc/LinkedList.h"
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[20];
    char raza[20];
    float peso;
}eMichi;

int mostrarMichi(eMichi* e);

//Constructor: asigna memoria e inicializa
eMichi* newMichi();

//Contructor con data: inicializa, valida y asigna valores
eMichi* newMichiParam(int legajo, char* nombre, char* raza, float peso);
eMichi* newMichiStr(char* legajo, char* nombre, char* raza, char* peso);

//Destructor:
int destroyMichi(eMichi* michi);

int MichiSetLegajo(eMichi* michi, int legajo);
int MichiSetNombre(eMichi* michi, char* nombre);
int MichiSetRaza(eMichi* michi, char* raza);
int MichiSetPeso(eMichi* michi, float peso);

int MichiGetLegajo(eMichi* michi, int* pLegajo);
int MichiGetNombre(eMichi* michi, char* nombre);
int MichiGetRaza(eMichi* michi, char* raza);
int MichiGetPeso(eMichi* michi, float* pPeso);


int mostrarMichi(eMichi* p);
int mostrarMichis(LinkedList* pArrayListMichi);

int michiCompareNombre(void* a,void* b);
#endif // MICHIS_H_INCLUDED
