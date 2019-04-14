/**
 * @brief Prueba del modulo object
 * @file object_test.c
 * @author Manuel Suarez, Saul Almazán, �?lvaro Becerra, Rodrigo Lardiés
 * @version 1.0
 * @date 12-11-2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "object_test.h"
#include "test.h"

#define MAX_TESTS 41 /*!< TAM_TESTS */

/**
 * @brief Funcion principal de pruebas para el modulo object.
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
        printf("Running all test for module object:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Running test %d:\t", test);
        if (test < 1 && test > MAX_TESTS) {
            printf("Error: unknown test %d\t", test);
            exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_object_create();
    if (all || test == 2) test1_object_set_name();
    if (all || test == 3) test2_object_set_name();
    if (all || test == 4) test3_object_set_name();
    if (all || test == 5) test1_object_set_id();
    if (all || test == 6) test2_object_set_id();
    if (all || test == 7) test1_object_set_light();
    if (all || test == 8) test2_object_set_light();
    if (all || test == 9) test1_object_set_open();
    if (all || test == 10) test2_object_set_open();
    if (all || test == 11) test1_object_set_on();
    if (all || test == 12) test2_object_set_on();
    if (all || test == 13) test1_object_get_name();
    if (all || test == 14) test2_object_get_name();
    if (all || test == 15) test1_object_take_object();
    if (all || test == 16) test2_object_take_object();
    if (all || test == 17) test3_object_take_object();
    if (all || test == 18) test1_object_get_id();
    if (all || test == 19) test2_object_get_id();
    if (all || test == 20) test1_object_get_light();
    if (all || test == 21) test2_object_get_light();
    if (all || test == 22) test1_object_get_open();
    if (all || test == 23) test2_object_get_open();
    if (all || test == 24) test1_object_get_on();
    if (all || test == 25) test2_object_get_on();
    if (all || test == 26) test1_object_get_movable();
    if (all || test == 27) test2_object_get_movable();
    if (all || test == 28) test1_object_set_movable();
    if (all || test == 29) test2_object_set_movable();
    if (all || test == 30) test1_object_set_original_location();
    if (all || test == 31) test2_object_set_original_location();
    if (all || test == 32) test1_object_get_original_location();
    if (all || test == 33) test2_object_get_original_location();
    if (all || test == 34) test1_object_set_description();
    if (all || test == 35) test2_object_set_description();
    if (all || test == 36) test1_object_get_description();
    if (all || test == 37) test2_object_get_description();
    if (all || test == 38) test1_object_set_detailed_description();
    if (all || test == 39) test2_object_set_detailed_description();
    if (all || test == 40) test1_object_get_detailed_description();
    if (all || test == 41) test2_object_get_detailed_description();


    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/**
 * @test Prueba la función de creación de un objeto
 * @pre Nada
 * @post Un puntero no nulo al objeto creado
 */
void test1_object_create() {
    object *o = NULL;
    o = object_create();
    PRINT_TEST_RESULT(o != NULL);
    object_destroy(o);
}

/**
 * @test Prueba la función para establecer el nombre de un objeto
 * @pre Nombre que establecer al objeto
 * @post La salida debe ser OK
 */

void test1_object_set_name() {
    object *o;
    o = object_create();
    PRINT_TEST_RESULT(object_set_name(o, "Objeto") == OK);
    object_destroy(o);
}

/**
 * @test Prueba la función para establecer el nombre de un objeto
 * @pre El objeto al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_name() {
    object *o = NULL;
    PRINT_TEST_RESULT(object_set_name(o, "Objeto") == ERROR);
}

/**
 * @test Prueba la función para establecer el nombre de un objeto
 * @pre El objeto es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */

void test3_object_set_name() {
    object *o;
    o = object_create();
    PRINT_TEST_RESULT(object_set_name(o, NULL) == ERROR);
    object_destroy(o);
}

