/**
 * @brief En este fichero implementamos las funciones del objeto
 * @file object.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 20/10/2018
 */
#ifndef OBJECT_H
#define OBJECT_H

typedef struct _Object Object;/*!< Estructura de objeto */
#include "types.h"

/*funciones basicas de la creacion y liberar el objeto */

/**
* @brief crea un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @return Object (El objeto que crea)
*/
Object *object_create();

/**
* @brief destruye un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a destruir)
* @return void (no devuelve nada)
*/
void object_destroy(Object *);

/*funciones para obtener los campos de las funciones*/

/**
* @brief devuelve el nombre de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a usar)
* @return char (nombre del objeto)
*/
char *object_get_name(Object *);

/**
* @brief devuelve el Id de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a usar)
* @return Id (Id del objeto)
*/
Id object_get_id(Object *object);

/**
* @brief devuelve la descripcion de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a usar)
* @return char (descripcion del objeto)
*/
char *object_get_description(Object *object);

/*funciones para estableces los campos de el objeto*/

/**
* @brief modifica el id de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a modificar)
* @param nuevo_id (Id nuevo del objeto)
* @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
*/
STATUS object_set_id(Object *object, Id nuevo_id);

/**
* @brief modifica el nombre de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a modificar)
* @param nuevo_nombre (Nuevo nombre)
* @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
*/
STATUS object_set_name(Object *object, char *nuevo_nombre);

/**
* @brief modifica la descripcion de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a modificar)
* @param description (Nueva descripcion)
* @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
*/
STATUS object_set_description(Object *object, char *description);

/*Funcion para imprimir los campos del objeto en el fichero*/

/**
* @brief imprime un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a usar)
* @param f (donde se imprime)
* @return int (-1 si hay algun error)
*/
int object_print(FILE *f, Object *object);

#endif
