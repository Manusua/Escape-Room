#include "link.h"

int main (){
  Link *l;
  Id id1=NO_ID, id2=NO_ID;

  printf("prueba del fichero link.\n");
  l = link_create();


printf("ponemos el id del link\n");
link_set_id(l,1);
printf("ponemos el name del link\n");
link_set_name(l,"Pedri");
printf("ponemos las conexiones del link\n");
link_set_conection(l,NO_ID,2);
printf("ponemos el status del link\n");
link_set_status(l,TRUE);
printf("imprimimos el link\n");
link_print(l);
printf("probamos la funcion para obtener el id , %ld\n",link_get_id(l));
printf("probamos la funcion para obtener el nombre , %s\n",link_get_name(l));
printf("probamos la funcion para obtener el status , %u\n",link_get_status(l));
id1 = link_get_conection_1(l);
id2 = link_get_conection_2(l);
  printf("probamos la obtencion de los ids de conexiones %d, %d\n",(int) id1, (int) id2);

link_destroy(l);

  return 0;
}
