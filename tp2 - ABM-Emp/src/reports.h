#ifndef REPORTS_H_INCLUDED
#define REPORTS_H_INCLUDED
#include "arrayEmployees.h"
#include "sectores.h"



#endif // REPORTS_H_INCLUDED


/** \brief load the sector description
 * \param vec Employee*
 * \param size of Employee*
 * \param sectores eSector[]
 * \param size of sectores
 * \return not return
 *
 */
void reports(Employee vec[], int len, eSector sectores [], int lensec);



/** \brief show an reports options menu
 *
 * return return option chosen by the user
 */
int reportsMenu();



/** \brief calculator that makes the total and promedy of employee salaries
 * \param vec Employee*
 * \param size of Employee*
 * \return not return
 *
 */
void reportSalary(Employee vec[], int len);
