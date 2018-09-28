#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

Player create(Id id);
STATUS destroy(Object object);
char* get_name(Player player);
Id get_location(Player player);
Id get_object (Player player);
STATUS set_name(Player player, char*nombre);
STATUS set_location(Player player, Id location);
STATUS set_object(Player player, Id object);
STATUS print(Player player);

#endif
