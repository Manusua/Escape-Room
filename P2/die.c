#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "die.h"

struct _Die{
  Id id;
  int last;
};

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -id: identificador único de cada dado
*/
Die* die_create(Id id){
  Die *newDie;
  newDie = (Die*)malloc(sizeof(Die));
  newDie->id = id;
  /*Ponemos 0 para poder identificar luego en caso de que se asignara incorrectamente (ninguna tirada va a ser 0)*/
  newDie->last = 0;

  return newDie;
}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -id: identificador único del dado a destruir
Return:
    -STATUS: codigo quer indica si se ha podido realizar la operacion
*/
STATUS die_destroy(Die* die){
  if (die == NULL)
  		return ERROR;
  	free(die);
  	return OK;
}

/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -die: dado que tira
  -min: minimo del intervalo en el que estará contenido la tirada
  -max: maximo del intervalo en el que estará contenido la tirada
Return:
    -STATUS: codigo quer indica si se ha podido realizar la operacion
*/
STATUS die_roll(Die* die, int min, int max){
/*No aceptamos intervalos con el minimo 0 o negativo*/
  if(die == NULL || min < 1 || max <= min)
    return ERROR;
  int aux = (int)clock();
  aux = aux%(max - min) + min;
  die->last = aux;
  return OK;

}
/*
Autores: Rodrigo Lardies Guillen y Manuel Suárez Román
Date: 09/10/2018
Parámetros:
  -die: dado a imprimir
*/
void die_print(Die* die){
  printf("La ultima tirada fue: %d\n", die->last);
  return;
}
