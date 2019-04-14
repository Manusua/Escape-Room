
/* ===================================================================
File: space.h
Version: 3.0
Date: 1-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Contiene todos los prototipos de las funciones de space.c
Revision historica:
13-01-2015 versión 1.0 (Código inicial)
1-10-2018 version 2.0
       Nuevas funciones para coger y soltar un objeto.
21-10-2018 version 3.0 Nuevas funciones para manejar la descripción gráfica de un espacio
=================================================================== */
#ifndef SPACE_H
#define SPACE_H


#include "types.h"
#include "set.h"

#define MAX_SPACES 100
#define FIRST_SPACE 1
#define TAM_DIBUJO 21
#define TAM_DIBUJO_LINEA TAM_DIBUJO/3

typedef struct _Space Space;

/*Funciones para crear y destruir espacios*/
Space* space_create(Id id);
STATUS space_destroy(Space* space);

/*Funciones para obtener id y el nombre y cambiar el nombre de un espacio*/
Id space_get_id(Space* space);
STATUS space_set_name(Space* space, char* name);
const char* space_get_name(Space* space);

/*Funciones para obtener y establecer otros campos del espacio*/
STATUS space_set_north(Space* space, Id id);
Id space_get_north(Space* space);
STATUS space_set_south(Space* space, Id id);
Id space_get_south(Space* space);
STATUS space_set_east(Space* space, Id id);
Id space_get_east(Space* space);
STATUS space_set_west(Space* space, Id id);
Id space_get_west(Space* space);

/*Funcion para saber si un objeto está en un espacio*/
BOOL space_is_object_in(Space* space, Id id);

/*Función para imprimir un espacio*/
STATUS space_print(Space* space);

/*Funciones para coger y soltar un objeto*/
STATUS space_take_object(Space *space, Id id);
STATUS space_leave_object(Space *space, Id id);

/*funciones para manipular y obtener la informacion del dibujo*/
char* space_get_gdesc(Space *);
STATUS space_set_gdesc(Space*, char *);

/*funciones para manipular y obtener la descripcion de un espacio*/
char *space_get_description(Space *space);
STATUS space_set_description(Space *space, char *description);

#endif
