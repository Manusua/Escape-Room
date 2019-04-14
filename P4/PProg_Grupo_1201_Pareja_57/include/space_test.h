/** 
 * @brief Prueba del modulo space
 * @file space_test.h
 * @author Manuel Suarez, Saul Almazán, �?lvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#ifndef SPACE_TEST_H
#define SPACE_TEST_H

/**
 * @test Prueba la función de creación de un espacio
 * @pre Nada
 * @post Un puntero no nulo al espacio creado
 */
void test1_space_create();

/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre Nombre que establecer al espacio
 * @post La salida debe ser OK
 */

void test1_space_set_name();
/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre El espacio al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_name();
/**
 * @test Prueba la función para establecer el nombre de un espacio
 * @pre El espacio es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */

void test3_space_set_name();

/**
 * @test Prueba la función para establecer el norte de un espacio
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_space_set_north();
/**
 * @test Prueba la función para establecer el norte de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_north();
/**
 * @test Prueba la función para establecer el sur de un espacio
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_space_set_south();
/**
 * @test Prueba la función para establecer el sur de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_south();
/**
 * @test Prueba la función para establecer el este de un espacio
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_space_set_east();
/**
 * @test Prueba la función para establecer el este de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_east();
/**
 * @test Prueba la función para establecer el oeste de un espacio
 * @pre Id a establecer
 * @post La salida debe ser OK
 */
void test1_space_set_west();
/**
 * @test Prueba la función para establecer el norte de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_west();
/**
 * @test Prueba la función para obtener el nombre de un espacio
 * @pre Espacio con nombre establecido
 * @post La salida debe ser una comparación de cadenas igual a 0
 */

void test1_space_get_name();
/**
 * @test Prueba la función para obtener el nombre de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NULL
 */
void test2_space_get_name();
/**
 * @test Prueba la función para coger un objeto de un espacio
 * @pre Espacio sin objetos
 * @post La salida debe ser ERROR
 */
void test1_space_take_object();
/**
 * @test Prueba la función para coger un objeto de un espacio
 * @pre Espacio con objetos
 * @post La salida debe ser OK
 */
void test2_space_take_object();
/**
 * @test Prueba la función para coger un objeto de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test3_space_take_object();
/**
 * @test Prueba la función para obtener el norte de un espacio
 * @pre Espacio con norte asignado
 * @post La salida debe ser id=4
 */
void test1_space_get_north();
/**
 * @test Prueba la función para obtener el norte de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_north();
/**
 * @test Prueba la función para obtener el sur de un espacio
 * @pre Espacio con sur asignado
 * @post La salida debe ser id=4
 */
void test1_space_get_south();
/**
 * @test Prueba la función para obtener el sur de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_south();
/**
 * @test Prueba la función para obtener el este de un espacio
 * @pre Espacio con este asignado
 * @post La salida debe ser id=4
 */
void test1_space_get_east();
/**
 * @test Prueba la función para obtener el este de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_east();
/**
 * @test Prueba la función para obtener el oeste de un espacio
 * @pre Espacio con oeste asignado
 * @post La salida debe ser id=4
 */
void test1_space_get_west();
/**
 * @test Prueba la función para obtener el oeste de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_west();
/**
 * @test Prueba la función para obtener el id de un espacio
 * @pre Espacio con id asignado
 * @post La salida debe ser id=4
 */
void test1_space_get_id();
/**
 * @test Prueba la función para obtener el id de un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NO_ID
 */
void test2_space_get_id();
/**
 * @test Prueba la función para dejar un objeto en un espacio
 * @pre Espacio no NULL
 * @post La salida debe ser OK
 */
void test1_space_leave_object();
/**
 * @test Prueba la función para dejar un objeto en un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_leave_object();
/**
 * @test Prueba la función para dejar un establecer un dibujo en un espacio
 * @pre Espacio no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_gdesc();
/**
 * @test Prueba la función para dejar un establecer un dibujo en un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_gdesc();
/**
 * @test Prueba la función para dejar un obtener un dibujo en un espacio
 * @pre Espacio con dibujo
 * @post La salida debe ser una comparacion de cadenas igual a 0
 */
void test1_space_get_gdesc();
/**
 * @test Prueba la función para dejar un obtener un dibujo en un espacio
 * @pre Espacio NULL
 * @post La salida debe ser NULL
 */
void test2_space_get_gdesc();
/**
 * @test Prueba la función para dejar un establecer una descripcion en un espacio
 * @pre Espacio no NULL
 * @post La salida debe ser OK
 */
void test1_space_set_description();
/**
 * @test Prueba la función para dejar un establecer una descripcion en un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_set_description();
/**
 * @test Prueba la función para dejar un obtener una descripcion en un espacio
 * @pre Espacio con una descripcion
 * @post La salida debe ser una comparación de cadenas igual a 0
 */
void test1_space_get_description();
/**
 * @test Prueba la función para dejar un obtener una descripcion en un espacio
 * @pre Espacio NULL
 * @post La salida debe ser ERROR
 */
void test2_space_get_description();
#endif
