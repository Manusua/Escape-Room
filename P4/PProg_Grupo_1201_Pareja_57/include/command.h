  /**
 * @brief En este fichero definimos las funciones para los comandos
 * @file command.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 3.0
 * @date 7/10/2018
 */

#ifndef COMMAND_H
#define COMMAND_H
#include "types.h"

/**
 * Enumeracion de posibles comandos
 */
typedef enum enum_Command {
    NO_CMD = -1, /**< Sin comando */
    UNKNOWN, /**< Desconocido */
    QUIT, /**< Salir */
    GO, /**< Seguir */
    TAKE, /**< Coger objeto */
    LEAVE, /**< Soltar objeto */
    ROLL, /**< Tirar el dado */
    INSPECT, /**< Inspeccionar */
    FOLLOWING, /**< Siguiente */
    PREVIOUS, /**< Anterior */
    GOOSE_FOLLOWING, /**< Oca siguiente */
    GOOSE_PREVIOUS, /**< Oca anterior */
    TURNON, /**< Encender un objeto */
    TURNOFF, /**< Apagar un objeto */
    OPEN, /**< Abrir un objeto */
    SAVE, /**< Guardar una partida */
    LOAD /**< Cargar una partida */
} T_Command; /**< Posibles comandos*/


typedef struct _Command Command; /*!< definicion de la estructura de comando */

/**
 * @brief lee el comando del teclado y si es valido lo ejecuta
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param command* (el comando que recibe)
 * @return STATUS (OK si funciona correctamente o ERROR de lo contrario)
 */
STATUS command_get_user_input(Command* command);

/**
 * @brief crea un comando definiendo sus campos como UNKNOWN
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @return command* (el comando creado)
 */
Command *command_create();

/**
 * @brief destruye el comando y libera la memoria
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param command* (el comando que recibe)
 * @return void (No devuelve nada)
 */
void command_destroy(Command *command);

/**
 * @brief devuelve el simbolo del comando que se le pasa
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param command* (el comando que recibe)
 * @return T_Command (El simbolo del comando)
 */
T_Command command_get_command(Command *command);

/**
 * @brief devuelve el nombre del comando que se le pasa
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param command* (el comando que recibe)
 * @return char* (El nombre del comando)
 */
char *command_get_name(Command *command);
#endif
