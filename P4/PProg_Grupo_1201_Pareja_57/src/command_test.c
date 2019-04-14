/**
 * @brief Fichero de prueba del comando
 * @file command_test.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 10/11/2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "command.h"

/**
 * @brief funcion principal de prueba del comando 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 10/11/2018
 * @return int
 */
int main() {
    Command *cmd = NULL;
    printf("Prueba del modulo command. Esta prueba está diseñada para ser probada con el fichero entrada_command_test.ent. Si dicho archivo no está redireccionado, salga del programa.\n");
    cmd = command_create();
    if (cmd == NULL) {
        printf("Error al crear el comando");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el primer comando");
        return 1;
    }
    if (command_get_command(cmd) != ROLL) {
        command_destroy(cmd);
        printf("Error el primer comando no ha sido ROLL");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el segundo comando");
        return 1;
    }
    if (command_get_command(cmd) != UNKNOWN) {
        command_destroy(cmd);
        printf("Error el segundo comando no ha sido UNKNOWN");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el tercer comando");
        return 1;
    }
    if (command_get_command(cmd) != QUIT) {
        command_destroy(cmd);
        printf("Error el tercer comando no ha sido QUIT");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el cuarto comando");
        return 1;
    }
    if (command_get_command(cmd) != GO) {
        command_destroy(cmd);
        printf("Error el cuarto comando no ha sido GO");
        return 1;
    }
    if (strcmp(command_get_name(cmd), "north") != 0) {
        command_destroy(cmd);
        printf("Error el cuarto comando no tenía como acción north");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el quinto comando");
        return 1;
    }
    if (command_get_command(cmd) != TAKE) {
        command_destroy(cmd);
        printf("Error el quinto comando no ha sido TAKE");
        return 1;
    }
    if (strcmp(command_get_name(cmd), "libro") != 0) {
        command_destroy(cmd);
        printf("Error el quinto comando no tenía como objeto de acción libro");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el sexto comando");
        return 1;
    }
    if (command_get_command(cmd) != LEAVE) {
        command_destroy(cmd);
        printf("Error el sexto comando no ha sido LEAVE");
        return 1;
    }
    if (strcmp(command_get_name(cmd), "libro") != 0) {
        command_destroy(cmd);
        printf("Error el sexto comando no tenía como objeto de acción libro");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el séptimo comando");
        return 1;
    }
    if (command_get_command(cmd) != ROLL) {
        command_destroy(cmd);
        printf("Error el séptimo comando no ha sido ROLL");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el octavo comando");
        return 1;
    }
    if (command_get_command(cmd) != INSPECT) {
        command_destroy(cmd);
        printf("Error el octavo comando no ha sido INSPECT");
        return 1;
    }
    if (strcmp(command_get_name(cmd), "libro") != 0) {
        command_destroy(cmd);
        printf("Error el octavo comando no tenía como objeto de acción libro");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el noveno comando");
        return 1;
    }
    if (command_get_command(cmd) != FOLLOWING) {
        command_destroy(cmd);
        printf("Error el noveno comando no ha sido FOLLOWING");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el décimo comando");
        return 1;
    }
    if (command_get_command(cmd) != PREVIOUS) {
        command_destroy(cmd);
        printf("Error el décimo comando no ha sido PREVIOUS");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el undécimo comando");
        return 1;
    }
    if (command_get_command(cmd) != GOOSE_FOLLOWING) {
        command_destroy(cmd);
        printf("Error el undécimo comando no ha sido GOOSE_FOLLOWING");
        return 1;
    }
    if (command_get_user_input(cmd) == ERROR) {
        command_destroy(cmd);
        printf("Error al leer el duodécimo comando");
        return 1;

    }
    if (command_get_command(cmd) != GOOSE_PREVIOUS) {
        command_destroy(cmd);
        printf("Error el duodécimo comando no ha sido GOOSE_PREVIOUS");
        return 1;
    }
    command_destroy(cmd);
    printf("Todas las pruebas han sido pasadas con éxito.\n");
    return 0;
}
