/**
 * @brief En este fichero implementamos las funciones del jugador
 * @file player.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0
 * @date 20/10/2018
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "inventory.h"

typedef struct _Player Player; /*!< Estructura del jugador */

/*funciones basicas para crear y destruir el jugador*/

/**
 * @brief crea un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param max_obj (numero maximo de objetos de un jugador)
 * @return Player (El jugador que crea)
 */
Player *player_create(int max_obj);

/**
 * @brief destruye un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a destruir)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_destroy(Player *player);

/*funciones para establecer los valores de player*/

/**
 * @brief cambia el nombre de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a modificar)
 * @param name (nuevo nombre)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_set_name(Player *player, char *name);

/**
 * @brief cambia el Id de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a modificar)
 * @param id (nuevo Id)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_set_id(Player *player, Id id);

/**
 * @brief cambia el inventario de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a modificar)
 * @param bag (nuevo inventario)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_set_inventory(Player *player, Inventory *bag);

/**
 * @brief cambia el Id de la posicion de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a modificar)
 * @param space_id (nuevo Id de posicion)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_set_space_id(Player *player, Id space_id);

/*funciones para obtener cualquier campo de player*/

/**
 * @brief devuelve el nombre de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @return char* (Devuelve el nombre del objeto)
 */
char * player_get_name(Player *player);

/**
 * @brief devuelve el Id de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @return Id (Devuelve el Id del jugador)
 */
Id player_get_id(Player *);

/**
 * @brief devuelve el tamaño inventario de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 15/12/2018
 * @param player (jugador a usar)
 * @return int (Devuelve el tamaño inventario del jugador)
 */
Inventory* player_get_inventory(Player *player);
/**
 * @brief devuelve el inventario de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @return Inventory (Devuelve el inventario del jugador)
 */
Inventory* player_get_inventory(Player *);

/**
 * @brief devuelve el Id de la posicion de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @return Id (Devuelve el Id de la posicion del jugador)
 */
Id player_get_space_id(Player *);

/*funciones para el manejo de objetos*/

/**
 * @brief suelta un objeto que tiene el jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @param id (Id del objeto a soltar)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_drop_object(Player *player, Id id); /**
* @brief devuelve el tamaño inventario de un jugador
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
* @date 15/12/2018
* @param player (jugador a usar)
* @return int (Devuelve el tamaño inventario del jugador)
*/
Inventory* player_get_inventory(Player *player);

/**
 * @brief el jugador coge un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @param id (Id del objeto a coger)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_pick_object(Player *player, Id id);

/**
 * @brief comprueba si un jugador tiene un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @param id (Id del objeto a comprobar)
 * @return BOOL (TRUE si el jugador tiene el objeto o FALSE de lo contrario)
 */
BOOL player_has_object(Player *player, Id id);

/**
 * @brief el jugador tiene el inventario lleno
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @return BOOL (TRUE si el jugador tiene el inventario lleno o FALSE de lo contrario)
 */
BOOL player_bag_is_full(Player *player);

/*Imprime todos los datos del player*/

/**
 * @brief imprime el jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @param f (donde se va a imprimir)
 * @return int (-1 si hay algun error)
 */
int player_print(FILE *f, Player *player);
/**
 * @brief devuelve el tamaño inventario de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 15/12/2018
 * @param player (jugador a usar)
 * @return int (Devuelve el tamaño inventario del jugador)
 */
int player_get_inventory_size(Player *player);
#endif
