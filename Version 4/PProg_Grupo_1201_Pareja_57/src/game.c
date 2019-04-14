/**
 * @brief En este fichero definimos las funciones para el juego
 * @file game.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 3.0
 * @date 21/10/2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "game.h"
#include "game_management.h"

struct _Game {
    Player *player; /*!<Puntero a estructura jugador*/
    Object *object[MAX_OBJECT]; /*!<Punteros a estructura objeto*/
    Space* spaces[MAX_SPACES + 1]; /*!<Punteros a estructura espacio*/
    T_Command last_cmd; /*!<Último commando*/
    STATUS result_command; /*!<El resultado de la ejecución del último commando*/
    T_Command prev_cmd; /*!<Commando Previo*/
    STATUS result_prev_command; /*!<El resultado de la ejecución del commando anterior*/
    Die *die; /*!<Dado*/
    char last_description_asked[WORD_SIZE]; /*!<Última descripcion*/
    char dialogue[WORD_SIZE]; /*!<diálogo*/
    Link *link[MAX_LINK]; /*!<Puntero a estructura link*/
}; /*!<Estructura del juego */

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_unknown(Game* game);

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_exit(Game* game);

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_following(Game* game);

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_previous(Game* game);

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_oca_following(Game* game);

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_oca_previous(Game* game);

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando del objeto)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_take_object(Game* game, Command *cmd);

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando del objeto)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_leave_object(Game* game, Command *cmd);

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_roll(Game* game);

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando del objeto)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_inspect(Game* game, Command *cmd);

/**
 * @brief devuelve el estado tras usar el comando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando del objeto)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_go(Game *game, Command *cmd);

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_turnon(Game* game, Command *cmd);

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introdu#include "game_management.h"
cido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_turnoff(Game* game, Command *cmd);

/**
 * @brief abre el espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_open(Game* game, Command *cmd);

/**
 * @brief carga el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_load(Game* game, Command *cmd);


/**
 * @brief carga el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_save(Game* game, Command *cmd);
/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 17/12/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_down(Game* game);
/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 17/12/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_up(Game* game);
/**
 * @brief devuelve el id del espacio de esa posicion
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param position (posicion del espacio)
 * @return Id (Del espacio de la posicion dada)
 */

Id game_get_space_id_at(Game* game, int position);

/**
 * @brief crea un juego vacio sin jugadores ni objetos
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @return Game (el juego que hemos creado)
 */
Game* game_create() {
    Game* game = NULL;
    game = (Game*) calloc(1, sizeof (Game));
    if (game == NULL) return NULL;
    game->die = die_create();
    if (game->die == NULL) {
        free(game);
        return NULL;
    }
    die_set_id(game->die, 1);
    game->result_command = OK;
    game->last_cmd = NO_CMD;
    return game;
}

/**
 * @brief crea un juego cargando del archivo los espacios, los jugadores, los objetos
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param filename (El nombre del archivo del que cargamos los datos)
 * @return Game (el juego que hemos creado)
 */
Game* game_create_from_file(char* filename) {
    Game* game = NULL;
    game = game_create();
    if (game == NULL) return NULL;

    if (game_management_load_spaces(game, filename) == ERROR) {
        game_destroy(game);
        return NULL;
    }
    if (game_management_load_object(game, filename) == ERROR) {
        game_destroy(game);
        return NULL;
    }
    if (game_management_load_links(game, filename) == ERROR) {
        game_destroy(game);
        return NULL;
    }
    if (game_management_load_players(game, filename) == ERROR) {
        game_destroy(game);
        return NULL;
    }

    return game;
}

/**
 * @brief destruye el juego y libera la memoria
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a destruir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
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

/**
 * @brief destruye el juego para poder cargar otro
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 18/12/2018
 * @param game (El juego que vamos a destruir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_destroy_for_load(Game* game) {
    int i = 0;
    if (!game) return ERROR;
    for (i = 0; (i < MAX_SPACES) && (game->spaces[i] != NULL); i++) {
        space_destroy(game->spaces[i]);
        game->spaces[i] = NULL;
    }
    player_destroy(game->player);
    game->player = NULL;
    for (i = 0; (i < MAX_OBJECT) && (game->object[i] != NULL); i++) {
        object_destroy(game->object[i]);
        game->object[i] = NULL;
    }
    for (i = 0; (i < MAX_LINK) && (game->link[i] != NULL); i++) {
        link_destroy(game->link[i]);
        game->link[i] = NULL;
    }

    return OK;
}

/**
 * @brief En este caso devuelve FALSE siempre
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return BOOL
 */
