/*
 ============================================================================
 Name        : TP2.c
 Author      : Laura Parravicini
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define ELEMENTS 1000
#define EXIT 5
#define ADD 1
#define MODIF 2
#define LIST 4
#define DELETE 3
void enterMenu(int* option, int nextId);

int main(void) {
	int status;
	int option;
	int nextId = 1;
	int idDel;
	Employee new;
	Employee employees[ELEMENTS];
	status = initEmployees(employees,ELEMENTS);

	do{
		enterMenu(&option,nextId);
		switch(option){
			case ADD:
				new = employeeDataInput();
				status = addEmployee(employees,ELEMENTS,nextId,new.name,new.lastName,new.salary,new.sector);
				status != -1 ? nextId++ : printf("\n-!- Error adding employee -!-\n");
				break;
			case MODIF:
				status = modifyEmployee(employees,ELEMENTS);
				status != -1 ? printf("\n--- Successful ---\n\n") : printf("\n-!- Error modifying employee -!-\n");
				break;
			case DELETE:
				printf("\n --- Delete Employee ---\n -- Enter ID of employee to delete: ");
				scanf(" %d", &idDel);
				status = removeEmployee(employees, ELEMENTS, idDel);
				status != -1 ? printf("\n---- Employee Deleted ----\n\n") : printf("\n-!- Error in deletion -!- \n");
				break;
			case LIST:
				reportsEmployees(employees, ELEMENTS);
				break;
			case EXIT:
				break;
		}
	}while(option != EXIT);

	return EXIT_SUCCESS;
}

void enterMenu(int* option, int nextId){
	printf("------- Welcome to Employee System ------");
	printf("\n\t 1) Add Employee ");
	if(nextId > 1){
		printf("\n\t 2) Modify Employee \n\t 3) Delete Employee \n\t 4) Reports/Lists");
	}
	printf(" \n\t 5) Exit \n");
	utn_getNumero(option, "\n - Enter option: ", "-!- Invalid option -!-", 1,5,10);
}
