/** 
 * @brief Prueba del modulo space
 * @file space_test.c
 * @author Manuel Suarez, Saul Almazán, �?lvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "space.h"
#include "space_test.h"
#include "test.h"

#define MAX_TESTS 37 /*!< TAM_TESTS */

/** 
 * @brief Funcion principal de pruebas para el modulo Space. 
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
        printf("Running all test for module Space:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_space_create(5);
    if (all || test == 2) test1_space_set_name();
    if (all || test == 3) test2_space_set_name();
    if (all || test == 4) test3_space_set_name();
    if (all || test == 5) test1_space_set_north();
    if (all || test == 6) test2_space_set_north();
    if (all || test == 7) test1_space_set_south();
    if (all || test == 8) test2_space_set_south();
    if (all || test == 9) test1_space_set_east();
    if (all || test == 10) test2_space_set_east();
    if (all || test == 11) test1_space_set_west();
    if (all || test == 12) test2_space_set_west();
    if (all || test == 13) test1_space_get_name();
    if (all || test == 14) test2_space_get_name();
    if (all || test == 15) test1_space_take_object();
    if (all || test == 16) test2_space_take_object();
    if (all || test == 17) test3_space_take_object();
    if (all || test == 18) test1_space_get_north();
    if (all || test == 19) test2_space_get_north();
    if (all || test == 20) test1_space_get_south();
    if (all || test == 21) test2_space_get_south();
    if (all || test == 22) test1_space_get_east();
    if (all || test == 23) test2_space_get_east();
    if (all || test == 24) test1_space_get_west();
    if (all || test == 25) test2_space_get_west();
    if (all || test == 26) test1_space_get_id();
    if (all || test == 27) test2_space_get_id();
    if (all || test == 28) test1_space_leave_object();
    if (all || test == 29) test2_space_leave_object();
    if (all || test == 30) test1_space_set_gdesc();
    if (all || test == 31) test2_space_set_gdesc();
    if (all || test == 32) test1_space_get_gdesc();
    if (all || test == 33) test2_space_get_gdesc();
    if (all || test == 34) test1_space_set_description();
    if (all || test == 35) test2_space_set_description();
    if (all || test == 36) test1_space_get_description();
    if (all || test == 37) test2_space_get_description();


    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/**
 * @test Prueba la función de creación de un espacio
 * @pre Nada
 * @post Un puntero no nulo al espacio creado
 */
void test1_space_create() {
    Space *s = NULL;
    s = space_create(5);
    PRINT_TEST_RESULT(s != NULL);
    space_destroy(s);
}

/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre Nombre que establecer al espacio
 * @post La salida debe ser OK
 */

void test1_space_set_name() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, "Casilla") == OK);
    space_destroy(s);
}

/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre El espacio al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_name() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_name(s, "Casilla") == ERROR);
}

/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre El espacio es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */

void test3_space_set_name() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_name(s, NULL) == ERROR);
    space_destroy(s);
}

/**
 * @test Prueba la función para establecer el norte de un espacio
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_space_set_north() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_north(s, 4) == OK);
    space_destroy(s);
}

/**
 * @test Prueba la función para establecer el norte de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_north() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_north(s, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer el sur de un espacio
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_space_set_south() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_south(s, 4) == OK);
    space_destroy(s);
}

/**
 * @test Prueba la función para establecer el sur de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_south() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_south(s, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer el este de un espacio
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_space_set_east() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_east(s, 4) == OK);
    space_destroy(s);
}

/**
 * @test Prueba la función para establecer el este de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_east() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_east(s, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer el oeste de un espacio
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_space_set_west() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_west(s, 4) == OK);
    space_destroy(s);
}

/**
 * @test Prueba la función para establecer el norte de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_west() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_west(s, 4) == ERROR);
}

/**
 * @test Prueba la función para obtener el nombre de un espacio
 * @pre Espacio con nombre establecido
 * @post La salida debe ser una comparación de cadenas igual a 0
 */

void test1_space_get_name() {
    Space *s;
    s = space_create(5);
    space_set_name(s, "Casilla");
    PRINT_TEST_RESULT(strcmp(space_get_name(s), "Casilla") == 0);
    space_destroy(s);
}

/**
 * @test Prueba la función para obtener el nombre de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NULL
 */
void test2_space_get_name() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_name(s) == NULL);
}

/**
 * @test Prueba la función para coger un objeto de un espacio
 * @pre Espacio sin objetos
 * @post La salida debe ser ERROR
 */
void test1_space_take_object() {
    Space *s = NULL;
    s = space_create(5);
    PRINT_TEST_RESULT(space_take_object(s, 1) == ERROR);
    space_destroy(s);
}

/**
 * @test Prueba la función para coger un objeto de un espacio
 * @pre Espacio con objetos
 * @post La salida debe ser OK
 */
void test2_space_take_object() {
    Space *s = NULL;
    s = space_create(5);
    space_leave_object(s, 1);
    PRINT_TEST_RESULT(space_take_object(s, 1) == OK);
    space_destroy(s);
}

