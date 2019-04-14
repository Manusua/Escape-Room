/** 
 * @brief Prueba del modulo player
 * 
 * @file player_test.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés
 * @version 1.0 
 * @date 12-11-2018
 */

#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

/**
 * @test Prueba la función de creación de un jugador
 * @pre Un numero de objetos como parámetro
 * @post Un puntero no nulo al jugador creado
 */
void test1_player_create();

/**
 * @test Prueba la función de creación de un jugador
 * @pre Un numero de objetos erroneo como parámetro
 * @post Se obtiene un puntero NULL
 */
void test2_player_create();

/**
 * @test Prueba la función para establecer el nombre de un jugador
 * @pre Nombre que establecer al jugador
 * @post La salida debe ser OK
 */
void test1_player_set_name();

/**
 * @test Prueba la función para establecer el nombre de un jugador
 * @pre El jugador al que establecer el nombre es un puntero a NULL
 * @post La salida debe ser ERROR
 */
void test2_player_set_name();

/**
 * @test Prueba la función para establecer el nombre de un jugador
 * @pre El jugador es un puntero no NULL, pero el nombre a establecer es NULL
 * @post La salida debe ser ERROR
 */
void test3_player_set_name();

/**
 * @test Prueba la función para establecer el id de un jugador
 * @pre id que establecer al jugador
 * @post La salida debe ser OK
 */
void test1_player_set_id();
/**
 * @test Prueba la función para establecer el id de un jugador
 * @pre id válido, pero jugador NULL
 * @post La salida debe ser ERROR
 */
void test2_player_set_id();
/**
 * @test Prueba la función para establecer el id del espacio de un jugador
 * @pre id que establecer al jugador
 * @post La salida debe ser OK
 */
void test1_player_set_space_id();
/**
 * @test Prueba la función para establecer el id del espacio de un jugador
 * @pre id válido, pero jugador NULL
 * @post La salida debe ser ERROR
 */
void test2_player_set_space_id();
/**
 * @test Prueba la función para obtener el nombre de un jugador
 * @pre El jugador tiene un nombre establecido
 * @post La salida debe ser una comparación de cadenas igual a 0
 */
void test1_player_get_name();
/**
 * @test Prueba la función para obtener el nombre de un jugador
 * @pre El jugador es NULL
 * @post La salida debe ser NULL
 */
void test2_player_get_name();
/**
 * @test Prueba la función para obtener el id de un jugador
 * @pre El jugador tiene un id establecido
 * @post La salida debe ser id=1
 */
void test1_player_get_id();
/**
 * @test Prueba la función para obtener el id de un jugador
 * @pre El jugador es NULL
 * @post La salida debe ser NO_ID
 */
void test2_player_get_id();
/**
 * @test Prueba la función para obtener el id de un espacio de un jugador
 * @pre El jugador tiene un id establecido
 * @post La salida debe ser id=1
 */
void test1_player_get_space_id();
/**
 * @test Prueba la función para obtener el id de un jugador
 * @pre El jugador es NULL
 * @post La salida debe ser NO_ID
 */
void test2_player_get_space_id();
/**
 * @test Prueba la función para dejar un objeto de un jugador
 * @pre Jugador con un objeto
 * @post La salida debe ser OK
 */
void test1_player_drop_object();
/**
 * @test Prueba la función para dejar un objeto de un jugador
 * @pre Jugador con un objeto distinto al que se quiere dejar
 * @post La salida debe ser ERROR
 */
void test2_player_drop_object();
/**
 * @test Prueba la función para coger un objeto
 * @pre Jugador e id de un objeto
 * @post La salida debe ser OK
 */
void test1_player_pick_object();
/**
 * @test Prueba la función para coger un objeto
 * @pre Jugador NULL
 * @post La salida debe ser ERROR
 */
void test2_player_pick_object();
/**
 * @test Prueba la función para saber si un jugador tiene un objeto
 * @pre Jugador con un objeto
 * @post La salida debe ser TRUE
 */
void test1_player_has_object();
/**
 * @test Prueba la función para saber si un jugador tiene un objeto
 * @pre Jugador con un objeto distinto al que se pregunta
 * @post La salida debe ser FALSE
 */
void test2_player_has_object();
/**
 * @test Prueba la función para saber si la mochila de un jugador está llena
 * @pre Jugador con una mochila para más de un objeto
 * @post La salida debe ser FALSE
 */
void test1_player_bag_is_full();
/**
 * @test Prueba la función para saber si la mochila de un jugador está llena
 * @pre Jugador NULL
 * @post La salida debe ser TRUE
 */
void test2_player_bag_is_full();

#endif
