/** 
 * @brief Prueba del modulo player
 * 
 * @file player_test.c
 * @author 
 * @version 1.0 
 * @date 12-11-2018
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "player.h"
#include "player_test.h"
#include "test.h"

#define MAX_TESTS 23

/** 
 * @brief Funcion principal de pruebas para el modulo player. 
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
        printf("Prueba módulo player:\n");
    } else {
        test = atoi(argv[1]);
        all = 0;
        printf("Probando test %d:\t", test);
	if (test < 1 && test > MAX_TESTS) {
	  printf("Error: test %d desconocido\t", test);
	  exit(EXIT_SUCCESS);
        }
    }


    if (all || test == 1) test1_player_create();
    if (all || test == 2) test2_player_create();
    if (all || test == 3) test1_player_set_name();
    if (all || test == 4) test2_player_set_name();
    if (all || test == 5) test3_player_set_name();
    if (all || test == 6) test1_player_set_id();
    if (all || test == 7) test2_player_set_id();
    if (all || test == 8) test1_player_set_space_id();
    if (all || test == 9) test2_player_set_space_id();
    if (all || test == 10) test1_player_get_name();
    if (all || test == 11) test2_player_get_name();
    if (all || test == 12) test1_player_get_id();
    if (all || test == 13) test2_player_get_id();
    if (all || test == 14) test1_player_get_space_id();
    if (all || test == 15) test2_player_get_space_id();
    if (all || test == 16) test1_player_drop_object();
    if (all || test == 17) test2_player_drop_object();
    if (all || test == 18) test1_player_pick_object();
    if (all || test == 19) test2_player_pick_object();
    if (all || test == 20) test1_player_has_object();
    if (all || test == 21) test2_player_has_object();
    if (all || test == 22) test1_player_bag_is_full();
    if (all || test == 23) test2_player_bag_is_full();

    PRINT_PASSED_PERCENTAGE;

    return 1;
}

/**
 * @test Prueba la función de creación de un jugador
 * @pre Un numero de objetos como parámetro
 * @post Un puntero no nulo al jugador creado
 */
 
void test1_player_create() {
  int result = player_create(5)!=NULL ;
  PRINT_TEST_RESULT(result);
  player_destroy(p);
}
/**
 * @test Prueba la función de creación de un jugador
 * @pre Un numero de objetos erroneo como parámetro
 * @post Se obtiene un puntero NULL
 */
void test2_player_create() {
    Player *p=NULL;
    p = player_create(-1);
    PRINT_TEST_RESULT(!p);
}
/**
 * @test Prueba la función para establecer el nombre de un jugador
 * @pre Nombre que establecer al jugador
 * @post La salida debe ser OK
 */
void test1_player_set_name() {
    Player *p=NULL;
    p = player_create(3);
    PRINT_TEST_RESULT(player_set_name(p, "Paco") == OK);
	  player_destroy(p);

}
/**
 * @test Prueba la función para establecer el nombre de un jugador
 * @pre El jugador al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */

void test2_player_set_name() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_name(p, "Paco") == ERROR);
}
/**
 * @test Prueba la función para establecer el nombre de un jugador
 * @pre El jugador es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_player_set_name() {
    Player *p=NULL;
    p = player_create(3);
    PRINT_TEST_RESULT(player_set_name(p, NULL) == ERROR);
	  player_destroy(p);
}
/**
 * @test Prueba la función para establecer el id de un jugador
 * @pre id que establecer al jugador
 * @post La salida debe ser OK
 */
void test1_player_set_id() {
    Player *p=NULL;
    p = player_create(3);
    PRINT_TEST_RESULT(player_set_id(p, 1) == OK);
	  player_destroy(p);
}
/**
 * @test Prueba la función para establecer el id de un jugador
 * @pre id válido, pero jugador NULL
 * @post La salida debe ser ERROR
 */

void test2_player_set_id() {
    Player *p = NULL;
    PRINT_TEST_RESULT(player_set_id(p, 4) == ERROR);
}
/**
 * @test Prueba la función para establecer el id del espacio de un jugador
 * @pre id que establecer al jugador
 * @post La salida debe ser OK
 */
void test1_player_set_space_id() {
    Player *p=NULL;
    p = player_create(3);
    PRINT_TEST_RESULT(player_set_space_id(p, 1) == OK);
	player_destroy(p);
}
/**
 * @test Prueba la función para establecer el id del espacio de un jugador
 * @pre id válido, pero jugador NULL
 * @post La salida debe ser ERROR
 */
void test2_player_set_space_id() {
    Player *p=NULL;
    p = player_create(3);
    PRINT_TEST_RESULT(player_set_space_id(p, -1) == ERROR);
	 player_destroy(p);
}
/**
 * @test Prueba la función para obtener el nombre de un jugador
 * @pre El jugador tiene un nombre establecido
 * @post La salida debe ser una comparación de cadenas igual a 0
 */
