
/* ===================================================================
File: command.h
Version: 3.0
Date: 7-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Prototipos y enumeración de comandos
Revision historica:
19-12-2014 versión 1.0 (Código inicial)
1-10-2018 versión 2.0
       Nuevos comandos "Oca_Following", "Oca_Previous", "Coger" y "Soltar"
7-10-2018 versión 3.0
                Nuevo comando "Roll"
=================================================================== */
#ifndef COMMAND_H
#define COMMAND_H
#include "types.h"

/*Enumeración con todos los comando*/
typedef enum enum_Command {
    NO_CMD = -1,
    UNKNOWN,
    QUIT,
    GO,
    TAKE,
    LEAVE,
    ROLL,
    INSPECT,
    FOLLOWING,
    PREVIOUS,
    OCA_FOLLOWING,
    OCA_PREVIOUS
} T_Command;


typedef struct _Comand Comand;

/*Función para obtener un comando*/
STATUS comand_get_user_input(Comand* comand);

/*Funciones para trabajar con la estructura comando*/
Comand *comand_create();
void comand_destroy(Comand *comand);
T_Command comand_get_comand(Comand *comand);
char *comand_get_name(Comand *comand);
#endif
