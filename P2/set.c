#include <stdlib.h>
#include <stdio.h>
#include "set.h"

struct _Set{
	Id *ids;
	int num_id;
};

int set_search_id(Set *set, Id id);

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Return:
  -Set: un set vacio
*/
Set* set_create(){
	Set *set;
	set = (Set*)malloc(sizeof(Set));
	set->ids = (Id*)malloc(sizeof(Id));
	set->num_id = 0;
	return set;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -set: set a destruir
Return:
  -STATUS: codigo quer indica si se ha podido realizar la operacion
*/
STATUS set_destroy(Set *set){
	if (set == NULL || set->ids == NULL)
		return ERROR;
	free(set->ids);
	free(set);
	return OK;
}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -set: set al que añadiremos un id nuevo
	-id: id a añadir
Return:
  -STATUS: codigo quer indica si se ha podido realizar la operacion
*/
STATUS set_add(Set *set, Id id){
	if (set == NULL || set->ids == NULL)
		return ERROR;
	set->num_id++;
	set->ids = (Id*)realloc(set->ids, sizeof(Id)*set->num_id);
	set->ids[set->num_id - 1] = id;
	return OK;

}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -set: set al que eliminaremos un id
	-id: id a eliminar
Return:
  -STATUS: codigo quer indica si se ha podido realizar la operacion
*/
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
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -set: set sobre el que buscaremos
	-id: id que estamos buscando
Return:
  -int: posicion del id que hemos recibido en el conjunto
*/
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
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -set: set sobre el que buscamos
	-id: id a buscar
Return:
  -BOOL: TRUE si lo encontramos
*/
BOOL set_is_id(Set *set, Id id){
	if(set_search_id(set,id) != -1) return TRUE;
	else return FALSE;
}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -set: set que queremos imprimir
*/
void set_print(Set *set){
	int i;
	printf("The number of objects in the set is:: %d.\n", set->num_id);
	for(i = 0; i < set->num_id; i++){
		printf("Element %d: %ld \n", i, set->ids[i]);
	}
	return;
}
