
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "GameReader.h"
#include "player.h"
#include "object.h"
#include "die.h"

#define N_CALLBACK 9

/**
   Define the function type for the callbacks
*/
typedef STATUS (*callback_fn)(Game* game);



/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Campos:
  -player: jugador del juego (de momento solo 1)
  -object: objeto del juego (de momento solo 1)
  -spaces: espacios disponibles del juego
  -last_cmd: ultimo comando ejecutado por el jugador
*/
 struct _Game{
   Player *player;
   Object *objects[MAX_OBJECTS + 1];
   Space* spaces[MAX_SPACES + 1];
   T_Command last_cmd;
   Die* die;
};


/**
   List of callbacks for each command in the game
*/
STATUS game_callback_unknown(Game* game);
STATUS game_callback_exit(Game* game);
STATUS game_callback_following(Game* game);
STATUS game_callback_previous(Game* game);
STATUS game_callback_grasp(Game *game);
STATUS game_callback_drop(Game *game);
STATUS game_callback_roll(Game *game);
STATUS game_callback_left(Game *game);
STATUS game_callback_right(Game *game);

static  callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_following,
  game_callback_previous,
  game_callback_grasp,
  game_callback_drop,
  game_callback_roll,
  game_callback_left,
  game_callback_right};

/**
   Private functions
*/


Id game_get_space_id_at(Game* game, int position);


/**
   Game interface implementation
*/


