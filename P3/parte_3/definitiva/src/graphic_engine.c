/**
 * @brief En este fichero estaran las funciones relacionadas con la interfaz gráfica
 * @file graphic_engine.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 2.0
 * @date 8/11/2018
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphic_engine.h"

struct _Graphic_engine {
    Area *map;/*!< mapa*/
    Area *descript;/*!< descripcion*/
    Area *banner;/*!<  banner*/
    Area *help;/*!< ayuda*/
    Area *feedback; /*!< Devuelve*/
}; /*!< Estructura de la interfaz gráfica */

/**
* @brief crea una interfaz grafica 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 8/11/2018
* @return Graphic_engine (la interfaz que hemos creado)
*/
Graphic_engine *graphic_engine_create() {
    static Graphic_engine *ge = NULL;

    if (ge)
        return ge;

    screen_init();
    ge = (Graphic_engine *) malloc(sizeof (Graphic_engine));

    ge->map = screen_area_init(1, 1, 48, 15);
    ge->descript = screen_area_init(50, 1, 29, 15);
    ge->banner = screen_area_init(28, 17, 23, 1);
    ge->help = screen_area_init(1, 18, 78, 3);
    ge->feedback = screen_area_init(1, 21, 78, 3);

    return ge;
}

/**
* @brief destruye una interfaz grafica 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 8/11/2018
* @param ge (la interfaz que se va a destruir)
* @return void (no devuelve nada)
*/
void graphic_engine_destroy(Graphic_engine *ge) {
    if (!ge)
        return;

    screen_area_destroy(ge->map);
    screen_area_destroy(ge->descript);
    screen_area_destroy(ge->banner);
    screen_area_destroy(ge->help);
    screen_area_destroy(ge->feedback);

    screen_destroy();
    free(ge);
    return;
}

