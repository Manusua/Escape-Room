#include <stdlib.h>
#include <stdio.h>
#include "player.h"




typedef struct _Player{
	Id id;
	char name[WORD_SIZE + 1]
	Id location;
	Id object;
}Player


Player player_create(Id id){

  Player *newPlayer = NULL;

  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));

  if (newPlayer == NULL) {
    return NULL;
  }
  newPlayer->id = id;

  newPlayer->name[0] = '\0';

  newPlayer->location = NO_ID

  newPlayer->object = NO_ID;

  return newPlayer;
}


STATUS player_destroy(Player player){

  if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;

  return OK;
}


char* player_get_name(Player player){ 

  if (!player) {
    return ERROR;
  }

  return object->name;

}

Id player_get_location(Player player){ 

  if (!player) {
    return ERROR;
  }

  return object->location;

}

Id player_get_object (Player player){ 

  if (!player) {
    return ERROR;
  }

  return object->object;

}

STATUS player_set_name(Player player, char*nombre){ 

if (!player || !nombre) {
    return ERROR;
  }

  if (!strcpy(object->name, nombre)) {
    return ERROR;
  }

  return OK;
}


STATUS player_set_location(Player player, Id location){ 

if (!player || !location ) {
    return ERROR;
  }

  player->location = location;

  return OK;
}

STATUS player_set_object(Player player, Id object){ 

if (!player || !object ) {
    return ERROR;
  }

  player->object = object;

  return OK;
}

STATUS player_print(Player player){
 Id idaux = NO_ID;

  if (!player) {
    return ERROR;
  }

  fprintf(stdout, "--> Player (Id: %ld; Name: %s)\n", player->id, get_name(player);

  idaux = get_location(player);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Location: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> The player has no location.\n");
  }

  idaux = get_object(player);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> Object: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> The player has no object.\n");
  }
  return OK;

};

