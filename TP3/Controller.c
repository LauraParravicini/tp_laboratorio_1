#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee, int* loaded)
{
    FILE* p;

    if(path != NULL && pArrayListEmployee != NULL){
        p = fopen(path,"r");
        (*loaded) = parser_EmployeeFromText(p,pArrayListEmployee);
        (*loaded)++;

    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* loaded)
{
    FILE* p;

    if(path != NULL && pArrayListEmployee != NULL){
        p = fopen(path,"rb");
        (*loaded) = parser_EmployeeFromBinary(p,pArrayListEmployee);

    }
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* pId)
{
    Employee* nuevo = NULL;
    char nombre[20];
    int horas;
    int sueldo;
    int retorno;
    if(pArrayListEmployee != NULL){

            utn_getName(" - Enter name: ","-!- Invalid name -!-",1,30,10,nombre);
            utn_getNumero(&horas," - Enter worked hours: ","\n-!- Invalid -!-\n",0,1000,10);
            utn_getNumero(&sueldo," - Enter salary: ","\n-!- Invalid -!-\n",0,100000,10);
            (*pId)++;

            nuevo = employee_new();
            if(nuevo != NULL){
                if( employee_setId(nuevo,(*pId) )
                    && employee_setNombre(nuevo,nombre)
                    && employee_setHorasTrabajadas(nuevo,horas)
                    && employee_setSueldo(nuevo,sueldo) ){

                    printf("\n- Employee added :) -\n");
                    ll_add(pArrayListEmployee,nuevo);
                }else{
                    free(nuevo);
                    printf("\n-- Assigning Error--\n");
                }
            }

            retorno = 1;
    }else{
        printf("- No space available -");
        retorno = -1;
    }

    return retorno;
}

Employee* controller_searchEmployeeID(LinkedList* pArrayListEmployee,int id, int* index){
    Employee* aux = NULL;
    int idAux;
    //Search employee by id and return index
    for(int i = 0 ; i < ll_len(pArrayListEmployee) ; i++ ){
        aux = (Employee*) ll_get(pArrayListEmployee,i);
        employee_getId(aux,&idAux);
        if(aux != NULL && idAux == id){
            (*index) = i;
            break;
        }
    }

    return aux;
}

void controller_showEmployee(Employee* emp){
    int id;
    char nombre[128];
    int sueldo;
    int horas;

    if( emp != NULL &&
        employee_getId(emp, &id) &&
        employee_getNombre(emp, nombre) &&
        employee_getHorasTrabajadas(emp,&horas) &&
        employee_getSueldo(emp,&sueldo)  ) {

        printf(" %4d %15s  %3d   %5d ",id,nombre,horas,sueldo);
    }
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    int idIngresado;
    int indiceExiste = -1;
    Employee* aux = NULL;
    char nombre[128];
    int sueldo;
    int horas;
	int opcion;
	int retorno = -1;
	if(pArrayListEmployee != NULL){

		utn_getNumero(&idIngresado," - Enter Employee ID to edit: ","-!- Invalid ID -!-",0,20000,10);

        aux = controller_searchEmployeeID(pArrayListEmployee,idIngresado,&indiceExiste);

		if(indiceExiste >= 0){
			printf("\n     --Editing--\n   ID     Name        Hours Salary\n");

            controller_showEmployee(aux);

			printf("\n\t 1) Name \n\t 2) Hours \n\t 3) Salary \n\t 4) Back ");
			utn_getNumero(&opcion,"\nEnter option to modify 1-4: ","-!- Invalid option -!-",1,4,10);

            switch(opcion){
                case 1:
                    utn_getName(" - Enter name: ","-!- Invalid name -!-",1,30,10,nombre);
                    if( employee_setNombre(aux,nombre) ) printf("   -- Successfully edited -- \n");
                    break;
                case 2:
                    utn_getNumero(&horas," - Enter worked hours: ","-!- Invalid -!-",0,1000,10);
                    if(employee_setHorasTrabajadas(aux,horas) ) printf("   -- Successfully edited -- \n");
                    break;
                case 3:
                    utn_getNumero(&sueldo," - Enter new salary: ","-!- Invalid -!-",0,100000,10);
                    if(employee_setSueldo(aux,sueldo) ) printf("   -- Successfully edited -- \n");
                    break;
                case 4:
                    break;
            }

            retorno = 1;
		}else{
			printf("--- Employee does not exist ---\n");
			retorno = -1;
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int idIngresado;
    int indiceExiste = -1;
    Employee* aux = NULL;
    char confirmacion;
	int retorno = -1;
	if(pArrayListEmployee != NULL){

		utn_getNumero(&idIngresado," - Enter Employee ID to remove: ","-!- Invalid ID -!-",0,20000,10);

        aux = controller_searchEmployeeID(pArrayListEmployee,idIngresado,&indiceExiste);

		if(indiceExiste >= 0){
			printf("\n     -- Employee to remove --\n   ID     Name        Hours Salary\n");

            controller_showEmployee(aux);

            printf("\n Do you want to remove it? y/n: ");
            fflush(stdin);
			scanf(" %c",&confirmacion);
			if(confirmacion == 'y'){
                if( ll_remove(pArrayListEmployee,indiceExiste) == 0 ) printf("-- Employee removed --\n");
                employee_delete(aux);
			}else{
				printf("-- Deletion canceled --\n");
			}

            retorno = 1;
		}else{
			printf("--- Employee does not exist ---\n");
			retorno = -1;
		}
	}
	return retorno;
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empAux = NULL;

    int status = 0;
    int id;
    char nombre[30];
    int horas;
    int sueldo;
    int len = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL){
        printf("--- Employee List ---\n");
        printf("   ID     Name        Hours Salary\n");
        for(int i = 0; i < len; i++){
            empAux = ll_get(pArrayListEmployee,i);
            if( empAux != NULL &&
               employee_getId(empAux,&id) &&
               employee_getNombre(empAux, nombre) &&
               employee_getHorasTrabajadas(empAux,&horas) &&
               employee_getSueldo(empAux,&sueldo)  ) {

                printf(" %4d %15s %3d  %6d \n",id,nombre,horas,sueldo);
                status = 1;
            }
        }
    }
    return status;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    ll_sort(pArrayListEmployee,employeeCompareNombre, 1);

    return 1;
}

// --- Sort
int employeeCompareNombre(void* a,void* b){
    int status = 0;
    Employee* emp1 = NULL;
    Employee* emp2 = NULL;
    if(a != NULL && b != NULL){
        //Casteo lo que estaba en void a empleado
        emp1 = (Employee*) a;
        emp2 = (Employee*) b;
        // retorno = emp1->legajo - emp2->legajo , asi devuelvo de la funcion cuando da positivo y negativo
        status = strcmp(emp1->nombre,emp2->nombre);
    }

    return status;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee,int loaded)
{
    FILE* f = fopen(path,"w");
    Employee* aux = NULL;

    int id;
    char nombre[128];
    int horas;
    int sueldo;

    int ingresado;
    int flag = 0;

    char confirmacion;
    if(f != NULL){

            printf("\n This action will delete old data and rewrite. Do you want to continue? y/n: ");
            fflush(stdin);
            scanf(" %c",&confirmacion);
            if(confirmacion == 'y'){
                fprintf(f,"id,nombre,horas,sueldo\n");
                for(int i = 0; i < ll_len(pArrayListEmployee) ; i++){
                    aux = (Employee*) ll_get(pArrayListEmployee,i);
                    if(aux != NULL){

                        employee_getId(aux,&id);
                        employee_getNombre(aux,nombre);
                        employee_getHorasTrabajadas(aux,&horas);
                        employee_getSueldo(aux,&sueldo);


                        ingresado = fprintf(f,"%d,%s,%d,%d\n",id,nombre,horas,sueldo );
                        if(ingresado < 4){
                            flag = 1;
                            break;
                        }
                    }
                }

                if(flag){
                    printf("-!- Error saving employees in text file -!-\n");
                }else{
                    printf(" --- Saved successfully :) --- \n");
                }

            }else{
                printf("-- Data save canceled --\n");
            }


            fclose(f);
    }else{
        printf("-!- Error opening file -!-\n");
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f = fopen(path,"wb");
    Employee* aux = NULL;

    int ingresado;
    int flag = 0;
    char confirmacion;
    if(f != NULL){

        printf("\n This action will delete old data and rewrite. Do you want to continue? y/n: ");
        fflush(stdin);
        scanf(" %c",&confirmacion);
        if(confirmacion == 'y'){

            for(int i = 0; i < ll_len(pArrayListEmployee) ; i++){
                aux = (Employee*) ll_get(pArrayListEmployee,i);
                if(aux != NULL){

                    ingresado = fwrite( aux , sizeof(Employee),1,f);
                    if(ingresado < 1){
                        flag = 1;
                        break;
                    }
                }
            }

            if(flag){
                printf("-!- Error saving employees in binary file -!-\n");
            }else{
                printf(" --- Saved successfully :) --- \n");
            }
        }else{
                printf("-- Data save canceled --\n");
        }
        fclose(f);

    }else{
        printf("-!- Error opening file -!-\n");
    }

    return 1;
}

