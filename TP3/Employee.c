#include "Employee.h"


Employee* employee_new(){
     Employee* pEmp = (Employee*) malloc(sizeof(Employee));
     if(pEmp != NULL){
        pEmp->id = 0;
        strcpy(pEmp->nombre, "");
        pEmp->horasTrabajadas = 0;
        pEmp->sueldo = 0;
    }
    return pEmp;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo){
    Employee* pEmp = employee_new();
    if(pEmp != NULL){
        if( !( employee_setId(pEmp,atoi(idStr) )
           && employee_setNombre(pEmp,nombreStr)
           && employee_setHorasTrabajadas(pEmp,atoi(horasTrabajadasStr) )
           && employee_setSueldo(pEmp,atoi(sueldo) ) ) ){
                //Libero memoria en caso de que algun parametro este mal
                free(pEmp);
                pEmp = NULL;

        }
    }
    return pEmp;
}
void employee_delete(Employee* emp){
    if(emp != NULL){
        free(emp);
    }
}

int employee_setId(Employee* emp,int id){
    int status = 0;
    if(emp != NULL && id > 0){
        emp->id = id;
        status = 1;
    }
    return status;
}
int employee_getId(Employee* this,int* id){
    int status = 0;
    if(this != NULL && id != NULL){
        (*id) = this->id;
        status = 1;
    }
    return status;
}

int employee_setNombre(Employee* emp,char* nombre){
    int status = 0;
    if(emp != NULL && nombre != NULL){
        strcpy(emp->nombre,nombre);
        status = 1;
    }
    return status;
}
int employee_getNombre(Employee* this,char* nombre){
    int status = 0;
    if(this != NULL && nombre != NULL){
        strcpy(nombre,this->nombre);
        status = 1;
    }
    return status;
}

int employee_setHorasTrabajadas(Employee* emp,int horasTrabajadas){
    int status = 0;
    if(emp != NULL && horasTrabajadas > 0){
        emp->horasTrabajadas = horasTrabajadas;
        status = 1;
    }
    return status;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int status = 0;
    if(this != NULL && horasTrabajadas != NULL){
        (*horasTrabajadas) = this->horasTrabajadas;
        status = 1;
    }
    return status;
}

int employee_setSueldo(Employee* emp,int sueldo){
    int status = 0;
    if(emp != NULL && sueldo > 0){
        emp->sueldo = sueldo;
        status = 1;
    }
    return status;
}
int employee_getSueldo(Employee* this,int* sueldo){
    int status = 0;
    if(this != NULL && sueldo != NULL){
        (*sueldo) = this->sueldo;
        status = 1;
    }
    return status;
}



