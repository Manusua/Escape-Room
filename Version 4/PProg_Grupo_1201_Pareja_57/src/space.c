/**
 * @brief En este fichero implementamos las funciones de space
 * @file space.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0
 * @date 20/10/2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

struct _Space {
    Id id; /*!< Id del espacio*/
    char name[WORD_SIZE + 1]; /*!< Su nombre*/
    Id north; /*!< Id del espacio al norte*/
    Id south; /*!< Id del espacio al sur*/
    Id east; /*!< Id del espacio al este*/
    Id west; /*!< Id del espacio al oeste*/
    Id up; /*!< Id del espacio arriba*/
    Id down; /*!< Id del espacio abajo*/
    Set *objects; /*!< Id de los objetos que contiene*/
    char gdesc[TAM_DIBUJO + 1]; /*!< el dibujo*/
    char description[WORD_SIZE]; /*!< La descripcion del espacio*/
    BOOL light; /*!< Iluminación del espacio*/
    char detailed_description[WORD_SIZE]; /*!< La descripcion detallada del espacio*/
}; /*!< Estructura de espacio */

/**
 * @brief crea un espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param id (id del nuevo espacio)
 * @return Space* (El espacio que crea)
 */
Space* space_create(Id id) {

    Space *new_space = NULL;

    if (id == NO_ID)
        return NULL;

    new_space = (Space *) malloc(sizeof (Space));

    if (new_space == NULL) {
        return NULL;
    }
    new_space->id = id;

    new_space->name[0] = '\0';

    new_space->north = NO_ID;
    new_space->south = NO_ID;
    new_space->east = NO_ID;
    new_space->west = NO_ID;
    new_space->up = NO_ID;
    new_space->down = NO_ID;
    new_space->light = FALSE;
    new_space->objects = set_create();

    memset(new_space->gdesc, '\0', TAM_DIBUJO + 1);
    /*le introduciemos una cadena vacia para hacer comprobacion luego de que le introduzcamos algo */
    memset(new_space->description, '\0', WORD_SIZE);
    memset(new_space->detailed_description, '\0', WORD_SIZE);
    return new_space;
}

/**
 * @brief destruye y libera la memoria de un espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (el espacio a destruir)
 * @return STATUS (Ok si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_destroy(Space* space) {
    if (!space) {
        return ERROR;
    }
    set_destroy(space->objects);
    free(space);
    space = NULL;

    return OK;
}

/**
 * @brief cambia el nombre del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param name (nuevo nombre)
 * @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
 */
STATUS space_set_name(Space* space, char* name) {
    if (!space || !name) {
        return ERROR;
    }

    if (!strcpy(space->name, name)) {
        return ERROR;
    }

    return OK;
}

/**
 * @brief cambia el Id del norte del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para el norte)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_north(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
    space->north = id;
    return OK;
}

/**
 * @brief cambia el Id del sur del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para el sur)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_south(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
    space->south = id;
    return OK;
}

/**
 * @brief cambia el Id del este del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para el este)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_east(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
    space->east = id;
    return OK;
}

/**
 * @brief cambia el Id del oeste del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para el oeste)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_west(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
    space->west = id;
    return OK;
}

/**
 * @brief cambia el Id de arriba del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para arriba)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_up(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
    space->up = id;
    return OK;
}

/**
 * @brief cambia el Id de abajo del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @param id (Id nuevo para arriba)
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_down(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
    space->down = id;
    return OK;
}

/**
 * @brief cambia el estado de iluminación de un espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @param status
 * @return STATUS (OK si se ha realizado con exito o ERROR de lo contrario)
 */
STATUS space_set_light(Space* space, BOOL status) {
    if (!space) {
        return ERROR;
    }
    space->light = status;
    return OK;
}

/**
 * @brief devuelve el nombre del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return const char(El nombre del espacio)
 */
const char * space_get_name(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->name;
}

/**
 * @brief devuelve el Id del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return Id (El Id del espacio)
 */
Id space_get_id(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->id;
}

/**
 * @brief devuelve el Id del norte
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id del norte)
 */
Id space_get_north(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->north;
}

/**
 * @brief devuelve el Id del sur
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id del sur)
 */

Id space_get_south(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->south;
}

/**
 * @brief devuelve el Id del este
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id del este)
 */
Id space_get_east(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->east;
}

/**
 * @brief devuelve el Id del oeste
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id del oeste)
 */
Id space_get_west(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->west;
}

/**
 * @brief devuelve el Id arriba
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id arriba)
 */
Id space_get_up(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->up;
}

/**
 * @brief devuelve el Id abajo
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @return Id(devuelve el Id abajo)
 */
Id space_get_down(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->down;
}

