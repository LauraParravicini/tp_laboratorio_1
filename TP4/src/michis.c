#include "michis.h"
eMichi* newMichiStr(char* legajo, char* nombre, char* raza, char* peso){
     eMichi* pEmp = newMichi();
    if(pEmp != NULL){
        if( !(MichiSetLegajo(pEmp,atoi(legajo) )
           && MichiSetNombre(pEmp,nombre)
           && MichiSetPeso(pEmp, atof(peso) )
            && MichiSetRaza(pEmp,raza) ) ){
                //Libero memoria en caso de que algun parametro este mal
                free(pEmp);
                pEmp = NULL;

        }

    }

    return pEmp;

}

int mostrarMichi(eMichi* p){
    int status = 0;
    int legajo;
    char nombre[20];
    char raza[20];
    float peso;
    if(p != NULL &&
       MichiGetLegajo(p,&legajo) &&
       MichiGetNombre(p, nombre) &&
       MichiGetRaza(p,raza) &&
       MichiGetPeso(p,&peso) ){

        printf("%d   %10s   %10s   %.2f \n",legajo,nombre,raza,peso);
        status = 1;
       }
    return status;
}


eMichi* newMichi(){
    //Asigno memoria
    eMichi* pMichi = (eMichi*) malloc(sizeof(eMichi));
    if(pMichi != NULL){
        pMichi->legajo = 0;
        strcpy(pMichi->nombre, "");
        strcpy(pMichi->raza, "");
        pMichi->peso = 0;
    }
    return pMichi;
}

eMichi* newMichiParam(int legajo, char* nombre, char* raza, float peso){
    eMichi* pMichi = newMichi();
    if(pMichi != NULL){
        /*if(legajo > 0 && peso > 0 && nombre != NULL && strlen(nombre) > 3 && (sexo == 'f' || sexo == 'm') ){
            pmichi->legajo = legajo;
            strcpy(pmichi->nombre, nombre);
            pmichi->sexo = sexo;
            pmichi->peso = peso;*/

        // ---- Llamo a todos los setters para cargar los campos, si falla alguno va a dar falso, negado entra
        if( !(MichiSetLegajo(pMichi,legajo)
           && MichiSetNombre(pMichi,nombre)
          && MichiSetPeso(pMichi,peso)
            && MichiSetRaza(pMichi,raza) ) ){
                //Libero memoria en caso de que algun parametro este mal
                free(pMichi);
                pMichi = NULL;

        }
        /*}else{
            //Libero memoria en caso de que algun parametro este mal
            free(pmichi);
            pmichi = NULL;
        }*/

    }

    return pMichi;
}

int destroyMichi(eMichi* michi){
    int status = 0;
    if(michi != NULL){
        free(michi);
        status = 1;
    }
    return status;
}

int MichiSetLegajo(eMichi* michi, int legajo){
    int status = 0;
    if(michi != NULL && legajo > 0){
        michi->legajo = legajo;
        status = 1;
    }
    return status;
}

int MichiSetNombre(eMichi* michi, char* nombre){
    int status = 0;
    if(michi != NULL && nombre != NULL && strlen(nombre) > 0 && strlen(nombre) < 20){
        strcpy(michi->nombre,nombre);
        status = 1;
    }
    return status;
}

int MichiSetRaza(eMichi* michi, char* raza){
    int status = 0;
    if(michi != NULL && raza != NULL && strlen(raza) > 0 && strlen(raza) < 20){
        strcpy(michi->raza,raza);
        status = 1;
    }
    return status;
}

int MichiSetPeso(eMichi* michi, float peso){
    int status = 0;
    if(michi != NULL && peso >= 0){
        michi->peso = peso;
        status = 1;
    }
    return status;
}


int MichiGetLegajo(eMichi* michi, int* pLegajo){
    int status = 0;
    if(michi != NULL && pLegajo != NULL){
        (*pLegajo) = michi->legajo;
        status = 1;
    }
    return status;
}

int MichiGetNombre(eMichi* michi, char* nombre){
    int status = 0;
    if(michi != NULL && nombre != NULL){
        strcpy(nombre,michi->nombre);
        status = 1;
    }
    return status;
}

int MichiGetRaza(eMichi* michi, char* raza){
    int status = 0;
    if(michi != NULL && raza != NULL){
        strcpy(raza,michi->raza);
        status = 1;
    }
    return status;
}


int MichiGetPeso(eMichi* michi, float* pPeso){
    int status = 0;
    if(michi != NULL && pPeso != NULL){
        (*pPeso) = michi->peso;
        status = 1;
    }
    return status;
}


int mostrarMichis(LinkedList* pArrayListMichi)
{
    eMichi* michiAux = NULL;

    int status = 0;
    int legajo;
    char nombre[20];
    char raza[20];
    float peso;
    int len = ll_len(pArrayListMichi);

    if(pArrayListMichi != NULL){
        printf("--- Michi List ---\n");
        printf("   ID     Nombre       Raza     Peso\n");
        for(int i = 0; i < len; i++){
            michiAux = ll_get(pArrayListMichi,i);
            if( michiAux != NULL &&
               MichiGetLegajo(michiAux,&legajo) &&
               MichiGetNombre(michiAux, nombre) &&
               MichiGetRaza(michiAux,raza) &&
               MichiGetPeso(michiAux,&peso)  ) {

                printf(" %4d %15s %3s  %6.2f \n",legajo,nombre,raza,peso);
                status = 1;
            }
        }
    }
    return status;
}

int michiCompareNombre(void* a,void* b){
    int status = 0;
    eMichi* michi1 = NULL;
    eMichi* michi2 = NULL;
    if(a != NULL && b != NULL){
        //Casteo lo que estaba en void a empleado
        michi1 = (eMichi*) a;
        michi2 = (eMichi*) b;
        status = strcmp(michi1->nombre,michi2->nombre);
    }

    return status;
}
