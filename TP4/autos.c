#include "autos.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"


/** \brief reserva un espacio en memoria para un auto nuevo
 *
 * \return devuelve un puntero de auto al espacio de memoria creado
 *
 */
eAuto* auto_new()
{
	eAuto* nuevoAuto =(eAuto*) malloc(sizeof(eAuto));

	    if(nuevoAuto != NULL)
	    {
	    	nuevoAuto->id = 0;
	    	nuevoAuto->anio = 0;
	    	nuevoAuto->precio = 0;
	        strcpy(nuevoAuto->marca, "");
	        strcpy(nuevoAuto->color, "");

	    }

	    return nuevoAuto;
}


/** \brief recibe los datos por una cadena, crea un auto y llama a funciones para cargar los datos al auto
 *
 * \param idStr char* id del auto
 * \param marca char* marca del auto
 * \param anio char* anio del auto
 * \param color char* color del auto
  * \param precio char* precio del auto
 * \return devuelve puntero al auto creado con lo datos del auto cargados al archivo
 *
 */
eAuto* auto_newParametros(char* idStr,char* marca, char* anio, char* color, char* precio)
{
	eAuto* nuevoAuto = auto_new();

	    if(nuevoAuto != NULL)
	    {
	        if(! (auto_setId(nuevoAuto, atoi(idStr)) && auto_setMarca(nuevoAuto, marca) && auto_setAnio(nuevoAuto, atoi(anio)) && auto_setColor(nuevoAuto, color) && auto_setPrecio(nuevoAuto, atoi(precio))) )
	        {
	            free(nuevoAuto);
	            nuevoAuto = NULL;
	        }
	    }
	    return nuevoAuto;
}


/** \brief carga el Id al auto
 *
 * \param this puntero al auto
 * \param id id del auto
 * \return 1 si pudo, 0 si no
 *
 */
int auto_setId(eAuto* this,int id)
{
	int todoOk = 0;

	    if(this != NULL && id >=0)
	    {
	        this->id = id;
	        todoOk = 1;
	    }
    return todoOk;
}

/** \brief Carga el Id de un auto en una variable
 *
 * \param this auto al que se le carga el dato
 * \param id puntero a la variable
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int auto_getId(eAuto* this,int* id)
{
	 int todoOk = 0;

		if(this != NULL && id != NULL)
		{
			*id = this->id;
			todoOk = 1;
		}
  return todoOk;
}

/** \brief carga la marca en el auto
 *
 * \param this puntero al auto
 * \param marca marca del auto
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int auto_setMarca(eAuto* this,char* marca)
{
	int todoOk = 0;

	    if(this != NULL && marca != NULL && strlen(marca) >= 3 && strlen(marca)< 20)
	    {
	    	normalizeStr(marca);
	        strcpy(this->marca, marca);
	        todoOk = 1;
	    }
	    return todoOk;
}

/** \brief Carga la marca de un auto en una variable
 *
 * \param this auto al que se le carga el dato
 * \param marca puntero a la variable
 * \return int
 *
 */
int auto_getMarca(eAuto* this,char* marca)
{
	 strcpy(marca, this->marca);

    return 1;
}

/** \brief carga el anio en el auto
 *
 * \param this puntero al auto
 * \param anio anio del auto
 * \return int
 *
 */
int auto_setAnio(eAuto* this,int anio)
{
	if(this != NULL && anio >=0)
	{
		 this->anio = anio;
	}

	 return 1;
}

/** \brief Carga el anio de un auto en una variable
 *
 * \param this auto al que se le carga el dato
 * \param anio puntero a la variable
 * \return int
 *
 */
int auto_getAnio(eAuto* this,int* anio)
{
	if(this != NULL && anio != NULL)
	{
		*anio = this->anio;
	}
	return 1;
}

/** \brief carga el precio en el auto
 *
 * \param this puntero al auto
 * \param precio precio del auto
 * \return int
 *
 */
int auto_setPrecio(eAuto* this,int precio)
{
	if(this != NULL && precio >= 0)
	{
		this->precio = precio;
	}
	return 1;
}

/** \brief Carga el precio de un auto en una variable
 *
 * \param this auto al que se le carga el dato
 * \param precio puntero a la variable
 * \return int
 *
 */
int auto_getPrecio(eAuto* this,int* precio)
{
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
	}
	return 1;
}

/** \brief carga el color en el auto
 *
 * \param this puntero al auto
 * \param marca marca del auto
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int auto_setColor(eAuto* this,char* color)
{
	int todoOk = 0;

	    if(this != NULL && color != NULL && strlen(color) >= 3 && strlen(color)< 20)
	    {
	        strcpy(this->color, color);
	        todoOk = 1;
	    }
	    return todoOk;
}

/** \brief Carga el color de un auto en una variable
 *
 * \param this auto al que se le carga el dato
 * \param color puntero a la variable
 * \return int
 *
 */
