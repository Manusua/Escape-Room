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
#include "game_reader.h"


struct _Game {
    Player *player; /*!<Puntero a estructura jugador*/
    Object *object[MAX_OBJECT]; /*!<Punteros a estructura objeto*/
    Space* spaces[MAX_SPACES + 1]; /*!<Punteros a estructura espacio*/
    T_Command last_cmd; /*!<Último comando*/
    STATUS resultado_comando; /*!<El resultado de la ejecución del último comando*/
    Die *die; /*!<Dado*/
    char ultima_descripcion_pedida[WORD_SIZE];/*!<Últimoa descripcion*/
    Link *link[MAX_LINK];/*!<Puntero a estructura link*/
};/*!<Estructura del juego */   

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
* @param cmd (comando del objeto)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_take_object(Game* game, Comand *cmd);

/**
* @brief devuelve el estado tras usar el comando correspondiente 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @param cmd (comando del objeto)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_leave_object(Game* game, Comand *cmd);

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
* @param cmd (comando del objeto)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_inspect(Game* game, Comand *cmd);

/**
* @brief devuelve el estado tras usar el comando correspondiente 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @param cmd (comando del objeto)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_go(Game *game, Comand *cmd);



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
        game->resultado_comando = OK;
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

        if (game_reader_load_spaces(game, filename) == ERROR) {
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
        if (game_reader_load_players(game, filename) == ERROR) {
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
* @brief En este caso devuelve FALSE siempre 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return BOOL (FALSE)
*/
    BOOL game_is_over(Game* game) {
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

        if (player == NULL) {
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

/**
* @brief pasa una cadena de objetos al juego 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @param space (El espacio de los objetos)
* @param cadena (cadena de objetos)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
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

/**
* @brief pasa una cadena de objetos del jugador al juego 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @param cadena (cadena de objetos)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
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

/**
* @brief tira el dado del juego
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que estamos usando)
* @return int (El valor de la tirada)
*/
    int game_get_roll_die(Game *game) {
        return die_get_resultado_anterior(game->die);
    }

/**
* @brief actualiza el juego tras pasarle el comando introducido 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a actualizar)
* @param comand (El comando introducido)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
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
            game->resultado_comando = game_callback_inspect(game, comand);
            return game->resultado_comando;
            case GO:
            game->resultado_comando = game_callback_go(game, comand);
            return game->resultado_comando;
            case NO_CMD:
            game->resultado_comando = OK;
            break;
            default:
            return ERROR;
        }
        return OK;
    }

/**
* @brief El ultimo comando usado  
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return T_Command (El nombre del comando)
*/
    T_Command game_get_last_command(Game* game) {
        return game->last_cmd;
    }

/**
* @brief devuelve el resultado de introducir el ultimo comando en el juego
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
    STATUS game_get_resultado_last_command(Game* game) {
        return game->resultado_comando;
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



/**Callbacks implementation for each action */

/**
* @brief devuelve el estado tras usar el comando correspondiente 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_unknown(Game* game) {
        return OK;
    }

/**
* @brief devuelve el estado tras usar el comando correspondiente 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_exit(Game* game) {
        return OK;
    }

/**
* @brief devuelve el estado tras usar el comando correspondiente 
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
* @brief devuelve el estado tras usar el comando correspondiente 
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
* @brief devuelve el estado tras usar el comando correspondiente 
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
* @brief devuelve el estado tras usar el comando correspondiente 
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
* @brief devuelve el estado tras usar el comando correspondiente 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_take_object(Game* game, Comand *cmd) {
        Id space_id = NO_ID, object_id = NO_ID;
        char object_name[WORD_SIZE];
        int i;
        if (cmd == NULL) return ERROR;
        if (player_bag_is_full(game->player) == TRUE) return ERROR;
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
        if (player_pick_object(game->player, object_id) == ERROR) return ERROR;
        return OK;

    }

/**
* @brief devuelve el estado tras usar el comando correspondiente 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_leave_object(Game* game, Comand *cmd) {
        Id space_id = NO_ID, object_id = NO_ID;
        int i;
        char object_name[WORD_SIZE];
        if (cmd == NULL) return ERROR;
        strcpy(object_name, comand_get_name(cmd));
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
* @brief devuelve el estado tras usar el comando correspondiente 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_roll(Game* game) {
        if (roll_die(game->die) < 1) return ERROR;
        return OK;
    }

/**
* @brief devuelve el estado tras usar el comando correspondiente 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_inspect(Game* game, Comand *cmd) {
        char name[WORD_SIZE] = "";
        int i;
        Id object_id = NO_ID, space_id = NO_ID;
        if (cmd == NULL) return ERROR;
        strcpy(name, comand_get_name(cmd));
        if (strcasecmp(name, "s") == 0 || strcasecmp(name, "space") == 0) {
            strcpy(game->ultima_descripcion_pedida, space_get_description(game_get_space(game, game_get_player_location(game))));
            return OK;
        }
        for (i = 0; game->object[i] != NULL && strcasecmp(object_get_name(game->object[i]), name) != 0 && i < MAX_OBJECT; i++);
        if (i > MAX_OBJECT) return ERROR;
        if (game->object[i] == NULL) return ERROR;
        object_id = object_get_id(game->object[i]);
        space_id = game_get_player_location(game);
        if (space_is_object_in(game_get_space(game, space_id), object_id) == FALSE && player_has_object(game->player, object_id) == FALSE) {
            return ERROR;
        }
        strcpy(game->ultima_descripcion_pedida, object_get_description(game->object[i]));
        return OK;
    }


/**
* @brief Devuelve la ultima descripcion del juego  
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return char (La descripcion)
*/
    char *game_get_ultima_descripcion(Game *game) {
        if (!game) return NULL;
        return game->ultima_descripcion_pedida;
    }

/**
* @brief devuelve el estado tras usar el comando correspondiente 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @param cmd (comando introducido)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/ 
    STATUS game_callback_go(Game *game, Comand *cmd) {
        char direction_move[WORD_SIZE] = "";
        if (cmd == NULL) return ERROR;
        strcpy(direction_move, comand_get_name(cmd));
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
        return ERROR;
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
