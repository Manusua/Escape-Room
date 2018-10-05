
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Módulo que define todas las acciones que influyen en los jugadores así como en las
acciones que estos pueden realizar
*/
#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "object.h"

typedef struct _Player Player;

Player* player_create(Id id);
STATUS player_destroy(Player *player);
char* player_get_name(Player *player);
Id player_get_location(Player *player);
Id player_get_object (Player *player);
STATUS player_set_name(Player *player, char*nombre);
STATUS player_set_location(Player *player, Id location);
STATUS player_set_object(Player *player, Id object);
STATUS player_print(Player *player);

#endif
