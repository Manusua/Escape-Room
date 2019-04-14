/**
 * @brief En este fichero definimos las funciones para los comandos
 * @file command.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 3.0
 * @date 7/10/2018
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "command.h"
#define CMD_LENGHT 30 /*!< longitud maxima del comando */
#define N_CMD 12 /*!< Tamaño de la cadena */


struct _Comand {
    T_Command cmd; /*!<Último comando*/
    char name[WORD_SIZE]; /*!<Nombre de la segunda parte de un comando*/
};/*!< Estructura del comando */

char*cmd_to_str[N_CMD] = {"No command", "Unknown", "Quit", "Go", "Take", "Leave", "Roll", "Inspect", "Following", "Previous", "Oca_Following", "Oca_Previous"}; /*!<Lista de comandos largos*/
char *short_cmd_to_str[N_CMD] = {"", "", "q", "g", "t", "l", "r", "i", "f", "p", "o", "a"}; /*!<Lista de comandos cortos*/

/**
* @brief lee el comando del teclado y si es valido lo ejecuta 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param comand* (el comando que recibe)
* @return STATUS (OK si funciona correctamente o ERROR de lo contrario)
*/
    STATUS comand_get_user_input(Comand *comand) {
        char input[CMD_LENGHT + WORD_SIZE + 1] = "", comando[CMD_LENGHT];
        char *parte = NULL;
        int i = UNKNOWN - NO_CMD + 1;
        if (comand == NULL) return ERROR;
        if (fgets(input, CMD_LENGHT + WORD_SIZE, stdin) != NULL) {
            parte = strtok(input, " \n");
            if (parte != NULL) {
                strcpy(comando, parte);
                parte = strtok(NULL, " \n");
                if (parte != NULL) {
                    strcpy(comand->name, parte);
                } else {
                    strcpy(comand->name, "\0");
                }
                comand->cmd = UNKNOWN;
                while (comand->cmd == UNKNOWN && i < N_CMD) {
                    if (!strcasecmp(comando, short_cmd_to_str[i]) || !strcasecmp(comando, cmd_to_str[i])) {
                        comand->cmd = i + NO_CMD;
                    } else {
                        i++;
                    }
                }
            }

        }
        return OK;
    }

/**
* @brief crea un comando definiendo sus campos como UNKNOWN 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @return comand* (el comando creado)
*/
    Comand *comand_create() {
        Comand *comand = NULL;
        comand = (Comand *) calloc(1, sizeof (Comand));
        return comand;
    }

/**
* @brief destruye el comando y libera la memoria 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param comand* (el comando que recibe)
* @return void (No devuelve nada)
*/
    void comand_destroy(Comand *comand) {
        if (comand == NULL) return;
        free(comand);
        return;
    }

/**
* @brief devuelve el simbolo del comando que se le pasa 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param comand* (el comando que recibe)
* @return T_Command (El simbolo del comando)
*/
    T_Command comand_get_comand(Comand *comand) {
        if (comand == NULL) return UNKNOWN;
        return comand->cmd;
    }

/**
* @brief devuelve el nombre del comando que se le pasa 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param comand* (el comando que recibe)
* @return char* (El nombre del comando)
*/
    char *comand_get_name(Comand *comand) {
        if (comand == NULL) return NULL;
        return comand->name;
    }
