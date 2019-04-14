/**
 * @brief En este fichero definimos las funciones para las reglas del juego
 * @file dialogue.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0
 * @date 20/12/2018
 */

#ifndef GAME_RULES_H
#define GAME_RULES_H
#include "types.h"
#include "game.h"
/**
* @brief ejecuta una regla del juego
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
* @date 16/12/2018
* @param game (El juego que vamos a usar)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/

STATUS game_rules_run (Game *game);

#endif
