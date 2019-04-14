#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

struct _Space {
  Id id;
  char name[WORD_SIZE + 1];
  Id north;
  Id south;
  Id east;
  Id west;
  Set* objects;
  char** gdesc;

};

Space* space_create(Id id) {
  int i,j;
  Space *newSpace = NULL;

  if (id == NO_ID)
    return NULL;

  newSpace = (Space *) malloc(sizeof (Space));

  if (newSpace == NULL) {
    return NULL;
  }
  newSpace->id = id;

  newSpace->name[0] = '\0';

  newSpace->north = NO_ID;
  newSpace->south = NO_ID;
  newSpace->east = NO_ID;
  newSpace->west = NO_ID;

  newSpace->objects = set_create();

  newSpace->gdesc=(char **)malloc(GDESC_LINES *sizeof(char*));
  if(newSpace->gdesc==NULL){
    return NULL;
  }

  for(i = 0; i < GDESC_LINES; ++i){
    newSpace->gdesc[i] = (char*)malloc(sizeof(char)*GDESC_TAM);
    if(newSpace->gdesc[i]==NULL){
      for(j=0;j<i;j++){
        free(newSpace->gdesc[i]);
      }
      free(newSpace->gdesc);
      return NULL;
    }
  }


  return newSpace;
}

STATUS space_destroy(Space* space) {

  if (!space) {
    return ERROR;
  }
  set_destroy(space->objects);

  free(space);
  space = NULL;

  return OK;
}

STATUS space_set_name(Space* space, char* name) {
  if (!space || !name) {
    return ERROR;
  }

  if (!strcpy(space->name, name)) {
    return ERROR;
  }

  return OK;
}

STATUS space_set_north(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->north = id;
  return OK;
}

STATUS space_set_south(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->south = id;
  return OK;
}

STATUS space_set_east(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->east = id;
  return OK;
}

STATUS space_set_west(Space* space, Id id) {
  if (!space || id == NO_ID) {
    return ERROR;
  }
  space->west = id;
  return OK;
}

STATUS space_set_object(Space* space, Id pos, Id object_id) {
  if (!space) {
    return ERROR;
  }
  if(pos == NO_ID){
    return set_del(space->objects, object_id);
  }
  else return set_add(space->objects, object_id);
}

/*Puesto que el array es estatico, pasamos string como parametro y ahi se devuelve la string */
char** space_get_gdesc(Space* space){
  if(space==NULL)return NULL;
  return space->gdesc;
}


const char * space_get_name(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->name;
}

Id space_get_id(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->id;
}

Id space_get_north(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->north;
}

Id space_get_south(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->south;
}

Id space_get_east(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->east;
}

Id space_get_west(Space* space) {
  if (!space) {
    return NO_ID;
  }
  return space->west;
}

STATUS space_set_gdesc(Space* space, char* string[]){
  int i;
  for(i = 0; i < NUM_STRINGS; ++i){
    if(string[i] != NULL){
      strcpy(space->gdesc[i], string[i]);
    }

  }
  return OK;
}

/*Supongo que hay que devolver el Set Entero*/
Set* space_get_object(Space* space) {
  if (!space) {
    return NULL;
  }
  return space->objects;
}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -space: espacio donde vamos a bsucar el objeto
  -object: objeto que buscaremos en el espacio
Return:
  -BOOL: true si lo encontramos
*/
BOOL space_is_object(Space* space, Id id){
  if(!space)
    return FALSE;
  return set_is_id(space->objects, id);
}

STATUS space_add_object(Space* space,Id id){

  if(space==NULL)return ERROR;
  if(space_is_object(space,id)==TRUE)return OK;
  if(set_add(space->objects,id)==ERROR)return ERROR;
  return OK;
}

STATUS space_print(Space* space) {
  Id idaux = NO_ID;
  Set* aux;
  int i ;
  if (!space) {
    return ERROR;
  }

  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }

  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");
  }

  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }

  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }
  aux = space_get_object(space);
  if (aux != NULL) {
    fprintf(stdout, "---> Objects in the space:\n");
    set_print(aux,stdout);
  } else {
    fprintf(stdout, "---> No object in the space.\n");
  }

  for(i = 0; i < NUM_STRINGS; ++i){
    fprintf(stdout, "%s\n", space->gdesc[i]);
  }
  return OK;
}
