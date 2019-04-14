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
#define TAM_DRAW 100 /*!< TAM_DRAW */

struct _Graphic_engine {
    Area *map; /*!< mapa*/
    Area *descript; /*!< descripcion*/
    Area *banner; /*!<  banner*/
    Area *help; /*!< ayuda*/
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

    ge->map = screen_area_init(1, 1, 58, 20);
    ge->descript = screen_area_init(60, 1, 38, 20);
    ge->banner = screen_area_init(28, 22, 23, 1);
    ge->help = screen_area_init(1, 23, 98, 3);
    ge->feedback = screen_area_init(1, 26, 98, 5);

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
    Id id_act = NO_ID, link_id_next = NO_ID, link_id_east = NO_ID, link_id_west = NO_ID, link_id_down = NO_ID, link_id_up = NO_ID;
    Id id_west = NO_ID, id_east = NO_ID, id_south = NO_ID, id_north = NO_ID, id_up = NO_ID, id_down = NO_ID, link_id_prev = NO_ID;
    Space* space_act = NULL;
    Link *link = NULL, *link1 = NULL;
    char dibujo_casilla[TAM_DIBUJO + 1];
    char str[255], string_to_draw[TAM_DRAW];
    char name_link[TAM_DRAW], name_link_1[WORD_SIZE];
    /*extern char *cmd_to_str[];*/
    int i, j;

