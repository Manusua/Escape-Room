
/* ===================================================================
File: game.h
Version: 3.0
Date: 21-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Contiene todos los prototipos de las funciones de game públicas, así como la estructura de game
Revision historica:
13-01-2015 versión 1.0 (código inicial)
1-10-2018 versión 2.0
      Añadidas funciones para coger y soltar objetos y avanzar y retroceder de oca a oca. Además, se ha
      modificado la estructura para incluir punteros a objeto y a jugador.
21-10-2018 versión 3.0
                Creadas nuevas funciones para imprimir objetos en la máquina gráfica y función para el comando roll.
                Se han modificado funciones como game_update
=================================================================== */

#ifndef GAME_H
#define GAME_H

#include "space.h"
#include "command.h"
#include "object.h"
#include "player.h"
#include "die.h"
#include "link.h"
#define MAX_OBJECT 100
#define MAX_LINK 4*MAX_SPACES


typedef struct _Game Game;

/*Funciones para crear, actualizar y destruir un juego*/
Game* game_create();
Game* game_create_from_file(char* filename);
STATUS game_update(Game* game, Comand* comand);
STATUS game_destroy(Game* game);
BOOL game_is_over(Game* game);

/*Función para añadir un espacio o un objeto a un juego*/
STATUS game_add_space(Game* game, Space* space);
STATUS game_add_object(Game* game, Object *object);
STATUS game_add_link(Game* game, Link *link);
STATUS game_add_player(Game* game, Player *player);

/*Funciones para imprimir pantalla y los datos de un juego*/
void game_print_screen(Game* game);
void game_print_data(Game* game);

/*Funcion para establecer la localizacion de un objeto*/
STATUS game_set_object_location(Game* game, Id id, Id id_object);

/*Funciones para obtener datos de un juego*/
int game_get_roll_die(Game *game);
STATUS game_cadena_objetos_localizacion(Game *game, char* cadena);
STATUS game_cadena_objetos(Game *game, Space* space, char *cadena);
STATUS game_cadena_objetos_jugador(Game *game, char *cadena);
Id game_get_player_object(Game* game);
char *game_get_player_name(Game* game);
Space* game_get_space(Game* game, Id id);
Id game_get_player_location(Game* game);
Id game_get_object_location(Game* game, Id id);
char *game_get_object_name(Game *game, Id id);
T_Command game_get_last_command(Game* game);
STATUS game_get_resultado_last_command(Game* game);
Id game_get_id_conected_space(Game *game, Id link_id, Id space_id);
Link *game_get_link(Game *game, Id link_id);
char *game_get_ultima_descripcion(Game *game);
#endif
