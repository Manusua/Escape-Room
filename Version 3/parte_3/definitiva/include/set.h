/**
 * @brief En este fichero implementamos las funciones de set
 * @file set.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 20/10/2018
 */

#ifndef SET_H
#define SET_H
#include "types.h"
#define TAM_SET 32 /*!< tamaño maximo del set */
typedef struct _Set Set; /*!< Estructura de Set */


/**
* @brief crea un Set 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @return Set (El set que crea)
*/
Set * set_create();

/**
* @brief destruye y libera la memoria de un Set 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a destruir)
* @return void (No devuelve nada)
*/
void set_destroy(Set *set);


/**
* @brief añade un objeto a un Set 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @param id (El id del objeto que se añade al set)
* @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
*/
STATUS set_add(Set *set, Id id);

/**
* @brief borra un objeto de un Set 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @param id (El id del objeto que se borra del set)
* @return STATUS (OK si se realiza con exito o ERROR de lo contrario)
*/
STATUS set_delete_element(Set *set, Id id);

/**
* @brief devuelve el numero de objetos 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @return int (el numero de objetos)
*/
int set_get_num_ids(Set *set);

/**
* @brief comprueba si un objeto esta dentro de un set
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @param id (El id del objeto que se comprueba)
* @return BOOl (TRUE si el objeto esta dentro del set o FALSE de lo contrario)
*/
BOOL set_is_id_in(Set* set, Id id);

/**
* @brief comprueba si un set esta vacio
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @return BOOl (TRUE si el set esta vacio o FALSE de lo contrario)
*/
BOOL set_is_empty(Set* set);

/**
* @brief comprueba si un set esta lleno
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param set (El set a usar)
* @return BOOl (TRUE si el set esta lleno o FALSE de lo contrario)
*/
BOOL set_is_full(Set *set);

/**
* @brief imprime un set
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param f (donde se va a imprimir)
* @param set (El set a imprimir)
* @return int (-1 si hay algun error)
*/
int set_print(FILE *f, Set *set);

#endif
