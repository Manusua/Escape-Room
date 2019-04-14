
/* ===================================================================
File: space.c
Version: 3.0
Date: 21-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Contiene todas las funciones que perimiten crear jugadores y trabajar con sus campos
Revision historica:
13-01-2015 versión 1.0 (Código inicial)
1-10-2018 version 2.0 Nuevas funciones para coger y soltar un objeto.
21-10-2018 version 3.0 Nuevas funciones para manejar la descripción gráfica de un espacio
=================================================================== */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "space.h"

/*Estructura de espacio que le permite relacionarse con espacios al norte, sur, este y oeste y guarda su nombre y un objeto*/
struct _Space {
    Id id; /*Id del espacio*/
    char name[WORD_SIZE + 1]; /*Su nombre*/
    Id north; /*Id del espacio al norte*/
    Id south; /*Id del espacio al sur*/
    Id east; /*Id del espacio al este*/
    Id west; /*Id del espacio al oeste*/
    Set *set; /*Id del objeto que contiene*/
    char gdesc[TAM_DIBUJO+1]; /*el dibujo*/
    char description[WORD_SIZE]; /*La descripcion del espacio*/
};

/******************************************************************
 *Funcion: space_create
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que crea un espacio
 *Input: id del espacio
 *Output: el espacio creado o NULL si hay algún error
 ********************************************************************/
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
    new_space->set = set_create();

    memset(new_space->gdesc, '\0', TAM_DIBUJO+1);
    /*le introduciemos una cadena vacia para hacer comprobacion luego de que le introduzcamos algo */
    memset(new_space->description, '\0', WORD_SIZE);
    return new_space;
}

/******************************************************************
 *Funcion: space_destroy
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que destruye un espacio
 *Input: espacio
 *Output: OK si no hay ningún error y ERROR si no existe el espacio a destruir
 ********************************************************************/
STATUS space_destroy(Space* space) {
    if (!space) {
        return ERROR;
    }
    set_destroy(space->set);
    free(space);
    space = NULL;

    return OK;
}

/******************************************************************
 *Funcion: space_set_name
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que establece el nombre de un espacio
 *Input: espacio, nombre
 *Output: OK si no hay ningún error y ERROR si no existe el espacio o no se copia el nombre
 ********************************************************************/
STATUS space_set_name(Space* space, char* name) {
    if (!space || !name) {
        return ERROR;
    }

    if (!strcpy(space->name, name)) {
        return ERROR;
    }

    return OK;
}

/******************************************************************
 *Funcion: space_set_north
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que establece el norte de un espacio
 *Input: espacio, id
 *Output: OK si no hay ningún error y ERROR si no existe el espacio o no existe el id
 ********************************************************************/
STATUS space_set_north(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
    space->north = id;
    return OK;
}

/******************************************************************
 *Funcion: space_set_south
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que establece el sur de un espacio
 *Input: espacio, id
 *Output: OK si no hay ningún error y ERROR si no existe el espacio o no existe el id
 ********************************************************************/

STATUS space_set_south(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
    space->south = id;
    return OK;
}

/******************************************************************
 *Funcion: space_set_east
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que establece el este de un espacio
 *Input: espacio, id
 *Output: OK si no hay ningún error y ERROR si no existe el espacio o no existe el id
 ********************************************************************/

STATUS space_set_east(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
    space->east = id;
    return OK;
}

/******************************************************************
 *Funcion: space_set_west
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que establece el oeste de un espacio
 *Input: espacio, id
 *Output: OK si no hay ningún error y ERROR si no existe el espacio o no existe el id
 ********************************************************************/

STATUS space_set_west(Space* space, Id id) {
    if (!space || id == NO_ID) {
        return ERROR;
    }
    space->west = id;
    return OK;
}

/******************************************************************
 *Funcion: space_get_name
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que obtiene el nombre de un espacio
 *Input: espacio
 *Output: el nombre si no hay ningún error y NULL si no existe el espacio
 ********************************************************************/


const char * space_get_name(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->name;
}

/******************************************************************
 *Funcion: space_get_id
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que obtiene el id de un espacio
 *Input: espacio
 *Output: el id si no hay ningún error y NO_ID si no existe el espacio
 ********************************************************************/

