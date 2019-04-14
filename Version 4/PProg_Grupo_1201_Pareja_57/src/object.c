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
    char description[WORD_SIZE]; /*!< Descripcion del objeto */
    BOOL movable; /*!< Si el objeto es movible*/
    Id original_location; /*!<Localizacion original*/
    BOOL hidden; /*!< Si el objeto esta oculto*/
    Id open; /*!< Si el objeto se puede abrir*/
    BOOL light; /*!< Si el objeto puede iluminar el espacio*/
    BOOL on; /*!< Si el objeto esta encenido o apagado*/
    char detailed_description[WORD_SIZE]; /*!< Descripcion detallada del objeto */
}; /*!< Estructura del objeto*/

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
    object->movable = FALSE;
    object->original_location = NO_ID;
    object->hidden = FALSE;
    object->open = NO_ID;
    object->light = FALSE;
    object->on = FALSE;
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
 * @brief devuelve si el objeto se puede mover o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return char (descripcion del objeto)
 */
BOOL object_get_movable(Object *object) {
    if (object == NULL) return FALSE;
    return object->movable;
}

/**
 * @brief devuelve el Id de la localizacion original
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return Id (Id del objeto)
 */
Id object_get_original_location(Object *object) {
    if (!object) return NO_ID;
    return object->original_location;
}

/**
 * @brief devuelve si el objeto esta oculto o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return Id (Id del objeto)
 */
BOOL object_get_hidden(Object *object) {
    if (!object) return NO_ID;
    return object->hidden;
}

/**
 * @brief devuelve el id del objeto que nos dice si puede abrir el link
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return Id (Id del objeto)
 */
Id object_get_open(Object *object) {
    if (!object) return NO_ID;
    return object->open;
}

/**
 * @brief devuelve el true si el objeto esta encendido o false sino
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return boolean
 */
BOOL object_get_light(Object *object) {
    if (!object) return FALSE;
    return object->light;
}

/**
 * @brief devuelve el BOOL si el objeto esta encendido
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return BOOL
 */
BOOL object_get_on(Object *object) {
    if (!object) return FALSE;
    return object->on;
}

/**
 * @brief devuelve LA descripcion detalla del objecto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @return Id (Id del objeto)
 */
char *object_get_detailed_description(Object *object) {
    if (!object) return NULL;
    ;
    return object->detailed_description;
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
 * @brief modifica la movilidad del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a usar)
 * @param movable (BOOL)
 * @return ok si todo va bien error si no
 */
STATUS object_set_movable(Object *object, BOOL movable) {
    if (object == NULL) return ERROR;
    object->movable = movable;
    return OK;
}

/**
 * @brief modifica la localizacion original del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param nuevo_id (Id nuevo del objeto)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_original_location(Object * object, Id nuevo_id) {
    if (!object) return ERROR;
    object->original_location = nuevo_id;

    return OK;
}

/**
 * @brief modifica el objeto si esta escondido o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param hidden (BOOl)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_hidden(Object * object, BOOL hidden) {
    if (!object) return ERROR;
    object->hidden = hidden;

    return OK;
}

/**
 * @brief modifica el objeto si esta escondido o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param open (Id)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_open(Object * object, Id open) {
    if (!object) return ERROR;
    object->open = open;

    return OK;
}

/**
 * @brief modifica el objeto tiene luz o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param light (BOOL)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_light(Object * object, BOOL light) {
    if (!object) return ERROR;
    object->light = light;

    return OK;
}

/**
 * @brief modifica el objeto puede iluminar el espacio o no
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param on (BOOL)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_on(Object * object, BOOL on) {
    if (!object) return ERROR;
    object->on = on;

    return OK;
}

/**
 * @brief modifica la descripciondetalla del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param object (Objeto a modificar)
 * @param description
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS object_set_detailed_description(Object *object, char *description) {
    if (object == NULL || description == NULL) return ERROR;
    strcpy(object->detailed_description, description);
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