int auto_getColor(eAuto* this,char* color)
{
    strcpy(color, this->color);

    return 1;
}

/** \brief menu de opciones
 *
 * \param opcion int* carga la opcion elegida por el usuario
 * \return void
 *
 */

void menu(int* opcion)
{
    system("cls");
    printf("----------Gestion de Autos---------\n\n");
    printf("1-Cargar los datos de los autos desde el archivo autos.csv .\n");
    printf("2-Alta autos\n");
    printf("3-Modificar autos\n");
    printf("4-Baja autos\n");
    printf("5-Ordenar autos\n");
    printf("6-Listar autos\n");
    printf("7-Realizar BackUp\n");
    printf("8-Verificar si los elementos de la lista y el BackUp son iguales\n");
    printf("9-Realizar sublista de anios\n");
    printf("10-Vaciar sublista\n");
    printf("11-Eliminar sublista\n");
    printf("12-Guardar los datos de los autos en el archivo autos.csv \n");
    printf("13-Salir \n");

    fflush(stdin);
    utn_getEntero(opcion, 3, "Ingrese una opcion: ", "ERROR. Opcion ingresada no valida\n", 1, 13);

}

/** \brief Busca si un ID existe en la lista
 *
  * \param id id a buscar
 * \param lista Lista a revisar
 * \return retorna indice si pudo cargar, -1 si fallo
 *
 */
int buscarAutoId(int id, LinkedList* lista)
{
    int indice = -1;
    int tam = ll_len(lista);
    eAuto* auto1;
    int auxId;


    if(lista != NULL)
    {
		for(int i = 0; i < tam; i++)
		{
			auto1 = (eAuto*) ll_get(lista, i);
			auto_getId(auto1, &auxId);

			if(auxId == id)
			{
				indice = ll_indexOf(lista, auto1);
				break;
			}
		}
    }

    return indice;
}

/** \brief Da de alta un nuevo auto a la lista
 *
 * \param lista lista en la que se cargara el nuevo auto
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int altaAuto(LinkedList* lista)
{
    int todoOK = 0;
    int id;
    int existe;

    eAuto* auxAuto = (eAuto*) auto_new();

    system("cls");

    printf("----Alta Autos----\n");

    printf("Ingrese ID: ");
    scanf("%d", &id);

    existe = buscarAutoId( id, lista );

    if(existe != -1)
    {
        printf("Ya existe un auto con ese ID");
    }
    else
    {
        auxAuto->id = id;


        printf("Ingrese marca: ");
        fflush(stdin);
        gets(auxAuto->marca);
        normalizeStr(auxAuto->marca);


        printf("Ingrese anio: ");
        scanf("%d", &auxAuto->anio);

        printf("Ingrese color: ");
        fflush(stdin);
        gets(auxAuto->color);
        normalizeStr(auxAuto->color);

        printf("Ingrese precio: ");
        scanf("%f", &auxAuto->precio);

        if (ll_add(lista, auxAuto) == 0)
        {
            todoOK = 1;
            printf("Se ha realizado el alta del auto\n");
        }

    }

    return todoOK;
}

/** \brief Muestra la lista de autos cargados en el sistema
 *
 * \param lista lista que se va a mostrar
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int listarAutos(LinkedList* lista)
{
	int todoOk =  0;
	int tam = ll_len(lista);
    printf("  ID          NOMBRE     ANIO      COLOR     PRECIO\n");

    if(lista != NULL)
    {
    	todoOk = 1;

		for (int i = 0; i < tam; i++)
		{
			listarAuto(lista, i);
		}

    }
	return todoOk;
}

/** \brief Muestra un auto de la lista
 *
 * \param lista lista en la que se encuentra el auto
 * \param indice indice del elemento en la lista
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int listarAuto(LinkedList* lista, int indice)
{
	int todoOk = 0;

    eAuto* auxAuto = (eAuto*) auto_new();

    if(lista != NULL)
    {
    	todoOk = 1;
		auxAuto = ll_get(lista, indice);
		printf("%4d   %12s      %4d      %10s   %10.2f \n", auxAuto->id, auxAuto->marca, auxAuto->anio, auxAuto->color, auxAuto->precio);
    }

    return todoOk;
}


/** \brief Pide id del auto para modificarlo
 *
 * \param lista lista donde se encuentra el auto
 * \return lista de autos modificados
 *
 */