Id space_get_id(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->id;
}

/******************************************************************
 *Funcion: space_get_north
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que obtiene el id norte de un espacio
 *Input: espacio
 *Output: el id si no hay ningún error y NO_ID si no existe el espacio
 ********************************************************************/

Id space_get_north(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->north;
}

/******************************************************************
 *Funcion: space_get_south
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que obtiene el id sur de un espacio
 *Input: espacio
 *Output: el id si no hay ningún error y NO_ID si no existe el espacio
 ********************************************************************/


Id space_get_south(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->south;
}

/******************************************************************
 *Funcion: space_get_east
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que obtiene el id este de un espacio
 *Input: espacio
 *Output: el id si no hay ningún error y NO_ID si no existe el espacio
 ********************************************************************/

Id space_get_east(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->east;
}

/******************************************************************
 *Funcion: space_get_west
 *Date: ??
 *Autores: Codigo Inicial
 *Description: Función que obtiene el id oeste de un espacio
 *Input: espacio
 *Output: el id si no hay ningún error y NO_ID si no existe el espacio
 ********************************************************************/

Id space_get_west(Space* space) {
    if (!space) {
        return NO_ID;
    }
    return space->west;
}



/******************************************************************
 *Funcion: space_print
 *Date: 21-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que imprime los datos de un objeto
 *Input: espacio
 *Output: OK si todo ha ido bien y ERROR si algo falló
 ********************************************************************/

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

    set_print(stdout, space->set);
    fprintf(stdout, "%s", space->gdesc);
    return OK;
}

/*******************************************************************
 *Funcion: space_take_object
 *Date: 1-10-2018
 *Autores: Alvaro Becerra Jiminez y Saul Almazan
 *Description: Función que coge el objeto de un espacio
 *Input: espacio
 *Output: el id del objeto cogido o NO_ID si no existe el espacio o el objeto
 ********************************************************************/

STATUS space_take_object(Space *space, Id id) {
    if (!space) return ERROR;
    if (set_is_id_in(space->set, id) == TRUE) {
        set_delete_element(space->set, id);
        return OK;
    }
    return ERROR;
}

/******************************************************************
 *Funcion: space_leave_object
 *Date: 1-10-2018
 *Autores: Alvaro Becerra Jiminez y Saul Almazan
 *Description: Función que suelta un objeto en un espacio
 *Input: espacio
 *Output: OK si todo fue bien y ERROR si algo falló
 ********************************************************************/

STATUS space_leave_object(Space *space, Id id) {
    if (space == NULL || id == NO_ID) return ERROR;
    return set_add(space->set, id);
}

/******************************************************************
 *Funcion: space_get_gdesc
 *Date: 13-10-2018
 *Autores: Alvaro Becerra Jiminez y Saul Almazan
 *Description: Función devuelve el gdesc
 *Input: espacio
 *Output: char*
 ********************************************************************/

char* space_get_gdesc(Space* space) {
    if (!space) {
        return NULL;
    }
    return space->gdesc;
}

/******************************************************************
 *Funcion: space_set_gdesc
 *Date: 13-10-2018
 *Autores: Alvaro Becerra Jiminez y Saul Almazan
 *Description: Función que inserta el gdesc en el espacio
 *Input: espacio
 *Output: OK si todo fue bien y ERROR si algo falló
 ********************************************************************/

STATUS space_set_gdesc(Space* space, char* gdesc) {
    if (!space || !gdesc) {
        return ERROR;
    }
    strcpy(space->gdesc, gdesc);
    return OK;

}

char *space_get_description(Space *space){
  if(space==NULL) return NULL;
  return space->description;
}

STATUS space_set_description(Space *space, char *description){
  if(space==NULL || description==NULL) return ERROR;
  strcpy(space->description, description);
  return OK;
}

/******************************************************************
 *Funcion: space_is_object_in
 *Date: 13-10-2018
 *Autores: Alvaro Becerra Jiminez y Saul Almazan
 *Description: Función que nos indica si un objeto está en un espacio
 *Input: espacio, id del objeto
 *Output: boolean
 ********************************************************************/

BOOL space_is_object_in(Space* space, Id id) {
    return set_is_id_in(space->set, id);
}
