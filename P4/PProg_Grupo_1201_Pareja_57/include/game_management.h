/**
 * @brief En este fichero definimos las funciones para el leer los diferentes elementos del juego de un fichero
 * @file game_management.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 2.0
 * @date 3/11/2018
 */
#ifndef GAME_MANAGEMENT_H
#define GAME_MANAGEMENT_H

#include "game.h"

/*Función para cargar espacios y objetos*/

/**
 * @brief carga los espacios en el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El fichero que contiene los datos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_load_spaces(Game* game, char* filename);

/**
 * @brief carga los objetos en el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El fichero que contiene los datos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */

STATUS game_management_load_object(Game *game, char* filename);

/**
 * @brief carga los links en el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El fichero que contiene los datos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_load_links(Game *game, char * filename);


/**
 * @brief carga los jugadores en el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El fichero que contiene los datos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_load_players(Game *game, char* filename);

/**
 * @brief guarda el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El nombre del fichero donde se va a guardar el juego)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */

STATUS game_management_save(Game *game, char* filename);
/**
 * @brief guarda un espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param space (el que queremos guardar)
 * @param f donde se va a guardar
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_save_space(Space *space, FILE *f);
/**
 * @brief guarda el jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (el juego con el jugador a guardar)
 * @param f donde se va a guardar
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_save_player(Game *game, FILE *f);
/**
 * @brief guarda un link
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param link (el que queremos guardar)
 * @param f donde se va a guardar
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_save_link(Link *link, FILE *f);
/**
 * @brief guarda un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (el juego)
 * @param object (el que queremos guardar)
 * @param f (El nombre del fichero donde está guardado el juego)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */

STATUS game_management_save_object(Game* game, Object *object, FILE *f);

/**
 * @brief carga un juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 30/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El nombre del fichero donde está guardado el juego)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */

STATUS game_management_load(Game *game, char* filename);

#endif
