
/* ===================================================================
File: game.c
Version: 3.0
Date: 21-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Contiene todas las funciones que perimiten crear un juego y actualizarlo
Revision historica:
13-01-2015 versión 1.0 (código inicial)
1-10-2018 versión 2.0
       Añadidas funciones para coger y soltar objetos y avanzar y retroceder de oca a oca. Además, se han
       modificado las funciones relativas a objetos y jugadores.
21-10-2018 versión 3.0
                Creadas nuevas funciones para imprimir objetos en la máquina gráfica y función para el comando roll.
                Se han modificado funciones como game_update
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "game.h"
#include "game_reader.h"

/** La estructura game almacena datos del juego como los espacios, el jugador, los objetos y el último comando**/
struct _Game {
    Player *player; /*Puntero a estructura jugador*/
    Object *object[MAX_OBJECT]; /*Punteros a estructura objeto*/
    Space* spaces[MAX_SPACES + 1]; /*Punteros a estructura espacio*/
    T_Command last_cmd; /*Último comando*/
    STATUS resultado_comando; /*El resultado de la ejecución del último comando*/
    Die *die; /*Dado*/
    char ultima_descripcion_pedida[WORD_SIZE];
    Link *link[MAX_LINK];
};



/**List of callbacks for each command in the game**/
STATUS game_callback_unknown(Game* game);
STATUS game_callback_exit(Game* game);
STATUS game_callback_following(Game* game);
STATUS game_callback_previous(Game* game);
STATUS game_callback_oca_following(Game* game);
STATUS game_callback_oca_previous(Game* game);
STATUS game_callback_take_object(Game* game, Comand *cmd);
STATUS game_callback_leave_object(Game* game, Comand *cmd);
STATUS game_callback_roll(Game* game);
STATUS game_callback_inspect(Game* game, Comand *cmd);
STATUS game_callback_go(Game *game, Comand *cmd);


/**Private functions*/

Id game_get_space_id_at(Game* game, int position);


/**Game interface implementation*/

/******************************************************************
 *Funcion :game_create
 *Date: 21-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que se encarga de crear el juego
 *Input: el nombre del jugador
 *Output: game o NULL
 ********************************************************************/

Game* game_create() {
    int i;
    Game* game = NULL;
    game = (Game*) calloc(1, sizeof (Game));
    if (game == NULL) return NULL;

    game->player = player_create();
    if (game->player == NULL){
      free(game);
     return NULL;
   }
    game->die = die_create();
    if (game->die == NULL){
      player_destroy(game->player);
      free(game);
       return NULL;
    }
    die_set_id(game->die, 1);
    game->resultado_comando = OK;
    game->last_cmd = NO_CMD;
    return game;
}

/******************************************************************
 *Funcion :game_create_from_file
 *Date: 21-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que crea un juego desde un fichero
 *Input: el nombre del fichero donde esta el tablero y el nombre del jugador
 *Output: game o NULL
 ********************************************************************/

Game* game_create_from_file(char* filename) {
    Game* game = NULL;
    game = game_create();
    if (game == NULL) return NULL;

    if (game_reader_load_spaces(game, filename) == ERROR){
		game_destroy(game);
		return NULL;
	}
    if (player_set_space_id(game->player, game_get_space_id_at(game, 0)) == ERROR) {
				game_destroy(game);
        return NULL;
    }
    if (game_reader_load_object(game, filename) == ERROR) {
				game_destroy(game);
        return NULL;
    }
	if (game_reader_load_links(game, filename) == ERROR) {
				game_destroy(game);
        return NULL;
    }
    if(game_reader_load_player(game, filename)==ERROR){
  				game_destroy(game);
          return NULL;
      }

    return game;
}

/******************************************************************
 *Funcion :game_destroy
 *Date: 21-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que se encarga de liberar la memoria de game
 *Input: Game game que va a ser liberado
 *Output: OK si todo funciona bien
 ********************************************************************/

