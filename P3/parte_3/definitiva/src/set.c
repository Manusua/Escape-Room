/**
 * @brief En este fichero implementamos las funciones de set
 * @file set.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 20/10/2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"


struct _Set {
    Id id[TAM_SET]; /*!< ids */
    int num_obj; /*!< numero de ids almacenados */
};/*!< Estructura de Set */

/**
* @brief crea un Set 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @return Set (El set que crea)
*/
Set * set_create() {
    int i;
    Set * set;
    set = (Set*) malloc(sizeof (Set));
    if (!set) {
        return NULL;
    }
    set->num_obj = -1;
    for (i = 0; i < TAM_SET; i++) {
        set->id[i] = NO_ID;
    }
    return set;
}

/**
* @brief destruye y libera la memoria de un Set 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a destruir)
* @return void (No devuelve nada)
*/
void set_destroy(Set *set) {
    if (set) {
        free(set);
    }
}


/**
* @brief añade un objeto a un Set 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @param id (El id del objeto que se añade al set)
* @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
*/
STATUS set_add(Set * set, Id id) {
    if (!set || id == NO_ID) {
        return ERROR;
    }
    if (set->num_obj + 1 >= TAM_SET) {
        return ERROR;
    }
    set->id[set->num_obj + 1] = id;
    set->num_obj = set->num_obj + 1;
    return OK;

}


/**
* @brief borra un objeto de un Set 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @param id (El id del objeto que se borra del set)
* @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
*/
STATUS set_delete_element(Set *set, Id id) {
    int i;
    if (!set || id == NO_ID) {
        return ERROR;
    }
    i = 0;
    while (set->id[i] != id && i < TAM_SET) {
        i++;
    }
    if (i >= TAM_SET) return ERROR;
    set->id[i] = NO_ID;
    for (i = i + 1; i < TAM_SET && set->id[i] != NO_ID; i++) { /*Movemos todos los elementos para no dejar huecos*/
        set->id[i - 1] = set->id[i];
    }
    set->id[i - 1] = NO_ID;
    set->num_obj--;
    return OK;
}


/**
* @brief devuelve el numero de objetos 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @return int (el numero de objetos)
*/
int set_get_num_ids(Set *set) {
    return set->num_obj + 1;
}

/**
* @brief comprueba si un objeto esta dentro de un set
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @param id (El id del objeto que se comprueba)
* @return BOOl (TRUE si el objeto esta dentro del set o FALSE de lo contrario)
*/
BOOL set_is_id_in(Set*set, Id id) {
    int i, flag = 0;
    for (i = 0; i <= set->num_obj; i++) {
        if (set->id[i] == id) {
            flag = 1;
        }
    }
    if (flag == 1) {
        return TRUE;
    }
    return FALSE;
}

/**
* @brief comprueba si un set esta vacio
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @return BOOl (TRUE si el set esta vacio o FALSE de lo contrario)
*/
BOOL set_is_empty(Set*set) {
    if (!set) {
        return FALSE;
    }
    if (set->num_obj == -1) {
        return TRUE;
    }
    return FALSE;
}

/**
* @brief comprueba si un set esta lleno
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @return BOOl (TRUE si el set esta lleno o FALSE de lo contrario)
*/
BOOL set_is_full(Set *set) {
    if (set->num_obj == TAM_SET - 1) {
        return TRUE;
    }
    return FALSE;
}

/**
* @brief imprime un set
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param f (donde se va a imprimir)
* @param set (El set a imprimir)
* @return int (-1 si hay algun error)
*/
int set_print(FILE *f, Set *set) {
    int i, sum = 0;
    if (!set) {
        return -1;
    }
    for (i = 0; i <= set->num_obj; i++) {
        sum = sum + fprintf(f, "%ld\t", set->id[i]);
    }
    fprintf(f, "\n");
    return sum;
}
