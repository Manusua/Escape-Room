/** 
 * @brief Prueba del modulo link
 * 
 * @file link_test.c
 * @author Manuel Suarez, Saul Almazán, �?lvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "link.h"
#include "link_test.h"
#include "test.h"

#define MAX_TESTS 20 /*!< TAM_TESTS */

/** 
 * @brief Funcion principal de pruebas para el modulo link. 
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
        printf("Prueba módulo link:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Probando test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: test %d desconocido\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_link_create();
    if (all || test == 2) test1_link_set_name();
    if (all || test == 3) test2_link_set_name();
    if (all || test == 4) test3_link_set_name();
    if (all || test == 5) test1_link_set_id();
    if (all || test == 6) test2_link_set_id();
    if (all || test == 7) test1_link_set_conection();
    if (all || test == 8) test2_link_set_conection();
    if (all || test == 9) test1_link_set_status();
    if (all || test == 10) test2_link_set_status();
    if (all || test == 11) test1_link_get_name();
    if (all || test == 12) test2_link_get_name();
    if (all || test == 13) test1_link_get_id();
    if (all || test == 14) test2_link_get_id();
    if (all || test == 15) test1_link_get_conection_1();
    if (all || test == 16) test2_link_get_conection_1();
    if (all || test == 17) test1_link_get_conection_2();
    if (all || test == 18) test2_link_get_conection_2();
    if (all || test == 19) test1_link_set_status();
    if (all || test == 20) test2_link_set_status();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/**
 * @test Prueba la función de creación de un link
 * @pre Nada
 * @post Un puntero no nulo al link creado
 */

void test1_link_create() {
    Link *l = NULL;
    l = link_create();
    PRINT_TEST_RESULT(l != NULL);
    link_destroy(l);
}

/**
 * @test Prueba la función para establecer el nombre de un link
 * @pre Nombre que establecer al link
 * @post La salida debe ser OK
 */
void test1_link_set_name() {
    Link *l = NULL;
    l = link_create();
    PRINT_TEST_RESULT(link_set_name(l, "Union") == OK);
    link_destroy(l);

}

/**
 * @test Prueba la función para establecer el nombre de un link
 * @pre El link al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */

void test2_link_set_name() {
    Link *l = NULL;
    PRINT_TEST_RESULT(link_set_name(l, "Union") == ERROR);
}

/**
 * @test Prueba la función para establecer el nombre de un link
 * @pre El link es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_link_set_name() {
    Link *l = NULL;
    l = link_create();
    PRINT_TEST_RESULT(link_set_name(l, NULL) == ERROR);
    link_destroy(l);
}

/**
 * @test Prueba la función para establecer el id de un link
 * @pre id que establecer al link
 * @post La salida debe ser OK
 */
void test1_link_set_id() {
    Link *l = NULL;
    l = link_create();
    PRINT_TEST_RESULT(link_set_id(l, 1) == OK);
    link_destroy(l);
}

/**
 * @test Prueba la función para establecer el id de un link
 * @pre id válido, pero link NULL
 * @post La salida debe ser ERROR
 */

