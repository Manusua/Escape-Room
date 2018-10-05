#include <stdlib.h>
#include <stdio.h>
#include "set.h"



void main(){
	Set *set = set_create;
	set_add(set, 1);
	set_add(set, 2);
	set_add(set, 3);	
	set_print(set);
	set_del(set);
	set_print(set);
	set_add(set, 5);
	se5t_print(set);
	set_del(set);
	set_del(set);
	set_print(set);
	set_del(set);
	set_print(set);
	set_destroy(set);
	return;
}
