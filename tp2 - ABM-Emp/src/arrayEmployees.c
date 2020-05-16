#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"


int menu()
{
    int option;

    system("cls");
    printf("----------Gestion de Empleados---------\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Modificar Empleado\n");
    printf("3- Baja Empleado\n");;
    printf("4- Informes Empleados\n");
    printf("5- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

int initEmployees(Employee list[], int len)
{
    if(list != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }

        return 0;
    }
    else
    {
        return -1;
    }
}

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary, int index, int sector)
{
    int allOK = 0;

    for(int i = 0; i < len; i++)
    {
        normalizeStr(name);
        normalizeStr(lastName);
        list[index].id = id;
        strcpy(list[index].name, name);
        strcpy(list[index].lastName, lastName);
        list[index].salary = salary;
        list[index].sector = sector;
        list[index].isEmpty = 0;

    }

    allOK = 1;

    return allOK;
}

int collectInfo(Employee list[], int len, int* nextId, char auxName[], char auxLastname[], float *auxSalary, int* auxSector, int *index, eSector sectores[], int lensec)
{
    int id = *nextId;
    int newId = id + 1;
    int allOk = -1;

    *index = lookForEmpty(list, len);

    if(index < 0)
    {
        printf("Sistema completo\n");
    }
    else
    {
        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(auxName);
        printf("Ingrese Apellido: ");
        fflush(stdin);
        gets(auxLastname);

        printf("Ingrese sueldo: ");
        scanf("%f", auxSalary);

        showSectors(sectores, lensec);
        printf("\nIngrese ID de sector: ");
        scanf("%d", auxSector);

        *nextId = newId;
        allOk = 0;
    }

    return allOk;
}

int lookForEmpty(Employee list[], int len)
{
    int index = -1;

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}

void showEmployee(Employee x, eSector sectores [], int lensec)
{
    char sectorName[20];

    loadSectorDescription(sectorName, x.sector, sectores, lensec);

    printf("%5d | %5s | %5s | %5.2f | %5s\n\n", x.id, x.name,x.lastName, x.salary, sectorName);
}

void printEmployees(Employee vec[], int len, eSector sectores [], int lensec)
{

    int flag = 0;

    system("cls");
    printf("-------------Lista de Empleados-------------\n\n");

    for(int i = 0; i < len; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            showEmployee(vec[i], sectores, lensec);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("**--No hay empleados para mostrar--**\n");
    }
}


int removeEmployee(Employee list[], int len, int id, eSector sectores [], int lensec)
{
    int index;
    char ConfirmRemove;

    system("cls");

    printf("----Baja Empleado----\n");

    printEmployees(list, len, sectores, lensec);

    printf("Ingrese ID: ");
    scanf("%d", &id);

    index = findEmployeeById( list, lensec, id);

    if(index == -1)
    {
        printf("No existe un empleado con el ID: %d\n", id);
    }
    else
    {
        printf("\nEl ID %d pertenece al empleado:\n", id);
        printf(" ID    Nombre   Apellido  Salario   Sector\n\n");

        showEmployee(list[index], sectores, lensec);

        printf("Confirma baja? s/n: ");
        fflush(stdin);
        scanf("%c", &ConfirmRemove);

        if(ConfirmRemove == 's')
        {
            list[index].isEmpty = 1;

            printf("Operacion relaizada con exito\n");
        }
        else if(ConfirmRemove == 'n')
        {
            printf("Operacion cancelada\n");
        }
    }

    return -1;
}


