#include <stdio.h>
#include <stdlib.h>
#include "link.h"

struct _Link {
    Id id;
    char name[TAM];
    Id id_conexion[2];
    BOOL state;
};

Link *link_create() {
    Link *link;
    link = malloc(sizeof (Link));
    if (!link) {
        return NULL;
    }
    link->id = NO_ID;
    link->id_conexion[0] = NO_ID;
    link->id_conexion[1] = NO_ID;
    link->state = FALSE;
    return link;
}

void link_destroy(Link *link) {
    if (link) {
        free(link);
    }
}

Id link_get_id(Link *link) {
    if (!link) {
        return -1;
    }
    return link->id;
}

char * link_get_name(Link *link) {
    if (!link) {
        return NULL;
    }
    return link->name;
}

Id link_get_conection_1(Link *link) {
    if (!link) {
        return NO_ID;
    }

    return link->id_conexion[0];
}

Id link_get_conection_2(Link *link) {
    if (!link) {
        return NO_ID;
    }

    return link->id_conexion[1];
}

BOOL link_get_status(Link *link) {
    if (!link) {
        return FALSE;
    }
    return link->state;
}

STATUS link_set_id(Link * link, Id id) {
    if (!link || id == NO_ID) {
        return ERROR;
    }
    link->id = id;
    return OK;
}

STATUS link_set_name(Link *link, char *name) {
    if (!link || !name) {
        return ERROR;
    }
    strcpy(link->name, name);

    return OK;
}

STATUS link_set_conection(Link *link, Id id1, Id id2) {
    if (!link) {
        return ERROR;
    }
    link->id_conexion[0] = id1;
    link->id_conexion[1] = id2;
    return OK;
}

STATUS link_set_status(Link *link, BOOL bool) {
    if (!link) {
        return ERROR;
    }
    link->state = bool;
    return OK;
}

int link_print(Link *link) {
    if (!link) {
        return -1;
    }
    return fprintf(stdout, "id %ld ,name :%s ,id_conexion %ld %ld, status %u (1 es true 0 es false) \n", link->id, link->name, link->id_conexion[0], link->id_conexion[1], link->state);

}
