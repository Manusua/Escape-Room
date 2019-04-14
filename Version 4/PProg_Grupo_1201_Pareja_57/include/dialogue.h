/**
 * @brief En este fichero definimos las funciones para el dialogo
 * @file dialogue.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0
 * @date 20/11/2018
 */

#ifndef DIALOGUE_H
#define DIALOGUE_H
#include "types.h"
#include "command.h"

/**
 * @brief imprime la descripcion de la acción
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 16/12/2018
 * @param command comando que se acaba de ejecutar
 * @param prev_cmd comando previo
 * @param prev_stat true si se ha podido ejecutar el comando anterior
 * @param act_stat resultado de la ejecucion del comando
 * @param aux cadena donde se imprime el resultado
 * @return OK o ERROR
 */

STATUS dialogue_action(Command *command, T_Command prev_cmd, STATUS prev_stat, STATUS act_stat, char * aux);


#endif
