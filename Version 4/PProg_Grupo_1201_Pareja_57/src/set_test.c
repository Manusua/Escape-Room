/** 
 * @brief Prueba del modulo set
 * 
 * @file set_test.c
 * @author Manuel Suarez, Saul Almazán, �?lvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "set.h" 
#include "set_test.h"
#include "test.h"

#define MAX_TESTS 14 /*!< TAM_TESTS */

/** 
 * @brief Funcion principal de pruebas para el modulo set. 
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
        printf("Prueba módulo set:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Probando test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: test %d desconocido\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_set_create();
    if (all || test == 2) test1_set_delete_element();
    if (all || test == 3) test2_set_delete_element();
    if (all || test == 4) test3_set_delete_element();
    if (all || test == 5) test1_set_add();
    if (all || test == 6) test2_set_add();
    if (all || test == 7) test1_set_is_full();
    if (all || test == 8) test2_set_is_full();
    if (all || test == 9) test1_set_is_empty();
    if (all || test == 10) test2_set_is_empty();
    if (all || test == 11) test1_set_is_id_in();
    if (all || test == 12) test2_set_is_id_in();
    if (all || test == 13) test1_set_get_num_ids();
    if (all || test == 14) test2_set_get_num_ids();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/**
 * @test Prueba la función de creación de un set
 * @pre nada
 * @post Un puntero no nulo al set creado
 */

void test1_set_create() {
    Set *s = NULL;
    s = set_create();
    PRINT_TEST_RESULT(s != NULL);
    set_destroy(s);
}


/**
 * @test Prueba la función para borrar un objeto de un set
 * @pre set con un objeto
 * @post La salida debe ser OK
 */
void test1_set_delete_element() {
    Set *s = NULL;
    s = set_create();
    set_add(s, 1);
    PRINT_TEST_RESULT(set_delete_element(s, 1) == OK);
    set_destroy(s);

}

/**
 * @test Prueba la función para borrar un objeto de un set
 * @pre set NULL
 * @post La salida debe ser ERROR
 */

void test2_set_delete_element() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_delete_element(s, 1) == ERROR);
}

/**
 * @test Prueba la función para borrar un objeto de un set
 * @pre set sin objetos
 * @post La salida debe ser ERROR
 */
void test3_set_delete_element() {
    Set *s = NULL;
    s = set_create();
    PRINT_TEST_RESULT(set_delete_element(s, 1) == ERROR);
    set_destroy(s);
}

/**
 * @test Prueba la función para añadir un objeto a un set
 * @pre id que establecer en el set
 * @post La salida debe ser OK
 */
void test1_set_add() {
    Set *s = NULL;
    s = set_create();
    PRINT_TEST_RESULT(set_add(s, 1) == OK);
    set_destroy(s);
}

/**
 * @test Prueba la función para añadir un objeto a un set
 * @pre id válido, pero set NULL
 * @post La salida debe ser ERROR
 */

void test2_set_add() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_add(s, 4) == ERROR);
}

/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre set vacío
 * @post La salida debe ser FALSE
 */
void test1_set_is_full() {
    Set *s = NULL;
    s = set_create(s);
    PRINT_TEST_RESULT(set_is_full(s) == FALSE);
    set_destroy(s);
}

/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre set lleno
 * @post La salida debe ser TRUE
 */
void test2_set_is_full() {
    Set *s = NULL;
	int i;
    s = set_create();
	for (i=0; i<TAM_SET; i++){
    set_add(s, i);
	}
    PRINT_TEST_RESULT(set_is_full(s) == TRUE);
    set_destroy(s);
}

/**
 * @test Prueba la función para comprobar si un invetario está vacío
 * @pre set vacío
 * @post La salida debe ser TRUE
 */
void test1_set_is_empty() {
    Set *s = NULL;
    s = set_create();
    PRINT_TEST_RESULT(set_is_empty(s) == TRUE);
    set_destroy(s);

}

/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre set lleno
 * @post La salida debe ser FALSE
 */
void test2_set_is_empty() {
    Set *s = NULL;
    s = set_create();
    set_add(s, 1);
    PRINT_TEST_RESULT(set_is_empty(s) == FALSE);
    set_destroy(s);
}

/**
 * @test Prueba la función para saber si hay un objeto en el set
 * @pre El set tiene un objeto
 * @post La salida debe ser TRUE
 */
void test1_set_is_id_in() {
    Set *s = NULL;
    s = set_create();
    set_add(s, 1);
    PRINT_TEST_RESULT(set_is_id_in(s, 1) == TRUE);
    set_destroy(s);
}

/**
 * @test Prueba la función para saber si hay un objeto en el set
 * @pre El set es NULL
 * @post La salida debe ser FALSE
 */
void test2_set_is_id_in() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_is_id_in(s, 1) == FALSE);
}

/**
 * @test Prueba la función para obtener el numero de ids de un set
 * @pre El set tiene cero ids
 * @post La salida debe ser tam=0
 */
void test1_set_get_num_ids() {
    Set *s = NULL;
    s = set_create();
    PRINT_TEST_RESULT(set_get_num_ids(s) == 0);
    set_destroy(s);
}

/**
 * @test Prueba la función para obtener el numero de ids de un set
 * @pre El set es NULL
 * @post La salida debe ser -1
 */
void test2_set_get_num_ids() {
    Set *s = NULL;
    PRINT_TEST_RESULT(set_get_num_ids(s) == -1);
}
