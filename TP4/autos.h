#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED


typedef struct
{
    int id;
    char marca[128];
    int anio;
    char color[50];
    float precio;

}eAuto;


/** \brief reserva un espacio en memoria para un auto nuevo
 *
 * \return devuelve un puntero de auto al espacio de memoria creado
 *
 */
eAuto* auto_new();

/** \brief recibe los datos por una cadena, crea un auto y llama a funciones para cargar los datos al auto
 *
 * \param idStr char* id del auto
 * \param nombreStr char* nombre del auto
 * \param sueldo char*sueldo del auto
 * \param horasTrabajadasStr char* horas trabajadas del auto
 * \return devuelve puntero al auto creado con lo datos del auto cargados al archivo
 *
 */
eAuto* auto_newParametros(char* idStr,char* marcaStr, char* anio, char* color, char* precio);

/** \brief elimina un auto de memoria
 *
 * \return sin retorno
 *
 */
void auto_delete();

/** \brief carga el Id al auto
 *
 * \param this puntero al auto
 * \param id id del auto
 * \return sin retorno
 *
 */
int auto_setId(eAuto* this,int id);

/** \brief Carga el Id de un auto en una variable
 *
 * \param this auto al que se le carga el dato
 * \param id puntero a la variable
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int auto_getId(eAuto* this,int* id);


/** \brief carga el nombre en el auto
 *
 * \param this puntero al auto
 * \param nombre nombre del auto
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int auto_setMarca(eAuto* this,char* marca);

/** \brief Carga el marca de un auto en una variable
 *
 * \param this auto al que se le carga el dato
 * \param marca puntero a la variable
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int auto_getMarca(eAuto* this,char* marca);

/** \brief carga la cantidad de horas en el auto
 *
 * \param this puntero al auto
 * \param horasTrabajadas cantidad de horas que trabajo el auto
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int auto_setAnio(eAuto* this,int anio);

/** \brief Carga la cantidad de horas de un auto en una variable
 *
 * \param this auto al que se le carga el dato
 * \param anio puntero a la variable
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int auto_getAnio(eAuto* this,int* anio);

/** \brief carga la cantidad de horas en el auto
 *
 * \param this puntero al auto
 * \param sueldo cantidad del sueldo del auto
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int auto_setPrecio(eAuto* this,int precio);

/** \brief Carga el precio de un auto en una variable
 *
 * \param this auto al que se le carga el dato
 * \param precio puntero a la variable
 * \return retorna 1 si pudo cargar, 0 si fallo
 *
 */
int auto_getPrecio(eAuto* this,int* precio);

/** \brief menu de opciones
 *
 * \return opcion elegida por el usuario
 *
 */

 int auto_setColor(eAuto* this,char* color);

 int auto_getColor(eAuto* this,char* color);

void menu(int* opcion);

int listarAutos(LinkedList* lista);
int listarAuto(LinkedList* lista, int indice);

int menuEliminacionListas();
int menuOrdenamientoAutos();
int altaAuto(LinkedList* lista);
int autoComparaId(void* a, void* b);
int autoComparaMarca(void* a, void* b);
int autoComparaColor(void* a, void* b);
int autoComparaPrecio(void* a, void* b);
int autoComparaAnio(void* a, void* b);

int modificarAuto(LinkedList* lista);
void bajaAuto(LinkedList* lista);




#endif // auto_H_INCLUDED
