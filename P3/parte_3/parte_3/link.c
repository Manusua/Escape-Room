
#include "link.h"

struct _Link{
  Id id;
  char name[TAM];
  Id id_conexion[2];
  BOOL state;
};

Link *link_create(){
  Link *link;
  link = malloc(sizeof(Link));
  if (!link){
    return NULL;
  }
  link->id = NO_ID;
  link->id_conexion[0] = NO_ID;
  link->id_conexion[1] = NO_ID;
  link->state = FALSE;
return link;
}

void link_destroy(Link *l){
  if (l){
    free(l);
  }
}

Id link_get_id(Link *l){
  if (!l){
    return -1;
  }
    return l->id;
}
char * link_get_name(Link *l){
  if (!l){
    return NULL;
  }
  return l->name;
}

Id link_get_conection_1(Link *l){
  if (!l){
    return NULL;
  }

  return l->id_conexion[0];
}
Id link_get_conection_2(Link *l){
  if (!l){
    return NULL;
  }

  return l->id_conexion[1];
}

BOOL link_get_status(Link *l){
  if (!l){
    return FALSE;
  }
return l->state;
}

STATUS link_set_id(Link * l,Id id){
  if (!l || id == NO_ID){
    return ERROR;
  }
  l->id = id;
  return OK;
}

STATUS link_set_name(Link *l ,char *name){
  if (!l || !name){
    return ERROR;
  }
  strcpy(l->name,name);

return OK;
}
STATUS link_set_conection(Link *l,Id id1 ,Id id2){
  if (!l){
    return ERROR;
  }
  l->id_conexion[0]=id1;
  l->id_conexion[1]=id2;
  return OK;
}
STATUS link_set_status(Link *l,BOOL bo){
  if(!l){
    return ERROR;
  }
  l->state = bo;
  return OK;
}


int link_print(Link *l){
  if (!l){
    return -1;
  }
  return fprintf (stdout ,"id %ld ,name :%s ,id_conexion %ld %ld, status %u (1 es true 0 es false) \n", l->id,l->name,l->id_conexion[0],l->id_conexion[1],l->state);

}
