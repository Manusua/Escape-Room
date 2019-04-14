/**
 * @brief En este fichero implementamos las funciones de space
 * @file space.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0
 * @date 20/10/2018
 */
#ifndef SPACE_H
#define SPACE_H


#include "types.h"
#include "set.h"

#define MAX_SPACES 10000 /*!< maximo de espacios */
#define FIRST_SPACE 1 /*!< primer espacio */
#define TAM_DIBUJO 21 /*!< maximo de dibujo */
#define TAM_DIBUJO_LINEA TAM_DIBUJO/3 /*!< maximo del dibujo de cada linea */

typedef struct _Space Space; /*!< Estructura de espacio */

/**
 * @brief crea un espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param id (id del nuevo espacio)
 * @return Space* (El espacio que crea)
 */
Space* space_create(Id id);

/**
 * @brief destruye y libera la memoria de un espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (el espacio a destruir)
 * @return STATUS (Ok si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_destroy(Space* space);

/**
 * @brief devuelve el Id del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return Id (El Id del espacio)
 */
Id space_get_id(Space* space);

/**
 * @brief cambia el nombre del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param name (nuevo nombre)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS space_set_name(Space* space, char* name);

/**
 * @brief devuelve el nombre del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return const char(El nombre del espacio)
 */
const char* space_get_name(Space* space);

/**
 * @brief cambia el Id del norte del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para el norte)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_north(Space* space, Id id);

/**
 * @brief devuelve el Id del norte
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id del norte)
 */
Id space_get_north(Space* space);

/**
 * @brief cambia el Id del sur del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para el sur)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_south(Space* space, Id id);

/**
 * @brief devuelve el Id del sur
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id del sur)
 */
Id space_get_south(Space* space);

/**
 * @brief cambia el Id del este del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para el este)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_east(Space* space, Id id);

/**
 * @brief devuelve el Id del este
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id del este)
 */
Id space_get_east(Space* space);

/**
 * @brief cambia el Id del oeste del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para el oeste)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_west(Space* space, Id id);

/**
 * @brief devuelve el Id del oeste
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id del oeste)
 */
Id space_get_west(Space* space);


/**
 * @brief comprueba si hay un objeto en el espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (Id del objeto a comprobar)
 * @return BOOL (TRUE si se el objeto esta en el espacio o FALSE de lo contrario)
 */
BOOL space_is_object_in(Space* space, Id id);


/**
 * @brief imprime el espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return STATUS (Ok si se imprime bien o ERROR de lo contrario)
 */
STATUS space_print(Space* space);

/**
 * @brief coge un objeto del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (id del objeto a coger)
 * @return STATUS (OK si se coge bien o ERROR de lo contrario)
 */
STATUS space_take_object(Space *space, Id id);

/**
 * @brief suelta un objeto del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (id del objeto a soltar)
 * @return STATUS (OK si se suelta bien o ERROR de lo contrario)
 */
STATUS space_leave_object(Space *space, Id id);

/**
 * @brief devuelve el contenido del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return char (La informacion del espacio)
 */
char* space_get_gdesc(Space *);

/**
 * @brief cambia el contenido del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param  gdesc (La informacion del espacio)
 * @return STATUS (OK si se modifica bien o ERROR de lo contrario)
 */

STATUS space_set_gdesc(Space*, char *);

/**
 * @brief devuelve la descripcion del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return char (La descripcion del espacio)
 */
char *space_get_description(Space *space);

/**
 * @brief cambia la descripcion del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param description (La descripcion del espacio)
 * @return STATUS (OK si se modifica bien o ERROR de lo contrario)
 */
STATUS space_set_description(Space *space, char *description);

/**
 * @brief cambia la descripcion detallada del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param space (espacio a usar)
 * @param description (La informacion del espacio)
 * @return STATUS (OK si se modifica bien o ERROR de lo contrario)
 */
STATUS space_set_detailed_description(Space* space, char* description);
/**
 * @brief devuelve la descripcion detallada del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param space (espacio a usar)
 * @return char (La descripcion del espacio)
 */
char *space_get_detailed_description(Space *space);

/**
 * @brief devuelve el Id arriba
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id arriba)
 */
Id space_get_up(Space* space);
/**
 * @brief devuelve el Id abajo
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id abajo)
 */
Id space_get_down(Space* space);
/**
 * @brief devuelve el estado de iluminación
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @return True si está iluminado, False en caso contrario
 */
BOOL space_get_light(Space* space);

/**
 * @brief cambia el Id de arriba del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para arriba)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_up(Space* space, Id id);

/**
 * @brief cambia el Id de abajo del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para arriba)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_down(Space* space, Id id);

/**
 * @brief cambia el estado de iluminación de un espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @param status
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_light(Space* space, BOOL status);

#endif
