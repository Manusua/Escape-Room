/**
 * @brief En este fichero definimos las funciones para el leer los diferentes elementos del juego de un fichero
 * @file game_management.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 2.0
 * @date 3/11/2018
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game_management.h"

/**
 * @brief carga los espacios en el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El fichero que contiene los datos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_load_spaces(Game* game, char* filename) {
    FILE* file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char gdesc[TAM_DIBUJO + 1] = "";
    char description[WORD_SIZE] = "";
    char detailed_description[WORD_SIZE] = "";
    char* toks = NULL;
    Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, up = NO_ID, down = NO_ID;
    Space* space = NULL;
    int light_print;
    STATUS status = OK;
    if (!filename) {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file)) {
        if (strncmp("#s:", line, 3) == 0) {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            north = atol(toks);
            toks = strtok(NULL, "|");
            east = atol(toks);
            toks = strtok(NULL, "|");
            south = atol(toks);
            toks = strtok(NULL, "|");
            west = atol(toks);
            toks = strtok(NULL, "|");
            up = atol(toks);
            toks = strtok(NULL, "|");
            down = atol(toks);
            toks = strtok(NULL, "|");
            light_print = atoi(toks);
            toks = strtok(NULL, "|");
            if (toks != NULL) {
                if (strcmp(toks, "\r\n") != 0 && strcmp(toks, "\n") != 0) {
                    /*strcpy(&gdesc[0], toks);
                    toks = strtok(NULL, "|");
                    strcpy(&gdesc[7], toks);
                    toks = strtok(NULL, "|");
                    strcpy(&gdesc[14], toks);*/
                    strcpy(gdesc, toks);
                } else {
                    memset(gdesc, ' ', TAM_DIBUJO);
                    gdesc[TAM_DIBUJO] = '\0';
                }
            } else {
                memset(gdesc, ' ', TAM_DIBUJO);
                gdesc[TAM_DIBUJO] = '\0';
            }
            toks = strtok(NULL, "|");
            if (toks != NULL) {
                if (strcmp(toks, "\r\n") != 0 && strcmp(toks, "\n") != 0) {
                    strcpy(description, toks);
                } else strcpy(description, "");
            } else strcpy(description, "");
            toks = strtok(NULL, "|");
            if (toks != NULL) {
                if (strcmp(toks, "\r\n") != 0 && strcmp(toks, "\n") != 0) {
                    strcpy(detailed_description, toks);
                } else strcpy(detailed_description, "");
            } else strcpy(detailed_description, "");
#ifdef DEBUG
            printf("Leido:#s:%ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%d|%s|%s|%s\n", id, name, north, east, south, west, up, down, light_print, gdesc, description, detailed_description);
#endif
            space = space_create(id);
            if (space != NULL) {
                space_set_name(space, name);
                space_set_north(space, north);
                space_set_east(space, east);
                space_set_south(space, south);
                space_set_west(space, west);
                space_set_up(space, up);
                space_set_down(space, down);
                if (light_print == 1) {
                    space_set_light(space, TRUE);
                } else {
                    space_set_light(space, FALSE);
                }
                space_set_gdesc(space, gdesc);
                space_set_description(space, description);
                space_set_detailed_description(space, detailed_description);
                game_add_space(game, space);
            }
        }
    }

    if (ferror(file)) {
        status = ERROR;
    }

    fclose(file);

    return status;
}

/**
 * @brief carga los objetos en el juego
 * @author Manueel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El fichero que contiene los datos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */

STATUS game_management_load_object(Game *game, char* filename) {
    FILE* file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    char description[WORD_SIZE] = "";
    char detailed_description[WORD_SIZE] = "";
    char* toks = NULL;
    int light_print, on_print, movable_print, hidden_print;
    Id id = NO_ID, space_id = NO_ID, open = NO_ID, original_location = NO_ID;
    Object* object = NULL;
    STATUS status = OK;
    if (!filename) {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file)) {
        if (strncmp("#o:", line, 3) == 0) {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            space_id = atol(toks);
            toks = strtok(NULL, "|");
            open = atol(toks);
            toks = strtok(NULL, "|");
            original_location = atol(toks);
            toks = strtok(NULL, "|");
            light_print = atol(toks);
            toks = strtok(NULL, "|");
            on_print = atol(toks);
            toks = strtok(NULL, "|");
            movable_print = atol(toks);
            toks = strtok(NULL, "|");
            hidden_print = atol(toks);
            toks = strtok(NULL, "|");
            if (toks != NULL) {
                if (strcmp(toks, "\r\n") != 0 && strcmp(toks, "\n") != 0) {
                    strcpy(description, toks);
                } else strcpy(description, "");
            } else strcpy(description, "");
            toks = strtok(NULL, "|");
            if (toks != NULL) {
                if (strcmp(toks, "\r\n") != 0 && strcmp(toks, "\n") != 0) {
                    strcpy(detailed_description, toks);
                } else strcpy(detailed_description, "");
            } else strcpy(detailed_description, "");
#ifdef DEBUG
            printf("#o:%ld|%s|%ld|%ld|%ld|%d|%d|%d|%d|%s|%s\n", id, name, space_id, open, original_location, light_print, on_print, movable_print, hidden_print, description, detailed_description);
#endif
            object = object_create();
            if (object != NULL) {
                object_set_name(object, name);
                object_set_id(object, id);
                game_set_object_location(game, space_id, id);
                object_set_description(object, description);
                if (on_print == 1) {
                    object_set_on(object, TRUE);
                } else {
                    object_set_on(object, FALSE);
                }
                if (light_print == 1) {
                    object_set_light(object, TRUE);
                } else {
                    object_set_light(object, FALSE);
                }
                if (movable_print == 1) {
                    object_set_movable(object, TRUE);
                } else {
                    object_set_movable(object, FALSE);
                }
                if (hidden_print == 1) {
                    object_set_hidden(object, TRUE);
                } else {
                    object_set_hidden(object, FALSE);
                }
                object_set_original_location(object, original_location);
                object_set_detailed_description(object, detailed_description);
                object_set_open(object, open);
                game_add_object(game, object);
            }
        }
    }

    if (ferror(file)) {
        status = ERROR;
    }

    fclose(file);

    return status;
}

