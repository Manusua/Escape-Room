/**
 * @brief En este fichero implementamos las funciones del dado
 * @file die.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 10/11/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "die.h"


struct _Die {
    Id id; /*!<Id del dado*/
    int resultado_anterior; /*!<Último resultado*/
}; /*!<Estructura del dado */

/**
 * @brief Crea el dado y devuelve el puntero al mismo
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @return Die (El dado que hemos creado)
 */
    Die *die_create() {
        Die *die = NULL;
        die = (Die*) calloc(1, sizeof (Die));
        if (die == NULL) return NULL;
        die->id = NO_ID;
        return die;
    }

/**
 * @brief Destruye el dado y libera la memoria
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param die (puntero a dado)
 * @return void (No devuelve nada)
 */
    void die_destroy(Die *die) {
        if (die == NULL) return;
        free(die);
        return;
    }

/**
 * @brief Destruye el dado y libera la memoria
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param die (el dado que vamos a usar)
 * @param id (el que sera el id del dado)
 * @return STATUS (OK si funciona correctamente o ERROR si no)
 */
    STATUS die_set_id(Die * die, Id id) {
        if (die == NULL || id == NO_ID) return ERROR;
        die->id = id;
        return OK;
    }

/**
 * @brief Devuelve el id del dado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param die (el dado que vamos a usar)
 * @return Id (El id del dado)
 */
    Id die_get_id(Die *die) {
        if (die == NULL) return NO_ID;
        return die->id;
    }

/**
 * @brief Devuelve el resultado obtenido en la anterior tirada
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param die (el dado que vamos a usar)
 * @return int (El valor de la tirada)
 */
    int die_get_resultado_anterior(Die *die) {
        if (die == NULL) return -1;
        return die->resultado_anterior;
    }

/**
 * @brief Tira el dado y devuelve un entero aleatorio entre el inf y el sup
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param die (el dado que vamos a usar)
 * @return int (El valor de la tirada)
 */
    int roll_die(Die *die) {
        int res, sup = 6, inf = 1;
        if (die == NULL) return -1;
        res = (int) ((rand() / (RAND_MAX + 1.0))*(sup - inf + 1) + inf);
        die->resultado_anterior = res;
        return res;
    }

/**
 * @brief Imprime el valor de la tirada del dado en el archivo proporcionado
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @param f (El archivo donde lo queremos imprimir)
 * @param die (el dado que vamos a usar)
 * @return int (devuelve -1 si hay algun error o el un entero en caso contrario)
 */
    int die_print(FILE *f, Die *die) {
        if (die == NULL) return -1;
        return fprintf(f, "%ld, %d", die->id, die->resultado_anterior);
    }