BOOL game_is_over(Game* game) {
    if (!game->player) {
        printf("Tu personaje se ha vuelto loco y se ha suicidado. Has perdido.\n");
        return TRUE;
    }
    if (strcasecmp(space_get_name(game_get_space(game, game_get_player_location(game))), "Salida") == 0) {
        printf("Has logrado salir de la casa. Has ganado.\n");
        return TRUE;
    }
    return FALSE;
}

/**
 * @brief añade un espacio al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego al que vamos a añadir)
 * @param space (Lo que vamos a añadir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
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

/**
 * @brief añade un objeto al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego al que vamos a añadir)
 * @param object (Lo que vamos a añadir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
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

/**
 * @brief añade un link al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego al que vamos a añadir)
 * @param link (Lo que vamos a añadir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
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

/**
 * @brief añade un jugador al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego al que vamos a añadir)
 * @param player (Lo que vamos a añadir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_add_player(Game* game, Player* player) {

    if (player == NULL)
        return ERROR;

    /*Solo permitimos que haya un jugador, si intentamos añadir cuando ya hay uno, provocamos error*/
    if (game->player != NULL) {
        player_destroy(player);
        return ERROR;
    }
    game->player = player;

    return OK;
}

/**
 * @brief devuelve el id del espacio de esa posicion
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param position (posicion del espacio)
 * @return Id (Del espacio de la posicion dada)
 */
Id game_get_space_id_at(Game* game, int position) {

    if (position < 0 || position >= MAX_SPACES) {
        return NO_ID;
    }

    return space_get_id(game->spaces[position]);
}

/**
 * @brief devuelve el id de la posicion del jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param id (id del espacio)
 * @return Id (La posicion del jugador)
 */
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

/**
 * @brief modifica la posicion de un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego al que vamos a añadir)
 * @param id (id nuevo que queremos asignar)
 * @param id_object (id del objeto que queremos modificar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */

STATUS game_set_object_location(Game* game, Id id, Id id_object) {
    if (id == NO_ID || id_object == NO_ID) {
        return ERROR;
    }
    return space_leave_object(game_get_space(game, id), id_object);
}

/**
 * @brief devuelve el id de la posicion del jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return Id (La posicion del jugador)
 */
Id game_get_player_location(Game* game) {
    return player_get_space_id(game->player);
}

/**
 * @brief devuelve el id de la posicion del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param id (El id del objeto)
 * @return Id (La posicion del objeto)
 */
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

/**
 * @brief devuelve el nombre del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param id (El id del objeto)
 * @return char* (El nombre del objeto)
 */
char *game_get_object_name(Game *game, Id id) {
    int i;
    for (i = 0; object_get_id(game->object[i]) != id; i++);
    return object_get_name(game->object[i]);
}

/**
 * @brief devuelve el nombre de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return char* (El nombre del jugador)
 */
char *game_get_player_name(Game* game) {
    return player_get_name(game->player);
}

/**
 * @brief pasa una cadena de objetos al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cadena (cadena de objetos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_string_objects_localization(Game *game, char* cadena) {
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

/**
 * @brief pasa una cadena de objetos al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param space (El espacio de los objetos)
 * @param cadena (cadena de objetos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_string_objects(Game *game, Space* space, char *cadena) {
    int i, flag = 0;
    if (!space || !cadena) return ERROR;
    for (i = 0; i < MAX_OBJECT && game->object[i] != NULL; i++) {
        if (space_is_object_in(space, object_get_id(game->object[i])) == TRUE && object_get_hidden(game->object[i]) == FALSE) {
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

/**
 * @brief pasa una cadena de objetos del jugador al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cadena (cadena de objetos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_string_objects_player(Game *game, char *cadena) {
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

/**
 * @brief tira el dado del juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que estamos usando)
 * @return int (El valor de la tirada)
 */
int game_get_roll_die(Game *game) {
    return die_get_last_roll(game->die);
}