/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que guardar la información de un nuevo juego
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
Game * game_create() {
  int i;
  Game *game;

  game=(Game*)malloc(sizeof(Game));
  if(game==NULL)return NULL;

  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }

  game->player=player_create(1);
  if(game->player==NULL){
    game_destroy(game);
    return NULL;
  }

  for (i = 0; i < MAX_OBJECTS; i++) {
    game->objects[i] = NULL;
  }
  game->last_cmd = NO_CMD;
  game->die = die_create(1);
  if(game->die==ERROR){
    game_destroy(game);
    return NULL;
  }

  return game;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que guardar la información de un nuevo juego cargandolo desde un archivo
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS game_create_from_file(Game* game, char* filename) {


  if (game_reader_load_spaces(game, filename) == ERROR)
    return ERROR;

  if (game_reader_load_objects(game, filename) == ERROR)
    return ERROR;

  game_set_player_location(game, game_get_space_id_at(game, 0));

  return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego a destruir
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS game_destroy(Game* game) {
  int i = 0;

  for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
    space_destroy(game->spaces[i]);
  }

  for (i = 0; (i < MAX_OBJECTS) && (game->objects[i] != NULL); i++) {
    object_destroy(game->objects[i]);
  }

  if(game->player!=NULL)player_destroy(game->player);

  die_destroy(game->die);

  return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que añadir un espacio
  -space: espacio a añadir al juego
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS game_add_space(Game* game, Space* space) {
  int i = 0;

  if (space == NULL) {
    return ERROR;
  }

  while ( (i < MAX_SPACES) && (game->spaces[i] != NULL)){
    i++;
  }

  if (i >= MAX_SPACES) {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 19/10/2018
Parámetros:
  -game: juego sobre el que añadir un objeto
  -object: objeto a añadir al juego
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS game_add_object(Game* game, Object* object){
  int i = 0;

  if (object == NULL) {
    return ERROR;
  }

  while ( (i < MAX_OBJECTS) && (game->objects[i] != NULL)){
    i++;
  }

  if (i >= MAX_OBJECTS) {
    return ERROR;
  }

  game->objects[i] = object;

  return OK;


}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos
  -position: posición de la que queremos hallar su identificador
Return:
  -Id: identificador de la posicion deseada
*/
Id game_get_space_id_at(Game* game, int position) {

  if (position < 0 || position >= MAX_SPACES) {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos
  -id: identificador del spacio que queremos hallar
Return:
  -Space: espacio que queremos hallar
*/
Space* game_get_space(Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    if (id == space_get_id(game->spaces[i])){
      return game->spaces[i];
    }
  }

  return NULL;
}

Object* game_get_object ( Game* game, Id id){
  int i = 0;

  if (id == NO_ID) {
    return NULL;
  }

  for (i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; i++) {
    if (id == object_get_id(game->objects[i])){
      return game->objects[i];
    }
  }

  return NULL;
}

Id game_get_object_location(Game* game, Id id){
  int i;
  for(i = 0; i < MAX_SPACES; ++i){
    if(space_is_object(game->spaces[i], id))
      return space_get_id(game->spaces[i]);
    }
  return (long) NULL;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos
  -id: identificador del jugador del que queremos establecer su posición
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS game_set_player_location(Game* game, Id id) {

  if (id == NO_ID) {
    return ERROR;
  }

  if(player_set_location(game->player,id)==ERROR)
    return ERROR;


  return OK;

}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos
  -id: identificador del objeto del que queremos establecer su localizacion
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS game_set_object_location(Game* game, Id pos, Id object_id) {

  return space_set_object(game->spaces[player_get_location(game->player) - 1],pos, object_id);

}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos
Return:
  -Id: identificador de la posición del jugador
*/
Id game_get_player_location(Game* game) {

  return player_get_location(game->player);
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos
Return:
  -Id: identificador de la posición del objeto
*/
Id game_get_player_object(Game* game){
  return player_get_object(game->player);
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos
  -cmd: ultimo comando del usuario
Return:
  -STATUS: código que indica si se ha podido realizar la tarea correctamente
*/
STATUS game_update(Game* game, T_Command cmd) {

  game->last_cmd = cmd;
  return (*game_callback_fn_list[cmd])(game);

}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos
Return:
  -T_Command: ultimo comando del usuario
*/
T_Command game_get_last_command(Game* game){
  return game->last_cmd;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego del que queremos imprimir la informacion
*/
void game_print_data(Game* game) {

  int i;

  if(game==NULL)return;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    space_print(game->spaces[i]);
  }

  if(player_print(game->player)==ERROR)return;
  for(i = 0; i < MAX_OBJECTS && game->objects[i] != NULL; ++i){
    object_print(game->objects[i]);
  }

}

int game_get_last_roll(Game* game){
  int roll;

  if(game==NULL)return -1;

  roll=die_get(game->die);
  if(roll<1 || roll>6)return 0;

  return roll;
}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego que queremos finalizar
Return:
  -BOOL: fin del jjuego
*/
BOOL game_is_over(Game* game) {
  return FALSE;
}

/**
   Callbacks implementation for each action
*/

STATUS game_callback_unknown(Game* game) {
  return OK;
}

STATUS game_callback_exit(Game* game) {
  return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos de realizar la acción de siguiente
*/
STATUS game_callback_following(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
	       game_set_player_location(game, current_id);
      }
      return OK;
    }
  }
  return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos de realizar la acción de atrás
*/
STATUS game_callback_previous(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
	       game_set_player_location(game, current_id);
      }
      return OK;
    }
  }
  return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos de realizar la acción de coger el objeto
*/
STATUS game_callback_grasp(Game *game){
  int i;
  char input[WORD_SIZE] = "";
  Id player_loc=NO_ID;
  Id object_id=NO_ID;
  scanf("%s", input);
  for(i = 0;  i < MAX_OBJECTS; ++i){
    if(strcmp(object_get_name(game->objects[i]), input) == 0){
      object_id = object_get_id(game->objects[i]);
    }
  }
  player_loc = game_get_player_location(game);

  if(space_is_object(game->spaces[player_loc - 1],object_id)){
    if(object_id == NO_ID || player_loc==NO_ID)
      return ERROR;
    if(player_get_object(game->player) != NO_ID){
      return ERROR;
    }
    game_set_object_location(game,NO_ID, object_id);
    player_set_object(game->player,object_id);
    return OK;
  }
  return ERROR;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos de realizar la acción de dejar el objeto
*/
STATUS game_callback_drop(Game *game){

  Id player_loc=NO_ID;
  Id object_id=NO_ID;

  player_loc = game_get_player_location(game);
  object_id = game_get_player_object(game);

  if(object_id == NO_ID || player_loc==NO_ID)
    return ERROR;
  game_set_object_location(game,player_loc,object_id);
  player_set_object(game->player,NO_ID);
  return OK;
}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -game: juego sobre el que tratamos de realizar la acción de tirar el dado
*/
STATUS game_callback_roll(Game *game){

  if(game == NULL) return ERROR;

  die_roll(game->die, 1, 6);

  return OK;
}

STATUS game_callback_left(Game *game){
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID) {
         game_set_player_location(game, current_id);
      }
      return OK ;
    }
  }
  return OK;
}


STATUS game_callback_right(Game *game){
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id) {
    return ERROR;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID) {
         game_set_player_location(game, current_id);
      }
      return OK;
    }
  }
  return OK;
}
