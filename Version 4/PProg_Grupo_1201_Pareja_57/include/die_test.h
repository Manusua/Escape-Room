/** 
 * @brief Prueba del modulo die
 * 
 * @file die_test.h
 * @author Manuel Suarez, Saul Almazán, �?lvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#ifndef DIE_TEST_H
#define DIE_TEST_H

/**
 * @test Prueba la función de creación de un dado
 * @pre nada
 * @post Un puntero no nulo al dado creado
 */

void test1_die_create();

/**
 * @test Prueba la función para establecer un id en el dado
 * @pre dado no NULL e id
 * @post La salida debe ser OK
 */
void test1_die_set_id();

/**
 * @test Prueba la función para establecer un id en el dado
 * @pre dado NULL
 * @post La salida debe ser ERROR
 */
void test2_die_set_id();

/**
 * @test Prueba la función para obtener el id de un dado
 * @pre El dado tiene id
 * @post La salida debe ser id=1
 */
void test1_die_get_id();

/**
 * @test Prueba la función para obtener el id de un dado
 * @pre El dado es NULL
 * @post La salida debe ser -1
 */
void test2_die_get_id();
/**
 * @test Prueba la función para tirar un dado
 * @pre dado no NULL
 * @post La salida debe ser >0
 */
void test1_die_roll();

/**
 * @test Prueba la función para tirar un dado
 * @pre El dado es NULL
 * @post La salida debe ser -1
 */
void test2_die_roll();

/**
 * @test Prueba la función para obtener la tirada de un dado
 * @pre dado no NULL
 * @post La salida debe ser >0
 */
void test1_die_get_last_roll();
/**
 * @test Prueba la función para obtener la tirada de un dado
 * @pre El dado es NULL
 * @post La salida debe ser -1
 */
void test2_die_get_last_roll();
#endif