int findEmployeeById(Employee list[], int len, int id)
{
    int index = -1;

    for(int i = 0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}

int modifyEmployee(Employee vec[], int len, eSector sectores[], int lensec)
{
    int index;
    char confirm;
    char goOn = 's';
    int auxId;
    float newSalary;
    char newName[51];
    char newLastName[51];
    int newSector;
    int allOk = -1;
    int option;


    system("cls");
    printf("***** Modificar empleado *****\n\n");

    printEmployees(vec, len, sectores, lensec);

    printf("Ingrese ID: ");
    scanf("%d", &auxId);

    index = findEmployeeById( vec, lensec, auxId);

    if(index == -1)
    {
        printf("No existe un empleado con el ID: %d\n\n", auxId);
    }

    else
    {
        printEmployees(vec, len, sectores, lensec);

        printf("El ID %d pertenece al empleado:\n", auxId);
        printf(" ID    Nombre   Apellido  Salario   Sector\n\n");

        showEmployee(vec[index], sectores, lensec);
        printf("Modifica empleado?: ");
        fflush(stdin);
        scanf("%c", &confirm);


        if(confirm == 's')
        {
            do
            {
                system("cls");

                printf("----------Gestion de Empleados---------\n\n");
                printf("1- Modificar nombre\n");
                printf("2- Modificar apellido\n");
                printf("3- Modificar salario\n");;
                printf("4- Modificar sector\n");
                printf("Ingrese opcion: ");
                fflush(stdin);
                scanf("%d", &option);


                switch(option)
                {
                case 1:
                    printf("Modificar nombre\n");
                    normalizeStr(newName);
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(newName);

                    strcpy(vec[index].name, newName);

                    printf("Se ha actualizado el nombre del empleado con exito\n\n");
                    break;
                case 2:
                    printf("Modificar apellido\n");
                    normalizeStr(newLastName);
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(newLastName);

                    strcpy(vec[index].lastName, newLastName);

                    printf("Se ha actualizado el apellido del empleado con exito\n\n");
                    break;
                case 3:
                    printf("Modificar Sueldo\n");

                    printf("Ingrese nuevo sueldo: ");
                    scanf("%f", &newSalary);

                    vec[index].salary = newSalary;
                    printf("Se ha actualizado el sueldo con exito\n\n");
                    break;
                case 4:
                    printf("Modificar sector\n");

                    printf("Ingrese nuevo sector: ");
                    scanf("%d", &newSector);

                    vec[index].sector = newSector;
                    printf("Se ha actualizado el sector con exito\n\n");
                    break;
                default:
                {
                    printf("Se ha cancelado la operacion\n\n");
                }
                }

                printf("Datos modificados correctamente\n");

                printEmployees(vec, len, sectores, lensec);

                printf("\nDesea continuar con las modificaciones? s/n: ");
                fflush(stdin);
                scanf("%c", &confirm);

                if(confirm == 's')
                {
                    goOn = 's';
                }
                else if(confirm == 'n')
                {
                    goOn = 'n';
                }

            }
            while(goOn == 's');

        }
        else if(confirm == 'n')
        {
            printf("No se han modificado ningun empleado\n");
        }


    }
    allOk = 0;


    return allOk;
}


int sortEmployees(Employee vec[], int len, int order)
{
    int allOk = -1;

    Employee auxEmployee;

    for(int i = 0; i < len - 1; i++)
    {
        for(int j = i + 1; j < len; j++)
        {
            allOk = 0;

            if(vec[i].isEmpty == 0 && vec[j].isEmpty == 0)
            {

                if(order == 1)
                {
                    if(vec[i].sector > vec[j].sector || (vec[i].sector == vec[j].sector && (strcmp( vec[i].lastName, vec[j].lastName )) < 0))
                    {
                        auxEmployee = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxEmployee;
                    }
                }
                else if(order == 0)
                {
                    if(vec[i].sector < vec[j].sector || (vec[i].sector == vec[j].sector && (strcmp( vec[i].lastName, vec[j].lastName )) < 0))
                    {
                        auxEmployee = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxEmployee;
                    }
                }
            }
        }
    }

    return allOk;
}

int strLwr(char string[])
{
    int allOk = -1;
    int i = 0;

    while(string[i] != '\0')
    {
        string[i] = tolower(string[i]);
        i++;
    }
    allOk = 0;

    return allOk;
}

int normalizeStr(char string[])
{
    int allOk = -1;
    int i = 0;

    strLwr(string);
    string[0] = toupper(string[0]);

    while(string[i] != '\0')
    {
        if(string[i] == ' ')
        {
            string[i + 1] = toupper(string[i + 1]);
            allOk = 0;
        }
        i++;
    }

    return allOk;
}