/**
 * @brief actualiza el juego tras pasarle el commando introducido
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a actualizar)
 * @param command (El commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_update(Game* game, Command *command) {
    game->prev_cmd = game->last_cmd;
    game->result_prev_command = game->result_command;
    game->last_cmd = command_get_command(command);
    memset(game->dialogue, '\0', WORD_SIZE);
    switch (command_get_command(command)) {
        case UNKNOWN:
            game->result_command = game_callback_unknown(game);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case QUIT:
            game->result_command = game_callback_exit(game);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case FOLLOWING:
            game->result_command = game_callback_following(game);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case PREVIOUS:
            game->result_command = game_callback_previous(game);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case GOOSE_FOLLOWING:
            game->result_command = game_callback_oca_following(game);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case GOOSE_PREVIOUS:
            game->result_command = game_callback_oca_previous(game);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case TAKE:
            game->result_command = game_callback_take_object(game, command);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case LEAVE:
            game->result_command = game_callback_leave_object(game, command);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case ROLL:
            game->result_command = game_callback_roll(game);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case INSPECT:
            game->result_command = game_callback_inspect(game, command);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case GO:
            game->result_command = game_callback_go(game, command);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case TURNON:
            game->result_command = game_callback_turnon(game, command);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case TURNOFF:
            game->result_command = game_callback_turnoff(game, command);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case OPEN:
            game->result_command = game_callback_open(game, command);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case SAVE:
            game->result_command = game_callback_save(game, command);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case LOAD:
            game->result_command = game_callback_load(game, command);
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            return game->result_command;
        case NO_CMD:
            game->result_command = OK;
            dialogue_action(command, game->prev_cmd, game->result_prev_command, game->result_command, game->dialogue);
            break;
        default:
            return ERROR;
    }
    return OK;
}

/**
 * @brief Para saber si la mochila del jugador está llena
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 16/12/2018
 * @param game (El juego que vamos a usar)
 * @return bool
 */
BOOL game_player_bag_is_full(Game* game) {
    return player_bag_is_full(game->player);
}

/**
 * @brief El ultimo commando usado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return T_Command (El nombre del commando)
 */
T_Command game_get_last_command(Game* game) {
    return game->last_cmd;
}

/**
 * @brief se obtiene el diálogo
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 16/12/2018
 * @param game (El juego que vamos a usar)
 * @return char* (El diálogo)
 */
char* game_get_dialogue(Game* game) {
    return game->dialogue;
}

/**
 * @brief se tira el dado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 16/12/2018
 * @param game (El juego que vamos a usar)
 * @return int (El resultado)
 */
int game_roll_die(Game* game) {
    return die_roll(game->die);
}

/**
 * @brief devuelve el resultado de introducir el ultimo commando en el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_get_result_last_command(Game* game) {
    return game->result_command;
}

/**
 * @brief El ultimo commando usado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 9/12/2018
 * @param game (El juego que vamos a usar)
 * @return T_Command (El nombre del commando)
 */
T_Command game_get_prev_command(Game* game) {
    return game->prev_cmd;
}

/**
 * @brief devuelve el resultado de introducir el ultimo commando en el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 9/12/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_get_result_prev_command(Game* game) {
    return game->result_prev_command;
}

/**
 * @brief Imprime el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego a imprimir)
 * @return void (No devuelve nada)
 */
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

/**Funciones de eventos aleatorios**/

/**
 * @brief cambia la luz del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game
 * @return STATUS
 */

STATUS game_change_light_space(Game *game) {
    Space *s = NULL;
    if (!game)return ERROR;

    s = game_get_space(game, game_get_player_location(game));
    if (!s) return ERROR;

    if (space_set_light(s, !space_get_light(s)) == ERROR)return ERROR;
    strcat(game->dialogue, " Ademas, se ha cambiado la luz de la habitacion.");

    return OK;
}

/**
 * @brief cierra un link
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game 
 * @return STATUS
 */

STATUS game_close_links(Game *game) {
    int i, flag = 0;
    Space *s = NULL;
    s = game_get_space(game, game_get_player_location(game));
    if (!s) return ERROR;
    for (i = 0; i < MAX_LINK && game->link[i] != NULL; i++) {
        if (space_get_north(s) == link_get_id(game->link[i])) {
            link_set_status(game->link[i], !link_get_status(game->link[i]));
            flag = 1;
        } else if (space_get_south(s) == link_get_id(game->link[i])) {
            link_set_status(game->link[i], !link_get_status(game->link[i]));
            flag = 1;
        } else if (space_get_east(s) == link_get_id(game->link[i])) {
            link_set_status(game->link[i], !link_get_status(game->link[i]));
            flag = 1;
        } else if (space_get_west(s) == link_get_id(game->link[i])) {
            link_set_status(game->link[i], !link_get_status(game->link[i]));
            flag = 1;
        }


    }
    if (flag == 1) {
        strcat(game->dialogue, " Ademas, se han cerrado o abierto varias puertas por el viento.");
    }
    return OK;
}

/**
 * @brief mata al jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game
 * @return STATUS
 */
STATUS game_kill_player(Game *game) {
    if (!game) return ERROR;
    player_destroy(game->player);
    game->player = NULL;

    return OK;

}

/**
 * @brief cambia un link
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game
 * @return STATUS
 */
