#ifndef INVENTORY_H
#define INVENTORY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "set.h"



typedef struct _Inventory Inventory;


Inventory * inventory_create(int tam);
STATUS inventory_destroy(Inventory *bag);
BOOL inventory_is_full(Inventory *bag);	
BOOL inventory_is_empty(Inventory *bag);
BOOL inventory_is_object_in(Inventory *bag, Id id);
STATUS inventory_add_object(Inventory *bag, Id id);
STATUS inventory_delete_object(Inventory *bag,Id id);
Set* inventory_get_set(Inventory *bag);
int inventory_get_size(Inventory *bag);
STATUS inventory_set_set(Inventory *bag,Set *set);
STATUS inventory_set_size(Inventory *bag, int tam);
void inventory_print(Inventory *bag, FILE *filename);



#endif