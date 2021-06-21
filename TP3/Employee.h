#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief It creates a new Employee dynamically allocated initialized
 *
 * \return Employee*
 *
 */
Employee* employee_new();

/** \brief It creates a new Employee dynamically allocated initialized with the parameters given
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldo char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/** \brief Destroys an employee dynamically alocated
 *
 * \param emp Employee*
 * \return void
 *
 */
void employee_delete(Employee* emp);

/** \brief Setter used to assign ID
 *
 * \param emp Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* emp,int id);

/** \brief Getter used to obtain ID in the parameter
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Setter used to assign Nombre
 *
 * \param emp Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* emp,char* nombre);

/** \brief Getter used to obtain Nombre in the parameter
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Setter used to assign Horas Trabajadas
 *
 * \param emp Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* emp,int horasTrabajadas);

/** \brief Getter used to obtain HorasTrabajadas in the parameter
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Setter used to assign Sueldo
 *
 * \param emp Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* emp,int sueldo);

/** \brief Getter used to obtain Sueldo in the parameter
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
