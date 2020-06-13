#include "Employee.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "utn.h"


Employee* employee_new()
{
	Employee* nuevoEmpleado =(Employee*) malloc(sizeof(Employee));

	    if(nuevoEmpleado != NULL)
	    {
	    	nuevoEmpleado->id = 0;
	    	nuevoEmpleado->horasTrabajadas = 0;
	    	nuevoEmpleado->sueldo = 0;
	        strcpy(nuevoEmpleado->nombre, "");
	    }

	    return nuevoEmpleado;
}



Employee* employee_newParametros(char* idStr,char* nombreStr,char* sueldoStr, char* horasTrabajadasStr)
{
	Employee* nuevoEmpleado = employee_new();

	    if(nuevoEmpleado != NULL)
	    {
	        if(! (employee_setId(nuevoEmpleado, atoi(idStr)) && employee_setNombre(nuevoEmpleado, nombreStr) && employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr)) && employee_setSueldo(nuevoEmpleado, atoi(sueldoStr))))
	        {
	            free(nuevoEmpleado);
	            nuevoEmpleado = NULL;
	        }
	    }
	    return nuevoEmpleado;
}



void employee_delete(Employee* empleado)
{
	free(empleado);
}

int employee_setId(Employee* this,int id)
{
	int todoOk = 0;

	    if(this != NULL && id >=0)
	    {
	        this->id = id;
	        todoOk = 1;
	    }
	    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
	 int todoOk = 0;

		if(this != NULL && id != NULL)
		{
			*id = this->id;
			todoOk = 1;
		}
  return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int todoOk = 0;

	    if(this != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre)< 20)
	    {
	    	normalizeStr(nombre);
	        strcpy(this->nombre, nombre);
	        todoOk = 1;
	    }
	    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
	 strcpy(nombre, this->nombre);


	    return 1;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	if(this != NULL && horasTrabajadas >=0)
	{
		 this->horasTrabajadas = horasTrabajadas;
	}

	 return 1;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
	}
	return 1;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	if(this != NULL && sueldo >=0)
	{
		this->sueldo = sueldo;
	}
	return 1;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
	}
	return 1;
}

