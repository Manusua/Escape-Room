#include <stdio.h>
#include <stdlib.h>
#include "object.h"



typedef struct _Object{
  Id identifier;
  char* name;
} Object;



Object create(Id id){

  Object *newObject = NULL;

  if (id == NO_ID)
    return NULL;

  newObject = (Object *) malloc(sizeof (Object));

  if (newObject == NULL) {
    return NULL;
  }
  newObject->id = id;

  newObject->name[0] = '\0';

  return newObject;
}


STATUS destroy(Object object){

  if (!object) {
    return ERROR;
  }

  free(object);
  object = NULL;

  return OK;
}

char* get(Object object){ 

  if (!object) {
    return ERROR;
  }

  return object->name;

}

STATUS set(Object object, char*nombre){ 

if (!object || !nombre) {
    return ERROR;
  }

  if (!strcpy(object->name, nombre)) {
    return ERROR;
  }

  return OK;


}


STATUS print(Object object){
  Id idaux = NO_ID;

  if (!object) {
    return ERROR;
  }

  fprintf(stdout, "--> Object (Id: %ld; Name: %s)\n", object->id, get(object);

  return OK;
}