STATUS game_appear_link(Game *game) {
    int j;
    Link *l = NULL;
    for (j = 0; j < MAX_LINK && game->link[j] != NULL && strcasecmp(link_get_name(game->link[j]), "Tobogan") != 0; j++);
    if (j > MAX_OBJECT) return ERROR;
    if (game->link[j] == NULL) {
        l = link_create();
        if (l == NULL) return ERROR;
        link_set_status(l, TRUE);
        link_set_name(l, "Tobogan");
        link_set_id(l, 13);
        link_set_conection(l, 2, 11);
        game_add_link(game, l);
        for (j = 0; j < MAX_SPACES && game->spaces[j] != NULL && strcasecmp(space_get_name(game->spaces[j]), "Terraza") != 0; j++);
        if (j > MAX_OBJECT) return ERROR;
        if (game->link[j] == NULL) return ERROR;
        space_set_east(game->spaces[j], 13);
        strcat(game->dialogue, " Ademas, se ha creado un nuevo link");
        return OK;
    }

    return ERROR;
}

/**
 * @brief cambia la localizacion de un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game
 * @return STATUS
 */

STATUS game_change_object_location(Game *game) {
    int i, flag = 0, aleat;
    Space *s = NULL;
    s = game_get_space(game, game_get_player_location(game));
    aleat = game_roll_die(game);
    if (!s) return ERROR;
    for (i = 0; i < MAX_OBJECT && game->object[i] != NULL; i++) {
        if (space_is_object_in(s, object_get_id(game->object[i])) == TRUE) {
            flag = 1;
            space_take_object(s, object_get_id(game->object[i]));
            if (game_set_object_location(game, aleat, object_get_id(game->object[i])) == ERROR)return ERROR;
        }
    }
    if (flag == 1) {
        strcat(game->dialogue, " Ademas, se han cambiado magicamente de lugar algunos objectos.");
    }
    return OK;
}

/**
 * @brief oculta un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game
 * @return STATUS
 */

STATUS game_hide_objects(Game *game) {
    int i, flag = 0;
    Space *s = NULL;
    s = game_get_space(game, game_get_player_location(game));
    if (!s) return ERROR;
    for (i = 0; i < MAX_OBJECT && game->object[i] != NULL; i++) {
        if (space_is_object_in(s, object_get_id(game->object[i])) == TRUE) {
            if (object_get_hidden(game->object[i]) == FALSE) {
                flag = 1;
                object_set_hidden(game->object[i], TRUE);
            } else {
                flag = 1;
                object_set_hidden(game->object[i], FALSE);
            }
        }
    }
    if (flag == 1) {
        strcat(game->dialogue, " Ademas, se han ocultado y han aparecido algunos objetos.");
    }
    return OK;
}


