/** 
 * @brief Prueba del modulo player
 * 
 * @file set_test.h
 * @author Manuel Suarez, Saul Almazán, �?lvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#ifndef SET_TEST_H
#define SET_TEST_H

/**
 * @test Prueba la función de creación de un set
 * @pre nada
 * @post Un puntero no nulo al set creado
 */

void test1_set_create();


/**
 * @test Prueba la función para borrar un objeto de un set
 * @pre set con un objeto
 * @post La salida debe ser OK
 */
void test1_set_delete_element();

/**
 * @test Prueba la función para borrar un objeto de un set
 * @pre set NULL
 * @post La salida debe ser ERROR
 */

void test2_set_delete_element();

/**
 * @test Prueba la función para borrar un objeto de un set
 * @pre set sin objetos
 * @post La salida debe ser ERROR
 */
void test3_set_delete_element();

/**
 * @test Prueba la función para añadir un objeto a un set
 * @pre id que establecer en el set
 * @post La salida debe ser OK
 */
void test1_set_add();

/**
 * @test Prueba la función para añadir un objeto a un set
 * @pre id válido, pero set NULL
 * @post La salida debe ser ERROR
 */

void test2_set_add();

/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre set vacío
 * @post La salida debe ser FALSE
 */
void test1_set_is_full();

/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre set lleno
 * @post La salida debe ser TRUE
 */
void test2_set_is_full();

/**
 * @test Prueba la función para comprobar si un invetario está vacío
 * @pre set vacío
 * @post La salida debe ser TRUE
 */
void test1_set_is_empty();

/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre set lleno
 * @post La salida debe ser FALSE
 */
void test2_set_is_empty();

/**
 * @test Prueba la función para saber si hay un objeto en el set
 * @pre El set tiene un objeto
 * @post La salida debe ser TRUE
 */
void test1_set_is_id_in();

/**
 * @test Prueba la función para saber si hay un objeto en el set
 * @pre El set es NULL
 * @post La salida debe ser FALSE
 */
void test2_set_is_id_in();

/**
 * @test Prueba la función para obtener el numero de ids de un set
 * @pre El set tiene cero ids
 * @post La salida debe ser tam=0
 */
void test1_set_get_num_ids();

/**
 * @test Prueba la función para obtener el numero de ids de un set
 * @pre El set es NULL
 * @post La salida debe ser -1
 */
void test2_set_get_num_ids();
#endif