STATUS game_destroy(Game* game) {
    int i = 0;
    if (!game) return ERROR;
    for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
        space_destroy(game->spaces[i]);
    }
    player_destroy(game->player);
    for (i = 0; (i < MAX_OBJECT) && (game->object[i] != NULL); i++) {
        object_destroy(game->object[i]);
    }
    die_destroy(game->die);
    for (i = 0; (i < MAX_LINK) && (game->link[i] != NULL); i++) {
        link_destroy(game->link[i]);
    }
    free(game);

    return OK;
}

/******************************************************************
 *Funcion :game_add_space
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que se encarga de añadir espacios
 *Input: Game donde se va a introducir el espacio y el espacio a añadir
 *Output: OK si todo funciona bien y ERROR si hay algun fallo.
 ********************************************************************/

STATUS game_add_space(Game* game, Space* space) {
    int i = 0;

    if (space == NULL) {
        return ERROR;
    }

    while ((i < MAX_SPACES) && (game->spaces[i] != NULL)) {
        i++;
    }

    if (i >= MAX_SPACES) {
        return ERROR;
    }

    game->spaces[i] = space;

    return OK;
}

/******************************************************************
 *Funcion :game_add_object
 *Date: 5-10-2018
 *Autores: Alvaro Becerra Jimenez
 *Description: Función que añade objetos a un juego
 *Input: Game donde se va a introducir el objeto y el objeto a añadir
 *Output: OK si todo funciona bien y ERROR si hay algún fallo.
 ********************************************************************/

STATUS game_add_object(Game* game, Object *object) {
    int i = 0;
    if (object == NULL) {
        return ERROR;
    }
    while ((i < MAX_OBJECT) && (game->object[i] != NULL)) {
        i++;
    }
    if (i >= MAX_OBJECT) {
        return ERROR;
    }
    game->object[i] = object;
    return OK;
}

STATUS game_add_link(Game* game, Link* link) {
    int i = 0;

    if (link == NULL) {
        return ERROR;
    }

    while ((i < MAX_LINK) && (game->link[i] != NULL)) {
        i++;
    }

    if (i >= MAX_LINK) {
        return ERROR;
    }

    game->link[i] = link;

    return OK;
}

/******************************************************************
 *Funcion :game_get_space_id_at
 *Date: ??
 *Autores: Código Inicial
 *Description: Función que se encarga de obtener el id de un espacio dada una posición
 *Input: Game y la posicion
 *Output: Id o no_id si hay algun fallo
 ********************************************************************/

Id game_get_space_id_at(Game* game, int position) {

    if (position < 0 || position >= MAX_SPACES) {
        return NO_ID;
    }

    return space_get_id(game->spaces[position]);
}

/******************************************************************
 *Funcion :game_get_space
 *Date: ??
 *Autores: Código inicial
 *Description: Función que se encarga buscar un espacio a través de su id
 *Input: Game y el id del espacio
 *Output: space o NULL si no existe tal espacio
 ********************************************************************/

Space* game_get_space(Game* game, Id id) {
    int i = 0;

    if (id == NO_ID) {
        return NULL;
    }
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        if (id == space_get_id(game->spaces[i])) {
            return game->spaces[i];
        }
    }
    return NULL;
}

/******************************************************************
 *Funcion :game_set_object_location
 *Date: 1-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que se encarga de establecer la localizacion de un objecto
 *Input: Game, id del espacio donde se debe colocar el objeto y id del objeto
 *Output: OK si todo funciona bien y ERROR si hay algun fallo.
 ********************************************************************/

STATUS game_set_object_location(Game* game, Id id, Id id_object) {
    if (id == NO_ID || id_object == NO_ID) {
        return ERROR;
    }
    return space_leave_object(game_get_space(game, id), id_object);
}

/******************************************************************
 *Funcion :game_get_player_location
 *Date: 1-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que se encarga de devolver la localizacion del jugador
 *Input: Game
 *Output: Id o NO_ID si no existe jugador
 ********************************************************************/

Id game_get_player_location(Game* game) {
    return player_get_space_id(game->player);
}

/******************************************************************
 *Funcion :game_get_object_location
 *Date: 1-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que se encarga de devolver el id del espacio donde se encuentra el objecto
 *Input: Game y id del objeto
 *Output: Id o NO_ID si no existe tal objeto
 ********************************************************************/