/**
 * @brief carga los links en el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El fichero que contiene los datos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_load_links(Game *game, char * filename) {
    FILE* file = NULL;
    char line[WORD_SIZE] = "";
    char name[WORD_SIZE] = "";
    Link *link;
    char* toks = NULL;
    Id id = NO_ID, id1, id2;
    BOOL estado;

    if (!filename) {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (!file) {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file)) {
        if (strncmp("#l:", line, 3) == 0) {
            toks = strtok(line + 3, "|");
            id = atol(toks); /*id de enlace*/
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            id1 = atol(toks);
            toks = strtok(NULL, "|");
            id2 = atol(toks);
            toks = strtok(NULL, "|");
            estado = atol(toks);

#ifdef DEBUG
            printf("Leido: %ld|%s|%ld|%ld|%d\n", id, name, id1, id2, estado);
#endif
            link = link_create();
            if (link != NULL) {
                link_set_name(link, name);
                link_set_id(link, id);
                link_set_conection(link, id1, id2);
                if (estado == 0) {
                    link_set_status(link, TRUE);
                } else {
                    link_set_status(link, FALSE);
                }
                game_add_link(game, link);
            }
        }
    }
    if (ferror(file)) {
        fclose(file);
        return ERROR;
    }
    fclose(file);

    return OK;

}

/**
 * @brief carga los jugadores en el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El fichero que contiene los datos)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_load_players(Game *game, char* filename) {

    FILE* file = NULL;
    char name[WORD_SIZE] = "";
    char line[WORD_SIZE] = "";
    char* toks = NULL;
    Id id = NO_ID, space_id = NO_ID, object_id = NO_ID;
    int num_obj;
    Player* player = NULL;
    STATUS status = OK;
    if (!filename) {
        return ERROR;
    }

    file = fopen(filename, "r");
    if (file == NULL) {
        return ERROR;
    }

    while (fgets(line, WORD_SIZE, file)) {
        if (strncmp("#p:", line, 3) == 0) {
            toks = strtok(line + 3, "|");
            id = atol(toks);
            toks = strtok(NULL, "|");
            strcpy(name, toks);
            toks = strtok(NULL, "|");
            space_id = atol(toks);
            toks = strtok(NULL, "|");
            num_obj = atol(toks);
#ifdef DEBUG
            printf("Leido: %ld|%s|%ld|%d\n", id, name, space_id, num_obj);
#endif
            player = player_create(num_obj);
            if (player != NULL) {
                player_set_name(player, name);
                player_set_id(player, id);
                player_set_space_id(player, space_id);
                while (toks != NULL) {
                    toks = strtok(NULL, "|");
                    if (toks != NULL) {
                        if (strcmp(toks, "\r\n") != 0 && strcmp(toks, "\n") != 0) {
                            object_id = atol(toks);
                            player_pick_object(player, object_id);
                        }
                    }
                }
                status = game_add_player(game, player);
            }
        }
    }

    if (ferror(file)) {
        status = ERROR;
    }
    fclose(file);

    return status;
}

/**
 * @brief guarda el juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El nombre del fichero donde se va a guardar el juego)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */

STATUS game_management_save(Game *game, char* filename) {
    int i;
    FILE *file;
    if (!filename) {
        return ERROR;
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        return ERROR;
    }

    for (i = 0; i < MAX_SPACES + 1 && game_get_space_order(game, i); ++i) {
        game_management_save_space(game_get_space_order(game, i), file);
    }
    for (i = 0; i < MAX_OBJECT && game_get_object_order(game, i); ++i) {
        game_management_save_object(game, game_get_object_order(game, i), file);
    }
    for (i = 0; i < MAX_LINK && game_get_link_order(game, i); ++i) {
        game_management_save_link(game_get_link_order(game, i), file);
    }
    game_management_save_player(game, file);
    fclose(file);

    return OK;
}

