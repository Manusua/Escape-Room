/**
 * @brief En este fichero implementamos las funciones de link
 * @file link.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 15/11/2018
 */


#ifndef LINK_H
#define LINK_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "types.h"

typedef struct _Link Link; /*!< Estructura del link */

/**
* @brief crea un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @return Link (El link que crea)
*/
Link *link_create();

/**
* @brief destruye y libera la memoria de un link
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a destruir)
* @return void (No devuelve nada)
*/
void link_destroy(Link *link);

/**
* @brief devuelve el Id de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a usar)
* @return Id (Id del link)
*/
Id link_get_id(Link *link);

/**
* @brief devuelve el Id de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a usar)
* @return char (nombre del link)
*/
char * link_get_name(Link *link);

/**
* @brief el Id de la conexion 1 del link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a usar)
* @return  (Id de la conexion)
*/
Id link_get_conection_1(Link *link);

/**
* @brief el Id de la conexion 2 del link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a usar)
* @return Id (Id de la conexion)
*/
Id link_get_conection_2(Link *link);

/**
* @brief comprueba si la conexion esta abierta o cerrada 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a usar)
* @return BOOL (TRUE o FALSE dependiendo de si la conexion esta abierta o cerrada)
*/
BOOL link_get_status(Link *link);

/**
* @brief modifica el Id de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a modificar)
* @param id (Nuevo Id)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS link_set_id(Link *link, Id id);

/**
* @brief modifica el nombre de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a modificar)
* @param name (Nuevo nombre)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS link_set_name(Link *link, char *name);

/**
* @brief modifica ela conexion de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a modificar)
* @param id1 (Nuevo id)
* @param id2 (Nuevo Id)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS link_set_conection(Link *link, Id id1, Id id2);

/**
* @brief modifica el estado de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a modificar)
* @param bool (Nuevo estado)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS link_set_status(Link *link, BOOL bool);

/**
* @brief imprime un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a modificar)
* @return int (-1 si no se ha realizado con exito)
*/
int link_print(Link *link);



#endif
