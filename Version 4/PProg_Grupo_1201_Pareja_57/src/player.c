/**
 * @brief En este fichero implementamos las funciones del jugador
 * @file player.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0
 * @date 20/10/2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"

struct _Player {
    char name[WORD_SIZE]; /*!< Nombre del jugador*/
    Id id; /*!< Su Id*/
    Inventory *inventory; /*!< El inventario del jugador*/
    Id space_id; /*!< El número identificador del espacio en el que se encuentra el jugador*/
}; /*!< Estructura del jugador */

/**
 * @brief crea un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/201
 * @param max_obj (numero maximo de objetos de un jugador)
 * @return Player* (El jugador que crea)
 */
Player * player_create(int max_obj) {
    Player *player = NULL;
    player = (Player*) malloc(sizeof (Player));
    if (!player) {
        return NULL;
    }
    player->id = NO_ID;
    player->inventory = NULL;
    player->inventory = inventory_create(max_obj);
    if (player->inventory == NULL) {
        free(player);
        return NULL;
    }
    player->space_id = NO_ID;

    return player;
}

/**
 * @brief destruye un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a destruir)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_destroy(Player *player) {
    if (player) {
        if (player->inventory != NULL) {
            if (inventory_destroy(player->inventory) == ERROR) {
                free(player);
                return ERROR;
            }
        }
        free(player);
        player = NULL;
        return OK;
    }
    return ERROR;
}

/**
 * @brief cambia el nombre de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a modificar)
 * @param name (nuevo nombre)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_set_name(Player *player, char *name) {
    if (!player || !name) {
        return ERROR;
    }
    strcpy(player->name, name);
    return OK;
}

/**
 * @brief cambia el Id de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a modificar)
 * @param id (nuevo Id)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_set_id(Player *player, Id id) {
    if (!player) {
        return ERROR;
    }
    player->id = id;
    return OK;
}

/**
 * @brief cambia el inventario de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a modificar)
 * @param bag (nuevo inventario)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_set_inventory(Player *player, Inventory *bag) {
    if (!player) {
        return ERROR;
    }
    if (player->inventory != NULL) {
        inventory_destroy(player->inventory);
    }
    player->inventory = bag;
    return OK;
}

/**
 * @brief cambia el Id de la posicion de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a modificar)
 * @param space_id (nuevo Id de posicion)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_set_space_id(Player *player, Id space_id) {
    if (!player) {
        return ERROR;
    }
    player->space_id = space_id;
    return OK;
}

/**
 * @brief devuelve el nombre de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @return char* (Devuelve el nombre del objeto)
 */
char * player_get_name(Player *player) {
    if (!player) {
        return NULL;
    }
    return player->name;
}

/**
 * @brief devuelve el Id de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @return Id (Devuelve el Id del jugador)
 */
Id player_get_id(Player *player) {
    if (!player) {
        return NO_ID;
    }
    return player->id;
}

/**
 * @brief devuelve el Id de la posicion de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @return Id (Devuelve el Id de la posicion del jugador)
 */
Id player_get_space_id(Player *player) {
    if (!player) {
        return NO_ID;
    }
    return player->space_id;
}

/**
 * @brief devuelve el inventario de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @return Inventory* (Devuelve el inventario del jugador)
 */
Inventory* player_get_inventory(Player *player) {
    if (player == NULL)return NULL;

    return player->inventory;
}

/**
 * @brief devuelve el tamaño inventario de un jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 15/12/2018
 * @param player (jugador a usar)
 * @return int (Devuelve el tamaño inventario del jugador)
 */
int player_get_inventory_size(Player *player) {
    if (player == NULL)return NO_ID;

    return inventory_get_size(player->inventory);
}

/**
 * @brief suelta un objeto que tiene el jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @param id (Id del objeto a soltar)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_drop_object(Player *player, Id id) {

    if (player == NULL || id == NO_ID) return ERROR;
    if (player_has_object(player, id) == FALSE)return ERROR;
    if (inventory_delete_object(player->inventory, id) == ERROR)return ERROR;
    return OK;
}

/**
 * @brief el jugador coge un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @param id (Id del objeto a coger)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS player_pick_object(Player *player, Id id) {
    if (player == NULL || id == NO_ID)return ERROR;

    if (inventory_is_full(player->inventory) == TRUE)return ERROR;
    if (inventory_add_object(player->inventory, id) == ERROR)return ERROR;
    return OK;
}

/**
 * @brief comprueba si un jugador tiene un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @param id (Id del objeto a comprobar)
 * @return BOOL (TRUE si el jugador tiene el objeto o FALSE de lo contrario)
 */
BOOL player_has_object(Player *player, Id id) {
    if (player == NULL || id == NO_ID)return FALSE;

    return inventory_is_object_in(player->inventory, id);
}

/**
 * @brief el jugador tiene el inventario lleno
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @return BOOL (TRUE si el jugador tiene el inventario lleno o FALSE de lo contrario)
 */
BOOL player_bag_is_full(Player *player) {
    if (!player) return TRUE;
    return inventory_is_full(player->inventory);
}

/**
 * @brief imprime el jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 20/10/2018
 * @param player (jugador a usar)
 * @param f (donde se va a imprimir)
 * @return int (-1 si hay algun error)
 */
int player_print(FILE *f, Player *player) {
    if (!f || !player) {
        return ERROR;
    }
    fprintf(f, "Nombre: %s, id=%ld, casilla=%ld, inventario: ", player->name, player->id, player->space_id);

    inventory_print(player->inventory, stdout);

    return OK;
}
