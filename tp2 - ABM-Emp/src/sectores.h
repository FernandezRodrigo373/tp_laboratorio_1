#ifndef SECTORES_H_INCLUDED
#define SECTORES_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

#endif // SECTORES_H_INCLUDED


/** \brief load the sector description
 * \param string to upload the sector description
 * \param sector id to copy
 * \param sectores eSector[]
 * \param len int
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 *
 */
int loadSectorDescription(char descripcion[], int id, eSector sectores[], int len);


/** \brief show the sector list
 * \param sector list
 * \param len int
 * \return int Return (0) if Error [Invalid length or NULL pointer] - (1) if Ok
 */
void showSectors(eSector sectores[], int len);