Id game_get_object_location(Game* game, Id id) {
    Id id_space = NO_ID;
    int i;
    if (id == NO_ID) return NO_ID;
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        if (space_is_object_in(game->spaces[i], id) == TRUE) {
            id_space = space_get_id(game->spaces[i]);
            break;
        }
    }
    return id_space;
}

/******************************************************************
 *Funcion :game_get_object_name
 *Date: 1-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que obtiene y devuelve el nombre de un objeto de juego
 *Input: Game y el Id del objeto
 *Output: char * nombre del objeto.
 ********************************************************************/

char *game_get_object_name(Game *game, Id id) {
    int i;
    for (i = 0; object_get_id(game->object[i]) != id; i++);
    return object_get_name(game->object[i]);
}

/******************************************************************
 *Funcion :game_get_player_name
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que obtiene y devuelve el nombre del jugador del juego
 *Input: Game
 *Output: char * nombre del objeto.
 ********************************************************************/

char *game_get_player_name(Game* game) {
    return player_get_name(game->player);
}

/******************************************************************
 *Funcion :game_cadena_objetos_localizacion
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que guerda en una cadena nombre_objeto:space_id donde se encuentra
 *Input: Game, cadena en la que se guarda
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_cadena_objetos_localizacion(Game *game, char* cadena) {
    char space_id_cadena[TAM];
    Id space_id;
    int i;
    if (!cadena) return ERROR;
    for (i = 0; i < MAX_OBJECT && game->object[i] != NULL; i++) {
        space_id = game_get_object_location(game, object_get_id(game->object[i]));
        if (space_id != NO_ID) {
            strcat(cadena, object_get_name(game->object[i]));
            strcat(cadena, ":");
            sprintf(space_id_cadena, "%ld", space_id);
            strcat(cadena, space_id_cadena);
            strcat(cadena, " ");
        }
    }
    return OK;
}

/******************************************************************
 *Funcion :game_cadena_objetos
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que guerda en una cadena los objetos de un espacio
 *Input: Game, espacio y cadena en la que se guarda
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_cadena_objetos(Game *game, Space* space, char *cadena) {
    int i, flag = 0;
    if (!space || !cadena) return ERROR;
    for (i = 0; i < MAX_OBJECT && game->object[i] != NULL; i++) {
        if (space_is_object_in(space, object_get_id(game->object[i])) == TRUE) {
            if (flag == 0) {
                strcat(cadena, object_get_name(game->object[i]));
                flag = 1;
            } else {
                strcat(cadena, ",");
                strcat(cadena, object_get_name(game->object[i]));
            }
        }
    }
    return OK;
}

STATUS game_cadena_objetos_jugador(Game *game, char *cadena) {
    int i, flag = 0;
    if (!cadena) return ERROR;
    for (i = 0; i < MAX_OBJECT && game->object[i] != NULL; i++) {
        if (player_has_object(game->player, object_get_id(game->object[i])) == TRUE) {
            if (flag == 0) {
                strcat(cadena, object_get_name(game->object[i]));
                flag = 1;
            } else {
                strcat(cadena, ",");
                strcat(cadena, object_get_name(game->object[i]));
            }
        }
    }
    return OK;
}

/******************************************************************
 *Funcion :game_get_player_objec
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que devuelve el id del objeto de un jugador
 *Input: Game
 *Output: el id
 ********************************************************************/

Id game_get_player_object(Game* game) {
    return player_get_object_id(game->player);
}

/******************************************************************
 *Funcion :game_get_player_objec
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que devuelve resultado de tirar un dado
 *Input: Game
 *Output: entero entre 1 y 6
 ********************************************************************/

int game_get_roll_die(Game *game) {
    return die_get_resultado_anterior(game->die);
}

/******************************************************************
 *Funcion :game_update
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que actualiza el juego
 *Input: Game y un puntero a comando
 *Output: OK
 ********************************************************************/