    /* Paint the in the map area */
    screen_area_clear(ge->map);
    if ((id_act = game_get_player_location(game)) != NO_ID) {
        space_act = game_get_space(game, id_act);
        link_id_prev = space_get_north(space_act);
        link_id_next = space_get_south(space_act);
        link_id_east = space_get_east(space_act);
        link_id_west = space_get_west(space_act);
        link_id_up = space_get_up(space_act);
        link_id_down = space_get_down(space_act);
        strcpy(dibujo_casilla, space_get_gdesc(space_act));

        if (id_act != NO_ID) {
            /*Imprimimos la parte inicial de la casilla*/
            id_east = game_get_id_conected_space(game, link_id_east, id_act);
            id_west = game_get_id_conected_space(game, link_id_west, id_act);
            id_north = game_get_id_conected_space(game, link_id_prev, id_act);
            link = game_get_link(game, link_id_prev);
            if (id_north != NO_ID) {
                if (link_get_status(link) == TRUE) {
                    strcpy(name_link, link_get_name(link));
                    sprintf(str, "                       / ");
                    screen_area_puts(ge->map, str);
                    sprintf(str, "                      / %s", name_link);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     +---------------/      -------------+");
                    screen_area_puts(ge->map, str);
                } else {
                    strcpy(name_link, link_get_name(link));
                    sprintf(str, "                                   ");
                    screen_area_puts(ge->map, str);
                    sprintf(str, "                        %s", name_link);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     +-----------------------------------+");
                    screen_area_puts(ge->map, str);
                }
            } else {
                sprintf(str, "                                   ");
                screen_area_puts(ge->map, str);
                sprintf(str, "                        ");
                screen_area_puts(ge->map, str);
                sprintf(str, "     +-----------------------------------+");
                screen_area_puts(ge->map, str);
            }
            sprintf(str, "     |                                   |");
            screen_area_puts(ge->map, str);
            sprintf(str, "     | J1                             %2d |", (int) id_act);
            screen_area_puts(ge->map, str);
            link = NULL;
            /*Link up*/
            id_up = game_get_id_conected_space(game, link_id_up, id_act);
            link = game_get_link(game, link_id_up);
            if (id_up != NO_ID) {
                if (link_get_status(link) == TRUE) {
                    strcpy(name_link, link_get_name(link));
                    sprintf(str, "     |                  __               |");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "     |                __|");
                    strcat(string_to_draw, name_link);
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    string_to_draw[j] = '|';
                    j++;
                    string_to_draw[j] = '\0';
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     |                |                  |");
                    screen_area_puts(ge->map, str);
                } else {
                    strcpy(name_link, link_get_name(link));
                    sprintf(str, "     |                  ->               |");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "     |                 |");
                    strcat(string_to_draw, name_link);
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    string_to_draw[j] = '|';
                    j++;
                    string_to_draw[j] = '\0';
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     |                                   |");
                    screen_area_puts(ge->map, str);
                }
            } else {
                sprintf(str, "     |                                   |");
                screen_area_puts(ge->map, str);
                sprintf(str, "     |                                   |");
                screen_area_puts(ge->map, str);
                sprintf(str, "     |                                   |");
                screen_area_puts(ge->map, str);
            }
            link = NULL;
            /*Link este y oeste*/
            if (link_id_east != NO_ID && link_id_west != NO_ID && id_east != NO_ID && id_west != NO_ID) {
                link = game_get_link(game, link_id_east);
                strcpy(name_link, link_get_name(link));
                link1 = game_get_link(game, link_id_west);
                strcpy(name_link_1, link_get_name(link1));
                if (link_get_status(link) == TRUE && link_get_status(link1) == TRUE) {
                    sprintf(str, "     /                                     /");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "    /");
                    strcat(string_to_draw, name_link_1);
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    strcat(string_to_draw, " /");
                    strcat(string_to_draw, name_link);
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "   /                                     /");
                    screen_area_puts(ge->map, str);
                } else if (link_get_status(link) == TRUE) {
                    sprintf(str, "     |                                     /");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "     |");
                    strcat(string_to_draw, name_link_1);
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    strcat(string_to_draw, " /");
                    strcat(string_to_draw, name_link);
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     |                                   /");
                    screen_area_puts(ge->map, str);
                } else if (link_get_status(link1) == TRUE) {
                    sprintf(str, "     /                                    |");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "    /");
                    strcat(string_to_draw, name_link_1);
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    strcat(string_to_draw, "|");
                    strcat(string_to_draw, name_link);
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "   /                                     |");
                    screen_area_puts(ge->map, str);
                } else {
                    sprintf(str, "     |                                   |");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "     |");
                    strcat(string_to_draw, name_link_1);
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    strcat(string_to_draw, "|");
                    strcat(string_to_draw, name_link);
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     |                                   |");
                    screen_area_puts(ge->map, str);
                }
            } else if (link_id_east != NO_ID && id_east != NO_ID) {
                link = game_get_link(game, link_id_east);
                strcpy(name_link, link_get_name(link));
                if (link_get_status(link) == TRUE) {
                    sprintf(str, "     |                                     /");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "     |");
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    strcat(string_to_draw, " /");
                    strcat(string_to_draw, name_link);
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     |                                   /");
                    screen_area_puts(ge->map, str);
                } else {
                    sprintf(str, "     |                                   |");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "     |");
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    strcat(string_to_draw, "|");
                    strcat(string_to_draw, name_link);
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     |                                   |");
                    screen_area_puts(ge->map, str);
                }
            } else if (link_id_west != NO_ID && id_west != NO_ID) {
                link1 = game_get_link(game, link_id_west);
                strcpy(name_link_1, link_get_name(link1));
                if (link_get_status(link1) == TRUE) {
                    sprintf(str, "     /                                   |");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "    /");
                    strcat(string_to_draw, name_link_1);
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    strcat(string_to_draw, "|");
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "   /                                     |");
                    screen_area_puts(ge->map, str);
                } else {
                    sprintf(str, "     |                                   |");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "     |");
                    strcat(string_to_draw, name_link_1);
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    strcat(string_to_draw, "|");
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     |                                   |");
                    screen_area_puts(ge->map, str);
                }
            } else {
                sprintf(str, "     |                                   |");
                screen_area_puts(ge->map, str);
                sprintf(str, "     |                                   |");
                screen_area_puts(ge->map, str);
                sprintf(str, "     |                                   |");
                screen_area_puts(ge->map, str);
            }
            sprintf(str, "     |                                   |");
            screen_area_puts(ge->map, str);
            /*link down*/
            id_down = game_get_id_conected_space(game, link_id_down, id_act);
            link = game_get_link(game, link_id_down);
            if (id_down != NO_ID) {
                if (link_get_status(link) == TRUE) {
                    strcpy(name_link, link_get_name(link));
                    sprintf(str, "     |                  __               |");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "     |                __|");
                    strcat(string_to_draw, name_link);
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    string_to_draw[j] = '|';
                    j++;
                    string_to_draw[j] = '\0';
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     |                |                  |");
                    screen_area_puts(ge->map, str);
                } else {
                    strcpy(name_link, link_get_name(link));
                    sprintf(str, "     |                  ->               |");
                    screen_area_puts(ge->map, str);
                    memset(string_to_draw, '\0', TAM_DRAW);
                    strcat(string_to_draw, "     |                 |");
                    strcat(string_to_draw, name_link);
                    j = strlen(string_to_draw);
                    for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                        string_to_draw[j] = ' ';
                        j++;
                    }
                    string_to_draw[j] = '|';
                    j++;
                    string_to_draw[j] = '\0';
                    strcpy(str, string_to_draw);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "     |                                   |");
                    screen_area_puts(ge->map, str);
                }
            } else {
                sprintf(str, "     |                                   |");
                screen_area_puts(ge->map, str);
                sprintf(str, "     |                                   |");
                screen_area_puts(ge->map, str);
                sprintf(str, "     |                                   |");
                screen_area_puts(ge->map, str);
            }
            /*Imprimimos la primera parte del dibujo de la casilla*/
            memset(string_to_draw, '\0', TAM_DRAW);
            strcpy(&string_to_draw[0], "     |  ");
            strcat(string_to_draw, dibujo_casilla);
            j = strlen(string_to_draw);
            for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                string_to_draw[j] = ' ';
                j++;
            }
            strcat(string_to_draw, "|");
            strcpy(str, string_to_draw);
            screen_area_puts(ge->map, str);
            /*Imprimimos los objetos*/
            if (space_get_light(space_act) == TRUE) {
                memset(string_to_draw, '\0', TAM_DRAW);
                strcpy(&string_to_draw[0], "     | ");
                game_string_objects(game, space_act, string_to_draw);
                j = strlen(string_to_draw);
                for (i = TAM_TOTAL_CASILLA - j - 1; i > 0; i--) {
                    string_to_draw[j] = ' ';
                    j++;
                }
                string_to_draw[j] = '|';
                j++;
                string_to_draw[j] = '\0';
                strcpy(str, string_to_draw);
                screen_area_puts(ge->map, str);
            } else {
                sprintf(str, "     |                                   |");
                screen_area_puts(ge->map, str);
            }

            link = NULL;
            /*Imprimimos la parte final de la casilla*/
            link = game_get_link(game, link_id_next);
            id_south = game_get_id_conected_space(game, link_id_next, id_act);
            if (id_south != NO_ID) {
                if (link_get_status(link) == TRUE) {
                    strcpy(name_link, link_get_name(link));
                    sprintf(str, "     +---------------      /-------------+");
                    screen_area_puts(ge->map, str);
                    sprintf(str, "                          / %s", name_link);
                    screen_area_puts(ge->map, str);

                    sprintf(str, "                         /");
                    screen_area_puts(ge->map, str);

                } else {
                    strcpy(name_link, link_get_name(link));
                    sprintf(str, "     +-----------------------------------+");
                    screen_area_puts(ge->map, str);
                    sprintf(str, "                        %s", name_link);
                    screen_area_puts(ge->map, str);
                    sprintf(str, "                                   ");
                    screen_area_puts(ge->map, str);


                }
            } else {
                sprintf(str, "     +-----------------------------------+");
                screen_area_puts(ge->map, str);
                sprintf(str, "                                   ");
                screen_area_puts(ge->map, str);
                sprintf(str, "                        ");
                screen_area_puts(ge->map, str);

            }
            /*id_south = game_get_id_conected_space(game, link_id_next, id_act);
            if (id_south!=NO_ID){
              sprintf(str, "                     |                   ");
              screen_area_puts(ge->map, str);
              sprintf(str, "                     | %2d                   ", (int) id_south);
              screen_area_puts(ge->map, str);
              sprintf(str, "                     v                   ");
              screen_area_puts(ge->map, str);
            }*/
        }
    }
    /* Paint the in the description area */
    screen_area_clear(ge->descript);
    /*Escribimos la localización de todos los objetos*/
    /*memset(string_to_draw, '\0', TAM_DRAW);
    game_string_objects_localization(game, string_to_draw);
    sprintf(str, "  Objects location:");
    screen_area_puts(ge->descript, str);
    sprintf(str, " %s", string_to_draw);
    screen_area_puts(ge->descript, str);*/
    /*Escribimos los objetos del jugador*/
    memset(string_to_draw, '\0', TAM_DRAW);
    game_string_objects_player(game, string_to_draw);
    if (strcmp(string_to_draw, "") == 0) {
        sprintf(str, " Objetos del jugador J1 %s: ", game_get_player_name(game));
    } else {
        sprintf(str, " Objetos del jugador J1 %s: %s", game_get_player_name(game), string_to_draw);
    }
    screen_area_puts(ge->descript, str);
    if (game_player_bag_is_full(game) == TRUE) {
        sprintf(str, "  Mochila del jugador llena.");
        screen_area_puts(ge->descript, str);
    }
    /*if (game_get_roll_die(game) < 1) {
        sprintf(str, "  Ultimo valor del dado: ");
    } else {
        sprintf(str, "  Ultimo valor del dado: %d", game_get_roll_die(game));
    }
    screen_area_puts(ge->descript, str);*/
    if (space_get_light(space_act) == TRUE) {
        sprintf(str, "  Habitacion con luz.");
        screen_area_puts(ge->descript, str);
    } else {
        sprintf(str, "  Habitacion sin luz.");
        screen_area_puts(ge->descript, str);
    }
    if (game_get_last_command(game) == GO && game_get_result_last_command(game) == OK) {
        sprintf(str, "  Nueva habitacion: %s.", space_get_description(space_act));
        screen_area_puts(ge->descript, str);
    }
    if (game_get_last_command(game) == INSPECT && game_get_result_last_command(game) == OK) {
        if (strcmp(game_get_last_description_asked(game), "") != 0) {
            sprintf(str, "  Descripcion pedida: %s.", game_get_last_description_asked(game));
            screen_area_puts(ge->descript, str);
        } else {
            sprintf(str, "  Descripcion pedida: No disponible.");
            screen_area_puts(ge->descript, str);
        }
    }
    /* Paint the in the banner area */
    screen_area_puts(ge->banner, " La Casa Encantada ");

    /* Paint the in the help area */
    screen_area_clear(ge->help);
    sprintf(str, " The commands you can use are:");
    screen_area_puts(ge->help, str);
    sprintf(str, "     go(g), take(t), leave(l), roll(r), inspect(i), quit(q)");
    screen_area_puts(ge->help, str);
    sprintf(str, "     following(f), previous(p), goose_following(o), goose_previous(a)");
    screen_area_puts(ge->help, str);
    sprintf(str, "     turnon(e), turnoff(c) or open(h)");
    screen_area_puts(ge->help, str);
    /* Paint the in the feedback area */
    sprintf(str, "  %s", game_get_dialogue(game));
    screen_area_puts(ge->feedback, str);

    /* Dump to the terminal */
    screen_paint();
    printf("prompt:> ");
}
