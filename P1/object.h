#ifndef OBJECT_H
#define OBJECT_H


#include "types.h"


typedef struct _Object Object;

Object create(Id id);
STATUS destroy(Object object);
char* get(Object object);
STATUS set(Object object, char*nombre);
STATUS print(Object object);


#endif
