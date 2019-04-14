/* ===================================================================
File: inventory.h
Version: 1.0
Date: 1-10-2018
Autores: Saul Almazan, Alvaro Becerra Jiminez, Rodrigo Lardiés y Manuel Suarez
Description: Contiene todos los prototipos de las funciones de object.c
Revision historica: 
1-10-2018 versión 1.0 
=================================================================== */

#include "inventory.h"


struct _Inventory {
    Set *objects;
    int tam;
};

Inventory * inventory_create(int tam){
	
	Inventory *bag;	

	if(tam<0)return NULL;

	bag=malloc(sizeof(Inventory));
	if(bag==NULL)return NULL;

	bag->objects=set_create();
	if(bag->objects==NULL){
		free(bag);
		return NULL;
	}

	bag->tam=tam;

	return bag;
}

STATUS inventory_destroy(Inventory *bag){

	if(bag==NULL)return ERROR;

	if(set_destroy(bag->objects)==ERROR)return ERROR;

	free(bag);

	return OK;
}

BOOL inventory_is_full(Inventory *bag){
	if(bag==NULL || bag->objects==NULL)return FALSE;

	if(set_get_num_ids(bag->objects)>=bag->tam)return TRUE;

	return FALSE;
}


BOOL inventory_is_empty(Inventory *bag){
	if(bag==NULL || bag->objects==NULL)return FALSE;

	if(set_get_num_ids(bag->objects)==0)return TRUE;

	return FALSE;

}

BOOL inventory_is_object_in(Inventory *bag, Id id){
	if(bag==NULL || id==NO_ID)return ERROR;

	return set_is_id_in(bag->objects,id);
}

STATUS inventory_add_object(Inventory *bag, Id id){
	
	if(bag == NULL || id==NO_ID)return ERROR;
	
	if(inventory_is_full(bag)==TRUE)return ERROR;

	return set_add(bag->objects, id);
}

STATUS inventory_delete_object(Inventory *bag,Id id){
	if(bag==NULL || id==NO_ID)return ERROR;

	if(inventory_is_empty(bag)==FALSE)return ERROR;

	return set_delete_element(bag->objects,id);
}

Set* inventory_get_set(Inventory *bag){
	if(bag==NULL)return NULL;

	return bag->objects;
}

int inventory_get_size(Inventory *bag){
	if(bag==NULL)return -1;

	return bag->tam;
}

STATUS inventory_set_set(Inventory *bag,Set *set){
	if(bag==NULL || set==NULL)return ERROR;

	if(bag->objects!=NULL){
		if(set_destroy(bag->objects)==ERROR)return ERROR;
	}

	bag->objects=set;

	return OK;
}

STATUS inventory_set_size(Inventory *bag, int tam){
	if(bag==NULL || tam<1)return ERROR;
	bag->tam=tam;

	return OK;
}

void inventory_print(Inventory *bag,FILE *filename){

	if(bag==NULL || filename==NULL) return;

	fprintf(filename,"El tamaño del inventario es: %d\n",bag->tam);

	set_print(filename,bag->objects);
}