/**
* @brief hace la interfaz grafica del juego 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 8/11/2018
* @param ge (la interfaz que se va a usar)
* @param game (El juego que se va a usar)
* @return void (no devuelve nada)
*/
void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
    Id id_act = NO_ID, link_id_next = NO_ID, link_id_east = NO_ID, link_id_west = NO_ID;
    Id id_west = NO_ID, id_east = NO_ID, id_next = NO_ID;
    Space* space_act = NULL;
    char dibujo_casilla[TAM_DIBUJO + 1];
    char str[255], cadena_a_dibujar[255];
    T_Command last_cmd = UNKNOWN;
    extern char *cmd_to_str[];
    int i, j;
    STATUS resultado_comando;


    /* Paint the in the map area */
    screen_area_clear(ge->map);
    if ((id_act = game_get_player_location(game)) != NO_ID) {
        space_act = game_get_space(game, id_act);
        link_id_next = space_get_south(space_act);
        link_id_east = space_get_east(space_act);
        link_id_west = space_get_west(space_act);
        strcpy(dibujo_casilla, space_get_gdesc(space_act));

        if (id_act != NO_ID) {
            /*Imprimimos la parte inicial de la casilla*/
            id_east = game_get_id_conected_space(game, link_id_east, id_act);
            id_west = game_get_id_conected_space(game, link_id_west, id_act);
            if (link_id_east != NO_ID && link_id_west != NO_ID && id_east != NO_ID && id_west != NO_ID) {
                sprintf(str, "  %2d +-------------+ %2d", (int) link_id_west, (int) link_id_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "%2d<--| J1        %2d|-->%2d", (int) id_west, (int) id_act, (int) id_east);
            } else if (link_id_east != NO_ID && id_east != NO_ID) {
                sprintf(str, "     +-------------+ %2d", (int) link_id_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "     | J1        %2d|-->%2d", (int) id_act, (int) id_east);
            } else if (link_id_west != NO_ID && id_west != NO_ID) {
                sprintf(str, "  %2d +-------------+", (int) link_id_west);
                screen_area_puts(ge->map, str);
                sprintf(str, "%2d<--| J1        %2d|", (int) id_west, (int) id_act);
            } else {
                sprintf(str, "     +-------------+");
                screen_area_puts(ge->map, str);
                sprintf(str, "     | J1        %2d|", (int) id_act);
            }
            screen_area_puts(ge->map, str);
            /*Imprimimos la primera parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "     |  ");
            for (i = 0, j = strlen(cadena_a_dibujar); i < TAM_DIBUJO_LINEA; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "    |");
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos la segunda parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "     |  ");
            for (i = TAM_DIBUJO_LINEA, j = strlen(cadena_a_dibujar); i < 2 * TAM_DIBUJO_LINEA; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "    |");

            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos la tercera parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "     |  ");
            for (i = 2 * TAM_DIBUJO_LINEA, j = strlen(cadena_a_dibujar); i < 3 * TAM_DIBUJO_LINEA; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "    |");
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos los objetos*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "     | ");
            game_cadena_objetos(game, space_act, cadena_a_dibujar);
            j = strlen(cadena_a_dibujar);
            for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                cadena_a_dibujar[j] = ' ';
                j++;
            }
            cadena_a_dibujar[j] = '|';
            j++;
            cadena_a_dibujar[j] = '\0';
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos la parte final de la casilla*/
            sprintf(str, "     +-------------+");
            screen_area_puts(ge->map, str);
        }

        id_next = game_get_id_conected_space(game, link_id_next, id_act);
        if (link_id_next != NO_ID && id_next != NO_ID) {
            link_id_east = space_get_east(game_get_space(game, id_next));
            link_id_west = space_get_west(game_get_space(game, id_next));
            id_west = game_get_id_conected_space(game, link_id_west, id_next);
            id_east = game_get_id_conected_space(game, link_id_east, id_next);
            sprintf(str, "           v %2d", (int) link_id_next);
            screen_area_puts(ge->map, str);
            strcpy(dibujo_casilla, space_get_gdesc(game_get_space(game, id_next)));
            /*Imprimimos la primera parte de la casilla*/
            if (link_id_east != NO_ID && link_id_west != NO_ID && id_east != NO_ID && id_west != NO_ID) {
                sprintf(str, "  %2d +-------------+ %2d", (int) link_id_west, (int) link_id_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "%2d<--|           %2d|-->%2d", (int) id_west, (int) id_next, (int) id_east);
            } else if (link_id_east != NO_ID && id_east != NO_ID) {
                sprintf(str, "     +-------------+ %2d", (int) link_id_east);
                screen_area_puts(ge->map, str);
                sprintf(str, "     |           %2d|-->%2d", (int) id_next, (int) id_east);
            } else if (link_id_west != NO_ID && id_west != NO_ID) {
                sprintf(str, "  %2d +-------------+", (int) link_id_west);
                screen_area_puts(ge->map, str);
                sprintf(str, "%2d<--|           %2d|", (int) id_west, (int) id_next);
            } else {
                sprintf(str, "     +-------------+");
                screen_area_puts(ge->map, str);
                sprintf(str, "     |           %2d|", (int) id_next);
            }
            screen_area_puts(ge->map, str);
            /*Imprimimos la primera parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "     |  ");
            for (i = 0, j = strlen(cadena_a_dibujar); i < TAM_DIBUJO_LINEA; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "    |");
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos la segunda parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "     |  ");
            for (i = TAM_DIBUJO_LINEA, j = strlen(cadena_a_dibujar); i < 2 * TAM_DIBUJO_LINEA; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "    |");
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos la tercera parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "     |  ");
            for (i = 2 * TAM_DIBUJO_LINEA, j = strlen(cadena_a_dibujar); i < TAM_DIBUJO; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "    |");
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos los objetos*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "     | ");
            game_cadena_objetos(game, game_get_space(game, id_next), cadena_a_dibujar);
            j = strlen(cadena_a_dibujar);
            for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                cadena_a_dibujar[j] = ' ';
                j++;
            }
            cadena_a_dibujar[j] = '|';
            j++;
            cadena_a_dibujar[j] = '\0';
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos la parte final de la casilla*/
            sprintf(str, "     +-------------+");
            screen_area_puts(ge->map, str);
        }
    }

    /* Paint the in the description area */
    screen_area_clear(ge->descript);
    /*Escribimos la localización de todos los objetos*/
    memset(cadena_a_dibujar, '\0', 255);
    game_cadena_objetos_localizacion(game, cadena_a_dibujar);
    sprintf(str, "  Objects location:");
    screen_area_puts(ge->descript, str);
    sprintf(str, " %s", cadena_a_dibujar);
    screen_area_puts(ge->descript, str);
    /*Escribimos los objetos del jugador*/
    memset(cadena_a_dibujar, '\0', 255);
    game_cadena_objetos_jugador(game, cadena_a_dibujar);
    if (strcmp(cadena_a_dibujar, "") == 0) {
        sprintf(str, " Objetos del jugador J1 %s: ", game_get_player_name(game));
    } else {
        sprintf(str, " Objetos del jugador J1 %s: %s", game_get_player_name(game), cadena_a_dibujar);
    }
    screen_area_puts(ge->descript, str);
    if (game_get_roll_die(game) < 1) {
        sprintf(str, "  Ultimo valor del dado: ");
    } else {
        sprintf(str, "  Ultimo valor del dado: %d", game_get_roll_die(game));
    }
    screen_area_puts(ge->descript, str);
    if (game_get_last_command(game) == INSPECT) {
        if (strcmp(game_get_ultima_descripcion(game), "") != 0) {
            sprintf(str, "  Descripcion pedida: %s.", game_get_ultima_descripcion(game));
            screen_area_puts(ge->descript, str);
        } else {
            sprintf(str, "  Descripcion pedida: No disponible.");
            screen_area_puts(ge->descript, str);
        }
    }
    /* Paint the in the banner area */
    screen_area_puts(ge->banner, " The game of the Goose ");

    /* Paint the in the help area */
    screen_area_clear(ge->help);
    sprintf(str, " The commands you can use are:");
    screen_area_puts(ge->help, str);
    sprintf(str, "     go(g), take(t), leave(l), roll(r), inspect(i) or quit(q)");
    screen_area_puts(ge->help, str);
    sprintf(str, "     following(f), previous(p), oca_following(o), oca_previous(q)");
    screen_area_puts(ge->help, str);
    /* Paint the in the feedback area */
    last_cmd = game_get_last_command(game);
    resultado_comando = game_get_resultado_last_command(game);
    if (resultado_comando == OK) {
        sprintf(str, " %s: OK", cmd_to_str[last_cmd - NO_CMD]);
    } else {
        sprintf(str, " %s: ERROR", cmd_to_str[last_cmd - NO_CMD]);
    }
    screen_area_puts(ge->feedback, str);

    /* Dump to the terminal */
    screen_paint();
    printf("prompt:> ");
}
