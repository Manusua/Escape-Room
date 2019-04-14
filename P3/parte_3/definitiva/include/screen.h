/**
 * @brief En este fichero implementamos las funciones de screen
 * @file screen.h
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 20/10/2018
 */

#ifndef __SCREEN__
#define __SCREEN__

#define SCREEN_MAX_STR 80 /*!< MAX STR */

typedef struct _Area Area; /*!< Estructura de Area */


/**
* @brief inicia una pantalla 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @return void (No devuelve nada)
*/
void screen_init();

/**
* @brief destruye una pantalla 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @return void (No devuelve nada)
*/
void screen_destroy();

/**
* @brief imprime una pantalla 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @return void (No devuelve nada)
*/
void screen_paint();

/**
* @brief obtiene una pantalla 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param str (pantalla a obtener)
* @return void (No devuelve nada)
*/
void screen_gets(char *str);


/**
* @brief crea un Area 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 15/11/2018
* @param x (coordenada x)
* @param y (coordenada y)
* @param width (ancho)
* @param height (altura)
* @return Area (El area creada)
*/
Area* screen_area_init(int x, int y, int width, int height);

/**
* @brief destruye un Area 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param area (area a destruir)
* @return void (No devuelve nada)
*/
void screen_area_destroy(Area* area);

/**
* @brief vacia un Area 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param area (area a vaciar)
* @return void (No devuelve nada)
*/
void screen_area_clear(Area* area);

/**
* @brief resetea el cursor de un Area 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param area (area a usar)
* @return void (No devuelve nada)
*/
void screen_area_reset_cursor(Area* area);

/**
* @brief modifica un Area 
* @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
* @date 20/10/2018
* @param area (area a usar)
* @param str (cadena que se introduce)
* @return void (No devuelve nada)
*/
void screen_area_puts(Area* area, char *str);

#endif