STATUS game_update(Game* game, Comand *comand) {
    game->last_cmd = comand_get_comand(comand);
    switch (comand_get_comand(comand)) {
        case UNKNOWN:
            game->resultado_comando = game_callback_unknown(game);
            return game->resultado_comando;
        case QUIT:
            game->resultado_comando = game_callback_exit(game);
            return game->resultado_comando;
        case FOLLOWING:
            game->resultado_comando = game_callback_following(game);
            return game->resultado_comando;
        case PREVIOUS:
            game->resultado_comando = game_callback_previous(game);
            return game->resultado_comando;
        case OCA_FOLLOWING:
            game->resultado_comando = game_callback_oca_following(game);
            return game->resultado_comando;
        case OCA_PREVIOUS:
            game->resultado_comando = game_callback_oca_previous(game);
            return game->resultado_comando;
        case TAKE:
            game->resultado_comando = game_callback_take_object(game, comand);
            return game->resultado_comando;
        case LEAVE:
            game->resultado_comando = game_callback_leave_object(game, comand);
            return game->resultado_comando;
        case ROLL:
            game->resultado_comando = game_callback_roll(game);
            return game->resultado_comando;
	           case INSPECT:
	            game->resultado_comando= game_callback_inspect(game, comand);
	             return game->resultado_comando;
          case GO:
          game->resultado_comando= game_callback_go(game, comand);
		  return game->resultado_comando;
        case NO_CMD:
            game->resultado_comando = OK;
            break;
        default:
            return ERROR;
    }
    return OK;
}

/******************************************************************
 *Funcion :game_get_last_command
 *Date: ??
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que devuelve el resultado de la ejecución del último comando
 *Input: Game
 *Output: OK o ERROR
 ********************************************************************/

T_Command game_get_last_command(Game* game) {
    return game->last_cmd;
}

/******************************************************************
 *Funcion :game_get_resultado_last_command
 *Date: 13-10-2018
 *Autores: Código inicial
 *Description: Función que devuelve el último comando
 *Input: Game
 *Output: devuelve el ultimo comando del juego
 ********************************************************************/

STATUS game_get_resultado_last_command(Game* game) {
    return game->resultado_comando;
}

/******************************************************************
 *Funcion :game_print_data
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que escribe los datos de un juego. Se ha modificado para que incluya todos los objetos
 *Input: Game
 *Output: no devuelve nada.
 ********************************************************************/

void game_print_data(Game* game) {
    int i = 0;

    printf("\n\n-------------\n\n");

    printf("=> Spaces: \n");
    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        space_print(game->spaces[i]);
    }
    for (i = 0; i < MAX_OBJECT && game->object[i] != NULL; i++) {
        printf("=> Object location: %d\n", (int) game_get_object_location(game, object_get_id(game->object[i])));
    }

    printf("=> Player location: %d\n", (int) game_get_player_location(game));
    die_print(stdout, game->die);
    printf("prompt:> ");
    return;
}

/******************************************************************
 *Funcion :game_is_over
 *Date: ??
 *Autores: Código inicial
 *Description: Funcion que nos indica si el juego ha acabado
 *Input: Game
 *Output: False
 ********************************************************************/

BOOL game_is_over(Game* game) {
    return FALSE;
}

/**Callbacks implementation for each action */

