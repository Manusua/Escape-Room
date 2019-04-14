
/* ===================================================================
File: die.c
Version: 1.0
Date: 21-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: TAD dado
Revision historica: 
13-10-2018 versión 1.0 (Código inicial)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "die.h"

/*Estructura de un dado que almacena sun id y el último resultado*/
struct _Die {
    Id id; /*Id del dado*/
    int resultado_anterior; /*Último resultado*/
};

/******************************************************************
 *Funcion: die_create
 *Date: 13-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Función que crea un dado
 *Input: nada
 *Output: el dado creado
 ********************************************************************/

Die *die_create() {
    Die *die = NULL;
    die = (Die*) calloc(1, sizeof (Die));
    if (die == NULL) return NULL;
    die->id = NO_ID;
    return die;
}

/******************************************************************
 *Funcion: die_destroy
 *Date: 13-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Función que libera memoria de un dado
 *Input: el dado a destruir
 *Output: nada
 ********************************************************************/

void die_destroy(Die *die) {
    if (die == NULL) return;
    free(die);
    return;
}

/******************************************************************
 *Funcion: die_set_id
 *Date: 13-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Función que establece el id de un dado
 *Input: dado e id
 *Output: ok si toda la ejecución se completa y error si falla en algún punto
 ********************************************************************/

STATUS die_set_id(Die * die, Id id) {
    if (die == NULL || id == NO_ID) return ERROR;
    die->id = id;
    return OK;
}

/******************************************************************
 *Funcion: die_get_id
 *Date: 13-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Función que nos devuelve el id de un dado
 *Input: dado
 *Output: el id del dado o NO_ID si el dado no existe
 ********************************************************************/

Id die_get_id(Die *die) {
    if (die == NULL) return NO_ID;
    return die->id;
}

/******************************************************************
 *Funcion: die_get_resultado_anterior
 *Date: 13-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Función que nos devuelve el resultado anterior del dado
 *Input: dado
 *Output: el resultado o -1 si el dado no existe
 ********************************************************************/

int die_get_resultado_anterior(Die *die) {
    if (die == NULL) return -1;
    return die->resultado_anterior;
}

/******************************************************************
 *Funcion: roll_die
 *Date: 13-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Función que tira el dado
 *Input: dado
 *Output: resultado obtenido (entero entre 1 y 6)
 ********************************************************************/

int roll_die(Die *die) {
    int res, sup = 6, inf = 1;
    if (die == NULL) return -1;
    res = (int) ((rand() / (RAND_MAX + 1.0))*(sup - inf + 1) + inf);
    die->resultado_anterior = res;
    return res;
}

/******************************************************************
 *Funcion: die_print
 *Date: 13-10-2018
 *Autores: Alvaro Becerra Jiminez
 *Description: Función que imprime un dado
 *Input: dado
 *Output: número de caracteres impresos o un número menor que 0 si hay algún error
 ********************************************************************/

int die_print(FILE *f, Die *die) {
    if (die == NULL) return -1;
    return fprintf(f, "%ld, %d", die->id, die->resultado_anterior);
}
