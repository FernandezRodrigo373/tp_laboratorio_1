#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED


typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


/** \brief reserva un espacio en memoria para un empleado nuevo
 *
 * \return devuelve un puntero de empleado al espacio de memoria creado
 *
 */
Employee* employee_new();

/** \brief recibe los datos por una cadena, crea un empleado y llama a funciones para cargar los datos al empleado
 *
 * \param idStr char* id del empleado
 * \param nombreStr char* nombre del empleado
 * \param sueldo char*sueldo del empleado
 * \param horasTrabajadasStr char* horas trabajadas del empleado
 * \return devuelve puntero al empleado creado con lo datos del empleado cargados al archivo
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* sueldo, char* horasTrabajadasStr);

/** \brief elimina un empleado de memoria
 *
 * \return sin retorno
 *
 */
void employee_delete();

/** \brief carga el Id al empleado
 *
 * \param this puntero al empleado
 * \param id id del empleado
 * \return sin retorno
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Carga el Id de un empleado en una variable
 *
 * \param this empleado al que se le carga el dato
 * \param id puntero a la variable
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int employee_getId(Employee* this,int* id);


/** \brief carga el nombre en el empleado
 *
 * \param this puntero al empleado
 * \param nombre nombre del empleado
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Carga el nombre de un empleado en una variable
 *
 * \param this empleado al que se le carga el dato
 * \param nombre puntero a la variable
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief carga la cantidad de horas en el empleado
 *
 * \param this puntero al empleado
 * \param horasTrabajadas cantidad de horas que trabajo el empleado
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Carga la cantidad de horas de un empleado en una variable
 *
 * \param this empleado al que se le carga el dato
 * \param horasTrabajadas puntero a la variable
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief carga la cantidad de horas en el empleado
 *
 * \param this puntero al empleado
 * \param sueldo cantidad del sueldo del empleado
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Carga el sueldo de un empleado en una variable
 *
 * \param this empleado al que se le carga el dato
 * \param sueldo puntero a la variable
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief menu de opciones
 *
 * \return opcion elegida por el usuario
 *
 */
int menu();


/** \brief Da de alta un nuevo empleado a la lista
 *
 * \param lista lista en la que se cargara el nuevo empleado
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int altaEmpleado(LinkedList* lista);

/** \brief Muestra un empleado de la lista
 *
 * \param lista lista en la que se encuentra el empleado
 * \param indice indice del elemento en la lista
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int listarEmpleado(LinkedList* lista, int indice);

/** \brief Muestra la lista de empleado cargados en el sistema
 *
 * \param lista lista que se va a mostrar
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int listarEmpleados(LinkedList* lista);

/** \brief Busca si un ID existe en la lista
 *
  * \param id id a buscar
 * \param lista Lista a revisar
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int buscarEmpleadoId(int id, LinkedList* lista);


/** \brief Pide id del empleado para modificar el empleado
 *
 * \param lista lista donde se encuentra el empleado
 * \return indice del Id del empleado
 *
 */
int modificarEmpleado(LinkedList* lista);

/** \brief Borra un empelado de la lista recibiendo el ID del mismo
 *
 * \param lista lista en la que se encuentra el empleado
 * \return retorna 0 si pudo cargar, -1 si fallo
 *
 */
void bajaEmpleado(LinkedList* lista);

/** \brief Compara el ID de los empleados
 *
 * \param lista lista donde estan los empleados
 * \return sin retorno
 *
 */
int empleadoComparaId(void* a, void* b);

/** \brief Compara el nombre de los empleados
 *
 * \param lista lista donde estan los empleados
 * \return return retorna 1, -1 o 0 dependiendo de como se ordene
 *
 */
int empleadoComparaNombre(void* a, void* b);

/** \brief Compara el sueldo de los empleados
 *
 * \param lista lista donde estan los empleados
 * \return return retorna 1, -1 o 0 dependiendo de como se ordene
 *
 */
int empleadoComparaSueldo(void* a, void* b);

/** \brief Compara la cantidad de horas trabajadas de los empleados
 *
 * \param lista lista donde estan los empleados
 * \return return retorna 1, -1 o 0 dependiendo de como se ordene
 *
 */
int empleadoComparaHorasTrabajadas(void* a, void* b);

/** \brief menu de opciones para ordenar los empleados
 *
 * \return return retorna 1, -1 o 0 dependiendo de como se ordene
 *
 */
int menuOrdenamientoEmpleados();





#endif // employee_H_INCLUDED
