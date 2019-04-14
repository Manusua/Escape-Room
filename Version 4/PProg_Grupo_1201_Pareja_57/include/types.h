/**
 * @brief It defines common types
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H

#define WORD_SIZE 1000 /*!< Tamaño maximo para palabra */
#define TAM 32 /*!< Tam max */
#define NO_ID -1 /*!< Define NO_ID */

typedef long Id; /*!< Define la variable Id como long */

/**
 * Enumeracion de BOOL
 */
typedef enum {
    FALSE, /**< FALSE */
    TRUE /**< TRUE */
} BOOL;

/**
 * Enumeracion de STATUS
 */
typedef enum {
    ERROR, /**< ERROR */
    OK /**< OK */
} STATUS;

/**
 * Enumeracion de direccion
 */
typedef enum {
    N, /**< norte */
    S, /**< sur */
    E, /**< este */
    W /**< west */
} DIRECTION;

#endif
