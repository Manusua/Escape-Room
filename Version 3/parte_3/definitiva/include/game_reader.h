/**
 * @brief En este fichero definimos las funciones para el leer los diferentes elementos del juego de un fichero
 * @file game_reader.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 2.0
 * @date 3/11/2018
 */
#ifndef GAME_READER_H
#define GAME_READER_H

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
STATUS game_reader_load_spaces(Game* game, char* filename);

/**
* @brief carga los objetos en el juego 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego donde queremos cargar los datos)
* @param filename (El fichero que contiene los datos)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS game_reader_load_object(Game* game, char* filename);
/**
* @brief carga los links en el juego 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego donde queremos cargar los datos)
* @param filename (El fichero que contiene los datos)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS game_reader_load_links(Game *game, char * filename);
/**
* @brief carga los jugadores en el juego 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param game (El juego donde queremos cargar los datos)
* @param filename (El fichero que contiene los datos)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS game_reader_load_players(Game *game, char * filename);
 
#endif