/**
 * @test Prueba la función para establecer el norte de un objeto
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_object_set_id() {
    object *o;
    o = object_create(o);
    PRINT_TEST_RESULT(object_set_id(o, 4) == OK);
    object_destroy(o);
}

/**
 * @test Prueba la función para establecer el norte de un objeto
 * @pre objeto NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_north() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_set_north(s, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer el sur de un objeto
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_object_set_south() {
    object *s;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_south(s, 4) == OK);
    object_destroy(s);
}

/**
 * @test Prueba la función para establecer el sur de un objeto
 * @pre objeto NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_south() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_set_south(s, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer el este de un objeto
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_object_set_east() {
    object *s;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_east(s, 4) == OK);
    object_destroy(s);
}

/**
 * @test Prueba la función para establecer el este de un objeto
 * @pre objeto NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_east() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_set_east(s, 4) == ERROR);
}

/**
 * @test Prueba la función para establecer el oeste de un objeto
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_object_set_west() {
    object *s;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_west(s, 4) == OK);
    object_destroy(s);
}

/**
 * @test Prueba la función para establecer el norte de un objeto
 * @pre objeto NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_west() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_set_west(s, 4) == ERROR);
}

/**
 * @test Prueba la función para obtener el nombre de un objeto
 * @pre objeto con nombre establecido
 * @post La salida debe ser una comparación de cadenas igual a 0
 */

void test1_object_get_name() {
    object *s;
    s = object_create(5);
    object_set_name(s, "Casilla");
    PRINT_TEST_RESULT(strcmp(object_get_name(s), "Casilla") == 0);
    object_destroy(s);
}

/**
 * @test Prueba la función para obtener el nombre de un objeto
 * @pre objeto NULL
 * @post La salida debe ser NULL
 */
void test2_object_get_name() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_get_name(s) == NULL);
}

/**
 * @test Prueba la función para coger un objeto de un objeto
 * @pre objeto sin objetos
 * @post La salida debe ser ERROR
 */
void test1_object_take_object() {
    object *s = NULL;
    s = object_create(5);
    PRINT_TEST_RESULT(object_take_object(s, 1) == ERROR);
    object_destroy(s);
}

/**
 * @test Prueba la función para coger un objeto de un objeto
 * @pre objeto con objetos
 * @post La salida debe ser OK
 */
void test2_object_take_object() {
    object *s = NULL;
    s = object_create(5);
    object_leave_object(s, 1);
    PRINT_TEST_RESULT(object_take_object(s, 1) == OK);
    object_destroy(s);
}

/**
 * @test Prueba la función para coger un objeto de un objeto
 * @pre objeto NULL
 * @post La salida debe ser ERROR
 */
void test3_object_take_object() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_take_object(s, 1) == ERROR);
}

/**
 * @test Prueba la función para obtener el norte de un objeto
 * @pre objeto con norte asignado
 * @post La salida debe ser id=4
 */
void test1_object_get_north() {
    object *s;
    s = object_create(5);
    object_set_north(s, 4);
    PRINT_TEST_RESULT(object_get_north(s) == 4);
    object_destroy(s);
}

/**
 * @test Prueba la función para obtener el norte de un objeto
 * @pre objeto NULL
 * @post La salida debe ser NO_ID
 */
void test2_object_get_north() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_get_north(s) == NO_ID);
}

/**
 * @test Prueba la función para obtener el sur de un objeto
 * @pre objeto con sur asignado
 * @post La salida debe ser id=4
 */
void test1_object_get_south() {
    object *s;
    s = object_create(5);
    object_set_south(s, 4);
    PRINT_TEST_RESULT(object_get_south(s) == 4);
    object_destroy(s);
}

/**
 * @test Prueba la función para obtener el sur de un objeto
 * @pre objeto NULL
 * @post La salida debe ser NO_ID
 */
void test2_object_get_south() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_get_south(s) == NO_ID);
}

/**
 * @test Prueba la función para obtener el este de un objeto
 * @pre objeto con este asignado
 * @post La salida debe ser id=4
 */
void test1_object_get_east() {
    object *s;
    s = object_create(5);
    object_set_east(s, 4);
    PRINT_TEST_RESULT(object_get_east(s) == 4);
    object_destroy(s);
}

/**
 * @test Prueba la función para obtener el este de un objeto
 * @pre objeto NULL
 * @post La salida debe ser NO_ID
 */
void test2_object_get_east() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_get_east(s) == NO_ID);
}

