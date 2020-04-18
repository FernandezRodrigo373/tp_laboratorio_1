#include <stdio.h>
#include <stdlib.h>

#include "rodrigof.h"

int main()
{
    int a;
    int b;
    int flagOperando1 = 0;
    int flagOperando2 = 0;
    int resultadoSuma;
    int resultadoResta;
    float resultadoDivision;
    int resultadoMultiplicacion;
    double resultadoFact1;
    double resultadoFact2;
    int realizarOperaciones = 0;


    char seguir = 's';

    do
    {
        switch( mostrarMenu(a, b, flagOperando1,flagOperando2))
        {
        case 1:
            a = obtenerOperandos(a);
            flagOperando1 = 1;
            system("pause");
            break;
        case 2:
            b = obtenerOperandos(b);
            flagOperando2 = 1;
            system("pause");
            break;
        case 3:
            if(flagOperando1 && flagOperando2)
            {
                realizarOperaciones = 1;
                printf("Realizando operaciones...\n\n");
                resultadoSuma = sumar(a, b);
                resultadoResta = restar(a, b);
                resultadoDivision = division(a, b);
                resultadoMultiplicacion = multiplicar(a, b);
                resultadoFact1 = factorialPrimero(a);
                resultadoFact2 = factorialSegundo(b);
            }
            else
            {
                printf("Debe ingresar primero los operandos antes de realizar esta accion\n");
            }
            system("pause");
            break;
        case 4:
            if(realizarOperaciones)
            {
                printf("Los resultados de las operaciones son: ");
                printf("El resultado de la suma de %d + %d es: %d\n",a,b,resultadoSuma);
                printf("El resultado de la resta de %d - %d es: %d\n",a,b,resultadoResta);
                printf("El resultado de la division de %d / %d es: %.2f\n",a,b,resultadoDivision);
                printf("El resultado de la multiplicacion de %d * %d es: %d\n",a,b,resultadoMultiplicacion);
                printf("El factorial de %d es: %.2lf y el factorial de %d es: %.2lf\n",a, resultadoFact1, b, resultadoFact2);
            }
            else
            {
                printf("Error.Primero debe ingresar la opcion 3\n");
            }
            system("pause");
            break;
        case 5:
            printf("¿Desea continuar? s/n: ");
            fflush(stdin);
            scanf("%c", &seguir);
            system("pause");
            break;
        default:
            printf("Opcion no valida\n");
            system("pause");
        }
    }
    while(seguir == 's');

    return 0;
}












