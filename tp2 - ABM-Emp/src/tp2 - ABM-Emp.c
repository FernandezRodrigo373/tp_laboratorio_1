#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "sectores.h"
#include "reports.h"

#define LEN 1000
#define LENSEC 5

int main(void)
{

    setbuf(stdout, NULL);

    char goOn = 's';
    char confirm;
    int nextId = 999;
    int index;

    char auxName[51];
    char auxLastname[51];
    float auxSalary;
    int auxSector;
    int red;
    int green;
    int flag1 = 0;


    Employee list[LEN];
    eSector sectores[LENSEC] = { {1, "Sistemas"},{2, "Ventas"},{3, "RRHH"}, {4, "Compras"}, {5, "Contables"} };

    initEmployees(list, LEN);


    do
    {
        switch (menu())
        {
        case 1:
            printf("\n---Alta empleado---\n\n");
            green = collectInfo(list, LEN, &nextId, auxName, auxLastname, &auxSalary, &auxSector, &index, sectores, LENSEC);
            red = addEmployee(list, LEN, nextId, auxName, auxLastname, auxSalary, index,  auxSector);

            if(red == 0 && green == 0)
            {
                nextId++;
            }
            flag1 = 1;
            break;
        case 2:
            if(flag1)
            {
                printf("\n---Modificar empleados---\n\n");
                modifyEmployee(list, LEN, sectores, LENSEC);
            }
            else
            {
                printf("Error, Primero dar de alta a un empleado\n\n");
            }
            break;
        case 3:
            if(flag1)
            {
                printf("\n---Baja empleado---\n\n");
                removeEmployee(list, LEN, nextId, sectores, LENSEC);
            }
            else
            {
                printf("\nError, Primero dar de alta a un empleado\n\n");
            }
            break;
        case 4:
            if(flag1)
            {
                printf("\n---Informar---\n\n");
                reports(list, LEN, sectores, LENSEC);
            }
            else
            {
                printf("Error, Primero dar de alta a un empleado\n\n");
            }
            break;
        case 5:
            printf("Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirm);
            if(confirm == 's')
            {
                goOn = 'n';
            }
            break;
        }
        system("pause");
    }
    while(goOn == 's');

    return EXIT_SUCCESS;
}
