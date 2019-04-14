/**
 * @brief En este fichero definimos las funciones para el juego
 * @file game.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 3.0
 * @date 21/10/2018
 */

#ifndef GAME_H
#define GAME_H

#include "space.h"
#include "command.h"
#include "object.h"
#include "player.h"
#include "die.h"
#include "link.h"
#include "dialogue.h"
#define MAX_OBJECT 100 /*!< maximo de objetos del juego */
#define MAX_LINK 4*MAX_SPACES /*!< tamaño maximo para el link */


typedef struct _Game Game; /*!< definicion de la estructura de juego */

/**
 * @brief crea un juego vacio sin jugadores ni objetos
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @return game (el juego que hemos creado)
 */
Game* game_create();

/**
 * @brief crea un juego cargando del archivo los espacios, los jugadores, los objetos
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param filename (El nombre del archivo del que cargamos los datos)
 * @return Game (el juego que hemos creado)
 */
Game* game_create_from_file(char* filename);

/**
 * @brief actualiza el juego tras pasarle el comando introducido
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a actualizar)
 * @param command (El comando introducido)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_update(Game* game, Command* command);

/**
 * @brief destruye el juego y libera la memoria
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a destruir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_destroy(Game* game);

/**
 * @brief destruye el juego para poder cargar otro
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 18/12/2018
 * @param game (El juego que vamos a destruir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_destroy_for_load(Game* game);

/**
 * @brief En este caso devuelve FALSE siempre
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return BOOL (FALSE)
 */
BOOL game_is_over(Game* game);

/**
 * @brief se tira el dado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 16/12/2018
 * @param game (El juego que vamos a usar)
 * @return int (El resultado)
 */
int game_roll_die(Game* game);

/**
 * @brief Para saber si la mochila del jugador está llena
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 16/12/2018
 * @param game (El juego que vamos a usar)
 * @return bool
 */
BOOL game_player_bag_is_full(Game* game);

/**
 * @brief añade un espacio al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego al que vamos a añadir)
 * @param space (Lo que vamos a añadir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_add_space(Game* game, Space* space);

/**
 * @brief añade un objeto al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego al que vamos a añadir)
 * @param object (Lo que vamos a añadir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_add_object(Game* game, Object *object);

/**
 * @brief añade un link al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego al que vamos a añadir)
 * @param link (Lo que vamos a añadir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_add_link(Game* game, Link *link);

/**
 * @brief añade un jugador al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego al que vamos a añadir)
 * @param player (Lo que vamos a añadir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_add_player(Game* game, Player *player);

/**
 * @brief Imprime el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego a imprimir)
 * @return void (No devuelve nada)
 */
void game_print_data(Game* game);


/**
 * @brief Imprime el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego a imprimir)
 * @return void (No devuelve nada)
 */
void game_print_screen(Game* game);




/**
 * @brief crea una cadena con los objetos del jugador para guardarla
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cadena (cadena donde se va a guardar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_string_object_player_save(Game *game, char* cadena);

/**
 * @brief modifica la posicion de un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego al que vamos a añadir)
 * @param id (id nuevo que queremos asignar)
 * @param id_object (id del objeto que queremos modificar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_set_object_location(Game* game, Id id, Id id_object);

/**
 * @brief tira el dado del juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que estamos usando)
 * @return int (El valor de la tirada)
 */
int game_get_roll_die(Game *game);

/**
 * @brief devuelve el espacio de una posicion
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (El juego)
 * @param pos (posicion)
 * @return Space (El espacio en dicha posicion)
 */
Space *game_get_space_order(Game *game, int pos);

/**
 * @brief devuelve el link de una posicion
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (El juego)
 * @param pos (posicion)
 * @return Link (El link en dicha posicion)
 */
Link *game_get_link_order(Game *game, int pos);

/**
 * @brief devuelve el objeto de una posicion
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (El juego)
 * @param pos (posicion)
 * @return Object (El objeto en dicha posicion)
 */
Object *game_get_object_order(Game *game, int pos);

/**
 * @brief pasa una cadena de objetos al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cadena (cadena de objetos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_string_objects_localization(Game *game, char* cadena);

/**
 * @brief pasa una cadena de objetos al juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param space (El espacio de los objetos)
 * @param cadena (cadena de objetos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_string_objects(Game *game, Space* space, char *cadena);

/**
 * @brief pasa a una cadena los objetos del jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param cadena (cadena de objetos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_string_objects_player(Game *game, char *cadena);

/**
 * @brief devuelve el Id del objeto de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
Id game_get_player_object(Game* game);

/**
 * @brief devuelve el nombre de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return char (El nombre del jugador)
 */
char *game_get_player_name(Game* game);

/**
 * @brief devuelve el espacio del id que le pasamos
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param id (El id del espacio)
 * @return Space (El espacio del id)
 */
Space* game_get_space(Game* game, Id id);

/**
 * @brief devuelve el id de la posicion del jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return Id (La posicion del jugador)
 */
Id game_get_player_location(Game* game);

/**
 * @brief devuelve el id de la posicion del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param id (El id del objeto)
 * @return Id (La posicion del objeto)
 */
Id game_get_object_location(Game* game, Id id);

/**
 * @brief devuelve el nombre del objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param id (El id del objeto)
 * @return char* (El nombre del objeto)
 */
char *game_get_object_name(Game *game, Id id);

/**
 * @brief El ultimo comando usado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return T_Command (El nombre del comando)
 */
T_Command game_get_last_command(Game* game);

/**
 * @brief devuelve el resultado de introducir el ultimo comando en el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_get_result_last_command(Game* game);

/**
 * @brief El comando anterior
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return T_Command (El nombre del comando)
 */
T_Command game_get_prev_command(Game* game);

/**
 * @brief devuelve el resultado del anterior comando introducido
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_get_result_prev_command(Game* game);

/**
 * @brief devuelve el id del espacio conectado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param link_id (El id del link)
 * @param space_id (El id del espacio)
 * @return Id (El id del espacio conectado)
 */
Id game_get_id_conected_space(Game *game, Id link_id, Id space_id);

/**
 * @brief El link de un id pasado como argumento
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @param link_id (El id del link)
 * @return Link (El link de ese id)
 */
Link *game_get_link(Game *game, Id link_id);

/**
 * @brief Devuelve un puntero al jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego que vamos a usar)
 * @return player (El jugador)
 */
Player *game_get_player(Game *game);


/**
 * @brief Devuelve la ultima descripcion del juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 12/12/2018
 * @param game (El juego que vamos a usar)
 * @return char (La descripcion)
 */
char *game_get_last_description_asked(Game *game);

/**
 * @brief se obtiene el diálogo
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 16/12/2018
 * @param game (El juego que vamos a usar)
 * @return char* (El diálogo)
 */
char *game_get_dialogue(Game *game);
/**
 * @brief cambia la luz del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game
 * @return STATUS
 */

STATUS game_change_light_space(Game *game);

/**
 * @brief cierra un link
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game 
 * @return STATUS
 */

STATUS game_close_links(Game *game);
/**
 * @brief mata al jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game
 * @return STATUS
 */
STATUS game_kill_player(Game *game);

/**
 * @brief cambia un link
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game
 * @return STATUS
 */
STATUS game_appear_link(Game *game);
/**
 * @brief cambia la localizacion de un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game
 * @return STATUS
 */

STATUS game_change_object_location(Game *game);


/**
 * @brief oculta un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 19/12/2018
 * @param game
 * @return STATUS
 */

STATUS game_hide_objects(Game *game);

#endif

