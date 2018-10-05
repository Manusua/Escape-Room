#include <stdlib.h>
#include <stdio.h>
#include "set.h"

Struct _Set{
	Id *ids;
	int num_id;
};


Set set_create(){
	Set *set;
	set = (Set*)malloc(sizeof(Set));
	set->ids = (Id*)malloc(sizeof(Id));
	set->num_id = 0;
	return set;
}

STATUS set_destroy(Set *set){
	if (set == NULL || set->ids == NULL)
		return ERROR;
	free(set->ids);
	free(set);
	return OK;
}

STATUS set_add(Set *set, Id id){
	Id* ids = set->ids;
	if (set == NULL || set->ids == NULL)
		return ERROR;
	set->num_id++;
	set->ids = realloc(ids, num_id);
	return OK;

}


STATUS set_del(Set *set){
	if (set == NULL || set->ids == NULL)
		return ERROR;
	set->num_id--;
	free(set->ids[num_id]);
	return OK;
}

void set_print(Set *set){
	int i;
	printf("El numero de elementos del conjunto es: %d.\n", set->num_id);
	for(i = 0; i < set->num_id; i++){
		printf(Elemento %d: %ld\n, i, set->ids[i]);
	}
	return;
}