/**Callbacks implementation for each action */

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_unknown(Game* game) {
    return OK;
}

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_exit(Game* game) {
    return OK;
}

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_following(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Id link_id = NO_ID;

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
                if (link_get_id(game->link[i]) == link_id) break;
            }
            if (i >= MAX_LINK) return ERROR;
            if (game->link[i] == NULL) return ERROR;
            if (link_get_status(game->link[i]) == FALSE) return ERROR;
            current_id = link_get_conection_1(game->link[i]);
            if (current_id != NO_ID && current_id != space_id) {
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

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 17/12/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_up(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Id link_id = NO_ID;

    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
        return ERROR;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        current_id = space_get_id(game->spaces[i]);
        if (current_id == space_id) {
            link_id = space_get_up(game->spaces[i]);
            if (link_id == NO_ID) return ERROR;
            for (i = 0; i < MAX_LINK && game->link[i] != NULL; i++) {
                if (link_get_id(game->link[i]) == link_id) break;
            }
            if (i >= MAX_LINK) return ERROR;
            if (game->link[i] == NULL) return ERROR;
            if (link_get_status(game->link[i]) == FALSE) return ERROR;
            current_id = link_get_conection_1(game->link[i]);
            if (current_id != NO_ID && current_id != space_id) {
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

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 17/12/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_down(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Id link_id = NO_ID;

    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
        return ERROR;
    }

    for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++) {
        current_id = space_get_id(game->spaces[i]);
        if (current_id == space_id) {
            link_id = space_get_down(game->spaces[i]);
            if (link_id == NO_ID) return ERROR;
            for (i = 0; i < MAX_LINK && game->link[i] != NULL; i++) {
                if (link_get_id(game->link[i]) == link_id) break;
            }
            if (i >= MAX_LINK) return ERROR;
            if (game->link[i] == NULL) return ERROR;
            if (link_get_status(game->link[i]) == FALSE) return ERROR;
            current_id = link_get_conection_1(game->link[i]);
            if (current_id != NO_ID && current_id != space_id) {
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

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_previous(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Id link_id = NO_ID;
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
                if (link_get_id(game->link[i]) == link_id) break;
            }
            if (i >= MAX_LINK) return ERROR;
            if (game->link[i] == NULL) return ERROR;
            if (link_get_status(game->link[i]) == FALSE) return ERROR;
            current_id = link_get_conection_1(game->link[i]);
            if (current_id != NO_ID && current_id != space_id) {
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

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_oca_following(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Id link_id = NO_ID;

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
                if (link_get_id(game->link[i]) == link_id) break;
            }
            if (i >= MAX_LINK) return ERROR;
            if (game->link[i] == NULL) return ERROR;
            if (link_get_status(game->link[i]) == FALSE) return ERROR;
            current_id = link_get_conection_1(game->link[i]);
            if (current_id != NO_ID && current_id != space_id) {
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

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_oca_previous(Game* game) {
    int i = 0;
    Id current_id = NO_ID;
    Id space_id = NO_ID;
    Id link_id = NO_ID;

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
                if (link_get_id(game->link[i]) == link_id) break;
            }
            if (i >= MAX_LINK) return ERROR;
            if (game->link[i] == NULL) return ERROR;
            if (link_get_status(game->link[i]) == FALSE) return ERROR;
            current_id = link_get_conection_1(game->link[i]);
            if (current_id != NO_ID && current_id != space_id) {
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

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_take_object(Game* game, Command *cmd) {
    Id space_id = NO_ID, object_id = NO_ID;
    char object_name[WORD_SIZE];
    int i, evento_especial = 0;
    if (cmd == NULL) return ERROR;
    if (player_bag_is_full(game->player) == TRUE) return ERROR;
    space_id = game_get_player_location(game);
    if (space_id == NO_ID) {
        return ERROR;
    }
    strcpy(object_name, command_get_name(cmd));
    for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), object_name) != 0 && i < MAX_OBJECT; i++);
    if (i > MAX_OBJECT) return ERROR;
    if (game->object[i] == NULL) return ERROR;
    if (strcasecmp(object_get_name(game->object[i]), "Felpudo") == 0) {
        evento_especial = 1;
    }
    if (object_get_movable(game->object[i]) == FALSE || object_get_hidden(game->object[i]) == TRUE) return ERROR;
    object_id = object_get_id(game->object[i]);
    if (object_id == NO_ID) return ERROR;
    if (space_take_object(game_get_space(game, space_id), object_id) == ERROR) return ERROR;
    if (player_pick_object(game->player, object_id) == ERROR) return ERROR;
    if (evento_especial == 1) {
        for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), "Contrasena") != 0 && i < MAX_OBJECT; i++);
        if (i > MAX_OBJECT) return ERROR;
        if (game->object[i] == NULL) return ERROR;
        object_set_hidden(game->object[i], FALSE);
    }
    return OK;

}

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_leave_object(Game* game, Command *cmd) {
    Id space_id = NO_ID, object_id = NO_ID;
    int i;
    char object_name[WORD_SIZE];
    if (cmd == NULL) return ERROR;
    strcpy(object_name, command_get_name(cmd));
    space_id = game_get_player_location(game);
    for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), object_name) != 0 && i < MAX_OBJECT; i++);
    if (i > MAX_OBJECT) return ERROR;
    if (game->object[i] == NULL) return ERROR;
    object_id = object_get_id(game->object[i]);
    if (object_id == NO_ID) return ERROR;
    if (player_has_object(game->player, object_id) == FALSE) return ERROR;
    if ((space_leave_object(game_get_space(game, space_id), object_id)) == ERROR) return ERROR;
    if (player_drop_object(game->player, object_id) == ERROR) return ERROR;
    return OK;
}

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_roll(Game* game) {
    if (die_roll(game->die) < 1) return ERROR;
    return OK;
}

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_inspect(Game* game, Command *cmd) {
    char name[WORD_SIZE] = "";
    int i, j, evento_especial = 0;
    Id object_id = NO_ID, space_id = NO_ID;
    if (cmd == NULL) return ERROR;
    strcpy(name, command_get_name(cmd));
    if (space_get_light(game_get_space(game, game_get_player_location(game))) == FALSE) return ERROR;
    if (strcasecmp(name, "s") == 0 || strcasecmp(name, "space") == 0) {
        strcpy(game->last_description_asked, space_get_detailed_description(game_get_space(game, game_get_player_location(game))));
        return OK;
    }
    for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), name) != 0 && i < MAX_OBJECT; i++);
    if (i > MAX_OBJECT) return ERROR;
    if (game->object[i] == NULL) return ERROR;
    object_id = object_get_id(game->object[i]);
    space_id = game_get_player_location(game);
    if (strcasecmp(object_get_name(game->object[i]), "Cuadro") == 0) evento_especial = 1;
    if (space_is_object_in(game_get_space(game, space_id), object_id) == FALSE && player_has_object(game->player, object_id) == FALSE) {
        return ERROR;
    }
    if (space_get_light(game_get_space(game, space_id)) == FALSE) return ERROR;
    if (evento_especial == 1) {
        for (j = 0; game->object[j] != NULL && strcasecmp(object_get_name(game->object[j]), "Clave") != 0 && j < MAX_OBJECT; j++);
        if (j > MAX_OBJECT) return ERROR;
        if (game->object[j] == NULL) return ERROR;
        object_set_hidden(game->object[j], FALSE);
    }
    if (object_get_original_location(game->object[i]) == space_id && player_has_object(game->player, object_id) == FALSE) {
        strcpy(game->last_description_asked, object_get_description(game->object[i]));
    } else {
        strcpy(game->last_description_asked, object_get_detailed_description(game->object[i]));
    }
    return OK;

}