/**
 * @test Prueba la función para coger un objeto de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test3_space_take_object() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_take_object(s, 1) == ERROR);
}

/**
 * @test Prueba la función para obtener el norte de un espacio
 * @pre Espacio con norte asignado
 * @post La salida debe ser id=4
 */
void test1_space_get_north() {
    Space *s;
    s = space_create(5);
    space_set_north(s, 4);
    PRINT_TEST_RESULT(space_get_north(s) == 4);
    space_destroy(s);
}

/**
 * @test Prueba la función para obtener el norte de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_north() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_north(s) == NO_ID);
}

/**
 * @test Prueba la función para obtener el sur de un espacio
 * @pre Espacio con sur asignado
 * @post La salida debe ser id=4
 */
void test1_space_get_south() {
    Space *s;
    s = space_create(5);
    space_set_south(s, 4);
    PRINT_TEST_RESULT(space_get_south(s) == 4);
    space_destroy(s);
}

/**
 * @test Prueba la función para obtener el sur de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_south() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_south(s) == NO_ID);
}

/**
 * @test Prueba la función para obtener el este de un espacio
 * @pre Espacio con este asignado
 * @post La salida debe ser id=4
 */
void test1_space_get_east() {
    Space *s;
    s = space_create(5);
    space_set_east(s, 4);
    PRINT_TEST_RESULT(space_get_east(s) == 4);
    space_destroy(s);
}

/**
 * @test Prueba la función para obtener el este de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_east() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_east(s) == NO_ID);
}

/**
 * @test Prueba la función para obtener el oeste de un espacio
 * @pre Espacio con oeste asignado
 * @post La salida debe ser id=4
 */
void test1_space_get_west() {
    Space *s;
    s = space_create(5);
    space_set_west(s, 4);
    PRINT_TEST_RESULT(space_get_west(s) == 4);
    space_destroy(s);
}

/**
 * @test Prueba la función para obtener el oeste de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_west() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_west(s) == NO_ID);
}

/**
 * @test Prueba la función para obtener el id de un espacio
 * @pre Espacio con id asignado
 * @post La salida debe ser id=5
 */
void test1_space_get_id() {
    Space *s;
    s = space_create(5);
    PRINT_TEST_RESULT(space_get_id(s) == 5);
    space_destroy(s);
}

/**
 * @test Prueba la función para obtener el id de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_id() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_id(s) == NO_ID);
}

/**
 * @test Prueba la función para dejar un objeto en un espacio
 * @pre Espacio no NULL
 * @post La salida debe ser OK
 */
void test1_space_leave_object() {
    Space *s = NULL;
    s = space_create(5);
    PRINT_TEST_RESULT(space_leave_object(s, 1) == OK);
    space_destroy(s);
}

/**
 * @test Prueba la función para dejar un objeto en un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_leave_object() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_leave_object(s, 1) == ERROR);
}

/**
 * @test Prueba la función para dejar un establecer un dibujo en un espacio
 * @pre Espacio no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_gdesc() {
    Space *s = NULL;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_gdesc(s, "Oca") == OK);
    space_destroy(s);
}

/**
 * @test Prueba la función para dejar un establecer un dibujo en un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_gdesc() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_gdesc(s, "Oca") == ERROR);
}

/**
 * @test Prueba la función para dejar un obtener un dibujo en un espacio
 * @pre Espacio con dibujo
 * @post La salida debe ser una comparacion de cadenas igual a 0
 */
void test1_space_get_gdesc() {
    Space *s = NULL;
    s = space_create(5);
    space_set_gdesc(s, "Oca");
    PRINT_TEST_RESULT((strcmp(space_get_gdesc(s), "Oca")) == 0);
    space_destroy(s);
}

/**
 * @test Prueba la función para dejar un obtener un dibujo en un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NULL
 */
void test2_space_get_gdesc() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_gdesc(s) == NULL);
}

/**
 * @test Prueba la función para dejar un establecer una descripcion en un espacio
 * @pre Espacio no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_description() {
    Space *s = NULL;
    s = space_create(5);
    PRINT_TEST_RESULT(space_set_description(s, "Oca") == OK);
    space_destroy(s);
}

/**
 * @test Prueba la función para establecer una descripcion en un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_description() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_set_description(s, "Oca") == ERROR);
}

/**
 * @test Prueba la función para obtener una descripcion en un espacio
 * @pre Espacio con una descripcion
 * @post La salida debe ser una comparación de cadenas igual a 0
 */
void test1_space_get_description() {
    Space *s = NULL;
    s = space_create(5);
    space_set_description(s, "Oca");
    PRINT_TEST_RESULT(strcmp(space_get_description(s), "Oca") == 0);
    space_destroy(s);
}

/**
 * @test Prueba la función para dejar un obtener una descripcion en un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NULL
 */
void test2_space_get_description() {
    Space *s = NULL;
    PRINT_TEST_RESULT(space_get_description(s) == NULL);
}