void test2_link_set_id() {
    Link *l = NULL;
    PRINT_TEST_RESULT(link_set_id(l, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer la conexion de un link
 * @pre ids que establecer al link
 * @post La salida debe ser OK
 */
void test1_link_set_conection() {
    Link *l = NULL;
    l = link_create();
    PRINT_TEST_RESULT(link_set_conection(l, 1, 2) == OK);
    link_destroy(l);
}

/**
 * @test Prueba la función para establecer la conexion de un link
 * @pre ids válido, pero link NULL
 * @post La salida debe ser ERROR
 */
void test2_link_set_conection() {
    Link *l = NULL;
    PRINT_TEST_RESULT(link_set_conection(l, 1, 2) == ERROR);
}

/**
 * @test Prueba la función para establecer el estado de un link
 * @pre estado que establecer al link
 * @post La salida debe ser OK
 */
void test1_link_set_status() {
    Link *l = NULL;
    l = link_create();
    PRINT_TEST_RESULT(link_set_status(l, TRUE) == OK);
    link_destroy(l);
}

/**
 * @test Prueba la función para establecer el estado de un link
 * @pre estado válido, pero link NULL
 * @post La salida debe ser ERROR
 */
void test2_link_set_status() {
    Link *l = NULL;
    PRINT_TEST_RESULT(link_set_status(l, TRUE) == ERROR);
}

/**
 * @test Prueba la función para obtener el nombre de un link
 * @pre El link tiene un nombre establecido
 * @post La salida debe ser una comparación de cadenas igual a 0
 */
void test1_link_get_name() {
    Link *l = NULL;
    l = link_create();
    link_set_name(l, "Union");
    PRINT_TEST_RESULT(strcmp(link_get_name(l), "Union") == 0);
    link_destroy(l);

}

/**
 * @test Prueba la función para obtener el nombre de un link
 * @pre El link es NULL
 * @post La salida debe ser NULL
 */
void test2_link_get_name() {
    Link *l = NULL;
    PRINT_TEST_RESULT(link_get_name(l) == NULL);
}

/**
 * @test Prueba la función para obtener el id de un link
 * @pre El link tiene un id establecido
 * @post La salida debe ser id=1
 */
void test1_link_get_id() {
    Link *l = NULL;
    l = link_create();
    link_set_id(l, 1);
    PRINT_TEST_RESULT(link_get_id(l) == 1);
    link_destroy(l);
}

/**
 * @test Prueba la función para obtener el id de un link
 * @pre El link es NULL
 * @post La salida debe ser NO_ID
 */
void test2_link_get_id() {
    Link *l = NULL;
    PRINT_TEST_RESULT(link_get_id(l) == NO_ID);
}

/**
 * @test Prueba la función para obtener el id 1 de un link
 * @pre El link tiene un id establecido
 * @post La salida debe ser id=1
 */
void test1_link_get_conection_1() {
    Link *l = NULL;
    l = link_create();
    link_set_conection(l, 1, 2);
    PRINT_TEST_RESULT(link_get_conection_1(l) == 1);
    link_destroy(l);
}

/**
 * @test Prueba la función para obtener el id 1 de un link
 * @pre El link es NULL
 * @post La salida debe ser NO_ID
 */
void test2_link_get_conection_1() {
    Link *l = NULL;
    PRINT_TEST_RESULT(link_get_conection_1(l) == NO_ID);
}

/**
 * @test Prueba la función para obtener el id 2 de un link
 * @pre El link tiene un id establecido
 * @post La salida debe ser id=1
 */
void test1_link_get_conection_2() {
    Link *l = NULL;
    l = link_create();
    link_set_conection(l, 1, 2);
    PRINT_TEST_RESULT(link_get_conection_2(l) == 2);
    link_destroy(l);
}

/**
 * @test Prueba la función para obtener el id 2 de un link
 * @pre El link es NULL
 * @post La salida debe ser NO_ID
 */
void test2_link_get_conection_2() {
    Link *l = NULL;
    PRINT_TEST_RESULT(link_get_conection_2(l) == NO_ID);
}

/**
 * @test Prueba la función para saber el estado de un link
 * @pre link con un estado asignado
 * @post La salida debe ser TRUE
 */
void test1_link_get_status() {
    Link *l = NULL;
    l = link_create();
    link_set_status(l, TRUE);
    PRINT_TEST_RESULT(link_get_status(l) == TRUE);
    link_destroy(l);
}

/**
 * @test Prueba la función para saber el estado de un link
 * @pre link con un estado asignado
 * @post La salida debe ser FALSE
 */
void test2_link_get_status() {
    Link *l = NULL;
    l = link_create();
    link_set_status(l, FALSE);
    PRINT_TEST_RESULT(link_get_status(l) == FALSE);
    link_destroy(l);
}

