#include <stdio.h>
#include <stdlib.h>
#include "link.h"

int main() {
    Link *l;
    Id id1 = NO_ID, id2 = NO_ID;

    printf("prueba del fichero link.\n");
    l = link_create();
if (l==NULL){
printf("Error al crear el link");
return 1;
}


    printf("ponemos el id del link a 1\n");
    if (link_set_id(l, 1)==ERROR){
link_destroy(l);
printf("Error al establecer el id del link");
return 1;
}
    printf("ponemos el nombre del link: conexion\n");
    if (link_set_name(l, "conexion")==ERROR){
link_destroy(l);
printf("Error al establecer el nombre del link");
return 1;
}
    printf("ponemos las conexiones del link 3 y 2\n");
    if(link_set_conection(l, 3, 2)==ERROR){
link_destroy(l);
printf("Error al establecer las conexiones del link");
return 1;
}
    printf("ponemos el status del link abierto\n");
    if (link_set_status(l, TRUE)==ERROR){
link_destroy(l);
printf("Error al establecer el estado del link");
return 1;
}
    printf("imprimimos el link\n");
    if (link_print(l)<0){
link_destroy(l);
printf("Error al establecer imprimir el link");
return 1;
}
    printf("probamos la funcion para obtener el id , %ld\n", link_get_id(l));
    printf("probamos la funcion para obtener el nombre , %s\n", link_get_name(l));
    printf("probamos la funcion para obtener el status , %u\n", link_get_status(l));
    id1 = link_get_conection_1(l);
if (id1==NO_ID){
link_destroy(l);
printf("Error al obtener la conexion 1 del link");
return 1;
}
    id2 = link_get_conection_2(l);
if (id2==NO_ID){
link_destroy(l);
printf("Error al obtener la conexion 2 del link");
return 1;
}
    printf("probamos la obtencion de los ids de conexiones %d, %d\n", (int) id1, (int) id2);
    link_destroy(l);

    return 0;
}