int modificarAuto(LinkedList* lista)
{
	int todoOk = -1;
	int indice;
    char confirma;
    char seguir = 's';
    int id;
    int nuevoId;
    int nuevoPrecio;
    int nuevoAnio;
    char nuevaMarca[51];
    char nuevoColor[51];
    int opcion;

    eAuto* auxAuto = (eAuto*) auto_new();

    system("cls");
    printf("***** Modificar auto *****\n\n");

    listarAutos(lista);

    printf("Ingrese el ID del auto a modificar: ");
    scanf("%d", &id);

    indice = buscarAutoId(id, lista);

    if(indice == -1)
    {
        printf("No existe un auto con el ID: %d\n\n", id);
    }
    else
    {
    	auxAuto = ll_get(lista, indice);
    	listarAutos(lista);

        printf("El ID %d pertenece al auto:\n", id);
        printf("  ID    NOMBRE  ANIO  COLOR PRECIO\n");

        listarAuto(lista, indice);
       do
       {
        printf("Modifica auto? s/n: ");
        fflush(stdin);
        scanf("%c", &confirma);
       }
        while(confirma != 's' && confirma != 'n');


        if(confirma == 's')
        {
            do
            {
                system("cls");

                printf("----------Gestion de Autos---------\n\n");
                printf("1- Modificar marca\n");
                printf("2- Modificar id\n");
                printf("3- Modificar anio\n");;
                printf("4- Modificar precio\n");
                printf("5- Modificar color\n");

                do
                {
                    printf("Ingrese opcion: ");
                    fflush(stdin);
                    scanf("%d", &opcion);
                }
                while(opcion < 1 || opcion > 5);


                switch(opcion)
                {
                    case 1:
                        printf("Modificar marca\n");

                        printf("Ingrese nueva marca: ");
                        fflush(stdin);
                        gets(nuevaMarca);
                        normalizeStr(nuevaMarca);
                        strcpy(auxAuto->marca, nuevaMarca);

                        printf("Se ha actualizado la marca del auto con exito\n\n");
                        break;
                    case 2:
                        printf("Modificar id\n");

                        printf("Ingrese nuevo id: ");
                        scanf("%d", &nuevoId);

                        auxAuto->id = nuevoId;

                        printf("Se ha actualizado el id del auto con exito\n\n");
                        break;
                    case 3:
                        printf("Modificar anio\n");

                        printf("Ingrese nuevo anio: ");
                        scanf("%d", &nuevoAnio);

                        auxAuto->anio = nuevoAnio;
                        printf("Se ha actualizado el anio con exito\n\n");
                        break;
                    case 4:
                        printf("Modificar precio del auto\n");

                        printf("Ingrese nueva precio: ");
                        scanf("%d", &nuevoPrecio);

                        auxAuto->precio = nuevoPrecio;
                        printf("Se ha el precio con exito\n\n");
                        break;
                    case 5:
                        printf("Modificar color\n");

                        printf("Ingrese nuevo color: ");
                        fflush(stdin);
                        gets(nuevoColor);
                        normalizeStr(nuevoColor);
                        strcpy(auxAuto->color, nuevoColor);

                        printf("Se ha actualizado el color del auto con exito\n\n");
                    default:
                    {
                        printf("Se ha cancelado la operacion\n\n");
                    }
                }

                printf("Datos modificados correctamente\n");

                listarAutos(lista);

                printf("\nDesea continuar con las modificaciones? s/n: ");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's')
                {
                    seguir = 's';
                }
                else if(confirma == 'n')
                {
                    seguir = 'n';
                }
                else
                {
                	printf("Opcion no valida");
                }
            }
            while(seguir == 's');

        }
        else if(confirma == 'n')
        {
            printf("Ningun auto ha sido modificado\n");
        }
    }
    todoOk = 0;


    return todoOk;
}


/** \brief Borra un auto de la lista recibiendo el ID del mismo
 *
 * \param lista lista en la que se encuentra el auto
 * \return void
 *
 */
void bajaAuto(LinkedList* lista)
{
    int id;
    int indice;
    int tam = ll_len(lista);
    char confirmaBaja;
    int auxId;
    //int flag = 0;

    eAuto* auxAuto = (eAuto*) auto_new();

    system("cls");

    printf("----Baja Auto----\n");

    listarAutos(lista);

    for(int i = 0; i < tam; i++)
    {
        auxAuto = ll_get(lista, i);
        auto_getId(auxAuto, &auxId);

        if (auxAuto->id == id)
        {
            auxAuto->id = id;
            break;
        }
    }

    printf("Ingrese ID: ");
    scanf("%d", &id);

    indice = buscarAutoId(id, lista);

    if(indice == -1)
    {
        printf("No existe un auto con el ID: %d\n", id);
    }
    else
    {
		 printf("Se va a dar de baja al auto con el id: %d \n", id);
		 printf("  ID        NOMBRE       ANIO         COLOR         PRECIO\n");
		 listarAuto(lista, indice);

		 do
	       {
	        printf("Confirma la baja del auto? s/n: ");
	        fflush(stdin);
	        scanf("%c", &confirmaBaja);
	       }
            while(confirmaBaja != 's' && confirmaBaja != 'n');

		 if(confirmaBaja == 's'  )
		 {
			ll_remove(lista, indice);
            printf("Operacion realizada con exito\n");

		 }
		 else if(confirmaBaja == 'n')
		 {
			 printf("Operacion cancelada\n");
		 }
		 else
		 {
			 printf("operacion invalida\n");
		 }
    }

}

