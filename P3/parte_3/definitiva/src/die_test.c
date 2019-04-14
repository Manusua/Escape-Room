/**
 * @brief Fichero de prueba del dado
 * @file die_test.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 10/11/2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "die.h"

/**
* @brief funcion principal de prueba del dado 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param argc (numero de argumentos)
* @param argv[] (argumentos)
* @return int
*/
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
