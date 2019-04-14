#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Campos:
  -Id: identificador único de cada jugador
  -name: nombre del jugador
  -location: identificador de la posición del jugador
  -object: identificador del objeto que posee el jugador
*/
struct _Player{
	Id id;
	char name[WORD_SIZE + 1];
	Id location;
	Id object;
}Player;

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -id: identificador único de cada jugador
Return:
  -Player: jugador creado
*/

Player* player_create(Id id){


  Player *newPlayer;
  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));

  if (newPlayer == NULL) {
    return NULL;
  }
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  newPlayer->location = NO_ID;
  newPlayer->object = NO_ID;

  return newPlayer;
}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -player: jugador a destruir
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS player_destroy(Player *player){

  if (player==NULL) {
    return ERROR;
  }

  free(player);
  player = NULL;

  return OK;
}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -player: jugador del que se desea obtener el nombre
Return:
  -char*: nombre del jugador
*/
char* player_get_name(Player *player){ 

  if (player==NULL) {
    return ERROR;
  }

  return player->name;

}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -player: jugador del que se desea obtener la localización
Return:
  -Id: localización del jugador
*/
Id player_get_location(Player *player){ 

  if (!player) {
    return ERROR;
  }

  return player->location;

}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -player: jugador del que se desea obtener el objeto
Return:
  -Id: objeto del jugador
*/
Id player_get_object(Player *player){ 

  if (player==NULL) {
    return ERROR;
  }

  return player->object;

}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -player: jugador del que se desea establecer el nombre
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS player_set_name(Player *player, char*nombre){ 

if (player==NULL || nombre==NULL) {
    return ERROR;
  }

  if (!strcpy(player->name, nombre)) {
    return ERROR;
  }

  return OK;
}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -player: jugador del que se desea establecer la localización
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS player_set_location(Player *player, Id location){ 

if (player==NULL ) {
    return ERROR;
  }

  player->location = location;

  return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -player: jugador del que se desea establecer el objeto
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS player_set_object(Player *player, Id object){ 

if (player==NULL ) {
    return ERROR;
  }

  player->object = object;

  return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -player: jugador del que se desea mostrar la informacion
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS player_print(Player *player){
 
 Id idaux = NO_ID;

  if (player==NULL) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, get_player_name(player));

  idaux = get_player_location(player);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Location: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> The player has no location.\n");
  }

  idaux = get_player_object(player);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Object: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> The player has no object.\n");
  }
  return OK;

}