/** \brief Compara el ID de los autos
 *
 * \return return retorna 1, -1 o 0 dependiendo de como se ordene
 *
 */
int autoComparaId(void* a, void* b)
{
    int todoOk = 0;
    eAuto* primerId;
    eAuto* segundoId;

    if(a != NULL && b!= NULL)
    {
    	primerId = (eAuto*) a;
    	segundoId = (eAuto*) b;
    }

    if(primerId->id > segundoId->id)
    {
    	todoOk = 1;
    }
    else if(primerId->id < segundoId->id)
    {
    	todoOk = -1;
    }

    return todoOk;
}

/** \brief Compara la marca de los autos
 *
 * \return return retorna 1, -1 o 0 dependiendo de como se ordene
 *
 */
int autoComparaMarca(void* a, void* b)
{
	int todoOk = 0;
	char primerNombre[128];
	char segundoNombre[128];

	auto_getMarca(a, primerNombre);
	auto_getMarca(b, segundoNombre);


	if (strcmp(primerNombre, segundoNombre) > 0)
	{
		todoOk = 1;

	}
	else if (strcmp(primerNombre, segundoNombre) < 0)
	{
		todoOk = -1;
	}

	return todoOk;
}

/** \brief Compara el color de los autos
 *
 * \return return retorna 1, -1 o 0 dependiendo de como se ordene
 *
 */
int autoComparaColor(void* a, void* b)
{
	int todoOk = 0;
	char primerColor[128];
	char segundoColor[128];

	auto_getColor(a, primerColor);
	auto_getColor(b, segundoColor);

	if (strcmp(primerColor, segundoColor) > 0)
	{
		todoOk = 1;

	}
	else if (strcmp(primerColor, segundoColor) < 0)
	{
		todoOk = -1;
	}

	return todoOk;
}

/** \brief Compara el precio de los autos
 *
 * \return return retorna 1, -1 o 0 dependiendo de como se ordene
 *
 */
int autoComparaPrecio(void* a, void* b)
{
	int todoOk = 0;
	eAuto* primerPrecio;
	eAuto* segundoPrecio;

	if(a != NULL && b!= NULL)
	{
		primerPrecio = (eAuto*) a;
		segundoPrecio = (eAuto*) b;
	}
	if(primerPrecio->precio > segundoPrecio->precio)
	{
		todoOk = 1;
	}
	else if(primerPrecio->precio < segundoPrecio->precio)
	{
		todoOk = -1;
	}

	return todoOk;
}

/** \brief Compara el anio de los autos
 *
 * \return return retorna 1, -1 o 0 dependiendo de como se ordene
 *
 */
int autoComparaAnio(void* a, void* b)
{
	int todoOk = 0;

	eAuto* anio1;
	eAuto* anio2;

	if(a != NULL && b!= NULL)
	{
		anio1 = (eAuto*) a;
		anio2 = (eAuto*) b;
	}

	if(anio1->anio > anio2->anio)
	{
		todoOk = 1;
	}
	else if(anio1->anio < anio2->anio)
	{
		todoOk = -1;
	}

	return todoOk;
}

/** \brief menu para ordenar los autos
 *
 * \return opcion elegida por el usuario
 *
 */

int menuOrdenamientoAutos()
{
	int opcion;

	printf("Como desea ordenarlo?\n");
	printf("1 - Ordenar por ID\n");
	printf("2 - Ordenar por marca\n");
	printf("3 - Ordenar por anio\n");
	printf("4 - Ordenar por color\n");
	printf("5 - Ordenar por precio\n");

	do
    {
        printf("Indique opcion: ");
        scanf("%d", &opcion);
    }
    while(opcion < 1 || opcion > 5);


	return opcion;
}


/** \brief menu eliminar una lista
 *
 * \return opcion elegida por el usuario
 *
 */
int menuEliminacionListas()
{
	char opcion;

	printf("Desea eliminar la lista filtrada? \n");

	do
    {
        printf("Indique opcion s/n : ");
        fflush(stdin);
        scanf("%c", &opcion);
    }
    while(opcion != 's' && opcion != 'n');

	return opcion;

}