/**
 * @brief devuelve el estado de iluminación
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 22/11/2018
 * @param space (espacio a usar)
 * @return True si está iluminado, False en caso contrario
 */
BOOL space_get_light(Space* space) {
    if (!space) {
        return FALSE;
    }
    return space->light;
}

/**
 * @brief imprime el espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return STATUS (Ok si se imprime bien o ERROR de lo contrario)
 */
STATUS space_print(Space* space) {
    Id id_aux = NO_ID;

    if (!space) {
        return ERROR;
    }

    fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", space->id, space->name);

    id_aux = space_get_north(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> North link: %ld.\n", id_aux);
    } else {
        fprintf(stdout, "---> No north link.\n");
    }

    id_aux = space_get_south(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> South link: %ld.\n", id_aux);
    } else {
        fprintf(stdout, "---> No south link.\n");
    }

    id_aux = space_get_east(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> East link: %ld.\n", id_aux);
    } else {
        fprintf(stdout, "---> No east link.\n");
    }

    id_aux = space_get_west(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> West link: %ld.\n", id_aux);
    } else {
        fprintf(stdout, "---> No west link.\n");
    }
    id_aux = space_get_up(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> Up link: %ld.\n", id_aux);
    } else {
        fprintf(stdout, "---> No up link.\n");
    }
    id_aux = space_get_down(space);
    if (NO_ID != id_aux) {
        fprintf(stdout, "---> Down link: %ld.\n", id_aux);
    } else {
        fprintf(stdout, "---> No down link.\n");
    }
    if (TRUE != space_get_light(space)) {
        fprintf(stdout, "---> Space with light.\n");
    } else {
        fprintf(stdout, "---> No light.\n");
    }
    set_print(stdout, space->objects);
    fprintf(stdout, "%s", space->gdesc);
    fprintf(stdout, "%s", space->description);
    fprintf(stdout, "%s", space->detailed_description);
    return OK;
}

/**
 * @brief coge un objeto del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (id del objeto a coger)
 * @return STATUS (OK si se coge bien o ERROR de lo contrario)
 */
STATUS space_take_object(Space *space, Id id) {
    if (!space) return ERROR;
    if (set_is_id_in(space->objects, id) == TRUE) {
        set_delete_element(space->objects, id);
        return OK;
    }
    return ERROR;
}

/**
 * @brief suelta un objeto del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (id del objeto a soltar)
 * @return STATUS (OK si se suelta bien o ERROR de lo contrario)
 */
STATUS space_leave_object(Space *space, Id id) {
    if (space == NULL || id == NO_ID) return ERROR;
    return set_add(space->objects, id);
}

/**
 * @brief devuelve el contenido del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return char (La informacion del espacio)
 */
char* space_get_gdesc(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->gdesc;
}

/**
 * @brief cambia el contenido del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param gdesc (La informacion del espacio)
 * @return STATUS (OK si se modifica bien o ERROR de lo contrario)
 */
STATUS space_set_gdesc(Space* space, char* gdesc) {
    if (!space || !gdesc) {
        return ERROR;
    }
    strcpy(space->gdesc, gdesc);
    return OK;

}

/**
 * @brief cambia la descripcion detallada del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param space (espacio a usar)
 * @param description (La informacion del espacio)
 * @return STATUS (OK si se modifica bien o ERROR de lo contrario)
 */
STATUS space_set_detailed_description(Space* space, char* description) {
    if (!space || !description) {
        return ERROR;
    }
    strcpy(space->detailed_description, description);
    return OK;
}

/**
 * @brief devuelve la descripcion detallada del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 23/11/2018
 * @param space (espacio a usar)
 * @return char (La descripcion del espacio)
 */
char *space_get_detailed_description(Space *space) {
    if (space == NULL) return NULL;
    return space->detailed_description;
}

/**
 * @brief devuelve la descripcion del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @return char (La descripcion del espacio)
 */
char *space_get_description(Space *space) {
    if (space == NULL) return NULL;
    return space->description;
}

/**
 * @brief cambia la descripcion del espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param description (La descripcion del espacio)
 * @return STATUS (OK si se modifica bien o ERROR de lo contrario)
 */
STATUS space_set_description(Space *space, char *description) {
    if (space == NULL || description == NULL) return ERROR;
    strcpy(space->description, description);
    return OK;
}

/**
 * @brief comprueba si hay un objeto en el espacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param space (espacio a usar)
 * @param id (Id del objeto a comprobar)
 * @return BOOL (TRUE si se el objeto esta en el espacio o FALSE de lo contrario)
 */
BOOL space_is_object_in(Space* space, Id id) {
    return set_is_id_in(space->objects, id);
}