int menu()
{
    int opcion;

    system("cls");
    printf("----------Gestion de Empleados---------\n\n");
    printf("1-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2-Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3-Alta de empleado\n");
    printf("4-Modificar datos de empleado\n");
    printf("5-Baja de empleado\n");
    printf("6-Listar empleados\n");
    printf("7-Ordenar empleados\n");
    printf("8-Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9-Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10-Salir \n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int buscarEmpleadoId(int id, LinkedList* lista)
{
    int indice = -1;
    int tam = ll_len(lista);

    Employee* auxEmpleado = (Employee*) employee_new();

    if(lista != NULL && auxEmpleado != NULL)
    {
		for(int i = 0; i < tam; i++)
		{
			auxEmpleado = ll_get(lista, i);

			if(auxEmpleado->id == id)
			{
				indice = i;
				break;
			}
		}
    }

    return indice;
}


int altaEmpleado(LinkedList* lista)
{
    int todoOK = 0;
    int id;
    int existe;

    Employee* auxEmpleado = (Employee*) employee_new();

    system("cls");

    printf("----Alta Empleado----\n");

        printf("Ingrese ID: ");
        scanf("%d", &id);

        existe = buscarEmpleadoId(id, lista);

        if(existe != -1)
        {
            printf("Ya existe un empleado con ese ID");
        }
        else
        {
			auxEmpleado->id = id;


			printf("Ingrese Nombre: ");
			fflush(stdin);
			gets(auxEmpleado->nombre);
			normalizeStr(auxEmpleado->nombre);

			do
			{
				printf("Ingrese horas trabajadas: ");
				scanf("%d", &auxEmpleado->horasTrabajadas);
			}
			while(auxEmpleado->horasTrabajadas < 0 || auxEmpleado->horasTrabajadas > 100000);

			do
			{
				printf("Ingrese sueldo: ");
				scanf("%d", &auxEmpleado->sueldo);
			}
			while(auxEmpleado->sueldo < 8000 || auxEmpleado->sueldo > 100000);

			if (ll_add(lista, auxEmpleado) == 0)
			{
				todoOK = 1;
				printf("Se ha realizado el alta del empleado\n");
			}

        }

    return todoOK;
}

int listarEmpleados(LinkedList* lista)
{
	int todoOk =  0;
	int tam = ll_len(lista);
    printf("ID         NOMBRE    HORAS TRABAJADAS   SUELDO\n");

    if(lista != NULL)
    {
    	todoOk = 1;

		for (int i = 0; i < tam; i++)
		{
			listarEmpleado(lista, i);
		}

    }
	return todoOk;
}


int listarEmpleado(LinkedList* lista, int indice)
{
	int todoOk = 0;

    Employee* auxEmpleado = (Employee*) employee_new();

    if(lista != NULL)
    {
    	todoOk = 1;
		auxEmpleado = ll_get(lista, indice);
		printf("%5d%10s      %5d           %d \n", auxEmpleado->id, auxEmpleado->nombre, auxEmpleado->horasTrabajadas, auxEmpleado->sueldo);

    }

    return todoOk;
}

int modificarEmpleado(LinkedList* lista)
{
	int todoOk = -1;
	int indice;
    char confirma;
    char seguir = 's';
    int id;
    int nuevoId;
    int nuevoSueldo;
    char nuevoNombre[51];
    int nuevoHorasTrabajadas;
    int opcion;
    Employee* auxEmpleado = (Employee*) employee_new();

    system("cls");
    printf("***** Modificar empleado *****\n\n");

    listarEmpleados(lista);

    printf("Ingrese el ID del empleado a modificar: ");
    scanf("%d", &id);

    indice = buscarEmpleadoId(id, lista);

    if(indice == -1)
    {
        printf("No existe un empleado con el ID: %d\n\n", id);
    }
    else
    {
    	auxEmpleado = ll_get(lista, indice);
    	listarEmpleados(lista);

        printf("El ID %d pertenece al empleado:\n", id);
        printf("  ID    NOMBRE  HORAS TRABAJADAS  SUELDO\n");

        listarEmpleado(lista, indice);
       do
       {
        printf("Modifica empleado? s/n: ");
        fflush(stdin);
        scanf("%c", &confirma);
       }
        while(confirma != 's' && confirma != 'n');


        if(confirma == 's')
        {
            do
            {
                system("cls");

                printf("----------Gestion de Empleados---------\n\n");
                printf("1- Modificar nombre\n");
                printf("2- Modificar id\n");
                printf("3- Modificar sueldo\n");;
                printf("4- Modificar horasTrabajadas\n");
                printf("Ingrese opcion: ");
                fflush(stdin);
                scanf("%d", &opcion);


                switch(opcion)
                {
                case 1:
                    printf("Modificar nombre\n");

                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(nuevoNombre);
                    normalizeStr(nuevoNombre);
                    strcpy(auxEmpleado->nombre, nuevoNombre);


                    printf("Se ha actualizado el nombre del empleado con exito\n\n");
                    break;
                case 2:
                    printf("Modificar id\n");

                    printf("Ingrese nuevo id: ");
                    scanf("%d", &nuevoId);

                    auxEmpleado->id = nuevoId;

                    printf("Se ha actualizado el id del empleado con exito\n\n");
                    break;
                case 3:
                    printf("Modificar Sueldo\n");

                    printf("Ingrese nuevo sueldo: ");
                    scanf("%d", &nuevoSueldo);

                    auxEmpleado->sueldo = nuevoSueldo;
                    printf("Se ha actualizado el sueldo con exito\n\n");
                    break;
                case 4:
                    printf("Modificar horas trabajadas del empleado\n");

                    printf("Ingrese nueva cantidad de horas trabajdas: ");
                    scanf("%d", &nuevoHorasTrabajadas);

                    auxEmpleado->horasTrabajadas = nuevoHorasTrabajadas;
                    printf("Se ha actualizado las horas trabajadas con exito\n\n");
                    break;
                default:
                {
                    printf("Se ha cancelado la operacion\n\n");
                }
                }

                printf("Datos modificados correctamente\n");

                listarEmpleados(lista);

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
            printf("Ningun empleado ha sido modificado\n");
        }


    }
    todoOk = 0;


    return todoOk;
}

void bajaEmpleado(LinkedList* lista)
{

    int id;
    int indice;
    int tam = ll_len(lista);
    char confirmaBaja;
    int auxId;
   // int flag = 0;

    Employee* auxEmpleado = (Employee*) employee_new();

    system("cls");

    printf("----Baja Empleado----\n");

    listarEmpleados(lista);

    for (int i = 0; i < tam; i++)
       	 {
       		 auxEmpleado = ll_get(lista, i);
       		 employee_getId(auxEmpleado, &auxId);

       		 if (auxEmpleado->id == id)
             {
       			 auxEmpleado->id = id;
                  break;
             }
       	 }

    printf("Ingrese ID: ");
    scanf("%d", &id);

    indice = buscarEmpleadoId(id, lista);

    if(indice == -1)
    {
        printf("No existe un empleado con el ID: %d\n", id);
    }
    else
    {

		 printf("Se va a dar de baja al empleado con el id: %d \n", id);
		 printf("   ID   NOMBRE    HORAS TRABAJADAS  SUELDO\n");
		 listarEmpleado(lista, indice);

		 do
	       {
	        printf("Confirma la baja del empleado? s/n: ");
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



int empleadoComparaId(void* a, void* b)
{
    int todoOk = 0;
    Employee* primerId;
    Employee* segundoId;

    if(a != NULL && b!= NULL)
    {
    	primerId = (Employee*) a;
    	segundoId = (Employee*) b;
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

int empleadoComparaNombre(void* a, void* b)
{
	int todoOk = 0;
	char primerNombre[128];
	char segundoNombre[128];

	employee_getNombre(a, primerNombre);
	employee_getNombre(b, segundoNombre);


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

int empleadoComparaSueldo(void* a, void* b)
{
	int todoOk = 0;
	Employee* primerSueldo;
	Employee* segundoSueldo;

	if(a != NULL && b!= NULL)
	{
		primerSueldo = (Employee*) a;
		segundoSueldo = (Employee*) b;
	}

	if(primerSueldo->sueldo > segundoSueldo->sueldo)
	{
		todoOk = 1;
	}
	else if(primerSueldo->sueldo < segundoSueldo->sueldo)
	{
		todoOk = -1;
	}

	return todoOk;
}

int empleadoComparaHorasTrabajadas(void* a, void* b)
{
	int todoOk = 0;

	Employee* cantidadDeHoras1;
	Employee* cantidadDeHoras2;

	if(a != NULL && b!= NULL)
	{
		cantidadDeHoras1 = (Employee*) a;
		cantidadDeHoras2 = (Employee*) b;
	}

	if(cantidadDeHoras1->horasTrabajadas > cantidadDeHoras2->horasTrabajadas)
	{
		todoOk = 1;
	}
	else if(cantidadDeHoras1->horasTrabajadas < cantidadDeHoras2->horasTrabajadas)
	{
		todoOk = -1;
	}

	return todoOk;
}

int menuOrdenamientoEmpleados()
{
	int opcion;

	printf("Como desea ordenarlo?\n");
	printf("1 - Ordenar por ID\n");
	printf("2 - Ordenar por nombre\n");
	printf("3 - Ordenar por sueldos\n");
	printf("4 - Ordenar por horas trabajadas\n");

	printf("Indique opcion: ");
	scanf("%d", &opcion);

	return opcion;

}








