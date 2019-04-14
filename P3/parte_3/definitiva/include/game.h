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
* @param comand (El comando introducido)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS game_update(Game* game, Comand* comand);

/**
* @brief destruye el juego y libera la memoria 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a destruir)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS game_destroy(Game* game);


/**
* @brief En este caso devuelve FALSE siempre 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return BOOL (FALSE)
*/
BOOL game_is_over(Game* game);

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
* @brief pasa una cadena de objetos al juego 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @param cadena (cadena de objetos)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS game_cadena_objetos_localizacion(Game *game, char* cadena);

/**
* @brief pasa una cadena de objetos al juego 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @param space (El espacio de los objetos)
* @param cadena (cadena de objetos)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS game_cadena_objetos(Game *game, Space* space, char *cadena);

/**
* @brief pasa una cadena de objetos del jugador al juego 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @param cadena (cadena de objetos)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS game_cadena_objetos_jugador(Game *game, char *cadena);

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
STATUS game_get_resultado_last_command(Game* game);

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
* @brief Devuelve la ultima descripcion del juego  
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego que vamos a usar)
* @return char (La descripcion)
*/
char *game_get_ultima_descripcion(Game *game);
#endif
