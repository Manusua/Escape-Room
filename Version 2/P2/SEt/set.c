#include <stdlib.h>
#include <stdio.h>
#include "set.h"

struct _Set{
	Id *ids;
	int num_id;
};

int set_search_id(Set *set, Id id);


Set* set_create(){
	Set *set;
	set = (Set*)malloc(sizeof(Set));
	set->ids = (Id*)malloc(sizeof(Id));
	set->num_id = 0;
	return set;
}

STATUS set_destroy(Set *set){

	if (set == NULL || (set->ids == NULL && set->num_id != 0))
		return ERROR;
	free(set->ids);
	free(set);
	return OK;
}

STATUS set_add(Set *set, Id id){
	if (set == NULL || set->ids == NULL)
		return ERROR;
	set->num_id++;
	set->ids = (Id*)realloc(set->ids, sizeof(Id)*set->num_id);
	set->ids[set->num_id - 1] = id;
	return OK;

}

STATUS set_del(Set *set, Id id){
	int pos;
	if (set == NULL || set->ids == NULL)
		return ERROR;

	pos = set_search_id(set, id);
	set->num_id--;
	set->ids[pos] = set->ids[set->num_id];
	set->ids = (Id*)realloc(set->ids, sizeof(Id)*set->num_id);

	return OK;
}

int set_search_id(Set *set, Id id){
	int i;
	if (set == NULL || set->ids == NULL)
		return -1;
	for (i = 0; i < set->num_id; i++){
	if(id == set->ids[i]){
		return i;
	}
	}
	return -1;
}

void set_print(Set *set){
	int i;
	printf("El numero de elementos del conjunto es: %d.\n", set->num_id);
	for(i = 0; i < set->num_id; i++){
		printf("Elemento %d: %ld \n", i, set->ids[i]);
	}
	return;
}
