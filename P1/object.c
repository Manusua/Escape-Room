#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Campos:
  -Id: identificador único de cada objeto
  -name: nombre del objeto
*/

struct _Object{
  Id id;
  char  name[WORD_SIZE + 1];
}Object;


/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -id: identificador único de cada objeto
Return:
  -Object: objeto creado
*/

Object* object_create(Id id){

  Object *newObject = NULL;

  if (id == NO_ID )
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));

  if (newObject == NULL) {
    return NULL;
  }
  newObject->id = id;

  newObject->name[0] = '\0';

  return newObject;
}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -object: objeto a destruir
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS object_destroy(Object *object){

  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -object: objeto del que se desea obtener el nombre
Return:
  -char*: nombre del objeto
*/
char* object_get_name(Object *object){ 

  if (!object) {
    return ERROR;
  }

  return object->name;

}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -object: objeto del que se desea establecer el nombre
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS object_set_name(Object *object, char*nombre){ 

if (!object || !nombre) {
    return ERROR;
  }

  if (!strcpy(object->name, nombre)) {
    return ERROR;
  }

  return OK;


}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -object: objeto del que se desea mostrar la informacion
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS object_print(Object *object){

  if (object==NULL) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, get_name_object(object));

  return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -object: objetp del que se desea obtener el identificador
Return:
  -Id: identificador del objeto
*/
Id object_get_id(Object *object){

  if (object==NULL)return NO_ID;

  return object->id;
  
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -object: objeto del que se desea establecer el identificador
  -id: identificador a establecer en el objeto
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS object_set_id(Object *object, Id id){

  if(object==NULL || id == NULL)return ERROR;

  object->id=id;

  return OK;
}
