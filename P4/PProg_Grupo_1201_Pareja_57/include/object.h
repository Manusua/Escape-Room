/**
 * @brief En este fichero implementamos las funciones del objeto
 * @file object.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0
 * @date 20/10/2018
 */
#ifndef OBJECT_H
#define OBJECT_H

typedef struct _Object Object; /*!< Estructura de objeto */
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

/**
 * @brief devuelve la movilidad del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return bool true si se puede mover false si no
 */
BOOL object_get_movable(Object *object);

/**
 * @brief devuelve el Id de la localizacion original
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return Id (Id del objeto)
 */
Id object_get_original_location(Object *object);

/**
 * @brief devuelve si el objeto esta oculto o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return Id (Id del objeto)
 */
BOOL object_get_hidden(Object *object);

/**
 * @brief devuelve el id del objeto que nos dice si puede abrir el link
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return Id (Id del objeto)
 */
Id object_get_open(Object *object);

/**
 * @brief devuelve el true si el objeto esta encendido o false sino
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return boolean
 */
BOOL object_get_light(Object *object);

/**
 * @brief devuelve el BOOL si el objeto esta encendido
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return boolean
 */
BOOL object_get_on(Object *object);

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

/**
 * @brief modifica la descripciondetalla del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param description (la descripcion)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_detailed_description(Object *object, char *description);
/**
 * @brief modifica la movilidad del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @param movable (BOOL)
 * @return ok si todo va bien error si no
 */
STATUS object_set_movable(Object *object, BOOL movable);

/**
 * @brief modifica la localizacion original del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param nuevo_id (Id nuevo del objeto)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_original_location(Object * object, Id nuevo_id);

/**
 * @brief modifica el objeto si esta escondido o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param hidden (BOOL; si esta oculto o no)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_hidden(Object * object, BOOL hidden);

/**
 * @brief modifica el objeto si esta escondido o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param open (Id)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_open(Object * object, Id open);

/**
 * @brief modifica el objeto tiene luz o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param light (BOOl)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_light(Object * object, BOOL light);

/**
 * @brief modifica el objeto puede iluminar el espacio o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param on (BOOL)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_on(Object * object, BOOL on);
/*Funcion para imprimir los campos del objeto en el fichero*/

/**
 * @brief imprime un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param f (donde se imprime)
 * @param object (Objeto a usar)
 * @return int (-1 si hay algun error)
 */
int object_print(FILE *f, Object *object);

/**
 * @brief devuelve LA descripcion detalla del objecto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return Id (Id del objeto)
 */
char *object_get_detailed_description(Object *object);
/**
 * @brief nos dice si un objecto esta en su localizacion original o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @param location (id)
 * @return int (-1 si hay algun error)
 */
STATUS object_is_in_original_location(Object *object, Id location);

#endif
