/* ===================================================================
File: die.h
Version: 1.0
Date: 21-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: prototipos del TAD dado
Revision historica: 
13-10-2018 versión 1.0 (Código inicial)
=================================================================== */

#ifndef DIE_H
#define DIE_H
#include "types.h"

typedef struct _Die Die;

/*Funciones para trabajar con un dado*/
Die *die_create();
void die_destroy(Die *die);
STATUS die_set_id(Die * die, Id id);
Id die_get_id(Die *die);
int die_get_resultado_anterior(Die *die);
int roll_die(Die *die);
int die_print(FILE *f, Die *die);

#endif