/**
 * @brief guarda un espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param space (el que queremos guardar)
 * @param f donde se va a guardar
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_save_space(Space *space, FILE *f) {
    char name[WORD_SIZE] = "";
    char gdesc[TAM_DIBUJO + 1] = "";
    char description[WORD_SIZE] = "";
    char detailed_description[WORD_SIZE] = "";
    int light_print;
    Id id = NO_ID, north = NO_ID, east = NO_ID, south = NO_ID, west = NO_ID, up = NO_ID, down = NO_ID;
    id = space_get_id(space);
    north = space_get_north(space);
    south = space_get_south(space);
    east = space_get_east(space);
    west = space_get_west(space);
    up = space_get_up(space);
    down = space_get_down(space);
    strcpy(name, space_get_name(space));
    strcpy(gdesc, space_get_gdesc(space));
    strcpy(description, space_get_description(space));
    strcpy(detailed_description, space_get_detailed_description(space));
    if (space_get_light(space) == TRUE) {
        light_print = 1;
    } else light_print = 0;
    fprintf(f, "#s:%ld|%s|%ld|%ld|%ld|%ld|%ld|%ld|%d|%s|%s|%s\n", id, name, north, east, south, west, up, down, light_print, gdesc, description, detailed_description);
    return OK;
}

/**
 * @brief guarda el jugador
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param game (el juego con el jugador a guardar)
 * @param f donde se va a guardar
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_save_player(Game *game, FILE *f) {
    Player *player = NULL;
    char name[WORD_SIZE] = "";
    char objects[WORD_SIZE];
    int num_obj, ret;
    Id id = NO_ID, space_id = NO_ID;
    player = game_get_player(game);
    if (player == NULL) return ERROR;
    id = player_get_id(player);
    space_id = player_get_space_id(player);
    num_obj = player_get_inventory_size(player);
    strcpy(name, game_get_player_name(game));
    memset(objects, '\0', WORD_SIZE);
    ret = game_string_object_player_save(game, objects);
    if (ret == OK) {
        fprintf(f, "#p:%ld|%s|%ld|%d|%s\n", id, name, space_id, num_obj, objects);
    } else {
        fprintf(f, "#p:%ld|%s|%ld|%d\n", id, name, space_id, num_obj);
    }
    return OK;
}

/**
 * @brief guarda un link
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param link (el que queremos guardar)
 * @param f donde se va a guardar
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS game_management_save_link(Link *link, FILE *f) {
    char name[WORD_SIZE] = "";
    int status;
    Id id = NO_ID, id1 = NO_ID, id2 = NO_ID;
    id = link_get_id(link);
    strcpy(name, link_get_name(link));
    id1 = link_get_conection_1(link);
    id2 = link_get_conection_2(link);
    if (link_get_status(link) == TRUE) {
        status = 0;
    } else status = 1;
    fprintf(f, "#l:%ld|%s|%ld|%ld|%d\n", id, name, id1, id2, status);
    return OK;
}

/**
 * @brief guarda un objeto
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param object (el que queremos guardar)
 * @param game (el juego)
 * @param f (El nombre del fichero donde está guardado el juego)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */

STATUS game_management_save_object(Game* game, Object *object, FILE *f) {
    char name[WORD_SIZE] = "";
    char description[WORD_SIZE] = "";
    char detailed_description[WORD_SIZE] = "";
    int light_print, hidden_print, movable_print, on_print;
    Id id = NO_ID, open = NO_ID, original_location = NO_ID, space_id = NO_ID;
    id = object_get_id(object);
    open = object_get_open(object);
    original_location = object_get_original_location(object);

    space_id = game_get_object_location(game, id);

    strcpy(name, object_get_name(object));
    strcpy(description, object_get_description(object));
    strcpy(detailed_description, object_get_detailed_description(object));
    if (object_get_light(object) == TRUE) {
        light_print = 1;
    } else light_print = 0;
    if (object_get_on(object) == TRUE) {
        on_print = 1;
    } else on_print = 0;
    if (object_get_hidden(object) == TRUE) {
        hidden_print = 1;
    } else hidden_print = 0;
    if (object_get_movable(object) == TRUE) {
        movable_print = 1;
    } else movable_print = 0;
    fprintf(f, "#o:%ld|%s|%ld|%ld|%ld|%d|%d|%d|%d|%s|%s\n", id, name, space_id, open, original_location, light_print, on_print, movable_print, hidden_print, description, detailed_description);
    return OK;
}

/**
 * @brief carga un juego
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 30/11/2018
 * @param game (El juego donde queremos cargar los datos)
 * @param filename (El nombre del fichero donde está guardado el juego)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */

STATUS game_management_load(Game *game, char* filename) {

    if (!filename) {
        return ERROR;
    }
    game_destroy_for_load(game);
    if (game_management_load_spaces(game, filename) == ERROR) return ERROR;
    if (game_management_load_links(game, filename) == ERROR) return ERROR;
    if (game_management_load_object(game, filename) == ERROR) return ERROR;
    if (game_management_load_players(game, filename) == ERROR) return ERROR;
    return OK;
}
