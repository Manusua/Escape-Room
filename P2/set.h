#include <stdlib.h>
#include <stdio.h>
#include "types.h"

#define NUM_OBJECTS 5

typedef struct _Set Set;


Set* set_create();
STATUS set_destroy(Set *set);
STATUS set_add(Set *set, Id id);
STATUS set_del(Set *set, Id id);
BOOL set_is_id(Set *set, Id id);
void set_print(Set *set);
