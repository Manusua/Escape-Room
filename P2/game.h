/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Módulo que contiene las funciones relevantes al desarrollo principal del juego y
que coordina las llamadas a Player, Object y Space
*/

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "player.h"
#include "object.h"
#include "die.h"

typedef struct _Game Game;

STATUS game_create(Game* game);
STATUS game_create_from_file(Game* game, char* filename);
STATUS game_update(Game* game, T_Command cmd);
STATUS game_destroy(Game* game);
BOOL   game_is_over(Game* game);
void   game_print_screen(Game* game);
void   game_print_data(Game* game);
Space* game_get_space(Game* game, Id id);
Object* game_get_object(Game* game, Id id);
Id     game_get_player_location(Game* game);
Id     game_get_object_location(Game* game, Id id);
Id 	   game_get_player_object(Game* game);
T_Command game_get_last_command(Game* game);
STATUS game_add_space(Game* game, Space* space);
STATUS game_add_object(Game* game, Object* object);
STATUS game_set_player_location(Game* game, Id id);
STATUS game_set_object_location(Game* game, Id id);

#endif
