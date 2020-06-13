#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = -1;

	FILE* f;

	if(path != NULL && pArrayListEmployee!= NULL)
	{
		f = fopen(path, "r");


		if(f != NULL)
		{
			if(! parser_EmployeeFromText(f, pArrayListEmployee))
			{
				todoOk = 0;
			}
			fclose(f);
		}
	}
    return todoOk;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = -1;
		FILE* f;

		f = fopen(path, "rb");

		if(f != NULL)
		{
			if(!parser_EmployeeFromBinary(f, pArrayListEmployee))
			{
				todoOk = 0;
				printf("Archivo cargado con exito\n");
			}

			fclose(f);
		}
		else
		{
			printf("Error. No se pudo cargar el archivo\n");
		}

 return todoOk;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	altaEmpleado(pArrayListEmployee);
    return 1;
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
	modificarEmpleado(pArrayListEmployee);
    return 1;
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
	bajaEmpleado(pArrayListEmployee);
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
	listarEmpleados(pArrayListEmployee);
    return 1;
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
	int orden;

	switch(menuOrdenamientoEmpleados())
	{
	case 1:
		do
		{
		printf(" 1 - Ascendente");
		printf("\n 0 - Descendente\n");
		printf("¿Como desea ordenarlo?: ");
		scanf("%d", &orden);
		}while(orden != 1 && orden !=0);

		printf("Se estan realizando los cambios\n");
		ll_sort(pArrayListEmployee, empleadoComparaId, orden);
		controller_ListEmployee(pArrayListEmployee);
		break;
	case 2:
		do
		{
		printf(" 1 - Ascendente");
		printf("\n 0 - Descendente\n");
		printf("¿Como desea ordenarlo?: ");
		scanf("%d", &orden);
		}while(orden != 1 && orden !=0);

		printf("Se estan realizando los cambios\n");
		ll_sort(pArrayListEmployee, empleadoComparaNombre, orden );
		controller_ListEmployee(pArrayListEmployee);
		break;
	case 3:
		do
		{
		printf(" 1 - Ascendente");
		printf("\n 0 - Descendente\n");
		printf("¿Como desea ordenarlo?: ");
		scanf("%d", &orden);
		}while(orden != 1 && orden !=0);

		printf("Se estan realizando los cambios\n");
		ll_sort(pArrayListEmployee, empleadoComparaSueldo, orden );
		controller_ListEmployee(pArrayListEmployee);
		break;
	case 4:
		do
		{
		printf(" 1 - Ascendente");
		printf("\n 0 - Descendente\n");
		printf("¿Como desea ordenarlo?: ");
		scanf("%d", &orden);
		}while(orden != 1 && orden !=0);

		printf("Se estan realizando los cambios\n");
		ll_sort(pArrayListEmployee, empleadoComparaHorasTrabajadas, orden );
		controller_ListEmployee(pArrayListEmployee);
		break;
	default:
		printf("Opcion no valida");
	}
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = -1;
	FILE* f;
	int tam = ll_len(pArrayListEmployee);
	int id;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;

	Employee* auxEmpleado;

	if(pArrayListEmployee != NULL && path != NULL)
		{
			f = fopen(path, "w");

			if(f != NULL)
			{
				todoOk = 0;

				for(int i = 1; i < tam; i++)
				{
					auxEmpleado = ll_get(pArrayListEmployee, i);

					if(!employee_getId(auxEmpleado, &id) && !employee_getNombre(auxEmpleado, nombre) && !employee_getHorasTrabajadas(auxEmpleado, &horasTrabajadas) && !employee_getSueldo(auxEmpleado, &sueldo))
					{
						fprintf(f, "%5d,%10s,%6d,%7d\n", id, nombre, horasTrabajadas, sueldo);
					}
				}

				fclose(f);
			}
		}


    return todoOk;
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
	int todoOk = -1;
	FILE* f;
	int tam = ll_len(pArrayListEmployee);
	Employee* auxEmpleado;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		f = fopen(path, "wb");

		for(int i = 1; i < tam; i++)
		{
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

			if(auxEmpleado != NULL)
			{
				fwrite(auxEmpleado, sizeof(Employee), 1, f);
			}

		}
		fclose(f);
		todoOk = 0;
	}

	return todoOk;

}

