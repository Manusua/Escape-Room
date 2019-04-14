/* ===================================================================
File: object.c
Version: 1.0
Date: 1-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Contiene todas las funciones que perimiten crear objetos y trabajar con sus campos
Revision historica:
1-10-2018 versión 1.0
=================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/*Estructura del objeto que almacena el nombre y su id*/
struct _Object {
    Id id; /*Identificador del objeto*/
    char name[WORD_SIZE]; /*Nombre del objeto*/
    char description[WORD_SIZE];
};

/******************************************************************
 *Funcion :object_create
 *Date: 1-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Funcion que se encarga de crear el objecto
 *Input: nada
 *Output: el objeto o NULL si hay error
 ********************************************************************/

Object *object_create() {
    Object *object = NULL;
    object = (Object*) calloc(1, sizeof (Object));
    object->id = NO_ID;
    return object;
}

/******************************************************************
 *Funcion:object_destroy
 *Autores: Alvaro Becerra Jiminez
 *Date: 1-10-2018
 *Description: Funcion que se encarga de destruir el objecto
 *Input: Object
 *Output: nada
 ********************************************************************/

void object_destroy(Object * object) {
    if (object) {
        free(object);
        object = NULL;
    }
    return;
}

/******************************************************************
 *Funcion :object_get_id
 *Date: 1-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Funcion que se encarga de obtener el id de un objeto
 *Input: Object
 *Output: el id o NO_ID si el objeto del que se pide el id no existe
 ********************************************************************/

Id object_get_id(Object *object) {
    if (!object) return NO_ID;
    return object->id;
}

/******************************************************************
 *Funcion :object_get_name
 *Date: 1-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Funcion que se encarga de devolver el nombre del objeto
 *Input: object
 *Output: char * el nombre del objeto o NULL si el objeto del que se pide el nombre no existe
 ********************************************************************/

char *object_get_name(Object *object) {
    if (!object) return NULL;
    return object->name;
}

char *object_get_description(Object *object){
  if(object==NULL) return NULL;
  return object->description;
}

/******************************************************************
 *Funcion :object_set_id
 *Date: 1-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Funcion que se encarga de poner un nuevo id al objeto
 *Input: El objeto y el nuevo id
 *Output: Ok si sale bien y ERROR si no existe el objeto
 ********************************************************************/

STATUS object_set_id(Object * object, Id nuevo_id) {
    if (!object) return ERROR;
    object->id = nuevo_id; /*No comprobamos si el nuevo id es distinto a NO_ID porque en el juego,
						quizás queramos destruir el objeto de esta forma*/
    return OK;
}

STATUS object_set_description(Object *object, char *description){
  if(object==NULL || description==NULL) return ERROR;
  strcpy(object->description, description);
  return OK;
}

/******************************************************************
 *Funcion :object_set_name
 *Date: 1-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Funcion que se encarga de poner el nombre a un objeto
 *Input: El objeto y char * del nuevo nombre
 *Output: Ok si sale bien y ERROR si algún parámetro de la entrada no existe
 ********************************************************************/

STATUS object_set_name(Object *object, char *nuevo_nombre) {
    if (!object || !nuevo_nombre) return ERROR;
    strcpy(object->name, nuevo_nombre);
    return OK;
}



/******************************************************************
 *Funcion :object_set_id
 *Date: 1-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Funcion que se enccarga de imprimir el objeto
 *Input: El objeto y el fichero donde se escribirá
 *Output: un int que, si va todo bien, será mayor que 0
 ********************************************************************/

int object_print(FILE *f, Object *object) {
    if (!object || !f) return ERROR;
    return fprintf(f, " %ld %s\n", object->id, object->name);
}
