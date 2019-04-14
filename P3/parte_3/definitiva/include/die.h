/**
 * @brief En este fichero definimos las funciones para el dado
 * @file die.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 10/11/2018
 */

#ifndef DIE_H
#define DIE_H
#include "types.h"

typedef struct _Die Die; /*!< Definición de la estructura del dado */

/**
 * @brief Crea el dado y devuelve el puntero al mismo
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @return Die (El dado que hemos creado)
 */
Die *die_create();

/**
 * @brief Destruye el dado y libera la memoria
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param die puntero a dado
 * @return void (No devuelve nada)
 */
void die_destroy(Die *die);

/**
 * @brief Destruye el dado y libera la memoria
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param die (el dado que vamos a usar)
 * @param id (el que sera el id del dado)
 * @return STATUS (OK si funciona correctamente o ERROR si no)
 */
STATUS die_set_id(Die * die, Id id);

/**
 * @brief Devuelve el id del dado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param die (el dado que vamos a usar)
 * @return Id (El id del dado)
 */
Id die_get_id(Die *die);

/**
 * @brief Devuelve el resultado obtenido en la anterior tirada
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param die (el dado que vamos a usar)
 * @return int (El valor de la tirada)
 */
int die_get_resultado_anterior(Die *die);

/**
 * @brief Tira el dado y devuelve un entero aleatorio entre el inf y el sup
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param die (el dado que vamos a usar)
 * @return int (El valor de la tirada)
 */
int roll_die(Die *die);

/**
 * @brief Imprime el valor de la tirada del dado en el archivo proporcionado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param f (El archivo donde lo queremos imprimir)
 * @param die (el dado que vamos a usar)
 * @return int (devuelve -1 si hay algun error o el un entero en caso contrario)
 */
int die_print(FILE *f, Die *die);

#endif
