#include "sectores.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



void showSectors(eSector sectores[], int len)
{
    printf("----------Sectores--------\n");
    printf("--------ID Descripcion--------\n\n");

    for(int i = 0; i < len; i++)
    {
        printf("%d   %10s   \n", sectores[i].id, sectores[i].descripcion);
    }
}

int loadSectorDescription(char descripcion[], int id, eSector sectores[], int len)
{
    int allOK = 0;

    for(int i = 0; i < len; i++)
    {
        if(sectores[i].id == id)
        {
            strcpy(descripcion, sectores[i].descripcion);
            allOK = 1;
        }
    }

    return allOK;
}

