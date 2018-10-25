 /**
 * @brief It defines the game loop
 *
 * @file game_loop.c
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphic_engine.h"

int main(int argc, char *argv[]){
  Game* game;
  BOOL regis, aux;
  FILE* f;
  T_Command command = NO_CMD;
  Graphic_engine *gengine;
  if (argc < 2 || argc == 3 || argc > 4 || (argc == 4 && (strcmp(argv[2],"-l")!= 0))){
    fprintf(stderr, "Use: %s <game_data_file> [-l <log_file>] \n", argv[0]);
    return 1;
  }
  if(argc == 4)
    regis = TRUE;
  else
    regis = FALSE;

  if(regis)
    f = fopen(argv[3], "w");

  game=game_create();
  if(game==NULL)return 1;

  if (game_create_from_file(game, argv[1]) == ERROR){
    fprintf(stderr, "Error while initializing game.\n");
    return 1;
  }
  if ((gengine = graphic_engine_create()) == NULL){

    fprintf(stderr, "Error while initializing graphic engine.\n");
    game_destroy(game);
    return 1;
  }
  game_print_data(game);
  while ( (command != EXIT) && !game_is_over(game) ){
   graphic_engine_paint_game(gengine, game);
   command = command_get_user_input();
   aux = game_update(game, command);

   if(regis){
      if (aux)
        fprintf(f, "%s: OK\n",cmd_to_str[command + 1]);
      else
        fprintf(f, "%s: ERROR\n",cmd_to_str[command + 1]);
   }

  }
 game_destroy(game);
 graphic_engine_destroy(gengine);
 if(regis)
    fclose(f);
 return 0;
}
