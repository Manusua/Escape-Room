/**
 * @brief En este fichero implementamos las funciones de game_rules
 * @file game_rules.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0
 * @date 20/10/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include "game_rules.h"

/**
 * @brief ejecuta una regla del juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 16/12/2018
 * @param game (El juego que vamos a usar)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */

STATUS game_rules_run(Game *game) {
    int tirada;
    tirada = game_roll_die(game);
    if (tirada < 1) return ERROR;
    switch (tirada) {
        case 1:
            return game_change_light_space(game);
        case 2:
            return game_close_links(game);
        case 3:
            return game_kill_player(game);
        case 4:
            return game_appear_link(game);
        case 5:
            return game_change_object_location(game);
        case 6:
            return game_hide_objects(game);
        default: return ERROR;
    }
    return ERROR;
}
