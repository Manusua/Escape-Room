/**
 * @brief It defines a space
 *
 * @file space.h
 * @author Profesores PPROG
 * @version 1.0
 * @date 13-01-2015
 * @copyright GNU Public License
 */

#ifndef SPACE_H
#define SPACE_H

#include "types.h"
#include "set.h"

typedef struct _Space Space;

#define MAX_SPACES 100
#define FIRST_SPACE 1
#define GDESC_LINES 3
#define GDESC_TAM 8
#define NUM_STRINGS 3

Space* space_create(Id id);
STATUS space_destroy(Space* space);
Id space_get_id(Space* space);
STATUS space_set_name(Space* space, char* name);
const char* space_get_name(Space* space);
STATUS space_set_north(Space* space, Id id);
Id space_get_north(Space* space);
STATUS space_set_south(Space* space, Id id);
Id space_get_south(Space* space);
STATUS space_set_east(Space* space, Id id);
Id space_get_east(Space* space);
STATUS space_set_west(Space* space, Id id);
Id space_get_west(Space* space);
STATUS space_set_object(Space* space, Id pos, Id object_id);
Set* space_get_object(Space* space);
BOOL space_is_object(Space* space, Id id);
STATUS space_print(Space* space);
char** space_get_gdesc(Space* space);
STATUS space_set_gdesc(Space* space, char* string[]);
STATUS space_add_object(Space *space,Id id);
STATUS space_print_objects(Space *space,FILE *f);

#endif
