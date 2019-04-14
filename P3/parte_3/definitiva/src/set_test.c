/**
 * @brief En este fichero probamos las funciones del set
 * @file set_test.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 10/11/2018
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"


/**
* @brief funcion principal de prueba del set
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @return int
*/
int main() {
    Set *s;
    int i;

    printf("prueba del fichero set.\n");
    s = set_create(0);

    if (set_is_empty(s) == TRUE) {
        printf("Si se escribe esto es que el conjunto está vacío.\n");
    } else {
        printf("la funcion de set_is_empty no funciona correctamente.\n");
    }
    printf("insertamos elementos en el conjunto.\n");
    for (i = 0; i < 5; i++) {
        printf("insertamos el elemento %d\n", i);
        set_add(s, i);
        set_print(stdout, s);
    }

    printf("comprobamos el numero de ids(el numero de elementos).\n");
    printf("el numero de elementos es %d \n", set_get_num_ids(s));

    printf("quitamos un par de elementos para probar set_delete_element.\n");
    for (i = 4; i > 2; i--) {
        set_delete_element(s, i);
    }

    set_print(stdout, s);
    if (set_is_id_in(s, 2) == TRUE) {
        printf("Si este texto aparece significa que el elemento 2 está dentro del conjunto.\n");
    } else {
        printf("la funcion de ver si un id esta en el conjunto no funciona.\n");
    }

    set_destroy(s);

    return 0;
}
