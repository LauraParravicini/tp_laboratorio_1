#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option = 0;
    int loaded = 0;
    int status = 0;
    int flagLoad = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        printf("\n---- Employee CRUD Linked List -----\n");

        if(!flagLoad){
            printf("1) Load employees from text file\n");
            printf("2) Load employees from binary file\n");
        }else{
            printf("3) Add employee\n4) Modify employee\n5) Delete employee\n6) List employees\n7) Sort employees\n8) Save employees in text file\n9) Save employees in binary file\n");
        }

        if(utn_getNumero(&option," - Enter option (1-10): ","-!- Invalid option -!-",1,10,10)){

            switch(option)
            {
                case 1:
                    status = controller_loadFromText("data.csv",listaEmpleados,&loaded);
                    status == 1 ? printf("\n") : printf("-!- Error -!-\n\n");
                    flagLoad++;
                    break;
                case 2:
                    status = controller_loadFromBinary("data.bin",listaEmpleados,&loaded);
                    status == 1 ? printf("\n") : printf("-!- Error -!-\n\n");
                    flagLoad++;
                    break;
                case 3:
                    status = controller_addEmployee(listaEmpleados,&loaded);
                    status == 1 ? printf("\n") : printf("-!- Error -!-\n\n");
                    break;
                case 4:
                    status = controller_editEmployee(listaEmpleados);
                    status == 1 ? printf("\n") : printf("-!- Error -!-\n\n");
                    break;
                case 5:
                    status = controller_removeEmployee(listaEmpleados);
                    status == 1 ? printf("\n") : printf("-!- Error -!-\n\n");
                    break;
                case 6:
                    status = controller_ListEmployee(listaEmpleados);
                    status == 1 ? printf("\n") : printf("-!- Error -!-\n\n");
                    break;
                case 7:
                    status = controller_sortEmployee(listaEmpleados);
                    status == 1 ? printf("\n") : printf("-!- Error -!-\n\n");
                    break;
                case 8:
                    status = controller_saveAsText("data.csv",listaEmpleados,loaded);
                    status == 1 ? printf("\n") : printf("-!- Error -!-\n\n");
                    break;
                case 9:
                    status = controller_saveAsBinary("data.bin",listaEmpleados);
                    status == 1 ? printf("\n") : printf("-!- Error -!-\n\n");
                    break;
            }
        }
    }while(option != 10);
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

