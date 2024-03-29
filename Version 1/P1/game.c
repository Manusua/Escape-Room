
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "GameReader.h"
#include "player.h"
#include "object.h"

#define N_CALLBACK 6

/**
   Define the function type for the callbacks
*/
typedef void (*callback_fn)(Game* game);

/**
   List of callbacks for each command in the game 
*/
void game_callback_unknown(Game* game);
void game_callback_exit(Game* game);
void game_callback_following(Game* game);
void game_callback_previous(Game* game);
void game_callback_pick(Game *game);
void game_callback_drop(Game *game);

static callback_fn game_callback_fn_list[N_CALLBACK]={
  game_callback_unknown,
  game_callback_exit,
  game_callback_following,
  game_callback_previous,
  game_callback_pick,
  game_callback_drop};

/**
   Private functions
*/


Id     game_get_space_id_at(Game* game, int position);


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

STATUS game_create(Game* game) {
  int i;
  
  
  for (i = 0; i < MAX_SPACES; i++) {
    game->spaces[i] = NULL;
  }
  
  game->player=player_create(1);
  game->object=object_create(2);
  game->last_cmd = NO_CMD;
  
  return OK;
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

  if (game_create(game) == ERROR)
    return ERROR;

  if (game_load_spaces(game, filename) == ERROR)
    return ERROR;


  game_set_player_location(game, game_get_space_id_at(game, 0));
  game_set_object_location(game, game_get_space_id_at(game, 0));

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

  if(game->object!=NULL)object_destroy(game->object);
  if(game->player!=NULL)player_destroy(game->player);
        
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
STATUS game_set_object_location(Game* game, Id id) {
  
  
 if(object_set_id(game->object,id)==ERROR)
    return ERROR;

  return OK;
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

  return plauyer_get_location(game->player);
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos
Return:
  -Id: identificador de la localizacion del objeto
*/
Id game_get_object_location(Game* game) {
  return object_get_id(game->object);
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
  (*game_callback_fn_list[cmd])(game);
  return OK;
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
  if(object_print(game->object)==ERROR)return; 
  
  printf("prompt:> ");
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

void game_callback_unknown(Game* game) {
}

void game_callback_exit(Game* game) {
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos de realizar la acción de siguiente
*/
void game_callback_following(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  if (space_id == NO_ID) {
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID) {
	       game_set_player_location(game, current_id);
      }
      return;
    }
  }
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos de realizar la acción de atrás
*/
void game_callback_previous(Game* game) {
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;
  
  space_id = game_get_player_location(game);
  
  if (NO_ID == space_id) {
    return;
  }
  
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id) {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID) {
	       game_set_player_location(game, current_id);
      }
      return;
    }
  }
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos de realizar la acción de coger el objeto
*/
void game_callback_pick(Game *game){

  Id player_id=NO_ID;
  Id object_id=NO_ID;

  player_id = game_get_player_location(game);
  object_id = game_get_object_location(game);
 

  if(object_id == NO_ID || player_id==NO_ID)return;

  if(object_id==player_id){


    game_set_object_location(game,NO_ID);
    player_set_object(game->player,object_id);
    

  }
  return;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 04/10/2018
Parámetros:
  -game: juego sobre el que tratamos de realizar la acción de dejar el objeto
*/
void game_callback_drop(Game *game){

  Id player_id=NO_ID;
  Id object_id=NO_ID;

  player_id = game_get_player_location(game);
  object_id = game_get_player_object(game);
 

  if(object_id == NO_ID || player_id==NO_ID)return;

  
  game_set_object_location(game,player_id);
  player_set_object(game->player,NO_ID);

  
  return;
}

