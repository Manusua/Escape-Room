#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct _Link Link;

Link *link_create();
void link_destroy(Link *);

Id link_get_id(Link * );
char * link_get_name(Link * );
Id link_get_conection_1(Link * );
Id link_get_conection_2(Link * );
BOOL link_get_status(Link *);

STATUS link_set_id(Link * ,Id);
STATUS link_set_name(Link * ,char *);
STATUS link_set_conection(Link * ,Id ,Id );
STATUS link_set_status(Link *,BOOL);


int link_print(Link *);



#endif
