/*
 * employee.c
 *
 *  Created on: 11 may. 2021
 *      Author: laura
 */

#include "ArrayEmployees.h"
int initEmployees(Employee* list, int len){
	int status = -1;
	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			list[i].isEmpty = 1;
		}
		status = 0;
	}
	return status;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
	int status = -1;
	int freeIndex = -1;
	Employee new;
	if(list != NULL && len > 0 && id > 0 && name != NULL  && lastName != NULL && salary > 0 && sector > 0){
		//Buscar libre
		for(int i = 0; i < len; i ++){
			if(list[i].isEmpty == 1){
				freeIndex = i;
				break;
			}
		}
		//------
		if(freeIndex != -1){
			new.id = id;
			strcpy(new.name,name);
			strcpy(new.lastName,lastName);
			new.salary = salary;
			new.sector = sector;
			new.isEmpty = 0;
			list[freeIndex] = new;
			status = 0;
			printf("----- Added :) ----\n\n");
		}
	}
	return status;
}

int findEmployeeById(Employee* list, int len,int id){
	int index = -1;
	if(list != NULL && len > 0 && id > 0){
		for(int i = 0; i < len; i++){
			if(list[i].id == id && list[i].isEmpty == 0){
				index = i;
				break;
			}
		}
	}
	return index;
}

int removeEmployee(Employee* list, int len, int id){
	int status = -1;
	int find = -1;
	if(list != NULL && len > 0 && id > 0){
		find = findEmployeeById(list,len,id);
		if(find != -1){
			list[find].isEmpty = 1;
			status = 0;
		}
	}
	return status;
}

int sortEmployees(Employee* list, int len, int order){
	int status = -1;
	Employee aux;

	int i = 0;
	int j = 0;;
	if(list != NULL && len > 0 && (order == 0 || order == 1) ){
		if(order == 1){
			for(i = 0; i < len -1 ; i++){
				for(j = i+1; j < len; j++){
					if( strcmp(list[i].lastName,list[j].lastName ) > 0 || (   strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector > list[j].sector ) ){
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}else{
			for(i = 0; i < len -1 ; i++){
				for(j = i+1; j < len; j++){
					if( strcmp(list[i].lastName,list[j].lastName ) < 0 || (  !strcmp(list[i].lastName,list[j].lastName) && list[i].sector < list[j].sector ) ){
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
		}
		status = 0;
	}

	return status;
}

int printEmployees(Employee* list, int length){
	int status = -1;
	int flag = 0;
	if(list != NULL && length > 0){
		printf("\n------------ Employee List ----------\n");
				printf("   ID   Name          Surname         Salary     Sector\n");
		for(int i = 0; i < length; i++){
			if(list[i].isEmpty == 0){
				printf("   %d  %5s           %5s           %5.2f      %d \n",list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
				flag = 1;
			}
		}
		if(!flag){
			printf("------ No employees loaded ---\n\n");
		}
	}
	return status;
}

int modifyEmployee(Employee* list, int len){
	int status = -1;
	int index;
	int id;
	int option ;
	if(list != NULL && len > 0){
		printEmployees(list,len);
		utn_getNumero(&id, "\n-- Enter ID of employee to modify: ", "\n-!- ID invalido -!- ",1,1000,10);
		index = findEmployeeById(list, len, id);
		if(index == -1){
			printf("\n-!- Employee doesn't exist -!-\n");
			status = -1;
		}else{
			printf("----- EDITING -----");
			utn_getNumero(&option, "\n1) Name \n2) Surname \n3) Salary \n4) Sector \n5) Volver \n --- Enter field to edit: ", "\n-!- Opcion invalida -!- ",1,5,10);
			switch(option){
				case 1:
					__fpurge(stdin);
					utn_getName("\n-- Enter name: ", "\n-!- Invalid -!-", 1, 51, 10, list[index].name);
					break;
				case 2:
					__fpurge(stdin);
					utn_getName("\n-- Enter surname: ", "\n-!- Invalid -!-", 1, 51, 10, list[index].lastName);
					break;
				case 3:
					printf("\n -- Enter new salary: ");
					scanf(" %f", &list[index].salary);
					break;
				case 4:
					utn_getNumero(&list[index].sector, "\n Enter new sector: ", "\n-!- Invalido -!-", 0, 10000, 10);
					break;
				case 5:
					break;
			}
			status = 0;
		}
	}

	return status;
}

Employee employeeDataInput(){
	Employee new;
	__fpurge(stdin);
	utn_getName("\n-- Enter name: ", "\n-!- Invalid -!-", 1, 51, 10, new.name);

	__fpurge(stdin);
	utn_getName("\n-- Enter surname: ", "\n-!- Invalid -!-", 1, 51, 10, new.lastName);

	getFloat(&new.salary, "\n Enter salary: ", "-!- Invalido -!-");

	utn_getNumero(&new.sector, "\n Enter sector: ", "\n-!- Invalido -!-", 0, 10000, 10);
	return new;
}

int reportsEmployees(Employee* list, int len){
	int status = 0;
	int option;
	float sumSalary = 0;
	int cantEmp = 0;
	if(list != NULL && len > 0){
		utn_getNumero(&option, "\n\n--- Reports available ---\n 1) Employees (Last name/Sector ascendant) \n 2) Employees (Last name/Sector descendant) \n 3) Salaries and average \n 4) Back \n -- Select option: ", "\n-!- Invalid Option -!- \n",1,4,10);
		switch(option){
			case 1:
				status = sortEmployees(list, len, 1);
				printEmployees(list, len);
				break;
			case 2:
				status = sortEmployees(list, len, 0);
				printEmployees(list, len);
				break;
			case 3:
				sumSalary = 0;
				cantEmp = 0;
				for(int i = 0; i < len; i++){
					if(list[i].isEmpty == 0){
						sumSalary += list[i].salary;
						cantEmp++;
					}
				}
				float average = (float) sumSalary/cantEmp;
				printf("\n-------- Total salaries: %.2f ---- Average: %.2f \n", sumSalary, average);
				cantEmp = 0;
				for(int i = 0; i < len; i++){
					if(list[i].isEmpty == 0 && list[i].salary > average){
						cantEmp++;
					}
				}
				printf("------- Employees with salary above average: %d \n\n",cantEmp);
				break;
			case 4:
				break;
		}
	}

	return status;
}