/******************************************************************
 *Funcion:game_callback_unknown
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que no hace nada porque no se ha entendido el comando
 *Input: Game
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_callback_unknown(Game* game) {
    return OK;
}

/******************************************************************
 *Funcion:game_callback_exit
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que no hace nada y es llamada si el jugador quiere salir
 *Input: Game
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_callback_exit(Game* game) {
    return OK;
}

/******************************************************************
 *Funcion:game_callback_following
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que permite ir hacia adelante
 *Input: Game
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_callback_following(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Id link_id= NO_ID;

    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
        return ERROR;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        current_id = space_get_id(game->spaces[i]);
        if (current_id == space_id) {
          link_id = space_get_south(game->spaces[i]);
         if (link_id == NO_ID) return ERROR;
     for (i = 0; i < MAX_LINK && game->link[i] != NULL; i++) {
       if (link_get_id(game->link[i])==link_id) break;
     }
     if (i>=MAX_LINK) return ERROR;
     if (game->link[i]==NULL) return ERROR;
     if (link_get_status(game->link[i])==FALSE) return ERROR;
          current_id = link_get_conection_1(game->link[i]);
             if (current_id != NO_ID && current_id!=space_id) {
                 player_set_space_id(game->player, current_id);
                 return OK;
             }
             current_id = link_get_conection_2(game->link[i]);
             if (current_id != NO_ID) {
                 player_set_space_id(game->player, current_id);
                 return OK;
             }
        }
    }
    return ERROR;
}

/******************************************************************
 *Funcion:game_callback_previous
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que permite ir hacia atrás
 *Input: Game
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_callback_previous(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Id link_id= NO_ID;
    space_id = game_get_player_location(game);

    if (NO_ID == space_id) {
        return ERROR;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        current_id = space_get_id(game->spaces[i]);
        if (current_id == space_id) {
          link_id = space_get_north(game->spaces[i]);
         if (link_id == NO_ID) return ERROR;
     for (i = 0; i < MAX_LINK && game->link[i] != NULL; i++) {
       if (link_get_id(game->link[i])==link_id) break;
     }
     if (i>=MAX_LINK) return ERROR;
     if (game->link[i]==NULL) return ERROR;
     if (link_get_status(game->link[i])==FALSE) return ERROR;
          current_id = link_get_conection_1(game->link[i]);
             if (current_id != NO_ID && current_id!=space_id) {
                 player_set_space_id(game->player, current_id);
                 return OK;
             }
             current_id = link_get_conection_2(game->link[i]);
             if (current_id != NO_ID) {
                 player_set_space_id(game->player, current_id);
                 return OK;
             }
        }
    }
    return ERROR;
}

/******************************************************************
 *Funcion:game_callback_oca_following
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que permite ir de oca a oca
 *Input: Game
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_callback_oca_following(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Id link_id= NO_ID;

    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
        return ERROR;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        current_id = space_get_id(game->spaces[i]);
        if (current_id == space_id) {
          link_id = space_get_east(game->spaces[i]);
         if (link_id == NO_ID) return ERROR;
     for (i = 0; i < MAX_LINK && game->link[i] != NULL; i++) {
       if (link_get_id(game->link[i])==link_id) break;
     }
     if (i>=MAX_LINK) return ERROR;
     if (game->link[i]==NULL) return ERROR;
     if (link_get_status(game->link[i])==FALSE) return ERROR;
          current_id = link_get_conection_1(game->link[i]);
             if (current_id != NO_ID && current_id!=space_id) {
                 player_set_space_id(game->player, current_id);
                 return OK;
             }
             current_id = link_get_conection_2(game->link[i]);
             if (current_id != NO_ID) {
                 player_set_space_id(game->player, current_id);
                 return OK;
             }
        }
    }
    return ERROR;
}

/******************************************************************
 *Funcion:game_callback_oca_previous
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que permite ir de oca a oca hacia atrás
 *Input: Game
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_callback_oca_previous(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Id link_id= NO_ID;

    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
        return ERROR;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        current_id = space_get_id(game->spaces[i]);
        if (current_id == space_id) {
         link_id = space_get_west(game->spaces[i]);
        if (link_id == NO_ID) return ERROR;
    for (i = 0; i < MAX_LINK && game->link[i] != NULL; i++) {
      if (link_get_id(game->link[i])==link_id) break;
    }
    if (i>=MAX_LINK) return ERROR;
    if (game->link[i]==NULL) return ERROR;
    if (link_get_status(game->link[i])==FALSE) return ERROR;
         current_id = link_get_conection_1(game->link[i]);
            if (current_id != NO_ID && current_id!=space_id) {
                player_set_space_id(game->player, current_id);
                return OK;
            }
            current_id = link_get_conection_2(game->link[i]);
            if (current_id != NO_ID) {
                player_set_space_id(game->player, current_id);
                return OK;
            }
            }
        }

    return ERROR;
}

/******************************************************************
 *Funcion:game_callback_take_object
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que permite dejar un objeto
 *Input: Game
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_callback_take_object(Game* game, Comand *cmd) {
    Id space_id=NO_ID, object_id=NO_ID;
    char object_name[WORD_SIZE];
    int i;
    if (cmd==NULL) return ERROR;
    if (player_bag_is_full(game->player)==TRUE) return ERROR;
    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
        return ERROR;
    }
    strcpy(object_name, comand_get_name(cmd));
    for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), object_name) != 0 && i < MAX_OBJECT; i++);
    if (i > MAX_OBJECT) return ERROR;
    if (game->object[i] == NULL) return ERROR;
    object_id = object_get_id(game->object[i]);
    if (object_id == NO_ID) return ERROR;
        if (space_take_object(game_get_space(game, space_id), object_id) == ERROR) return ERROR;
        if (player_pick_object(game->player, object_id)==ERROR) return ERROR;
        return OK;

}

/******************************************************************
 *Funcion:game_callback_leave_object
 *Date: 26-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que permite dejar un objeto
 *Input: Game
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_callback_leave_object(Game* game, Comand *cmd) {
    Id space_id=NO_ID, object_id=NO_ID;
	int i;
    char object_name[WORD_SIZE];
    if(cmd==NULL) return ERROR;
    strcpy(object_name, comand_get_name(cmd));
    space_id = game_get_player_location(game);
    for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), object_name) != 0 && i < MAX_OBJECT; i++);
    if (i > MAX_OBJECT) return ERROR;
    if (game->object[i] == NULL) return ERROR;
    object_id = object_get_id(game->object[i]);
    if (object_id == NO_ID) return ERROR;
	if (player_has_object(game->player, object_id)==FALSE) return ERROR;
    if ((space_leave_object(game_get_space(game, space_id), object_id)) == ERROR) return ERROR;
    if (player_drop_object(game->player, object id)==ERROR) return ERROR;
    return OK;
}

/******************************************************************
 *Funcion:game_callback_roll
 *Date: 5-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Funcion que permite tirar el dado
 *Input: Game
 *Output: OK o ERROR
 ********************************************************************/

