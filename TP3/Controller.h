#include "parser.h"
#include "Employee.h"
#include "utn.h"


/** \brief It loads from a csv file employee data into a linked list
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param loaded int*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee,int* loaded);

/** \brief It loads from a bin file employee data into a linked list
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param loaded int*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee, int* loaded);

/** \brief Creates an employee, requesting its data and load it into the linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \param pId int*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,int* pId);

/** \brief Returns the employee located in the index sent in the parameters
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \param index int*
 * \return Employee*
 *
 */
Employee* controller_searchEmployeeID(LinkedList* pArrayListEmployee,int id, int* index);

/** \brief Displays the data of one employee
 *
 * \param emp Employee*
 * \return void
 *
 */
void controller_showEmployee(Employee* emp);

/** \brief It requests the ID of an employee and select the field you want to edit of that record
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief It removes one employee using its ID from the linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Lists all the employees in given linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief It sorts the employee by Name in the linked list
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief This is the condition used to sort the employees
 *
 * \param a void*
 * \param b void*
 * \return int
 *
 */
int employeeCompareNombre(void* a,void* b);

/** \brief Saves in text format the data present in the actual linked list
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \param loaded int
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee, int loaded);

/** \brief Saves in binary format the data present in the actual linked list
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



