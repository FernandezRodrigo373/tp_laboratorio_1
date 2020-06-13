#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);

	char seguir = 's';
	char confirma;
	int flagBin = 0;
	int flagText = 0;
	//int flagAlta = 0;

    //Employee* auxEmployee;

    LinkedList* lista = ll_newLinkedList();

    do
       {

           switch (menu())
           {
           case 1:
        	   if(flagText == 0 && flagBin != 1)
        	   {
        		  if(!controller_loadFromText("data.csv" , lista))
        		  {
        			  printf("No se pudo completar la carga\n");
        		  }
        		  else
        		  {
        			  flagText = 1;
        			  printf("El archivo se cargo con exito\n");
        		  }
        	   }
        	   else if(flagBin)
        	   {
        		   printf("El archivo fue cargado como binario previamente\n");
        	   }
               break;
           case 2:

        	   if(flagText != 1  && flagBin ==  0)
        	   {
        		   if (!controller_loadFromBinary("data.bin",lista))
				   {
					   printf("El archivo se cargo con exito\n");
				   }
        	   }
        	   else if(flagText)
        	   {
        		   printf("El archivo fue cargado como texto previamente\n");
        	   }
               break;
           case 3:
        	   if(flagText || flagBin)
        	   {
				   printf("Alta de empleado\n");

				   if(!controller_addEmployee(lista))
				   {
					   printf("Empleado dado de alta con exito\n");

				   }
        	   }
        	   else
        	   {
        		   printf("Primero debe cargar un archivo\n");
        	   }
               break;
           case 4:
        	   if(flagText || flagBin)
			   {
				   printf("Modificar datos de empleado\n");

				   controller_editEmployee(lista);
			   }
        	   else
			   {
				   printf("Primero debe cargar un archivo\n");
			   }
               break;
           case 5:
        	   if(flagText || flagBin)
			   {
        		   controller_removeEmployee(lista);
			   }
        	   else
			   {
				   printf("Primero debe cargar un archivo\n");
			   }
               break;
           case 6:
        	   if(flagText || flagBin)
			   {
				   controller_ListEmployee(lista);
			   }
        	   else
			   {
				   printf("Primero debe cargar un archivo\n");
			   }
               break;
           case 7:
        	   if(flagText || flagBin)
			   {
        		   controller_sortEmployee(lista);
			   }
			   else
			   {
				   printf("Primero debe cargar un archivo\n");
			   }
               break;
           case 8:
        	   if(flagText || flagBin)
			   {
        		   controller_saveAsText("data.csv", lista);
			   }
			   else
			   {
				   printf("Primero debe cargar un archivo\n");
			   }
               break;
           case 9:
        	   if(flagText || flagBin)
			   {
        		   controller_saveAsBinary("data.bin", lista);
			   }
			   else
			   {
				   printf("Primero debe cargar un archivo\n");
			   }
                break;
           case 10:
               printf("Confirma salida?: ");
               fflush(stdin);
               scanf("%c", &confirma);
               if(confirma == 's')
               {
                   seguir = 'n';
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


