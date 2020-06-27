#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "autos.h"
#include "controller.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_autoFromText(FILE* pFile , LinkedList* pArrayAutos)
{
	int todoOk = 0;
	int cant;
	char buffer[5][128];
	eAuto* auxAuto = NULL;

	if(pFile!= NULL && pArrayAutos != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,], %[^\n]",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%[^,],%[^,],%[^,], %[^,], %[^\n]",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

			if (cant == 5)
			{
				auxAuto = auto_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]);

				if (auxAuto != NULL)
				{

					ll_add(pArrayAutos, auxAuto);

				}
			}
		}
	}

	todoOk = 1;
	return todoOk;
}

