#include <stdio.h>
#include <stdlib.h>
#include "rodrigof.h"

/** \brief Obtiene los operandos indicados
 *
 * \param Operando 1
 * \param Operando 2
 * \return Devuelve operando ingresado
 *
 */

int obtenerOperandos(int a)
{
    int operandoIngresado;

    printf("Ingrese un operando: ");
    scanf("%d", &operandoIngresado);

    return operandoIngresado;
}

/** \brief Muestra el menu de opciones con 5 opciones
 *
 * \param Recibe operando 1
 * \param Recibe operando 2
 * \param Recibe la bandera del primer operando
 * \param Recibe la bandera del segundo operando
 * \return Retorna la opcion ingresada por el usuario
 *
 */


int mostrarMenu(int a, int b, int flag1, int flag2)
{
    int opcion;

    system("cls");
    printf("-------------------TRABAJO PRACTICO: Calculadora-------------------\n\n");
    if(flag1)
    {
        printf("1- Ingresar el primer operando (A = %d)\n", a);
    }
    else
    {
        printf("1- Ingresar el primer operando (A = x)\n");
    }

    if(flag2)
    {
        printf("2- Ingresar el segundo operando (B = %d)\n", b);
    }
    else
    {
        printf("2- Ingresar el segundo operando (B = y)\n");
    }

    printf("3- Realizar las operaciones:\n\n");
    printf("a) Calcular la suma (A+B)\n");
    printf("b) Calcular la resta (A-B)\n");
    printf("c) Calcular la division (A/B)\n");
    printf("d) Calcular la multiplicacion (A*B)\n");
    printf("e) Calcular el factorial (A! y B!)\n\n");
    printf("4-Mostrar resultados\n");
    printf("5-Salir de la calculadora\n\n\n");
    printf("Indique opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

/** \brief Suma dos numeros
 *
 * \param Recibe operando 1
 * \param Recibe operando 2
 * \return Resultado de la suma
 *
 */


int sumar(int a,int b)
{
    int result;

    result = a + b;

    return result;
}

/** \brief Resta dos numeros
 *
 * \param Recibe operando 1
 * \param Recibe operando 2
 * \return Resultado de la resta
 *
 */
int restar(int a, int b)
{
    int result;

    result = a - b;

    return result;
}


/** \brief Divide dos numeros
 *
 * \param Recibe operando 1
 * \param Recibe operando 2
 * \return Resultado de la division con un flotante
 *
 */

float division(int a, int b)
{
    float result;

    result = (float) a / b;

    return result;
}

/** \brief Multiplica dos numeros
 *
 * \param Recibe operando 1
 * \param Recibe operando 2
 * \return Resultado de la multiplicacion
 *
 */

int multiplicar(int a, int b)
{
    int result;

    result = a * b;

    return result;

}

/** \brief Calcula el factorial de un numero
 *
 * \param Recibe operando 1
 * \return Resultado del factorial del numero ingresado
 *
 */

long double factorialPrimero(int a)
{
    double fact = 1;

    for(int i = 1; i <= a; i++)
    {
        fact = fact * i;
    }

    return fact;
}

/** \brief Calcula el factorial de un numero
 *
 * \param Recibe operando 2
 * \return Resultado del factorial del numero ingresado
 *
 */
long double factorialSegundo(int b)
{
    double fact = 1;

    for(int i = 1; i <= b; i++)
    {
        fact = fact * i;
    }

    return fact;
}

