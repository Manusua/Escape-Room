
/* ===================================================================
File: set.c
Version: 1.0
Date: 21-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Implementacion del modulo encargado de crear el conjunto de objectos
Revision historica: 
13-10-2018 versión 1.0 (Código inicial)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

/*estructura definida para almacenar un array de ids de los objetos */
struct _Set {
    Id id[TAM_SET]; /*ids*/
    int num_obj; /*numero de ids almacenados*/
};

/******************************************************************
 *Funcion :set_create
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de crear el conjunto
 *Input: numero de objetos
 *Output: el objeto o NULL si hay error
 ********************************************************************/
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

/******************************************************************
 *Funcion :set_destroy
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de destruir el conjunto
 *Input: el conjunto
 *Output: nada
 ********************************************************************/
STATUS set_destroy(Set *set) {
    if (set) {
        free(set);
        return OK;
    }
    return ERROR;
}

/******************************************************************
 *Funcion :set_add
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de añadir un objeto al conjunto
 *Input: conjunto y el id del objeto
 *Output: Status si todo va bien OK si hay errores ERROR
 ********************************************************************/
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

/******************************************************************
 *Funcion :set_add
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de quitar un objeto al conjunto
 *Input: conjunto y el id del objeto
 *Output: Status si todo va bien OK si hay errores ERROR
 ********************************************************************/
STATUS set_delete_element(Set * set, Id id) {
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

/******************************************************************
 *Funcion :set_get_numids
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de devolver el nuermo de objetos
 *Input: conjunto
 *Output: el numero de objetos
 ********************************************************************/
int set_get_num_ids(Set *set) {
    return set->num_obj + 1;
}

/******************************************************************
 *Funcion :set_id_in
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de ver si el objeto esta en el conjunto o no
 *Input: conjunto y el id del objeto
 *Output: boolean
 ********************************************************************/
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

/******************************************************************
 *Funcion :set_is_empty
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que ve si el conjunto esta vacio o no
 *Input: conjunto
 *Output:boolean
 ********************************************************************/
BOOL set_is_empty(Set*set) {
    if (!set) {
        return FALSE;
    }
    if (set->num_obj == -1) {
        return TRUE;
    }
    return FALSE;
}

/******************************************************************
 *Funcion :set_is_full
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de ver si el conjunto esta lleno o no
 *Input: conjunto
 *Output: booloean
 ********************************************************************/
BOOL set_is_full(Set *set) {
    if (set->num_obj == TAM_SET - 1) {
        return TRUE;
    }
    return FALSE;
}

/******************************************************************
 *Funcion :set_print
 *Date: 1-10-2018
 *Autores: Saul Almazan
 *Description: Funcion que se encarga de imprimir el conjunto
 *Input: conjunto
 *Output: int que sera >0 si va todo bien y sino -1
 ********************************************************************/
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
