/**
 * @brief En este fichero probamos las funciones del inventario
 * @file inventory_test.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 10/11/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inventory.h"


/**
* @brief funcion principal de prueba del inventario 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 10/11/2018
* @param argc (numero de argumentos)
* @param argv[] (argumentos)
* @return int
*/
int main(int argc, char *argv[]) {
    Inventory *bag;
    int i;

    printf("prueba del fichero inventory.\n");
    bag = inventory_create(3);

    if (inventory_is_empty(bag) == TRUE) {
        printf("El inventario está vacío. y funciona\n");
    } else {
        printf("la funcion de set_is_empty no funciona correctamente.\n");
    }
    printf("insertamos elementos en el conjunto.\n");
    for (i = 0; i < 5; i++) {
        printf("insertamos el elemento %d\n", i);
        inventory_add_object(bag, i);
        inventory_print(bag, stdout);
    }

    printf("comprobamos el numero de elementos que caben\n");
    printf("el numero de elementos es %d \n", inventory_get_size(bag));


    printf("quitamos un par de elementos para probar set_delete_element.\n");
    for (i = 4; i > 2; i--) {
        inventory_delete_object(bag, i);
    }

    inventory_print(bag, stdout);

    inventory_destroy(bag);

    return 0;
}
