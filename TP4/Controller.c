#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "autos.h"
#include "parser.h"
#include "string.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListCars)
{
	int todoOk = -1;

	FILE* f;

	if(path != NULL && pArrayListCars!= NULL)
	{
		f = fopen(path, "r");


		if(f != NULL)
		{
			if(! parser_autoFromText(f, pArrayListCars))
			{
				todoOk = 0;
			}
			fclose(f);
		}
	}
    return todoOk;
}

/** \brief Guarda los datos de los autos en un archivo.csv
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListAuto)
{
	int todoOk = -1;
	FILE* f;
	int tam = ll_len(pArrayListAuto);
	int id;
	char marca[128];
	int anio;
	int precio;
	char color[20];

	eAuto* auxAuto;

	if(pArrayListAuto != NULL && path != NULL)
		{
			f = fopen(path, "w");

			if(f != NULL)
			{
				todoOk = 0;

				for(int i = 0; i < tam; i++)
				{
					auxAuto = ll_get(pArrayListAuto, i);

                    auto_getId(auxAuto, &id);
					auto_getMarca(auxAuto, marca);
					auto_getAnio(auxAuto, &anio);
					auto_getColor(auxAuto, color);
					auto_getPrecio(auxAuto, &precio);

                    fprintf(f,"%4d, %10s, %4d, %10s,%d\n", id, marca, anio, color, precio);

				}

				fclose(f);
			}
			else
            {
                printf("No se púdo guardar\n");
            }
		}


    return todoOk;
}


/** \brief muestra los autos que se encuentran en la lista
 *
* \param lista que se muestra
 * \return int
 *
 */
int controller_ListAuto(LinkedList* pArrayListAutos)
{
	listarAutos(pArrayListAutos);

    return 1;
}


/** \brief realiza una sublista
 *
 * \return lista nueva
 *
 */
int controller_NewListAnio(void* unAuto)
{
    int auxReturn = 0;

    eAuto* x;
    x = (eAuto*) unAuto;

    if(x->anio >= 2000 && x->anio <= 2005)
    {
        auxReturn = 1;
    }

    return auxReturn;
}


/** \brief añade un auto a la lista
 *
* \param lista en la que se agrega un auto
 * \return int
 *
 */
int controller_addAuto(LinkedList* pArrayListAutos)
{
	altaAuto(pArrayListAutos);

    return 1;
}

/** \brief realiza un backup de la lista de autos
 *
* \param lista a realizar el backup
 * \return el backup
 *
 */
LinkedList* controller_backUp(LinkedList* this)
{
    LinkedList* nuevaLista;

    if(this != NULL)
    {
        nuevaLista = ll_clone(this);
    }

    return nuevaLista;
}

/** \brief compara los datos de dos listas para saber si son iguales
 *
 * \param lista a comparar
  * \param lista a comparar
 * \return 0 si pudo, 1 si fallo
 *
 */
int controller_compareLinkedList(LinkedList* this, LinkedList* this2)
{
    int todoOk = 0;

    if(this != NULL && this2 != NULL)
    {
        if(ll_containsAll(this2, this))
        {
            todoOk = 1;
        }

    }
    return todoOk;
}

/** \brief borra los datos de una lista
 *
 * \param lista a modificar
 * \return 0 si limpio los datos, 1 si fallo
 *
 */
int controller_clearLinkedList(LinkedList* this)
{
    int todoOk = 1;

    if(this != NULL)
    {
        ll_clear(this);
        todoOk = 0;
    }

    return todoOk;
}


/** \brief Ordena los autos de la lista
 *
 * \param lista a ordenar
 * \return int
 *
 */
int controller_sortAuto(LinkedList* pArrayListAuto)
{
    int orden;

	switch(menuOrdenamientoAutos())
	{
        case 1:
            do
            {
            printf(" 1 - Ascendente");
            printf("\n 0 - Descendente\n");
            printf("¿Como desea ordenarlo?: ");
            scanf("%d", &orden);
            }
            while(orden != 1 && orden !=0);

            printf("Se estan realizando los cambios\n");
            ll_sort(pArrayListAuto, autoComparaId, orden);
            controller_ListAuto(pArrayListAuto);
            break;
        case 2:
            do
            {
            printf(" 1 - Ascendente");
            printf("\n 0 - Descendente\n");
            printf("¿Como desea ordenarlo?: ");
            scanf("%d", &orden);
            }
            while(orden != 1 && orden !=0);

            printf("Se estan realizando los cambios\n");
            ll_sort(pArrayListAuto, autoComparaMarca, orden );
            controller_ListAuto(pArrayListAuto);
            break;
        case 3:
            do
            {
            printf(" 1 - Ascendente");
            printf("\n 0 - Descendente\n");
            printf("¿Como desea ordenarlo?: ");
            scanf("%d", &orden);
            }
            while(orden != 1 && orden !=0);

            printf("Se estan realizando los cambios\n");
            ll_sort(pArrayListAuto, autoComparaAnio, orden );
            controller_ListAuto(pArrayListAuto);
            break;
        case 4:
            do
            {
            printf(" 1 - Ascendente");
            printf("\n 0 - Descendente\n");
            printf("¿Como desea ordenarlo?: ");
            scanf("%d", &orden);
            }
            while(orden != 1 && orden !=0);

            printf("Se estan realizando los cambios\n");
            ll_sort(pArrayListAuto, autoComparaColor, orden );
            controller_ListAuto(pArrayListAuto);
            break;
        case 5:
            do
            {
            printf(" 1 - Ascendente");
            printf("\n 0 - Descendente\n");
            printf("¿Como desea ordenarlo?: ");
            scanf("%d", &orden);
            }
            while(orden != 1 && orden !=0);

            printf("Se estan realizando los cambios\n");
            ll_sort(pArrayListAuto, autoComparaPrecio, orden );
            controller_ListAuto(pArrayListAuto);
            break;
        default:
            printf("Opcion no valida");
	}

    return 1;
}

/** \brief modifica la lista de autos
 *
 * \param lista de autos
 * \return retorna la lista modificada
 *
 */

int controller_editAuto(LinkedList* pArrayListAuto)
{
    modificarAuto(pArrayListAuto);
    return 1;
}

/** \brief elimina un auto de la lista
 *
 * \param lista de autos
 * \return retorna la lista modificada sin el auto eliminado
 *
 */
int controller_removeAuto(LinkedList* pArrayListAuto)
{
    bajaAuto(pArrayListAuto);
    return 1;
}





