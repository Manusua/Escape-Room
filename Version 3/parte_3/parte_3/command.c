
/* ===================================================================
File: player.c
Version: 3.0
Date: 21-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Interpreta los comandos
Revision historica:
19-12-2014 versión 1.0 (Código inicial)
1-10-2018 versión 2.0
       Nuevos comandos "Oca_Following", "Oca_Previous", "Coger" y "Soltar"
21-10-2018 versión 3.0
                Nuevo comando "roll". Creada estructura comando y las funciones necesarias para manejarla.
                Ahora el comando "coger" incluye el nombre de un objeto.
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "command.h"
#define CMD_LENGHT 30
#define N_CMD 8

/*Estructura comando que almacena un comando y el nombre de un objeto*/
struct _Comand {
    T_Command cmd; /*Último comando*/
    char name[WORD_SIZE]; /*Nombre de la segunda parte de un comando*/
};

char*cmd_to_str[N_CMD] = {"No command", "Unknown", "Quit", "Go", "Take", "Leave", "Roll", "Inspect, "Following", "Previous", "Oca_Following", "Oca_Previous""}; /*Lista de comandos largos*/
char *short_cmd_to_str[N_CMD] = {"", "", "q", "g", "t", "l", "r", "i", "f", "p", "o", "a"}; /*Lista de comandos cortos*/

/******************************************************************
 *Funcion: comand_get_user_input
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que interpreta los comandos introducidos por el jugador
 *Input: puntero a comand
 *Output: ok si toda la ejecución se completa y error si falla en algún punto
 ********************************************************************/

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

/******************************************************************
 *Funcion: create_comand
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que crea un comando
 *Input: nada
 *Output: el comando
 ********************************************************************/
Comand *comand_create() {
    Comand *comand = NULL;
    comand = (Comand *) calloc(1, sizeof (Comand));
    return comand;
}

/******************************************************************
 *Funcion: comand_destroy
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que libera un comando
 *Input: el comando a liberar
 *Output: nada
 ********************************************************************/

void comand_destroy(Comand *comand) {
    if (comand == NULL) return;
    free(comand);
    return;
}

/******************************************************************
 *Funcion: comand_get_cmd
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que nos devuelve el comando guardado
 *Input: el comando
 *Output: un comando perteneciente a la enumeración T_Command
 ********************************************************************/


T_Command comand_get_comand(Comand *comand) {
    if (comand == NULL) return UNKNOWN;
    return comand->cmd;
}

/******************************************************************
 *Funcion: comand_get_object_name
 *Date: 13-10-2018
 *Autores: Saul Almazan y Alvaro Becerra Jiminez
 *Description: Función que devuelve el nombre del objeto que se quiere coger
 *Input: el comando
 *Output: el nombre del objeto o null si no exite el comando o el nombre
 ********************************************************************/


char *comand_get_name(Comand *comand) {
    if (comand == NULL) return NULL;
    return comand->name;
}
