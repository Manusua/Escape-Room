
/* ===================================================================
File: graphic_engine.c
Version: 3.0
Date: 21-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Funciones que permiten crear, escribir y dibujar un entorno gráfico
Revision historica:
13-01-2015 versión 1.0 (código inicial)
1-10-2018 versión 2.0
      Se ha añadido que la máquina escriba los datos del jugador y el nombre de los objetos
1-10-2018 versión 3.0
                Se ha modificado la impresión por pantalla
=================================================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphic_engine.h"

/**Estructura de la máquina gráfica**/
struct _Graphic_engine {
    Area *map, *descript, *banner, *help, *feedback; /*Punteros a distintas áreas de escritura de datos*/
};

/******************************************************************
 *Funcion :graphic_engine_create
 *Date: ??
 *Autores: Código inicial
 *Description: Función que se encarga de crear la máquina gráfica
 *Input: nada
 *Output: la máquina gráfica creada o NULL
 ********************************************************************/

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

/******************************************************************
 *Funcion :graphic_engine_destroy
 *Date: ??
 *Autores: Código inicial
 *Description: Función que se encarga de destruir la máquina gráfica
 *Input: graphic_engine
 *Output: nada
 ********************************************************************/

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

/******************************************************************
 *Funcion :graphic_engine_paint_game
 *Date: 21-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que se encarga de pintar la máquina gráfica
 *Input: graphic_engine y game que se desea pintar
 *Output: nada
 ********************************************************************/

void graphic_engine_paint_game(Graphic_engine *ge, Game *game) {
    Id id_act = NO_ID, link_id_next = NO_ID, link_id_oca_east = NO_ID, link_id_oca_west = NO_ID, object = NO_ID;
    Space* space_act = NULL;
    char dibujo_casilla[TAM_DIBUJO];
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
        link_id_oca_east = space_get_east(space_act);
        link_id_oca_west = space_get_west(space_act);
        strcpy(dibujo_casilla, space_get_gdesc(space_act));

        if (id_act != NO_ID) {
            /*Imprimimos la parte inicial de la casilla*/
            if (link_id_oca_east != NO_ID && link_id_oca_west != NO_ID) {
              sprintf(str, " %2d +-------------+ %2d", (int) link_id_oca_west, (int) link_id_oca_east);
              screen_area_puts(ge->map, str);
                sprintf(str, " <--| J1        %2d|-->", (int) id_act);
            } else if (id_oca_east != NO_ID) {
              sprintf(str, "    +-------------+ %2d", (int) link_id_oca_east);
              screen_area_puts(ge->map, str);
                sprintf(str, "  | J1        %2d|>", (int) id_act);
            } else if (id_oca_west != NO_ID) {
              sprintf(str, " %2d +-------------+", (int) link_id_oca_west);
              screen_area_puts(ge->map, str);
                sprintf(str, " <--| J1        %2d|", (int) id_act);
            } else {
              sprintf(str, "    +-------------+");
              screen_area_puts(ge->map, str);
                sprintf(str, "    | J1        %2d|", (int) id_act);
            }
            screen_area_puts(ge->map, str);
            /*Imprimimos la primera parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "    |  ");
            for (i = 0, j = 4; i < TAM_DIBUJO_LINEA; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "     |");
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos la segunda parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "    |  ");
            for (i = TAM_DIBUJO_LINEA, j = 4; i < 2 * TAM_DIBUJO_LINEA; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "     |");

            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos la tercera parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "    |  ");
            for (i = 2 * TAM_DIBUJO_LINEA, j = 4; i < 3 * TAM_DIBUJO_LINEA; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "     |");
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos los objetos*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "    | ");
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
            sprintf(str, "    +-------------+");
            screen_area_puts(ge->map, str);
        }


        if (link_id_next != NO_ID) {
            link_id_oca_east = space_get_east(game_get_space(game, id_next));
            link_id_oca_west = space_get_west(game_get_space(game, id_next));
            sprintf(str, "          v %2d", (int) link_id_next);
            screen_area_puts(ge->map, str);
            strcpy(dibujo_casilla, space_get_gdesc(game_get_space(game, id_next)));
            /*Imprimimos la primera parte de la casilla*/
            if (link_id_oca_east != NO_ID && link_id_oca_west != NO_ID) {
              sprintf(str, " %2d +-------------+ %2d", (int) link_id_oca_west, (int) link_id_oca_east);
              screen_area_puts(ge->map, str);
                sprintf(str, " <--|           %2d|-->", (int) id_next);
            } else if (id_oca_east != NO_ID) {
              sprintf(str, "    +-------------+ %2d", (int) link_id_oca_east);
              screen_area_puts(ge->map, str);
                sprintf(str, "  |           %2d|>", (int) id_next);
            } else if (id_oca_west != NO_ID) {
              sprintf(str, " %2d +-------------+", (int) link_id_oca_west);
              screen_area_puts(ge->map, str);
                sprintf(str, " <--|           %2d|", (int) id_next);
            } else {
              sprintf(str, "    +-------------+");
              screen_area_puts(ge->map, str);
                sprintf(str, "    |           %2d|", (int) id_next);
            }
            screen_area_puts(ge->map, str);
            /*Imprimimos la primera parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "    |  ");
            for (i = 0, j = 5; i < TAM_DIBUJO_LINEA; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "    |");
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos la segunda parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "    |  ");
            for (i = TAM_DIBUJO_LINEA, j = 5; i < 2 * TAM_DIBUJO_LINEA; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "    |");
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos la tercera parte del dibujo de la casilla*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "    |  ");
            for (i = 2 * TAM_DIBUJO_LINEA, j = 5; i < TAM_DIBUJO; i++, j++) {
                cadena_a_dibujar[j] = dibujo_casilla[i];
            }
            strcat(cadena_a_dibujar, "    |");
            strcpy(str, cadena_a_dibujar);
            screen_area_puts(ge->map, str);
            /*Imprimimos los objetos*/
            memset(cadena_a_dibujar, '\0', 255);
            strcpy(&cadena_a_dibujar[0], "  | ");
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
            sprintf(str, "  +-------------+");
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
    object = game_get_player_object(game);
    if (object == NO_ID) {
        sprintf(str, " Objetos del jugador J1 %s: ", game_get_player_name(game));
    } else {
        sprintf(str, " Objetos del jugador J1 %s: %s", game_get_player_name(game), game_get_object_name(game, object));
    }
    screen_area_puts(ge->descript, str);
    if (game_get_roll_die(game) < 1) {
        sprintf(str, "  Ultimo valor del dado: ");
    } else {
        sprintf(str, "  Ultimo valor del dado: %d", game_get_roll_die(game));
    }
    screen_area_puts(ge->descript, str);
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