/**
 * @brief Devuelve la ultima descripcion del juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return char (La descripcion)
 */
char *game_get_last_description_asked(Game *game) {
    if (!game) return NULL;
    return game->last_description_asked;
}

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_go(Game *game, Command *cmd) {
    char direction_move[WORD_SIZE] = "";
    if (cmd == NULL) return ERROR;
    strcpy(direction_move, command_get_name(cmd));
    if (strcasecmp(direction_move, "n") == 0 || strcasecmp(direction_move, "north") == 0) {
        return game_callback_previous(game);
    }
    if (strcasecmp(direction_move, "s") == 0 || strcasecmp(direction_move, "south") == 0) {
        return game_callback_following(game);
    }
    if (strcasecmp(direction_move, "w") == 0 || strcasecmp(direction_move, "west") == 0) {
        return game_callback_oca_previous(game);
    }
    if (strcasecmp(direction_move, "e") == 0 || strcasecmp(direction_move, "east") == 0) {
        return game_callback_oca_following(game);
    }
    if (strcasecmp(direction_move, "u") == 0 || strcasecmp(direction_move, "up") == 0) {
        return game_callback_up(game);
    }
    if (strcasecmp(direction_move, "d") == 0 || strcasecmp(direction_move, "down") == 0) {
        return game_callback_down(game);
    }
    return ERROR;
}

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_turnon(Game* game, Command *cmd) {
    char name[WORD_SIZE] = "";
    int i;
    Id object_id = NO_ID, space_id = NO_ID;
    if (cmd == NULL) return ERROR;
    strcpy(name, command_get_name(cmd));

    for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), name) != 0 && i < MAX_OBJECT; i++);
    if (i > MAX_OBJECT) return ERROR;
    if (game->object[i] == NULL) return ERROR;
    if (object_get_light(game->object[i]) == FALSE) return ERROR;
    object_id = object_get_id(game->object[i]);
    if (object_id == NO_ID) return ERROR;
    if (player_has_object(game->player, object_id) == FALSE) return ERROR;
    space_id = game_get_player_location(game);
    if (space_id == NO_ID) return ERROR;
    space_set_light(game_get_space(game, space_id), TRUE);
    object_set_on(game->object[i], TRUE);
    return OK;
}