void test1_player_get_name() {
    Player *p=NULL;
    p = player_create(3);
	player_set_name(p, "Paco");
    PRINT_TEST_RESULT(strcmp(player_get_name(p), "Paco") == 0);
	  player_destroy(p);

}
/**
 * @test Prueba la función para obtener el nombre de un jugador
 * @pre El jugador es NULL
 * @post La salida debe ser NULL
 */
void test2_player_get_name() {
    Player *p=NULL;
    PRINT_TEST_RESULT(player_get_name(p) == NULL);
}
/**
 * @test Prueba la función para obtener el id de un jugador
 * @pre El jugador tiene un id establecido
 * @post La salida debe ser id=1
 */
void test1_player_get_id() {
    Player *p=NULL;
    p = player_create(3);
	player_set_id(p, 1);
    PRINT_TEST_RESULT(player_get_id(p) == 1);
	  player_destroy(p);
}
/**
 * @test Prueba la función para obtener el id de un jugador
 * @pre El jugador es NULL
 * @post La salida debe ser NO_ID
 */
void test2_player_get_id() {
    Player *p=NULL;
    PRINT_TEST_RESULT(player_get_id(p) == NO_ID);
}
/**
 * @test Prueba la función para obtener el id de un espacio de un jugador
 * @pre El jugador tiene un id establecido
 * @post La salida debe ser id=1
 */
void test1_player_get_space_id() {
    Player *p=NULL;
    p = player_create(3);
	player_set_space_id(p, 1);
    PRINT_TEST_RESULT(player_get_space_id(p) == 1);
	  player_destroy(p);
}
/**
 * @test Prueba la función para obtener el id de un jugador
 * @pre El jugador es NULL
 * @post La salida debe ser NO_ID
 */
void test2_player_get_space_id() {
    Player *p=NULL;
    PRINT_TEST_RESULT(player_get_space_id(p) == NO_ID);
}
/**
 * @test Prueba la función para dejar un objeto de un jugador
 * @pre Jugador con un objeto
 * @post La salida debe ser OK
 */
void test1_player_drop_object() {
    Player *p=NULL;
    p = player_create(3);
	player_pick_object(p, 1);
    PRINT_TEST_RESULT(player_drop_object(p, 1) == OK);
  player_destroy(p);
}
/**
 * @test Prueba la función para dejar un objeto de un jugador
 * @pre Jugador con un objeto distinto al que se quiere dejar
 * @post La salida debe ser ERROR
 */
void test2_player_drop_object() {
    Player *p=NULL;
    PRINT_TEST_RESULT(player_drop_object(p, 1) == ERROR);

}
/**
 * @test Prueba la función para coger un objeto
 * @pre Jugador e id de un objeto
 * @post La salida debe ser OK
 */
void test1_player_pick_object() {
    Player *p=NULL;
    p = player_create(3);
    PRINT_TEST_RESULT(player_pick_object(p, 1) == OK);
  player_destroy(p);
}
/**
 * @test Prueba la función para coger un objeto
 * @pre Jugador NULL
 * @post La salida debe ser ERROR
 */
void test2_player_pick_object() {
    Player *p=NULL;
    PRINT_TEST_RESULT(player_pick_object(p, 1) == ERROR);

}
/**
 * @test Prueba la función para saber si un jugador tiene un objeto
 * @pre Jugador con un objeto
 * @post La salida debe ser TRUE
 */

void test1_player_has_object() {
    Player *p=NULL;
    p = player_create(3);
	player_pick_object(p, 1);
    PRINT_TEST_RESULT(player_has_object(p,1) == TRUE);
	  player_destroy(p);
}
/**
 * @test Prueba la función para saber si un jugador tiene un objeto
 * @pre Jugador con un objeto distinto al que se pregunta
 * @post La salida debe ser FALSE
 */
void test2_player_has_object() {
    Player *p=NULL;
    p = player_create(3);
	player_pick_object(p, 1);
    PRINT_TEST_RESULT(player_has_object(p,3) == FALSE);
	  player_destroy(p);
}

/**
 * @test Prueba la función para saber si la mochila de un jugador está llena
 * @pre Jugador con una mochila para más de un objeto
 * @post La salida debe ser FALSE
 */
void test1_player_bag_is_full() {
    Player *p=NULL;
    p = player_create(3);
	player_pick_object(p, 1);
    PRINT_TEST_RESULT(player_bag_is_full(p) == FALSE);
	  player_destroy(p);
}
/**
 * @test Prueba la función para saber si la mochila de un jugador está llena
 * @pre Jugador NULL
 * @post La salida debe ser TRUE
 */
void test2_player_bag_is_full() {
    Player *p=NULL;
    PRINT_TEST_RESULT(player_bag_is_full(p) == TRUE);
}