STATUS game_callback_roll(Game* game) {
    if (roll_die(game->die) < 1) return ERROR;
    return OK;
}

STATUS game_callback_inspect(Game* game, Comand *cmd){
char name[WORD_SIZE]="";
int i;
if (cmd==NULL) return ERROR;
strcpy(name, comand_get_name(cmd));
if (strcasecmp(name, "s")==0 || strcasecmp(name, "space")==0){
strcpy (game->ultima_descripcion_pedida, space_get_description(game_get_space(game, game_get_player_location(game))));
return OK;
}
for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), name) != 0 && i < MAX_OBJECT; i++);
if (i > MAX_OBJECT) return ERROR;
if (game->object[i] == NULL) return ERROR;
if (space_is_object_in(game_get_space(game_get_player_location(game->player))), game->object[i]==FALSE && player_has_object(game->player, object_get_id(game->object[i]))==FALSE){
  return ERROR;
}
strcpy (game->ultima_descripcion_pedida, object_get_description(game->object[i]));
return OK;
}

char *game_get_ultima_descripcion(Game *game){
	if(!game) return NULL;
	return game->ultima_descripcion_pedida;
}

STATUS game_callback_go(Game *game, Comand *cmd){
char direction_move[WORD_SIZE]="";
if (cmd==NULL) return ERROR;
strcpy(direction_move, comand_get_name(cmd));
if (strcasecmp(direction_move, "n")==0 || strcasecmp(direction_move, "north")==0){
  return game_callback_previous(game);
}
if (strcasecmp(direction_move, "s")==0 || strcasecmp(direction_move, "south")==0){
  return game_callback_following(game);
}
if (strcasecmp(direction_move, "w")==0 || strcasecmp(direction_move, "west")==0){
  return game_callback_oca_previous(game);
}
if (strcasecmp(direction_move, "e")==0 || strcasecmp(direction_move, "east")==0){
  return game_callback_oca_following(game);
}
return ERROR;
}
Link *game_get_link(Game *game, Id link_id){
	int i = 0;
    if (link_id == NO_ID) {
        return NULL;
    }
    for (i = 0; i < MAX_LINK && game->link[i] != NULL; i++) {
        if (link_id == link_get_id(game->link[i])) {
            return game->link[i];
        }
    }
    return NULL;
}

Id game_get_id_conected_space(Game *game, Id link_id, Id space_id){
	Link *link=NULL;
	link=game_get_link(game, link_id);
	if (link==NULL) return NO_ID;
	if (link_get_conection_1(link)==space_id){
		return link_get_conection_2(link);
	} else return link_get_conection_1(link);
}