/**
 * @brief devuelve el estado tras usar el commando correspondiente
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_turnoff(Game* game, Command *cmd) {
    char name[WORD_SIZE] = "";
    int i;
    Id object_id = NO_ID, space_id = NO_ID;
    if (cmd == NULL) return ERROR;
    strcpy(name, command_get_name(cmd));

    for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), name) != 0 && i < MAX_OBJECT; i++);
    if (i > MAX_OBJECT) return ERROR;
    if (game->object[i] == NULL) return ERROR;
    if (object_get_light(game->object[i]) == FALSE) return ERROR;
    object_id = object_get_id(game->object[i]);
    if (object_id == NO_ID) return ERROR;
    if (player_has_object(game->player, object_id) == FALSE) return ERROR;
    space_id = game_get_player_location(game);
    if (space_id == NO_ID) return ERROR;
    space_set_light(game_get_space(game, space_id), FALSE);
    object_set_on(game->object[i], FALSE);
    return OK;
}

/**
 * @brief abre el espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_open(Game* game, Command *cmd) {
    char name[WORD_SIZE] = "";
    int i, j, evento_especial = 0, k;
    char *token, string[WORD_SIZE] = "";
    char link_name[WORD_SIZE] = "";
    Id object_id = NO_ID, id_space = NO_ID, id_link = NO_ID;
    strcpy(string, command_get_name(cmd));
    token = strtok(string, " \n");
    if (token == NULL) return ERROR;
    strcpy(link_name, token);
    token = strtok(NULL, " \n");
    if (token == NULL) return ERROR;
    strcpy(name, token);
    for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), name) != 0 && i < MAX_OBJECT; i++);
    if (i > MAX_OBJECT) return ERROR;
    if (game->object[i] == NULL) return ERROR;
    object_id = object_get_id(game->object[i]);
    if (strcasecmp(object_get_name(game->object[i]), "tnt") == 0) {
        evento_especial = 1;
        for (k = 0; game->object[k] != NULL && strcasecmp(object_get_name(game->object[k]), "Mechero") != 0 && k < MAX_OBJECT; k++);
        if (k > MAX_OBJECT) return ERROR;
        if (game->object[k] == NULL) return ERROR;
        if (player_has_object(game->player, object_get_id(game->object[k])) == FALSE) return ERROR;
    } else if (strcasecmp(object_get_name(game->object[i]), "extintor") == 0) evento_especial = 2;
    if (player_has_object(game->player, object_id) == FALSE)return ERROR;
    if (object_get_open(game->object[i]) == NO_ID) return ERROR;
    for (j = 0; j < MAX_LINK && game->link[j] != NULL && strcasecmp(link_get_name(game->link[j]), link_name) != 0; j++);
    if (j > MAX_OBJECT) return ERROR;
    if (game->link[j] == NULL) return ERROR;

    id_link = link_get_id(game->link[j]);
    id_space = game_get_player_location(game);
    if (object_get_open(game->object[i]) != id_link) return ERROR;
    if (space_get_east(game_get_space(game, id_space)) == id_link) {
        if (evento_especial == 1) {
            for (k = 0; game->object[k] != NULL && strcasecmp(object_get_name(game->object[k]), "extintor") != 0 && k < MAX_OBJECT; k++);
            if (k > MAX_OBJECT) return ERROR;
            if (game->object[k] == NULL) return ERROR;
            object_set_open(game->object[k], id_link);
            object_set_open(game->object[i], NO_ID);
            link_set_name(game->link[j], "Fuego");
            return OK;
        } else if (evento_especial == 2) {
            link_set_name(game->link[j], "MuroDestruido");
            object_set_open(game->object[i], NO_ID);
        }
        link_set_status(game->link[j], TRUE);
        return OK;
    }
    if (space_get_west(game_get_space(game, id_space)) == id_link) {
        if (evento_especial == 1) {
            for (k = 0; game->object[k] != NULL && strcasecmp(object_get_name(game->object[k]), "extintor") != 0 && k < MAX_OBJECT; k++);
            if (k > MAX_OBJECT) return ERROR;
            if (game->object[k] == NULL) return ERROR;
            object_set_open(game->object[k], id_link);
            object_set_open(game->object[i], NO_ID);
            link_set_name(game->link[j], "Fuego");
            return OK;
        } else if (evento_especial == 2) {
            link_set_name(game->link[j], "MuroDestruido");
            object_set_open(game->object[i], NO_ID);
        }
        link_set_status(game->link[j], TRUE);
        return OK;
    }
    if (space_get_north(game_get_space(game, id_space)) == id_link) {
        if (evento_especial == 1) {
            for (k = 0; game->object[k] != NULL && strcasecmp(object_get_name(game->object[k]), "extintor") != 0 && k < MAX_OBJECT; k++);
            if (k > MAX_OBJECT) return ERROR;
            if (game->object[k] == NULL) return ERROR;
            object_set_open(game->object[k], id_link);
            object_set_open(game->object[i], NO_ID);
            link_set_name(game->link[j], "Fuego");
            return OK;
        } else if (evento_especial == 2) {
            link_set_name(game->link[j], "MuroDestruido");
            object_set_open(game->object[i], NO_ID);
        }
        link_set_status(game->link[j], TRUE);
        return OK;
    }
    if (space_get_south(game_get_space(game, id_space)) == id_link) {
        if (evento_especial == 1) {
            for (k = 0; game->object[k] != NULL && strcasecmp(object_get_name(game->object[k]), "extintor") != 0 && k < MAX_OBJECT; k++);
            if (k > MAX_OBJECT) return ERROR;
            if (game->object[k] == NULL) return ERROR;
            object_set_open(game->object[k], id_link);
            object_set_open(game->object[i], NO_ID);
            link_set_name(game->link[j], "Fuego");
            return OK;
        } else if (evento_especial == 2) {
            link_set_name(game->link[j], "MuroDestruido");
            object_set_open(game->object[i], NO_ID);
        }
        link_set_status(game->link[j], TRUE);
        return OK;
    }
    if (space_get_up(game_get_space(game, id_space)) == id_link) {
        if (evento_especial == 1) {
            for (k = 0; game->object[k] != NULL && strcasecmp(object_get_name(game->object[k]), "extintor") != 0 && k < MAX_OBJECT; k++);
            if (k > MAX_OBJECT) return ERROR;
            if (game->object[k] == NULL) return ERROR;
            object_set_open(game->object[k], id_link);
            object_set_open(game->object[i], NO_ID);
            link_set_name(game->link[j], "Fuego");
            return OK;
        } else if (evento_especial == 2) {
            link_set_name(game->link[j], "MuroDestruido");
            object_set_open(game->object[i], NO_ID);
        }
        link_set_status(game->link[j], TRUE);
        return OK;
    }
    if (space_get_down(game_get_space(game, id_space)) == id_link) {
        if (evento_especial == 1) {
            for (k = 0; game->object[k] != NULL && strcasecmp(object_get_name(game->object[k]), "extintor") != 0 && k < MAX_OBJECT; k++);
            if (k > MAX_OBJECT) return ERROR;
            if (game->object[k] == NULL) return ERROR;
            object_set_open(game->object[k], id_link);
            object_set_open(game->object[i], NO_ID);
            link_set_name(game->link[j], "Fuego");
            return OK;
        } else if (evento_especial == 2) {
            link_set_name(game->link[j], "MuroDestruido");
            object_set_open(game->object[i], NO_ID);
        }
        link_set_status(game->link[j], TRUE);
        return OK;
    }
    return ERROR;
}

/**
 * @brief guarda el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_save(Game* game, Command *cmd) {
    char save[WORD_SIZE];
    char *symbol;
    memset(save, '\0', WORD_SIZE);
    strcpy(save, "Saves/");
    symbol = command_get_name(cmd);
    strcat(save, symbol);
    strcat(save, ".s");
    return game_management_save(game, save);

}

/**
 * @brief carga el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cmd (commando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_callback_load(Game* game, Command *cmd) {
    char load[WORD_SIZE];
    char *symbol;
    memset(load, '\0', WORD_SIZE);
    strcpy(load, "Saves/");
    symbol = command_get_name(cmd);
    strcat(load, symbol);
    strcat(load, ".s");

    return game_management_load(game, load);

}

/**
 * @brief El link de un id pasado como argumento
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param link_id (El id del link)
 * @return Link* (El link de ese id)
 */
