/**
 * @brief En este fichero implementamos las funciones de link
 * @file link.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 15/11/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include "link.h"

struct _Link {
    Id id;/*!< Id del link */
    char name[TAM]; /*!< Nombre */
    Id id_conexion[2]; /*!< Conexiones del likn */
    BOOL state; /*!< Estado: abierto o cerrado */
}; /*!< Estructura de link */


/**
* @brief crea un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @return Link (El link que crea)
*/
Link *link_create() {
    Link *link;
    link = malloc(sizeof (Link));
    if (!link) {
        return NULL;
    }
    link->id = NO_ID;
    link->id_conexion[0] = NO_ID;
    link->id_conexion[1] = NO_ID;
    link->state = FALSE;
    return link;
}


/**
* @brief destruye y libera la memoria de un link
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a destruir)
* @return void (No devuelve nada)
*/
void link_destroy(Link *link) {
    if (link) {
        free(link);
    }
}


/**
* @brief devuelve el Id de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a usar)
* @return Id (Id del link)
*/
Id link_get_id(Link *link) {
    if (!link) {
        return -1;
    }
    return link->id;
}


/**
* @brief devuelve el Id de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a usar)
* @return char (nombre del link)
*/
char * link_get_name(Link *link) {
    if (!link) {
        return NULL;
    }
    return link->name;
}


/**
* @brief el Id de la conexion 1 del link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a usar)
* @return Id (Id de la conexion)
*/
Id link_get_conection_1(Link *link) {
    if (!link) {
        return NO_ID;
    }

    return link->id_conexion[0];
}


/**
* @brief el Id de la conexion 2 del link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a usar)
* @return Id (Id de la conexion)
*/
Id link_get_conection_2(Link *link) {
    if (!link) {
        return NO_ID;
    }

    return link->id_conexion[1];
}


/**
* @brief comprueba si la conexion esta abierta o cerrada 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a usar)
* @return BOOL (TRUE o FALSE dependiendo de si la conexion esta abierta o cerrada)
*/
BOOL link_get_status(Link *link) {
    if (!link) {
        return FALSE;
    }
    return link->state;
}


/**
* @brief modifica el Id de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a modificar)
* @param id (Nuevo Id)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS link_set_id(Link * link, Id id) {
    if (!link || id == NO_ID) {
        return ERROR;
    }
    link->id = id;
    return OK;
}


/**
* @brief modifica el nombre de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a modificar)
* @param name (Nuevo nombre)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS link_set_name(Link *link, char *name) {
    if (!link || !name) {
        return ERROR;
    }
    strcpy(link->name, name);

    return OK;
}


/**
* @brief modifica ela conexion de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a modificar)
* @param id1 (Nuevo id1)
* @param id2 (Nuevo Id2)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS link_set_conection(Link* link, Id id1, Id id2) {
    if (!link) {
        return ERROR;
    }
    link->id_conexion[0] = id1;
    link->id_conexion[1] = id2;
    return OK;
}


/**
* @brief modifica el estado de un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a modificar)
* @param bool (Nuevo estado)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS link_set_status(Link *link, BOOL bool) {
    if (!link) {
        return ERROR;
    }
    link->state = bool;
    return OK;
}


/**
* @brief imprime un link 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param link (link a modificar)
* @return int (-1 si no se ha realizado con exito)
*/
int link_print(Link *link) {
    if (!link) {
        return -1;
    }
    return fprintf(stdout, "id %ld ,name :%s ,id_conexion %ld %ld, status %u (1 es true 0 es false) \n", link->id, link->name, link->id_conexion[0], link->id_conexion[1], link->state);

}
