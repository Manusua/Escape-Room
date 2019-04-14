/**
 * @brief En este fichero implementamos las funciones del objeto
 * @file object.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 20/10/2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"


struct _Object {
    Id id; /*!< Identificador del objeto*/
    char name[WORD_SIZE]; /*!< Nombre del objeto*/
    char description[WORD_SIZE];/*!< Descripcion del objeto */
};/*!< Estructura del objeto*/


/**
* @brief crea un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @return Object (El objeto que crea)
*/
Object *object_create() {
    Object *object = NULL;
    object = (Object*) calloc(1, sizeof (Object));
    object->id = NO_ID;
    return object;
}

/**
* @brief destruye un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a destruir)
* @return void (no devuelve nada)
*/
void object_destroy(Object * object) {
    if (object) {
        free(object);
        object = NULL;
    }
    return;
}

/**
* @brief devuelve el Id de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a usar)
* @return Id (Id del objeto)
*/
Id object_get_id(Object *object) {
    if (!object) return NO_ID;
    return object->id;
}

/**
* @brief devuelve el nombre de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a usar)
* @return char (nombre del objeto)
*/
char *object_get_name(Object *object) {
    if (!object) return NULL;
    return object->name;
}


/**
* @brief devuelve la descripcion de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a usar)
* @return char (descripcion del objeto)
*/
char *object_get_description(Object *object) {
    if (object == NULL) return NULL;
    return object->description;
}

/**
* @brief modifica el id de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a modificar)
* @param nuevo_id (Id nuevo del objeto)
* @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
*/
STATUS object_set_id(Object * object, Id nuevo_id) {
    if (!object) return ERROR;
    object->id = nuevo_id; /*No comprobamos si el nuevo id es distinto a NO_ID porque en el juego,
						quizás queramos destruir el objeto de esta forma*/
    return OK;
}


/**
* @brief modifica la descripcion de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a modificar)
* @param description (Nueva descripcion)
* @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
*/
STATUS object_set_description(Object *object, char *description) {
    if (object == NULL || description == NULL) return ERROR;
    strcpy(object->description, description);
    return OK;
}

/**
* @brief modifica el nombre de un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a modificar)
* @param nuevo_nombre (Nuevo nombre)
* @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
*/
STATUS object_set_name(Object *object, char *nuevo_nombre) {
    if (!object || !nuevo_nombre) return ERROR;
    strcpy(object->name, nuevo_nombre);
    return OK;
}

/**
* @brief imprime un objeto 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param object (Objeto a usar)
* @param f (donde se imprime)
* @return int (-1 si hay algun error)
*/
int object_print(FILE *f, Object *object) {
    if (!object || !f) return ERROR;
    return fprintf(f, " %ld %s\n", object->id, object->name);
}
