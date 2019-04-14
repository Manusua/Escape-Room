#include <stdlib.h>
#include <stdio.h>
#include "set.h"



int main(){
	Set *set = set_create();
	set_add(set, 1);
	set_add(set, 2);
	set_add(set, 3);	
	set_print(set);
	set_del(set,2);
	set_print(set);
	set_add(set, 5);
	set_print(set);
	set_del(set,5);
	set_del(set,1);
	set_print(set);
	set_del(set,3);
	set_print(set);
	set_destroy(set);
	return 0;
}
