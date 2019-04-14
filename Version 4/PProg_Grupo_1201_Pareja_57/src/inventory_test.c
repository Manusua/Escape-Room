/** 
 * @brief Prueba del modulo inventory
 * 
 * @file inventory_test.c
 * @author Manuel Suarez, Saul Almazán, �?lvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "set.h" 
#include "inventory.h"
#include "inventory_test.h"
#include "test.h"

#define MAX_TESTS 17 /*!< TAM_TESTS */

/** 
 * @brief Funcion principal de pruebas para el modulo inventory. 
 * 
 * Dos modos de ejecucion:
 *   1.-Si se ejecuta sin parametros se ejecutan todas las pruebas 
 *   2.-Si se ejecuta con un numero entre 1 y el numero de pruebas solo ejecuta 
 *      la prueba indicada  
 *  
 */
int main(int argc, char** argv) {

    int test = 0;
    int all = 1;

    if (argc < 2) {
        printf("Prueba módulo inventory:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Probando test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: test %d desconocido\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_inventory_create();
    if (all || test == 2) test2_inventory_create();
    if (all || test == 3) test1_inventory_delete_object();
    if (all || test == 4) test2_inventory_delete_object();
    if (all || test == 5) test3_inventory_delete_object();
    if (all || test == 6) test1_inventory_add_object();
    if (all || test == 7) test2_inventory_add_object();
    if (all || test == 8) test1_inventory_is_full();
    if (all || test == 9) test2_inventory_is_full();
    if (all || test == 10) test1_inventory_is_empty();
    if (all || test == 11) test2_inventory_is_empty();
    if (all || test == 12) test1_inventory_is_object_in();
    if (all || test == 13) test2_inventory_is_object_in();
    if (all || test == 14) test1_inventory_get_size();
    if (all || test == 15) test2_inventory_get_size();
    if (all || test == 16) test1_inventory_set_size();
    if (all || test == 17) test2_inventory_set_size();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/**
 * @test Prueba la función de creación de un inventario
 * @pre Un numero de objetos como parámetro
 * @post Un puntero no nulo al inventario creado
 */

void test1_inventory_create() {
    Inventory *i = NULL;
    i = inventory_create(5);
    PRINT_TEST_RESULT(i != NULL);
    inventory_destroy(i);
}

/**
 * @test Prueba la función de creación de un inventario
 * @pre Un numero de objetos erroneo como parámetro
 * @post Se obtiene un puntero NULL
 */
void test2_inventory_create() {
    Inventory *i = NULL;
    i = inventory_create(-1);
    PRINT_TEST_RESULT(!i);
}

/**
 * @test Prueba la función para borrar un objeto de un inventario
 * @pre Inventario con un objeto
 * @post La salida debe ser OK
 */
void test1_inventory_delete_object() {
    Inventory *i = NULL;
    i = inventory_create(3);
    inventory_add_object(i, 1);
    PRINT_TEST_RESULT(inventory_delete_object(i, 1) == OK);
    inventory_destroy(i);

}

/**
 * @test Prueba la función para borrar un objeto de un inventario
 * @pre Inventario NULL
 * @post La salida debe ser ERROR
 */

void test2_inventory_delete_object() {
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_delete_object(i, 1) == ERROR);
}

/**
 * @test Prueba la función para borrar un objeto de un inventario
 * @pre Inventario sin objetos
 * @post La salida debe ser ERROR
 */
void test3_inventory_delete_object() {
    Inventory *i = NULL;
    i = inventory_create(3);
    PRINT_TEST_RESULT(inventory_delete_object(i, 1) == ERROR);
    inventory_destroy(i);
}

/**
 * @test Prueba la función para añadir un objeto a un inventario
 * @pre id que establecer en el inventario
 * @post La salida debe ser OK
 */
void test1_inventory_add_object() {
    Inventory *i = NULL;
    i = inventory_create(3);
    PRINT_TEST_RESULT(inventory_add_object(i, 1) == OK);
    inventory_destroy(i);
}

/**
 * @test Prueba la función para añadir un objeto a un inventario
 * @pre id válido, pero inventario NULL
 * @post La salida debe ser ERROR
 */

void test2_inventory_add_object() {
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_add_object(i, 4) == ERROR);
}

/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre inventario vacío
 * @post La salida debe ser FALSE
 */
void test1_inventory_is_full() {
    Inventory *i = NULL;
    i = inventory_create(3);
    PRINT_TEST_RESULT(inventory_is_full(i) == FALSE);
    inventory_destroy(i);
}

/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre inventario lleno
 * @post La salida debe ser TRUE
 */
void test2_inventory_is_full() {
    Inventory *i = NULL;
    i = inventory_create(1);
    inventory_add_object(i, 1);
    PRINT_TEST_RESULT(inventory_is_full(i) == TRUE);
    inventory_destroy(i);
}

/**
 * @test Prueba la función para comprobar si un invetario está vacío
 * @pre inventario vacío
 * @post La salida debe ser TRUE
 */
void test1_inventory_is_empty() {
    Inventory *i = NULL;
    i = inventory_create(3);
    PRINT_TEST_RESULT(inventory_is_empty(i) == TRUE);
    inventory_destroy(i);

}

/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre inventario lleno
 * @post La salida debe ser FALSE
 */
void test2_inventory_is_empty() {
    Inventory *i = NULL;
    i = inventory_create(3);
    inventory_add_object(i, 1);
    PRINT_TEST_RESULT(inventory_is_empty(i) == FALSE);
    inventory_destroy(i);
}

/**
 * @test Prueba la función para saber si hay un objeto en el inventario
 * @pre El inventario tiene un objeto
 * @post La salida debe ser TRUE
 */
void test1_inventory_is_object_in() {
    Inventory *i = NULL;
    i = inventory_create(3);
    inventory_add_object(i, 1);
    PRINT_TEST_RESULT(inventory_is_object_in(i, 1) == TRUE);
    inventory_destroy(i);
}

/**
 * @test Prueba la función para saber si hay un objeto en el inventario
 * @pre El inventario es NULL
 * @post La salida debe ser FALSE
 */
void test2_inventory_is_object_in() {
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_is_object_in(i, 1) == FALSE);
}

/**
 * @test Prueba la función para obtener el tamaño de un inventario
 * @pre El inventario tiene un tamaño
 * @post La salida debe ser tam=3
 */
void test1_inventory_get_size() {
    Inventory *i = NULL;
    i = inventory_create(3);
    PRINT_TEST_RESULT(inventory_get_size(i) == 3);
    inventory_destroy(i);
}

/**
 * @test Prueba la función para obtener el tamaño de un inventario
 * @pre El inventario es NULL
 * @post La salida debe ser -1
 */
void test2_inventory_get_size() {
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_get_size(i) == -1);
}

/**
 * @test Prueba la función para establecer el tamaño de un inventario
 * @pre inventario no NULL
 * @post La salida debe ser OK
 */
void test1_inventory_set_size() {
    Inventory *i = NULL;
    i = inventory_create(3);
    PRINT_TEST_RESULT(inventory_set_size(i, 5) == OK);
    inventory_destroy(i);
}

/**
 * @test Prueba la función para establecer el tamaño de un inventario
 * @pre inventario NULL
 * @post La salida debe ser ERROR
 */
void test2_inventory_set_size() {
    Inventory *i = NULL;
    PRINT_TEST_RESULT(inventory_set_size(i, 1) == ERROR);

}
