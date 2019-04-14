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
typedef enum enum_Command{
    NO_CMD = -1,/**< Sin comando */
    UNKNOWN,/**< Desconocido */
    QUIT,/**< Salir */
    GO,/**< Seguir */
    TAKE,/**< Coger objeto */
    LEAVE,/**< Soltar objeto */
    ROLL,/**< Tirar el dado */
    INSPECT,/**< Inspeccionar */
    FOLLOWING,/**< Siguiente */
    PREVIOUS,/**< Anterior */
    OCA_FOLLOWING,/**< Oca siguiente */
    OCA_PREVIOUS/**< Oca anterior */
} T_Command;/**< Posibles comandos*/


typedef struct _Comand Comand; /*!< definicion de la estructura de comando */

/**
* @brief lee el comando del teclado y si es valido lo ejecuta 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param comand* (el comando que recibe)
* @return STATUS (OK si funciona correctamente o ERROR de lo contrario)
*/
STATUS comand_get_user_input(Comand* comand);

/**
* @brief crea un comando definiendo sus campos como UNKNOWN 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @return comand* (el comando creado)
*/
Comand *comand_create();

/**
* @brief destruye el comando y libera la memoria 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param comand* (el comando que recibe)
* @return void (No devuelve nada)
*/
void comand_destroy(Comand *comand);

/**
* @brief devuelve el simbolo del comando que se le pasa 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param comand* (el comando que recibe)
* @return T_Command (El simbolo del comando)
*/
T_Command comand_get_comand(Comand *comand);

/**
* @brief devuelve el nombre del comando que se le pasa 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param comand* (el comando que recibe)
* @return char* (El nombre del comando)
*/
char *comand_get_name(Comand *comand);
#endif
