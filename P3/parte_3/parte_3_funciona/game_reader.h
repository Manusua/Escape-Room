/* ===================================================================
File: game_reader.h
Version: 2.0
Date: 13-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Prototipo de game_reader.c
Revision historica:
1-10-2018 versión 1.0
13-10-2018 versión 2.0
        añadida carga de objetos y descripción de una casilla
=================================================================== */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"

/*Función para cargar espacios y objetos*/
STATUS game_reader_load_spaces(Game* game, char* filename);
STATUS game_reader_load_object(Game* game, char* filename);
STATUS game_reader_load_links(Game *game, char * filename);
STATUS game_reader_load_players(Game *game, char * filename);

#endif
