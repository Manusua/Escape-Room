


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GameReader.h"
#include "space.h"




STATUS game_reader_load_spaces(Game* game, char* filename) {
  int i,j;
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  char* toks = NULL;
  Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
  char** gdesc;
  Space* space = NULL;
  STATUS status = OK;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }
  gdesc=(char **)malloc(GDESC_LINES *sizeof(char*));
  if(gdesc==NULL){
    fclose(file);
    return ERROR;
  }

  for(i = 0; i < NUM_STRINGS; ++i){
    gdesc[i] = (char*)malloc(sizeof(char)*GDESC_TAM);
    if(gdesc[i]==NULL){
      for(j=0;j<i;j++){
        free(gdesc[i]);
      }
      free(gdesc);
      fclose(file);
      return ERROR;
    }
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#s:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      north = atol(toks);
      toks = strtok(NULL, "|");
      east = atol(toks);
      toks = strtok(NULL, "|");
      south = atol(toks);
      toks = strtok(NULL, "|");
      west = atol(toks);
      toks = strtok(NULL, "|");
      if(toks!=NULL){
        strncpy(gdesc[0],toks,GDESC_TAM);
        for(i = 1; i  < GDESC_LINES; i++){
          toks = strtok(NULL, "|");
          if(toks!=NULL){
            strncpy(gdesc[i],toks,GDESC_TAM);
          }
        }
      }
      else{
        for(i=0;i<GDESC_LINES;i++){
          gdesc[i][0]='\0';
        }
      }

      space = space_create(id);
      if (space != NULL) {
       space_set_name(space, name);
       space_set_north(space, north);
       space_set_east(space, east);
       space_set_south(space, south);
       space_set_west(space, west);

       space_set_gdesc(space, gdesc);
       game_add_space(game, space);
     }
   }
 }

 if (ferror(file)) {
  status = ERROR;
}

fclose(file);

return status;
}



STATUS game_reader_load_objects(Game* game, char* filename) {
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  Object* object = NULL;
  Id id;
  char* toks = NULL;

  if (!filename) {
    return ERROR;
  }

  file = fopen(filename, "r");
  if (file == NULL) {
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#o:", line, 3) == 0) {
      toks = strtok(line + 3, "|");
      id = atol(toks);
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      object = object_create(id);
      object_set_name(object, name);
      game_add_object(game, object);
      space_add_object(game_get_space(game,1),object_get_id(object));

    }
  }
  if (ferror(file)) {
    return ERROR;
  }

  fclose(file);

  return OK;
}
