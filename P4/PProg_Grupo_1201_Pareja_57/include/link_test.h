/** 
 * @brief Prueba del modulo link
 * @file link_test.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#ifndef LINK_TEST_H
#define LINK_TEST_H

/**
 * @test Prueba la función de creación de un link
 * @pre Nada
 * @post Un puntero no nulo al link creado
 */

void test1_link_create();
/**
 * @test Prueba la función para establecer el nombre de un link
 * @pre Nombre que establecer al link
 * @post La salida debe ser OK
 */
void test1_link_set_name();
/**
 * @test Prueba la función para establecer el nombre de un link
 * @pre El link al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */

void test2_link_set_name();
/**
 * @test Prueba la función para establecer el nombre de un link
 * @pre El link es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_link_set_name();
/**
 * @test Prueba la función para establecer el id de un link
 * @pre id que establecer al link
 * @post La salida debe ser OK
 */
void test1_link_set_id();
/**
 * @test Prueba la función para establecer el id de un link
 * @pre id válido, pero link NULL
 * @post La salida debe ser ERROR
 */

void test2_link_set_id();
/**
 * @test Prueba la función para establecer la conexion de un link
 * @pre ids que establecer al link
 * @post La salida debe ser OK
 */
void test1_link_set_conection();
/**
 * @test Prueba la función para establecer la conexion de un link
 * @pre ids válido, pero link NULL
 * @post La salida debe ser ERROR
 */
void test2_link_set_conection();
/**
 * @test Prueba la función para establecer el estado de un link
 * @pre estado que establecer al link
 * @post La salida debe ser OK
 */
void test1_link_set_status();
/**
 * @test Prueba la función para establecer el estado de un link
 * @pre estado válido, pero link NULL
 * @post La salida debe ser ERROR
 */
void test2_link_set_status();
/**
 * @test Prueba la función para obtener el nombre de un link
 * @pre El link tiene un nombre establecido
 * @post La salida debe ser una comparación de cadenas igual a 0
 */
void test1_link_get_name();
/**
 * @test Prueba la función para obtener el nombre de un link
 * @pre El link es NULL
 * @post La salida debe ser NULL
 */
void test2_link_get_name();
/**
 * @test Prueba la función para obtener el id de un link
 * @pre El link tiene un id establecido
 * @post La salida debe ser id=1
 */
void test1_link_get_id();
/**
 * @test Prueba la función para obtener el id de un link
 * @pre El link es NULL
 * @post La salida debe ser NO_ID
 */
void test2_link_get_id();
/**
 * @test Prueba la función para obtener el id 1 de un link
 * @pre El link tiene un id establecido
 * @post La salida debe ser id=1
 */
void test1_link_get_conection_1();
/**
 * @test Prueba la función para obtener el id 1 de un link
 * @pre El link es NULL
 * @post La salida debe ser NO_ID
 */
void test2_link_get_conection_1();
/**
 * @test Prueba la función para obtener el id 2 de un link
 * @pre El link tiene un id establecido
 * @post La salida debe ser id=1
 */
void test1_link_get_conection_2();
/**
 * @test Prueba la función para obtener el id 2 de un link
 * @pre El link es NULL
 * @post La salida debe ser NO_ID
 */
void test2_link_get_conection_2();
/**
 * @test Prueba la función para saber el estado de un link
 * @pre link con un estado asignado
 * @post La salida debe ser TRUE
 */
void test1_link_get_status();
/**
 * @test Prueba la función para saber el estado de un link
 * @pre link con un estado asignado
 * @post La salida debe ser FALSE
 */
void test2_link_get_status();

#endif
