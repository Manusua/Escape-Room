/**
 * @brief En este fichero implementamos las funciones del inventario
 * @file inventory.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 10/11/2018
 */


#ifndef INVENTORY_H
#define INVENTORY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "set.h"



typedef struct _Inventory Inventory;/*!< Estructura del inventario */

/**
* @brief crea un inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param tam (tamaño del inventario)
* @return inventory (El inventario que crea)
*/
Inventory * inventory_create(int tam);

/**
* @brief destruye un inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario a destruir)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS inventory_destroy(Inventory *bag);

/**
* @brief comprueba si el inventario esta lleno
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario a usar)
* @return BOOL (TRUE si esta lleno o FALSE de lo contrario)
*/
BOOL inventory_is_full(Inventory *bag);

/**
* @brief comprueba si el inventario esta vacio
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario a usar)
* @return BOOL (TRUE si esta vacio o FALSE de lo contrario)
*/
BOOL inventory_is_empty(Inventory *bag);

/**
* @brief comprueba si el objeto esta en el inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario a usar)
* @param id (Id del objeto)
* @return BOOL (TRUE si esta en el inventario o FALSE de lo contrario)
*/
BOOL inventory_is_object_in(Inventory *bag, Id id);

/**
* @brief añade un objeto del inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario a modificar)
* @param id (Id del objeto)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS inventory_add_object(Inventory *bag, Id id);

/**
* @brief quita un objeto del inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario a modificar)
* @param id (Id del objeto)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS inventory_delete_object(Inventory *bag, Id id);

/**
* @brief devuelve los objetos del inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario a destruir)
* @return Set (Objetos del inventario)
*/
Set* inventory_get_set(Inventory *bag);

/**
* @brief devuelve el tamaño de un inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario a usar)
* @return int (Tamaño del inventario)
*/
int inventory_get_size(Inventory *bag);

/**
* @brief modifica los objetos de un inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario a modificar)
* @param set (Objetos nuevos del inventario)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS inventory_set_set(Inventory *bag, Set *set);

/**
* @brief cambia el tamaño de un inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario que se va a cambiar)
* @param tam (tamaño nuevo del inventario)
* @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
*/
STATUS inventory_set_size(Inventory *bag, int tam);

/**
* @brief imprime un inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param bag (inventario a imprimir)
* @param filename (Donde se imprime)
* @return void (No devuelve nada)
*/
void inventory_print(Inventory *bag, FILE *filename);



#endif