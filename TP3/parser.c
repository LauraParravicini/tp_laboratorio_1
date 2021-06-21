#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* empAux = NULL;
    int cant;
    char buffer[4][128];
    int cargados = 0;
    if(pFile != NULL){
         cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
         do{
            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            if(cant < 4){
                break;
            }

            empAux = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

            if(empAux != NULL){
                    ll_add(pArrayListEmployee,empAux);
                    cargados++;

            }else{
                printf("-! Error generating new employee object !-\n");
                break;
            }
        }while(!feof(pFile));
        if(cargados){
            printf(" -- Loaded sucessfully :) -- \n");
        }else{
            printf(" -- File is empty --\n");
        }
        fclose(pFile);
    }else{
        printf("Error opening file\n");
    }
    return cargados;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int cant;
    int cargados = 0;
    Employee auxEmpleado;
    Employee* pEmpleado;
    if(pFile != NULL){
         //cant = fread(auxEmpleado,sizeof(Employee),1,pFile);
         do{
            cant = fread(&auxEmpleado,sizeof(Employee),1,pFile);
            pEmpleado = employee_new();
            if(cant == 1 && pEmpleado != NULL){
                if( employee_setId(pEmpleado,auxEmpleado.id) &&
                    employee_setNombre(pEmpleado,auxEmpleado.nombre) &&
                    employee_setHorasTrabajadas(pEmpleado,auxEmpleado.horasTrabajadas) &&
                    employee_setSueldo(pEmpleado,auxEmpleado.sueldo) )
                {
                     ll_add(pArrayListEmployee,pEmpleado);
                     cargados++;
                }else{
                    employee_delete(pEmpleado);
                }
            }

        }while(!feof(pFile));
        if(cargados){
            printf(" -- Loaded sucessfully :) -- \n");
        }else{
            printf(" -- File is empty --\n");
        }
        fclose(pFile);
    }else{
        printf("Error opening file\n");
    }

    return cargados;
}
