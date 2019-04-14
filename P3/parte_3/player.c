/* ===================================================================
File: player.c
Version: 1.0
Date: 1-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Contiene todas las funciones que perimiten crear jugadores y trabajar con sus campos
Revision historica:
1-10-2018 versión 1.0
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"


/*Estructura de Player que guarda información sobre su nombre, su id o dónde está y qué objetos lleva*/
struct _Player {
    char name[WORD_SIZE]; /*Nombre del jugador*/
    Id id; /*Su número identificador*/
    Inventory *inventory; /*El número identificador del objeto que lleva*/
    Id space_id; /*El número identificador del espacio en el que se encuentra el jugador*/
};

/******************************************************************
 *Funcion :player_create
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de crear el jugador
 *Input: nada
 *Output: el Player o NULL si no se ha podido crear
 ********************************************************************/

Player * player_create(int max_obj) {
    Player *player = NULL;
    player = (Player*) malloc(sizeof (Player));
    if (!player) {
        return NULL;
    }
    player->id = NO_ID;
    player->inventory = inventory_create(max_obj)
    if(player->inventory == NULL){
        free(player);
        return NULL;
    }
    player->space_id = NO_ID;

    return player;
}

/******************************************************************
 *Funcion :player_destroy
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de destruir el jugador
 *Input: El player
 *Output: nada
 ********************************************************************/

STATUS player_destroy(Player *player) {
    if (player) {
        if(player->inventory != NULL){
            if(inventory_destroy(player->inventory)==ERROR){
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

/******************************************************************
 *Funcion :player_set_name
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de establecer nombre del jugador
 *Input: El jugador y el nombre
 *Output: Ok si sale bien y ERROR si hay los parámetro de entrada no existen
 ********************************************************************/

STATUS player_set_name(Player *player, char *name) {
    if (!player || !name) {
        return ERROR;
    }
    strcpy(player->name, name);
    return OK;
}

/******************************************************************
 *Funcion :player_set_id
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de establecer el id del jugador
 *Input: El jugador y el id
 *Output: Ok si sale bien y Error si hay algo mal
 ********************************************************************/

STATUS player_set_id(Player *player, Id id) {
    if (!player) {
        return ERROR;
    }
    player->id = id;
    return OK;
}

/******************************************************************
 *Funcion :player_set_object_id
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de establecer el object id
 *Input: El jugador y el id del object
 *Output: Ok si sale bien y Error si hay algo mal
 ********************************************************************/

STATUS player_set_inventory(Player *player, Inventory *bag) {
    if (!player) {
        return ERROR;
    }
    if(player->inventory != NULL){
        inventory_destroy(palyer->inventory);
    }
    player->inventory = bag;
    return OK;
}

/******************************************************************
 *Funcion :player_set_space_id
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de establecer el space_id
 *Input: El jugador y el id del espacio
 *Output: Ok si sale bien y Error si hay algo mal
 ********************************************************************/

STATUS player_set_space_id(Player *player, Id space_id) {
    if (!player) {
        return ERROR;
    }
    player->space_id = space_id;
    return OK;
}

/******************************************************************
 *Funcion :player_get_name
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de devolver el nombre del jugador
 *Input: El jugador
 *Output: char * con el nombre del jugador o NULL si no existe el jugador
 ********************************************************************/

char * player_get_name(Player *player) {
    if (!player) {
        return NULL;
    }
    return player->name;
}

/******************************************************************
 *Funcion :player_get_id
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de devolver el id del jugador
 *Input: El jugador
 *Output: Id del jugador o NO_ID si no existe el jugador
 ********************************************************************/

Id player_get_id(Player *player) {
    if (!player) {
        return NO_ID;
    }
    return player->id;
}

/******************************************************************
 *Funcion :player_get_object_id
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se enccarga de devolver el id del object
 *Input: El jugador
 *Output: id del object o NO_ID si no existe el jugador
 ********************************************************************/

I


/******************************************************************
 *Funcion :player_get_space_id
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de devolver el id del space
 *Input: El jugador
 *Output: id del espacio o NO_ID si no existe el jugador
 ********************************************************************/

Id player_get_space_id(Player *player) {
    if (!player) {
        return NO_ID;
    }
    return player->space_id;
}



Inventory* player_get_inventory(Player *player){
    if(player==NULL)return NO_ID;

    return player->inventory;
}

BOOL player_drop_object(Player *player, Id id){

    if(player==NULL || id==NO_ID) return FALSE;
    if(player_has_object(player,id)==FALSE)return FALSE;
    if(inventory_delete_object(player->inventory)==ERROR)return FALSE;
    return TRUE;
}


BOOL player_pick_object(Player *player, Id id){
    if(player=NULL || id==NO_ID)return FALSE;

    if(inventory_is_full(player->inventory))return FALSE;
    if(inventory_add_object(player->inventory,id)==FALSE)return FALSE;
    return TRUE;
}

BOOL player_has_object(Player *player, Id id){
    if(player==NULL || id==NO_ID)return FALSE;

    return inventory_is_object_in(player->inventory, Id id);
}
BOOL player_bag_is_full(Player *player){
  if(!player) return TRUE;
  return inventory_is_full(player->inventory);
}
/******************************************************************
 *Funcion: player_print
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se enccarga de imprimir los datos del objeto
 *Input: El jugador y el fichero donde se han de escribir los datos
 *Output: int que si es mayor que 0, significa ha ido todo bien
 ********************************************************************/
int player_print(FILE *f, Player *player) {
    if (!f || !player) {
        return ERROR;
    }
    fprintf(f, "Nombre: %s, id=%ld, casilla=%ld, inventario: ", player->name, player->id, player->object_id, player->space_id);

    inventory_print(player->inventory);

    return OK;
}
