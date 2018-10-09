
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Módulo que define todas las acciones que influyen en los objetos así como en las
acciones que estos pueden realizar sobre ellos
*/
#ifndef OBJECT_H
#define OBJECT_H


#include "types.h"


typedef struct _Object Object;


#define MAX_OBJECTS 4

Object* object_create(Id id);
STATUS object_destroy(Object *object);
char* object_get_name(Object *object);
STATUS object_set_name(Object *object, char *nombre);
STATUS object_print(Object *object);
Id object_get_id(Object *object);
STATUS object_set_id(Object *object,Id newId);




#endif
