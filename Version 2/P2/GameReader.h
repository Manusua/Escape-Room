#ifndef GAMEREADER_H
#define GAMEREADER_H

#include "game.h"

#define GDESC_LINES 3
#define GDESC_TAM 8


STATUS game_reader_load_spaces(Game* game, char* filename);
STATUS game_reader_load_objects(Game* game, char* filename);

#endif
