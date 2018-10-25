#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
  Id id_act = NO_ID,  id_next = NO_ID, obj1_loc = NO_ID, obj2_loc = NO_ID, obj3_loc = NO_ID, obj4_loc = NO_ID;
  Space* space_act = NULL;
  char obj1_name[MAX_OBJ],obj2_name[MAX_OBJ],obj3_name[MAX_OBJ],obj4_name[MAX_OBJ];
  char obj1[MAX_OBJ], obj2[MAX_OBJ], obj3[MAX_OBJ], obj4[MAX_OBJ];
  char ** desc;
  char str[255];
  T_Command last_cmd = UNKNOWN;
  extern char *cmd_to_str[];


  /* Paint the in the map area */
  screen_area_clear(ge->map);
  if ((id_act = game_get_player_location(game)) != NO_ID){
    space_act = game_get_space(game, id_act);
    id_next = space_get_south(space_act);








    strcpy(obj1_name,object_get_name(game_get_object(game,1)));


    strcpy(obj2_name,object_get_name(game_get_object(game,2)));
    strcpy(obj3_name,object_get_name(game_get_object(game,3)));
    strcpy(obj4_name,object_get_name(game_get_object(game,4)));


    obj1_loc = game_get_object_location(game,1);
    obj2_loc = game_get_object_location(game,2);
    obj3_loc = game_get_object_location(game,3);
    obj4_loc = game_get_object_location(game,4);



    if (obj1_loc == id_act)
      strcpy(obj1,obj1_name);
    else
      strcpy(obj1," ");

    if (obj2_loc == id_act)
      strcpy(obj2,obj2_name);
    else
      strcpy(obj2," ");

    if (obj3_loc == id_act)
      strcpy(obj3,obj3_name);
    else
      strcpy(obj3," ");

    if (obj4_loc == id_act)
      strcpy(obj4,obj4_name);
    else
      strcpy(obj4," ");










    if (id_act != NO_ID) {


      if (id_act != NO_ID) {
        desc = space_get_gdesc(game_get_space(game,id_act));
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  | 8D      %2d|",(int) id_act);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s    |",desc[0]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s    |",desc[1]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s    |",desc[2]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s %s %s %s|",obj1, obj2, obj3, obj4);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
      }
      auxi = 0;
     /* for(i = 0; i < MAX_OBJECTS;++i){
        if (game_get_object_location(game, object_get_id(game_get_object(game, i))) == id_back){
          auxi++;
          auxili[i] = object_get_id(game_get_object(game, i));
        }
      }*/
      if (id_next != NO_ID) {
        desc = space_get_gdesc(game_get_space(game,id_next));
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
        sprintf(str, "  | 8D      %2d|",(int) id_next);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s    |",desc[0]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s    |",desc[1]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s    |",desc[2]);
        screen_area_puts(ge->map, str);
        sprintf(str, "  |%s %s %s %s|",obj1, obj2, obj3, obj4);
        screen_area_puts(ge->map, str);
        sprintf(str, "  +-----------+");
        screen_area_puts(ge->map, str);
      }
    }

  /* Paint the in the description area */
    screen_area_clear(ge->descript);
/*
if ((obj_loc = game_get_object_location(game)) != NO_ID){
  sprintf(str, "  Object location:%d", (int)obj_loc);
  screen_area_puts(ge->descript, str);
}

*/

    sprintf(str,"La última tirada es: %d",game_get_last_roll(game));


  }
  /* Paint the in the banner area */
  screen_area_puts(ge->banner, " The game of the Goose ");

  /* Paint the in the help area */
  screen_area_clear(ge->help);
  sprintf(str, " The commands you can use are:");
  screen_area_puts(ge->help, str);
  sprintf(str, "     following or f, previous or p, pick or c, drop or d,left or l, right or r, grab or g,roll or t, or exit or e");
  screen_area_puts(ge->help, str);

  /* Paint the in the feedback area */
  last_cmd = game_get_last_command(game);
  sprintf(str, " %s", cmd_to_str[last_cmd-NO_CMD]);
  screen_area_puts(ge->feedback, str);

  /* Dump to the terminal */
  screen_paint();
  printf("prompt:> ");
}
