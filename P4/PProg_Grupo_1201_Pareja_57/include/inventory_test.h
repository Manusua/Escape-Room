/** 
 * @brief Prueba del modulo player
 * 
 * @file inventory_test.h
 * @author Manuel Suarez, Saul Almazán, �?lvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#ifndef INVENTORY_TEST_H
#define INVENTORY_TEST_H

/**
 * @test Prueba la función de creación de un inventario
 * @pre Un numero de objetos como parámetro
 * @post Un puntero no nulo al inventario creado
 */

void test1_inventory_create();
/**
 * @test Prueba la función de creación de un inventario
 * @pre Un numero de objetos erroneo como parámetro
 * @post Se obtiene un puntero NULL
 */
void test2_inventory_create();
/**
 * @test Prueba la función para borrar un objeto de un inventario
 * @pre Inventario con un objeto
 * @post La salida debe ser OK
 */
void test1_inventory_delete_object();
/**
 * @test Prueba la función para borrar un objeto de un inventario
 * @pre Inventario NULL
 * @post La salida debe ser ERROR
 */

void test2_inventory_delete_object();
/**
 * @test Prueba la función para borrar un objeto de un inventario
 * @pre Inventario sin objetos
 * @post La salida debe ser ERROR
 */
void test3_inventory_delete_object();
/**
 * @test Prueba la función para añadir un objeto a un inventario
 * @pre id que establecer en el inventario
 * @post La salida debe ser OK
 */
void test1_inventory_add_object();
/**
 * @test Prueba la función para añadir un objeto a un inventario
 * @pre id válido, pero inventario NULL
 * @post La salida debe ser ERROR
 */

void test2_inventory_add_object();
/**
 * @test Prueba la función para comprobar si un inventario está lleno
 * @pre inventario vacío
 * @post La salida debe ser FALSE
 */
void test1_inventory_is_full();
/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre inventario lleno
 * @post La salida debe ser TRUE
 */
void test2_inventory_is_full();
/**
 * @test Prueba la función para comprobar si un invetario está vacío
 * @pre inventario vacío
 * @post La salida debe ser TRUE
 */
void test1_inventory_is_empty();
/**
 * @test Prueba la función para comprobar si un invetario está lleno
 * @pre inventario lleno
 * @post La salida debe ser FALSE
 */
void test2_inventory_is_empty();
/**
 * @test Prueba la función para saber si hay un objeto en el inventario
 * @pre El inventario tiene un objeto
 * @post La salida debe ser TRUE
 */
void test1_inventory_is_object_in();
/**
 * @test Prueba la función para saber si hay un objeto en el inventario
 * @pre El inventario es NULL
 * @post La salida debe ser FALSE
 */
void test2_inventory_is_object_in();
/**
 * @test Prueba la función para obtener el tamaño de un inventario
 * @pre El inventario tiene un tamaño
 * @post La salida debe ser tam=3
 */
void test1_inventory_get_size();
/**
 * @test Prueba la función para obtener el tamaño de un inventario
 * @pre El inventario es NULL
 * @post La salida debe ser -1
 */
void test2_inventory_get_size();
/**
 * @test Prueba la función para establecer el tamaño de un inventario
 * @pre inventario no NULL
 * @post La salida debe ser OK
 */
void test1_inventory_set_size();
/**
 * @test Prueba la función para establecer el tamaño de un inventario
 * @pre inventario NULL
 * @post La salida debe ser ERROR
 */
void test2_inventory_set_size();
#endif