Link *game_get_link(Game *game, Id link_id) {
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

/**
 * @brief devuelve el id del espacio conectado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param link_id (El id del link)
 * @param space_id (El id del espacio)
 * @return Id (El id del espacio conectado)
 */
Id game_get_id_conected_space(Game *game, Id link_id, Id space_id) {
    Link *link = NULL;
    link = game_get_link(game, link_id);
    if (link == NULL) return NO_ID;
    if (link_get_conection_1(link) == space_id) {
        return link_get_conection_2(link);
    } else return link_get_conection_1(link);
}

/**
 * @brief devuelve el espacio de una posicion
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (El juego)
 * @param pos (posicion)
 * @return Space (El espacio en dicha posicion)
 */
Space *game_get_space_order(Game *game, int pos) {
    if (!game || pos > MAX_SPACES) return NULL;
    return game->spaces[pos];
}

/**
 * @brief devuelve el link de una posicion
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (El juego)
 * @param pos (posicion)
 * @return Link (El link en dicha posicion)
 */
Link *game_get_link_order(Game *game, int pos) {
    if (!game || pos > MAX_LINK) return NULL;
    return game->link[pos];
}

/**
 * @brief devuelve el objeto de una posicion
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (El juego)
 * @param pos (posicion)
 * @return Object (El objeto en dicha posicion)
 */
Object *game_get_object_order(Game *game, int pos) {
    if (!game || pos > MAX_OBJECT) return NULL;
    return game->object[pos];
}

/**
 * @brief crea una cadena con los objetos del jugador para guardarla
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cadena (cadena donde se va a guardar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_string_object_player_save(Game *game, char* cadena) {
    int i, write = 0;
    Id object_id = NO_ID;
    char cadena_id[TAM];
    if (!cadena) return ERROR;
    for (i = 0; i < MAX_OBJECT && game->object[i] != NULL; i++) {
        object_id = object_get_id(game->object[i]);
        if (object_id != NO_ID && player_has_object(game->player, object_id)) {
            sprintf(cadena_id, "%ld|", object_id);
            strcat(cadena, cadena_id);
            write = 1;
        }
        object_id = NO_ID;
    }
    if (write == 0) return ERROR;
    return OK;
}

/**
 * @brief Devuelve un puntero al jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 12/12/2018
 * @param /game (El juego que vamos a usar)
 * @return player (El jugador)
 */
Player *game_get_player(Game *game) {
    if (game == NULL) return NULL;
    return game->player;
}
