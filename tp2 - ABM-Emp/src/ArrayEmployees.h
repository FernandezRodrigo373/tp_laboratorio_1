#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include "sectores.h"
#include <ctype.h>

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

#endif // EMPLEADO_H_INCLUDED



/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee[]
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param index int
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary, int index, int sector);



/** \brief print the content of employees array
 *
 * \param list Employee[]
 * \param length int
 * \param sectores eSector[]
 * return not return
 */
void printEmployees(Employee vec[], int len, eSector sectores [], int lensec);


/** \brief print the content of one employee
 *
 * \param x Employee[]
 * \param sectores eSector[]
 * \param lensec int
 *  return not return
 */
void showEmployee(Employee x, eSector sectores [], int lensec);




/** \brief show an options menu
 *
 * return return option chosen by the user
 */
int menu();


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len);


/** \brief collect employee information for "addEmployee"
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \param nextId* pointer to nextId
 * \param auxName char
 * \param auxLastName char
 * \param auxSalary* pointer to auxSalary
 * \param auxSector* pointer to auxSector
 * \param index* pointer to index
 * \param sectores eSector[]
 * \param lensec int
 *
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int collectInfo(Employee list[], int len, int* nextId, char auxName[], char auxLastname[], float *auxSalary, int* auxSector, int *index, eSector sectores[], int lensec);


/** \brief look for an empty place (isEmpty = 0) in employees vector
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int lookForEmpty(Employee* list, int len);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \param sectores eSector[]
 * \param lensec int
 *
 * \return int Return (0) if Error [Invalid length or NULL pointer or if can't
find a employee] - (-1) if Ok
 *
 */
int removeEmployee(Employee list[], int len, int id, eSector sectores [], int lensec);


/** \brief find an Employee by Id and returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id);


/** \brief allows modifying employee information
 *
 * \param vec Employee*
 * \param len int
 * \param sectores eSector[]
 * \param lensec int
 * \return int Return (0) if Error [Invalid length or NULL pointer or if can't
find a employee] - (-1) if Ok
 *
 */
int modifyEmployee(Employee vec[], int len, eSector sectores[], int lensec);


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param vec Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee vec[], int len, int order);


/** \brief normalize the sent string
 *
 * \param vec Employee*
 * \param String to load in "normalizeStr"
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int normalizeStr(char string[]);


/** \brief sets the entered string to lowercase by traversing it and in each position uses tolower.
 *
 * \param vec Employee*
 * \param String to load in lowercase
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int strLwr(char string[]);
