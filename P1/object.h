#ifndef OBJECT_H
#define OBJECT_H


#include "types.h"


typedef struct _Object Object;

//TODO no se exactamente que es un objeto asi que pongo 8 por ejemplo y ya lo cmabairemos si eso
#define MAX_OBJECTS 8

Object object_create(Id id);
STATUS object_destroy(Object object);
char* object_get(Object object);
STATUS object_set(Object object, char*nombre);
STATUS object_print(Object object);


#endif
