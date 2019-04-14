
/* ===================================================================
File: game_reader.c
Version: 2.0
Date: 13-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Módulo que permite cargar los espacios de un archivo a un juego
Revision historica:
1-10-2018 versión 1.0
13-10-2018 versión 2.0
        añadida carga de objetos y descripción de una casilla
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_reader.h"

/******************************************************************
 *Funcion :game_reader_load_spaces
 *Date: 13-10-2018
 *Autor: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que se encarga de leer los espacios y cargarlos
 *Input: Game y el nombre del fichero donde esta el tablero
 *Output: OK si todo funciona bien y ERROR si hay algun fallo.
 ********************************************************************/

STATUS game_reader_load_spaces(Game* game, char* filename) {
    FILE* file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char gdesc[TAM_DIBUJO+1];
    char description[WORD_SIZE];
    char* toks = NULL;
    Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID;
    Space* space = NULL;
    STATUS status = OK;
    if (!filename) {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        return ERROR;
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
			if (toks!=NULL){
			if (toks[0]!='\r'){
            strcpy(&gdesc[0], toks);
            toks = strtok(NULL, "|");
            strcpy(&gdesc[7], toks);
            toks = strtok(NULL, "|");
            strcpy(&gdesc[14], toks);
			} else {
				memset(gdesc, ' ', TAM_DIBUJO-1);
				gdesc[TAM_DIBUJO]='\0';
			}
			}else {
				memset(gdesc, ' ', TAM_DIBUJO-1);
				gdesc[TAM_DIBUJO]='\0';
			}
			toks = strtok(NULL, "|");
			if (toks!=NULL){
		    if(toks[0]!='\r'){
            strcpy(description, toks);
			} else strcpy(description, "");
			} else strcpy(description, "");

#ifdef DEBUG
            printf("Leido: %ld|%s|%ld|%ld|%ld|%ld|%s|%s\n", id, name, north, east, south, west, gdesc, description);
#endif
            space = space_create(id);
            if (space != NULL) {
                space_set_name(space, name);
                space_set_north(space, north);
                space_set_east(space, east);
                space_set_south(space, south);
                space_set_west(space, west);
                space_set_gdesc(space, gdesc);
                space_set_description(space,description);
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

/******************************************************************
 *Funcion :game_reader_load_spaces
 *Date: 13-10-2018
 *Autor: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que se encarga de leer los objetos y cargarlos
 *Input: Game y el nombre del fichero donde estan los objetos
 *Output: OK si todo funciona bien y ERROR si hay algun fallo.
 ********************************************************************/


STATUS game_reader_load_object(Game *game, char* filename) {
    FILE* file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char description[WORD_SIZE]="";
    char* toks = NULL;
    Id id = NO_ID, space_id = NO_ID;
    Object* object = NULL;
    STATUS status = OK;
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
            toks = strtok(NULL, "|");
            space_id = atol(toks);
			toks = strtok(NULL, "|");
			if (toks!=NULL){
            strcpy(description, toks);
			} else strcpy(description, "");
#ifdef DEBUG
            printf("Leido: %ld|%s|%ld\n", id, name, space_id);
#endif
            object = object_create();
            if (object != NULL) {
                object_set_name(object, name);
                object_set_id(object, id);
                game_set_object_location(game, space_id, id);
                object_set_description(object,description);
                game_add_object(game, object);
            }
        }
    }

    if (ferror(file)) {
        status = ERROR;
    }

    fclose(file);

    return status;
}




STATUS game_reader_load_links(Game *game,char * filename){
  FILE* file = NULL;
  char line[WORD_SIZE] = "";
  char name[WORD_SIZE] = "";
  Link *link;
  char* toks = NULL;
  Id id = NO_ID,id1,id2;
  BOOL estado;

  if (!filename) {
      return ERROR;
  }

  file = fopen(filename,"r");
  if (!file){
    return ERROR;
  }

  while (fgets(line, WORD_SIZE, file)) {
    if (strncmp("#l:", line, 3) == 0){
      toks = strtok(line + 3, "|");
      id = atol(toks);/*id de enlace*/
      toks = strtok(NULL, "|");
      strcpy(name, toks);
      toks = strtok(NULL, "|");
      id1 = atol(toks);
      toks = strtok(NULL, "|");
      id2 = atol(toks);
      toks = strtok(NULL, "|");
      estado = atol(toks);

#ifdef DEBUG
    printf("Leido: %ld|%s|%ld|%ld|%d\n", id, name, id1,id2, estado);
#endif
      link= link_create();
      if (link != NULL) {
          link_set_name(link, name);
          link_set_id(link, id);
          link_set_conection(link, id1, id2);
          link_set_status(link,estado);
          game_add_link(game,link);
      }
    }
  }
	    if (ferror(file)) {
			fclose(file);
        return ERROR;
  }
  fclose(file);

return OK;

}
