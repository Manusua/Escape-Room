/** 
 * @brief Prueba del modulo die
 * 
 * @file die_test.c
 * @author Manuel Suarez, Saul Almazán, �?lvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "die.h" 
#include "die_test.h"
#include "test.h"

#define MAX_TESTS 9 /*!< MAX_TESTS */

/** 
 * @brief Funcion principal de pruebas para el modulo die. 
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
        printf("Prueba módulo die:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Probando test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: test %d desconocido\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_die_create();
    if (all || test == 2) test1_die_set_id();
    if (all || test == 3) test2_die_set_id();
    if (all || test == 4) test1_die_get_id();
    if (all || test == 5) test2_die_get_id();
	if (all || test == 6) test1_die_roll();
    if (all || test == 7) test2_die_roll();
    if (all || test == 8) test1_die_get_last_roll();
    if (all || test == 9) test2_die_get_last_roll();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/**
 * @test Prueba la función de creación de un dado
 * @pre nada
 * @post Un puntero no nulo al dado creado
 */

void test1_die_create() {
    Die* d = NULL;
    d = die_create();
    PRINT_TEST_RESULT(d != NULL);
    die_destroy(d);
}

/**
 * @test Prueba la función para establecer un id en el dado
 * @pre dado no NULL e id
 * @post La salida debe ser OK
 */
void test1_die_set_id() {
    Die* d = NULL;
    d = die_create();
    PRINT_TEST_RESULT(die_set_id(d, 1) == OK);
    die_destroy(d);
}

/**
 * @test Prueba la función para establecer un id en el dado
 * @pre dado NULL
 * @post La salida debe ser ERROR
 */
void test2_die_set_id() {
    Die* d = NULL;
    PRINT_TEST_RESULT(die_set_id(d, 1) == ERROR);
}

/**
 * @test Prueba la función para obtener el id de un dado
 * @pre El dado tiene id
 * @post La salida debe ser id=1
 */
void test1_die_get_id() {
    Die* d = NULL;
    d = die_create();
	die_set_id(d, 1);
    PRINT_TEST_RESULT(die_get_id(d) == 1);
    die_destroy(d);
}

/**
 * @test Prueba la función para obtener el id de un dado
 * @pre El dado es NULL
 * @post La salida debe ser -1
 */
void test2_die_get_id() {
    Die* d = NULL;
    PRINT_TEST_RESULT(die_get_id(d) == NO_ID);
}
/**
 * @test Prueba la función para tirar un dado
 * @pre dado no NULL
 * @post La salida debe ser >0
 */
void test1_die_roll() {
    Die* d = NULL;
    d = die_create();
    PRINT_TEST_RESULT(die_roll(d)> 0);
    die_destroy(d);
}

/**
 * @test Prueba la función para tirar un dado
 * @pre El dado es NULL
 * @post La salida debe ser -1
 */
void test2_die_roll() {
    Die* d = NULL;
    PRINT_TEST_RESULT(die_roll(d) == NO_ID);
}

/**
 * @test Prueba la función para obtener la tirada de un dado
 * @pre dado no NULL
 * @post La salida debe ser >0
 */
void test1_die_get_last_roll() {
    Die* d = NULL;
    d = die_create();
	die_roll(d);
    PRINT_TEST_RESULT(die_get_last_roll(d)> 0);
    die_destroy(d);
}

/**
 * @test Prueba la función para obtener la tirada de un dado
 * @pre El dado es NULL
 * @post La salida debe ser -1
 */
void test2_die_get_last_roll() {
    Die* d = NULL;
    PRINT_TEST_RESULT(die_get_last_roll(d) == NO_ID);
}