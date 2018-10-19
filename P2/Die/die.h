#ifndef DIE_H
#define DIE_H
#include <stdlib.h>
#include <stdio.h>
#include "types.h"



typedef struct _Die Die;

Die* die_create(Id id);
STATUS die_destroy(Die* die);
STATUS die_roll(Die* die, int min, int max);
void die_print(Die* die);

#endif
