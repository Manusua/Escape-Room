
/* ===================================================================
File: die_test.c
Version: 1.0
Date: 21-10-2018
Autores: Saul Almazan y Alvaro Becerra Jiminez
Description: Prueba del TAD dado
Revision historica: 
13-10-2018 versión 1.0 (Código inicial)
=================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "die.h"

int main(int argc, char *argv[]) {
    Die *die = NULL;
    char cmd = '\0';
    int res;
    srand(time(NULL));
    die = die_create();
    if (die == NULL) return 1;
    if (die_set_id(die, 1) == ERROR) return 1;
    while (cmd != 'e') {
        printf("Introduzca comando: 'r' para tirar y 'e' para salir: ");
        scanf("%c", &cmd);
        if (cmd == 'r') {
            res = roll_die(die);
            printf("Resultado: %d\nDado: ", res);
            die_print(stdout, die);
            printf("\n");
        }
    }
    die_destroy(die);
    return 0;
}
