#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "controller.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int cant;
	char buffer[4][128];
	Employee* auxEmpleado = NULL;

	if(pFile!= NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3]);

		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]",buffer[0], buffer[1], buffer[2], buffer[3]);

			if (cant == 4)
			{
				auxEmpleado = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

				if (auxEmpleado != NULL)
				{

					ll_add(pArrayListEmployee, auxEmpleado);

				}
			}
		}
	}

	todoOk = 1;
	return todoOk;
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
	int retorno = -1;
	Employee* auxEmpleado;

	if(pFile != NULL)
	{
		do
		{
			auxEmpleado = employee_new();

			if(fread(auxEmpleado, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, auxEmpleado);
				retorno = 0;
			}
		}
		while(!feof(pFile));
	}

	return retorno;
}
