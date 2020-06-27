#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "autos.h"

int main()
{
    LinkedList* lista = ll_newLinkedList();
    LinkedList* listaFiltrada;
    LinkedList* backUpLista;

    char seguir = 's';
	char confirma;
	int opcion;
	int flagLista = 0;
	int flag = 0;
	int flagBackUp = 0;
	int eleccion = 0;

    if(lista == NULL)
    {
        printf("No se pudo conseguir memoria");
        exit(EXIT_FAILURE);
    }

    do
    {
        menu(&eleccion);
        switch(eleccion)
        {
            case 1:
               if(!controller_loadFromText("autos.csv" , lista))
        		  {
        			  printf("No se pudo completar la carga\n");
        		  }
        		  else
        		  {
        			  printf("El archivo se cargo con exito\n");
        			  flag = 1;
        		  }
                break;
            case 2:
                if(flag)
                {
                    controller_addAuto(lista);
                }
                else
                {
                    printf("Primero cargue los datos en la lista\n");
                }
                break;
            case 3:
                if(flag)
                {
                    controller_editAuto(lista);
                }
                else
                {
                    printf("Primero cargue los datos en la lista\n");
                }
                break;
            case 4:
                if(flag)
                {
                    controller_removeAuto(lista);
                }
                else
                {
                    printf("Primero cargue los datos en la lista\n");
                }
                break;
            case 5:
                if(flag)
                {
                    controller_sortAuto(lista);
                }
                else
                {
                    printf("Primero cargue los datos en la lista\n");
                }
                break;
            case 6:
                if(flag)
                {
                    controller_ListAuto(lista);
                }
                else
                {
                    printf("Primero cargue los datos en la lista\n");
                }
                break;
            case 7:
                if( flag )
                {
                    backUpLista = controller_backUp(lista);
                    controller_saveAsText("autos BackUp.csv", backUpLista);
                    printf("El backup se ha realizado con exito\n");
                    flagBackUp = 1;
                }
                else
                {
                    printf("No se puede realizar back up de una lista vacia\n");
                }
                break;
            case 8:
                if( flag )
                {
                    if(controller_compareLinkedList( lista, backUpLista ) && flagBackUp)
                    {
                        printf("Los elementos de la lista ya estan incluidos en el backup previamente realizado\n");
                    }
                    else
                    {
                        printf("No se encuentran todos los elementos del backup en la lista\n");
                    }
                }
                else
                {
                    printf("Primero cargue los datos en la lista\n");
                }
                break;
            case 9:
                if(flag)
                {
                    flagLista = 1;
                    listaFiltrada = ll_filter(lista, controller_NewListAnio );

                    listarAutos(listaFiltrada);

                    if(!controller_saveAsText("autosFiltrados.csv", listaFiltrada))
                    {
                        printf("Sublista realizada con exito\n");
                    }
                    else
                    {
                        printf("No se pudo realizar\n");
                    }
                }
                else
                {
                    printf("Primero cargue los datos en la lista\n");
                }
                break;
            case 10:
                if(flagLista)
                {
                    printf("Eliminacion de listas\n");

                    controller_clearLinkedList(listaFiltrada);
                    controller_saveAsText("autosFiltrados.csv", listaFiltrada);
                    printf("Lista vaciada con exito\n");
                    flag = 0;
                }
                else
                {
                    printf("Aun no se generaron nuevas listas\n");
                }
                break;
            case 11:
                if(flagLista)
                {
                    opcion = menuEliminacionListas();

                    if(opcion == 's')
                    {
                        if((ll_isEmpty(listaFiltrada)) != -1)
                        {
                            ll_deleteLinkedList(listaFiltrada);
                            printf("Se ha eliminado la lista\n ");
                        }
                        else
                        {
                            printf("La lista aun tiene elementos\n");
                        }
                    }
                    else if(opcion == 'n')
                    {
                        printf("Se cancelo la operacion\n");
                    }
                    else
                    {
                        printf("Opcion no valida\n");
                    }
                }
                break;
            case 12:
                controller_saveAsText("autos.csv", lista);
                break;
            case 13:
               printf("Confirma salida? s/n : ");
               fflush(stdin);
               scanf("%c", &confirma);
               if(confirma == 's')
               {
                   seguir = 'n';
               }
               else if(confirma == 'n')
               {
                   seguir = 's';
               }
               else
               {
                   printf("Opcion no valida\n");
               }
               break;
           default:
        	   printf("Error. Opcion no valida, Reingrese opcion 1-10\n");
           }
           system("pause");
       }
       while(seguir == 's');

    return 0;
}
