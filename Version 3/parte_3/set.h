/* ===================================================================
File: set.c
Version: 1.0
Date: 21-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Prototipos del TAD set.c
Revision historica: 
13-10-2018 versión 1.0 (Código inicial)
=================================================================== */

#ifndef SET_H
#define SET_H
#include "types.h"
#define TAM_SET 32
typedef struct _Set Set;

/*Funciones para crear y destruir un set*/
Set * set_create();
void set_destroy(Set *);

/*Funciones para trabajar con un set*/
STATUS set_add(Set *, Id);
STATUS set_delete_element(Set *, Id);
int set_get_num_ids(Set *);
BOOL set_is_id_in(Set*, Id);
BOOL set_is_empty(Set*);
BOOL set_is_full(Set *);
int set_print(FILE *, Set *);

#endif
