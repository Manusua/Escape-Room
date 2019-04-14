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
#define N_CMD 17 /*!< Tamaño de la cadena */

struct _Command {
    T_Command cmd; /*!<Último comando*/
    char name[WORD_SIZE]; /*!<Nombre de la segunda parte de un commando*/
}; /*!< Estructura del commando */

char*cmd_to_str[N_CMD] = {"No command", "Unknown", "Quit", "Go", "Take", "Leave", "Roll", "Inspect", "Following", "Previous", "Goose_Following", "Goose_Previous", "Turnon", "Turnoff", "Open", "Save", "Load"}; /*!<Lista de commandos largos*/
char *short_cmd_to_str[N_CMD] = {"", "", "q", "g", "t", "l", "r", "i", "f", "p", "o", "a", "e", "c", "h", "s", "d"}; /*!<Lista de commandos cortos*/

/**
 * @brief lee el comando del teclado y si es valido lo ejecuta
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param command* (el comando que recibe)
 * @return STATUS (OK si funciona correctamente o ERROR de lo contrario)
 */
STATUS command_get_user_input(Command *command) {
    char input[CMD_LENGHT + WORD_SIZE + 1] = "", comando[CMD_LENGHT], nexo[CMD_LENGHT];
    char *parte = NULL;
    int i = UNKNOWN - NO_CMD + 1;
    if (command == NULL) return ERROR;
    if (fgets(input, CMD_LENGHT + WORD_SIZE, stdin) != NULL) {
        parte = strtok(input, " \n");
        if (parte != NULL) {
            strcpy(comando, parte);
        }
        parte = strtok(NULL, " \n");
        if (parte != NULL) {
            memset(command->name, '\0', WORD_SIZE);
            strcpy(command->name, parte);
            parte = strtok(NULL, " \n");
            if (parte != NULL) {
                strcpy(nexo, parte);
                if (strcasecmp(nexo, "with") == 0 || strcasecmp(nexo, "w") == 0) {
                    parte = strtok(NULL, " \n");
                    if (parte != NULL) {
                        strcat(command->name, " ");
                        strcat(command->name, parte);
                    }
                }
            }
        } else {
            strcpy(command->name, "\0");
        }
        command->cmd = UNKNOWN;
        while (command->cmd == UNKNOWN && i < N_CMD) {
            if (!strcasecmp(comando, short_cmd_to_str[i]) || !strcasecmp(comando, cmd_to_str[i])) {
                command->cmd = i + NO_CMD;
            } else {
                i++;
            }
        }
    }
    return OK;
}

/**
 * @brief crea un comando definiendo sus campos como UNKNOWN
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @return command* (el comando creado)
 */
Command *command_create() {
    Command *command = NULL;
    command = (Command *) calloc(1, sizeof (Command));
    return command;
}

/**
 * @brief destruye el comando y libera la memoria
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param command* (el comando que recibe)
 * @return void (No devuelve nada)
 */
void command_destroy(Command *command) {
    if (command == NULL) return;
    free(command);
    return;
}

/**
 * @brief devuelve el simbolo del comando que se le pasa
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param command* (el comando que recibe)
 * @return T_Command (El simbolo del commando)
 */
T_Command command_get_command(Command *command) {
    if (command == NULL) return UNKNOWN;
    return command->cmd;
}

/**
 * @brief devuelve el nombre del comando que se le pasa
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @date 10/11/2018
 * @param command* (el comando que recibe)
 * @return char* (El nombre del commando)
 */
char *command_get_name(Command *command) {
    if (command == NULL) return NULL;
    return command->name;
}
