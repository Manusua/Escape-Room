#ifndef GAMEREADER_H
#define GAMEREADER_H

#include "game.h"


STATUS game_reader_load_spaces(Game* game, char* filename);
STATUS game_reader_load_objects(Game* game, char* filename);

#endif
