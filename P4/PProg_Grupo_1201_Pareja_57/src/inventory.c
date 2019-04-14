/**
 * @brief En este fichero implementamos las funciones del inventario
 * @file inventory.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 10/11/2018
 */
#include "inventory.h"

struct _Inventory {
    Set *objects; /*!< objetos del inventario */
    int tam; /*!< tamaño maximo del inventario */
}; /*!< Estructura del inventario */

/**
 * @brief crea un inventario 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param tam (tamaño del inventario)
 * @return inventory* (El inventario que crea)
 */
Inventory * inventory_create(int tam) {

    Inventory *bag;

    if (tam < 0)return NULL;

    bag = malloc(sizeof (Inventory));
    if (bag == NULL)return NULL;

    bag->objects = set_create();
    if (bag->objects == NULL) {
        free(bag);
        return NULL;
    }
    bag->tam = tam;

    return bag;
}

/**
 * @brief destruye un inventario 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario a destruir)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS inventory_destroy(Inventory *bag) {

    if (bag == NULL)return ERROR;

    set_destroy(bag->objects);

    free(bag);

    return OK;
}

/**
 * @brief comprueba si el inventario esta lleno
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario a usar)
 * @return BOOL (TRUE si esta lleno o FALSE de lo contrario)
 */
BOOL inventory_is_full(Inventory *bag) {
    if (bag == NULL || bag->objects == NULL)return FALSE;

    if (set_get_num_ids(bag->objects) >= bag->tam)return TRUE;

    return FALSE;
}

/**
 * @brief comprueba si el inventario esta vacio
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario a usar)
 * @return BOOL (TRUE si esta vacio o FALSE de lo contrario)
 */
BOOL inventory_is_empty(Inventory *bag) {
    if (bag == NULL || bag->objects == NULL)return FALSE;

    if (set_get_num_ids(bag->objects) == 0)return TRUE;

    return FALSE;

}

/**
 * @brief comprueba si el objeto esta en el inventario 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario a usar)
 * @param id (Id del objeto)
 * @return BOOL (TRUE si esta en el inventario o FALSE de lo contrario)
 */
BOOL inventory_is_object_in(Inventory *bag, Id id) {
    if (bag == NULL || id == NO_ID)return ERROR;

    return set_is_id_in(bag->objects, id);
}

/**
 * @brief añade un objeto del inventario 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario a modificar)
 * @param id (Id del objeto)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS inventory_add_object(Inventory *bag, Id id) {

    if (bag == NULL || id == NO_ID)return ERROR;

    if (inventory_is_full(bag) == TRUE)return ERROR;

    return set_add(bag->objects, id);
}

/**
 * @brief quita un objeto del inventario 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario a modificar)
 * @param id (Id del objeto)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS inventory_delete_object(Inventory *bag, Id id) {
    if (bag == NULL || id == NO_ID)return ERROR;

    if (inventory_is_empty(bag) == TRUE)return ERROR;

    return set_delete_element(bag->objects, id);
}

/**
 * @brief devuelve los objetos del inventario 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario a destruir)
 * @return Set (Objetos del inventario)
 */
Set* inventory_get_set(Inventory *bag) {
    if (bag == NULL)return NULL;

    return bag->objects;
}

/**
 * @brief devuelve el tamaño de un inventario 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario a usar)
 * @return int (Tamaño del inventario)
 */
int inventory_get_size(Inventory *bag) {
    if (bag == NULL)return -1;

    return bag->tam;
}

/**
 * @brief modifica los objetos de un inventario 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario a modificar)
 * @param set (Objetos nuevos del inventario)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS inventory_set_set(Inventory *bag, Set *set) {
    if (bag == NULL || set == NULL)return ERROR;

    if (bag->objects != NULL) {
        set_destroy(bag->objects);
    }

    bag->objects = set;

    return OK;
}

/**
 * @brief cambia el tamaño de un inventario 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario que se va a cambiar)
 * @param tam (tamaño nuevo del inventario)
 * @return STATUS (OK si se ha realizado correctamente o ERROR de lo contrario)
 */
STATUS inventory_set_size(Inventory *bag, int tam) {
    if (bag == NULL || tam < 1)return ERROR;
    bag->tam = tam;

    return OK;
}

/**
 * @brief imprime un inventario 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param bag (inventario a imprimir)
 * @param filename (Donde se imprime)
 * @return void (No devuelve nada)
 */
void inventory_print(Inventory *bag, FILE *filename) {

    if (bag == NULL || filename == NULL) return;

    fprintf(filename, "El tamaño del inventario es: %d\n", bag->tam);

    set_print(filename, bag->objects);
}
