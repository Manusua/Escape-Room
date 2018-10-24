#include <stdlib.h>
#include <stdio.h>
#include "screen.h"
#include "graphic_engine.h"

struct _Graphic_engine{
  Area *map, *descript, *banner, *help, *feedback;
};

Graphic_engine *graphic_engine_create(){
  static Graphic_engine *ge = NULL;

  if (ge)
    return ge;

  screen_init();
  ge = (Graphic_engine *) malloc(sizeof(Graphic_engine));

  ge->map      = screen_area_init( 1, 1, 48, 13);
  ge->descript = screen_area_init(50, 1, 29, 13);
  ge->banner   = screen_area_init(28,15, 23,  1);
  ge->help     = screen_area_init( 1,16, 78,  2);
  ge->feedback = screen_area_init( 1,19, 78,  3);

  return ge;

}

void graphic_engine_destroy(Graphic_engine *ge){
  if (!ge)
    return;

  screen_area_destroy(ge->map);
  screen_area_destroy(ge->descript);
  screen_area_destroy(ge->banner);
  screen_area_destroy(ge->help);
  screen_area_destroy(ge->feedback);

  screen_destroy();
  free(ge);
}

void graphic_engine_paint_game(Graphic_engine *ge, Game *game){
  int i, auxi = 0;
  Id auxili[MAX_OBJECTS];
  Id id_act = NO_ID, id_back = NO_ID, id_next = NO_ID, obj_loc = NO_ID;
  Space* space_act = NULL;
  char* aux[NUM_STRINGS];
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[];


  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID){
    space_act = game_get_space(game, id_act);
    id_back = space_get_north(space_act);
    id_next = space_get_south(space_act);
    for(i = 0; i < MAX_OBJECTS;++i){
      if (game_get_object_location(game, object_get_id(game_get_object(game, i))) == id_back){
        auxi++;
        auxili[i] = object_get_id(game_get_object(game, i));
      }
    }
    if (id_back != NO_ID) {
      sprintf(str, "  |         %2d|",(int) id_back);
      screen_area_puts(ge->map, str);
      switch (auxi) {
        case 0: sprintf(str, "  |           |"); break;
        case 1: sprintf(str, "  |     %ld     |",auxili[0]); break;
        case 2:sprintf(str, "  |   %ld   %ld   |",auxili[0], auxili[1]); break;
        case 3:sprintf(str, "  |  %ld  %ld %ld    |",auxili[0], auxili[1], auxili[2]); break;
        case 4:sprintf(str, "  | %ld %ld %ld %ld   |",auxili[0], auxili[1], auxili[2], auxili[3]); break;
      }
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "        ^");
      screen_area_puts(ge->map, str);
    }
    auxi = 0;
    for(i = 0; i < MAX_OBJECTS;++i){
      if (game_get_object_location(game, object_get_id(game_get_object(game, i))) == id_back){
        auxi++;
        auxili[i] = object_get_id(game_get_object(game, i));
      }
    }
    if (id_act != NO_ID) {
      space_get_gdesc(space_act, aux);
      sprintf(str, "  +-----------+");
      sprintf(str, "  | 8D      %2d|",(int) id_act);
      for(i = 0; i < NUM_STRINGS; ++i){
        sprintf(str, "  |%s|", aux[i]);
      }
      switch (auxi) {
        case 0: sprintf(str, "  |           |"); break;
        case 1: sprintf(str, "  |     %ld     |",auxili[0]); break;
        case 2:sprintf(str, "  |   %ld   %ld   |",auxili[0], auxili[1]); break;
        case 3:sprintf(str, "  |  %ld  %ld %ld    |",auxili[0], auxili[1], auxili[2]); break;
        case 4:sprintf(str, "  | %ld %ld %ld %ld   |",auxili[0], auxili[1], auxili[2], auxili[3]); break;
      }
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
    }
    auxi = 0;
    for(i = 0; i < MAX_OBJECTS;++i){
      if (game_get_object_location(game, object_get_id(game_get_object(game, i))) == id_back){
        auxi++;
        auxili[i] = object_get_id(game_get_object(game, i));
      }
    }
    if (id_next != NO_ID) {
      sprintf(str, "        v");
      screen_area_puts(ge->map, str);
      sprintf(str, "  +-----------+");
      screen_area_puts(ge->map, str);
      sprintf(str, "  |         %2d|",(int) id_next);
      screen_area_puts(ge->map, str);
      switch (auxi) {
        case 0: sprintf(str, "  |           |"); break;
        case 1: sprintf(str, "  |     %ld     |",auxili[0]); break;
        case 2:sprintf(str, "  |   %ld   %ld   |",auxili[0], auxili[1]); break;
        case 3:sprintf(str, "  |  %ld  %ld %ld    |",auxili[0], auxili[1], auxili[2]); break;
        case 4:sprintf(str, "  | %ld %ld %ld %ld   |",auxili[0], auxili[1], auxili[2], auxili[3]); break;
      }
      screen_area_puts(ge->map, str);
    }
  }

  /* Paint the in the description area */
  screen_area_clear(ge->descript);
/*TODO ESTO LO HE PUESTO ENTRE PARENTESIS PAR AQUE NO PARENTESIS
if ((obj_loc = game_get_object_location(game)) != NO_ID){
  sprintf(str, "  Object location:%d", (int)obj_loc);
  screen_area_puts(ge->descript, str);
}

*/

  /* Paint the in the banner area */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Paint the in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     following or f, previous or p, pick or c, drop or d, or exit or e");
  screen_area_puts(ge->help, str);

  /* Paint the in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s", cmd_to_str[last_cmd-NO_CMD]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
