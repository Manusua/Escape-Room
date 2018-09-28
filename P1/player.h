#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

#define MAX_PLAYERS 4

Player player_create(Id id);
STATUS player_destroy(Object object);
char* player_get_name(Player player);
Id player_get_location(Player player);
Id player_get_object (Player player);
STATUS player_set_name(Player player, char*nombre);
STATUS player_set_location(Player player, Id location);
STATUS player_set_object(Player player, Id object);
STATUS player_sprint(Player player);

#endif