/**
 * @test Prueba la función para obtener el oeste de un objeto
 * @pre objeto con oeste asignado
 * @post La salida debe ser id=4
 */
void test1_object_get_west() {
    object *s;
    s = object_create(5);
    object_set_west(s, 4);
    PRINT_TEST_RESULT(object_get_west(s) == 4);
    object_destroy(s);
}

/**
 * @test Prueba la función para obtener el oeste de un objeto
 * @pre objeto NULL
 * @post La salida debe ser NO_ID
 */
void test2_object_get_west() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_get_west(s) == NO_ID);
}

/**
 * @test Prueba la función para obtener el id de un objeto
 * @pre objeto con id asignado
 * @post La salida debe ser id=5
 */
void test1_object_get_id() {
    object *s;
    s = object_create(5);
    PRINT_TEST_RESULT(object_get_id(s) == 5);
    object_destroy(s);
}

/**
 * @test Prueba la función para obtener el id de un objeto
 * @pre objeto NULL
 * @post La salida debe ser NO_ID
 */
void test2_object_get_id() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_get_id(s) == NO_ID);
}

/**
 * @test Prueba la función para dejar un objeto en un objeto
 * @pre objeto no NULL
 * @post La salida debe ser OK
 */
void test1_object_leave_object() {
    object *s = NULL;
    s = object_create(5);
    PRINT_TEST_RESULT(object_leave_object(s, 1) == OK);
    object_destroy(s);
}

/**
 * @test Prueba la función para dejar un objeto en un objeto
 * @pre objeto NULL
 * @post La salida debe ser ERROR
 */
void test2_object_leave_object() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_leave_object(s, 1) == ERROR);
}

/**
 * @test Prueba la función para dejar un establecer un dibujo en un objeto
 * @pre objeto no NULL
 * @post La salida debe ser OK
 */
void test1_object_set_gdesc() {
    object *s = NULL;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_gdesc(s, "Oca") == OK);
    object_destroy(s);
}

/**
 * @test Prueba la función para dejar un establecer un dibujo en un objeto
 * @pre objeto NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_gdesc() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_set_gdesc(s, "Oca") == ERROR);
}

/**
 * @test Prueba la función para dejar un obtener un dibujo en un objeto
 * @pre objeto con dibujo
 * @post La salida debe ser una comparacion de cadenas igual a 0
 */
void test1_object_get_gdesc() {
    object *s = NULL;
    s = object_create(5);
    object_set_gdesc(s, "Oca");
    PRINT_TEST_RESULT((strcmp(object_get_gdesc(s), "Oca")) == 0);
    object_destroy(s);
}

/**
 * @test Prueba la función para dejar un obtener un dibujo en un objeto
 * @pre objeto NULL
 * @post La salida debe ser NULL
 */
void test2_object_get_gdesc() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_get_gdesc(s) == NULL);
}

/**
 * @test Prueba la función para dejar un establecer una descripcion en un objeto
 * @pre objeto no NULL
 * @post La salida debe ser OK
 */
void test1_object_set_description() {
    object *s = NULL;
    s = object_create(5);
    PRINT_TEST_RESULT(object_set_description(s, "Oca") == OK);
    object_destroy(s);
}

/**
 * @test Prueba la función para establecer una descripcion en un objeto
 * @pre objeto NULL
 * @post La salida debe ser ERROR
 */
void test2_object_set_description() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_set_description(s, "Oca") == ERROR);
}

/**
 * @test Prueba la función para obtener una descripcion en un objeto
 * @pre objeto con una descripcion
 * @post La salida debe ser una comparación de cadenas igual a 0
 */
void test1_object_get_description() {
    object *s = NULL;
    s = object_create(5);
    object_set_description(s, "Oca");
    PRINT_TEST_RESULT(strcmp(object_get_description(s), "Oca") == 0);
    object_destroy(s);
}

/**
 * @test Prueba la función para dejar un obtener una descripcion en un objeto
 * @pre objeto NULL
 * @post La salida debe ser NULL
 */
void test2_object_get_description() {
    object *s = NULL;
    PRINT_TEST_RESULT(object_get_description(s) == NULL);
}
