#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "command.h"

int main (){
Comand *cmd=NULL;
printf("Prueba del modulo command. Esta prueba está diseñada para ser probada con el fichero entrada_command_test.ent. Si dicho archivo no está redireccionado, salga del programa.\n");
cmd=comand_create();
if (cmd==NULL){
  printf("Error al crear el comando");
  return 1;
}
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el primer comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=ROLL){
      comand_destroy(cmd);
        printf("Error el primer comando no ha sido ROLL");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el segundo comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=UNKNOWN){
      comand_destroy(cmd);
        printf("Error el segundo comando no ha sido UNKNOWN");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el tercer comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=QUIT){
      comand_destroy(cmd);
        printf("Error el tercer comando no ha sido QUIT");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el cuarto comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=GO){
      comand_destroy(cmd);
        printf("Error el cuarto comando no ha sido GO");
        return 1;
    }
    if(strcmp(comand_get_name(cmd), "north")!=0){
      comand_destroy(cmd);
        printf("Error el cuarto comando no tenía como acción north");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el quinto comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=TAKE){
      comand_destroy(cmd);
        printf("Error el quinto comando no ha sido TAKE");
        return 1;
    }
    if(strcmp(comand_get_name(cmd), "libro")!=0){
      comand_destroy(cmd);
        printf("Error el quinto comando no tenía como objeto de acción libro");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el sexto comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=LEAVE){
      comand_destroy(cmd);
        printf("Error el sexto comando no ha sido LEAVE");
        return 1;
    }
    if(strcmp(comand_get_name(cmd), "libro")!=0){
      comand_destroy(cmd);
        printf("Error el sexto comando no tenía como objeto de acción libro");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el séptimo comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=ROLL){
      comand_destroy(cmd);
        printf("Error el séptimo comando no ha sido ROLL");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el octavo comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=INSPECT){
      comand_destroy(cmd);
        printf("Error el octavo comando no ha sido INSPECT");
        return 1;
    }
    if(strcmp(comand_get_name(cmd), "libro")!=0){
      comand_destroy(cmd);
        printf("Error el octavo comando no tenía como objeto de acción libro");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el noveno comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=FOLLOWING){
      comand_destroy(cmd);
        printf("Error el noveno comando no ha sido FOLLOWING");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el décimo comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=PREVIOUS){
      comand_destroy(cmd);
        printf("Error el décimo comando no ha sido PREVIOUS");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el undécimo comando");
        return 1;
    }
    if(comand_get_comand(cmd)!=OCA_FOLLOWING){
      comand_destroy(cmd);
        printf("Error el undécimo comando no ha sido OCA_FOLLOWING");
        return 1;
    }
    if (comand_get_user_input(cmd)==ERROR){
      comand_destroy(cmd);
        printf("Error al leer el duodécimo comando");
        return 1;

    }
    if(comand_get_comand(cmd)!=OCA_PREVIOUS){
      comand_destroy(cmd);
        printf("Error el duodécimo comando no ha sido OCA_PREVIOUS");
        return 1;
    }
    comand_destroy(cmd);
    printf("Todas las pruebas han sido pasadas con éxito.\n");
    return 0;
  }
