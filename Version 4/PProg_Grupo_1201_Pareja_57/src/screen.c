/**
 * @brief En este fichero implementamos las funciones de screen
 * @file screen.c
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @version 1.0
 * @date 20/10/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "screen.h"

#pragma GCC diagnostic ignored "-Wpedantic"

#define ROWS 32 /*!< maximo de filas */
#define COLUMNS 100 /*!< maximo de columnas */
#define TOTAL_DATA (ROWS * COLUMNS) + 1 /*!< maximo de datos */

#define BG_CHAR '~' /*!< define BG_CHAR */
#define FG_CHAR ' ' /*!< define FG_CHAR */
#define PROMPT " prompt:> " /*!< define 'prompt' */

#define ACCESS(d, x, y) (d + ((y) * COLUMNS) + (x)) /*!< define acceso */

struct _Area {
    int x; /*!< Coordenada X*/
    int y; /*!< Coordenada Y*/
    int width; /*!< Anchura*/
    int height; /*!<altura*/
    char *cursor; /*!<Cursor*/
}; /*!< Estructura de Area */

char *__data; /*!< Datos */



/**
 * @brief screen area cursor is out of bounds
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 20/10/2018
 * @param area (area a usar)
 * @return int (devuelve un entero)
 */
int screen_area_cursor_is_out_of_bounds(Area* area);

/**
 * @brief scroll up de un area 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 20/10/2018
 * @param area (area a usar)
 * @return void (No devuelve nada)
 */
void screen_area_scroll_up(Area* area);


/**
 * @brief screen utils replaces special char 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 20/10/2018
 * @param str (cadena a usar)
 * @return void (No devuelve nada)
 */
void screen_utils_replaces_special_chars(char* str);

/**
 * @brief inicia una pantalla 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 15/11/2018
 * @return void (No devuelve nada)
 */
void screen_init() {
    screen_destroy(); /* Dispose if previously initialized */
    __data = (char *) malloc(sizeof (char) * TOTAL_DATA);

    if (__data) {
        memset(__data, (int) BG_CHAR, TOTAL_DATA); /*Fill the background*/
        *(__data + TOTAL_DATA - 1) = '\0'; /*NULL-terminated string*/
    }
}

/**
 * @brief destruye una pantalla 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 15/11/2018
 * @return void (No devuelve nada)
 */
void screen_destroy() {
    if (__data)
        free(__data);
}

/**
 * @brief imprime una pantalla 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 15/11/2018
 * @return void (No devuelve nada)
 */
void screen_paint() {
    char *src = NULL;
    char dest[COLUMNS + 1];
    int i = 0;

    memset(dest, 0, COLUMNS + 1);

    if (__data) {
        /* puts(__data); */ /*Dump data directly to the terminal*/
        /*It works fine if the terminal window has the right size*/

        puts("\033[2J"); /*Clear the terminal*/
        for (src = __data; src < (__data + TOTAL_DATA - 1); src += COLUMNS) {
            memcpy(dest, src, COLUMNS);
            /* printf("%s\n", dest); */
            for (i = 0; i < COLUMNS; i++) {
                if (dest[i] == BG_CHAR) {
                    printf("\033[0;34;44m%c\033[0m", dest[i]); /* fg:blue(34);bg:blue(44) */
                } else {
                    printf("\033[0;30;47m%c\033[0m", dest[i]); /* fg:black(30);bg:white(47)*/
                }
            }
            printf("\n");
        }
    }
}

/**
 * @brief obtiene una pantalla 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 15/11/2018
 * @param str (pantalla a obtener)
 * @return void (No devuelve nada)
 */
void screen_gets(char *str) {
    fprintf(stdout, PROMPT);
    if (fgets(str, COLUMNS, stdin))
        *(str + strlen(str) - 1) = 0; /* Replaces newline character with '\0' */
}

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
Area* screen_area_init(int x, int y, int width, int height) {
    int i = 0;
    Area* area = NULL;

    if ((area = (Area*) malloc(sizeof (struct _Area)))) {
        *area = (struct _Area){x, y, width, height, ACCESS(__data, x, y)};

        for (i = 0; i < area->height; i++)
            memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
    }

    return area;
}

/**
 * @brief destruye un Area 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 20/10/2018
 * @param area (area a destruir)
 * @return void (No devuelve nada)
 */
void screen_area_destroy(Area* area) {
    if (area)
        free(area);
}

/**
 * @brief vacia un Area 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 20/10/2018
 * @param area (area a vaciar)
 * @return void (No devuelve nada)
 */
void screen_area_clear(Area* area) {
    int i = 0;

    if (area) {
        screen_area_reset_cursor(area);

        for (i = 0; i < area->height; i++)
            memset(ACCESS(area->cursor, 0, i), (int) FG_CHAR, (size_t) area->width);
    }
}

/**
 * @brief resetea el cursor de un Area 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 20/10/2018
 * @param area (area a usar)
 * @return void (No devuelve nada)
 */
void screen_area_reset_cursor(Area* area) {
    if (area)
        area->cursor = ACCESS(__data, area->x, area->y);
}

/**
 * @brief modifica un Area 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 20/10/2018
 * @param area (area a usar)
 * @param str (cadena que se introduce)
 * @return void (No devuelve nada)
 */
void screen_area_puts(Area* area, char *str) {
    int len = 0;
    char *ptr = NULL;

    if (screen_area_cursor_is_out_of_bounds(area))
        screen_area_scroll_up(area);

    screen_utils_replaces_special_chars(str);

    for (ptr = str; ptr < (str + strlen(str)); ptr += area->width) {
        memset(area->cursor, FG_CHAR, area->width);
        len = (strlen(ptr) < area->width) ? strlen(ptr) : area->width;
        memcpy(area->cursor, ptr, len);
        area->cursor += COLUMNS;
    }
}

/**
 * @brief screen area cursor is out of bounds
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 20/10/2018
 * @param area (area a usar)
 * @return int (devuelve un entero)
 */
int screen_area_cursor_is_out_of_bounds(Area* area) {
    return area->cursor > ACCESS(__data,
            area->x + area->width,
            area->y + area->height - 1);
}

/**
 * @brief scroll up de un area 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 20/10/2018
 * @param area (area a usar)
 * @return void (No devuelve nada)
 */
void screen_area_scroll_up(Area* area) {
    for (area->cursor = ACCESS(__data, area->x, area->y);
            area->cursor < ACCESS(__data, area->x + area->width, area->y + area->height - 2);
            area->cursor += COLUMNS) {
        memcpy(area->cursor, area->cursor + COLUMNS, area->width);
    }
}

/**
 * @brief screen utils replaces special char 
 * @author Manuel Suarez, Saul Almazán, Álvaro Becerra, Rodrigo Lardiés 
 * @date 20/10/2018
 * @param str (cadena a usar)
 * @return void (No devuelve nada)
 */
void screen_utils_replaces_special_chars(char* str) {
    char *pch = NULL;

    /* Replaces acutes and tilde with '??' */
    while ((pch = strpbrk(str, "ÁÉÍÓÚÑáéíóúñ")))
        memcpy(pch, "??", 2);
}
