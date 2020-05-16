#include "reports.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int reportsMenu()
{
    int option;

    system("cls");
    printf("----------Informe de Empleados---------\n\n");
    printf("1- Listar empleados alfabeticamente por Apellido y Sector\n");
    printf("2- Informar total y promedio de los salarios \n");
    printf("3- Salir \n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}

void reports(Employee vec[], int len, eSector sectores [], int lensec)
{
    char goOn = 's';
    char confirm;
    int order;

    do
    {
        switch (reportsMenu())
        {
        case 1:
            printf("-----Ordenar empleados-----\n");

            printf("0 - Descendente\n");
            printf("1 - Ascendente\n");
            printf("Como desea ordenarlo? : ");
            fflush(stdin);
            scanf("%d", &order);

            sortEmployees(vec, len, order);

            printEmployees(vec, len, sectores, lensec);
            break;
        case 2:
            reportSalary(vec, len);
            break;
        case 3:
            printf("Confirma salida? s/n: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                goOn = 'n';
            }
            else if(confirm == 'n')
            {
                goOn = 's';
            }
            else
            {
                printf("Opcion no valida\n");
            }
            break;
        default:
            printf("Opcion no valida\n");
            break;
        }
        system("pause");
    }
    while(goOn == 's');
}

void reportSalary(Employee vec[], int len)
{
    float salaryAcummulator = 0;
    int salaryCount = 0;
    float promedy;
    int employeeHigherSalary = 0;


    for( int i = 0; i < len; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            salaryAcummulator += vec[i].salary;
            salaryCount++;
        }
    }

    promedy = (float) salaryAcummulator/salaryCount;
    printf("El salario promedio de los empleados es %.2f\n\n", promedy);


    for( int i = 0; i < len; i++)
    {
        if(vec[i].isEmpty == 0 && vec[i].salary > promedy)
        {
            employeeHigherSalary++;
        }
    }


    printf("La cantidad de empleados que superan el sueldo promedio es: %d\n", employeeHigherSalary);

}
