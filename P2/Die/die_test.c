#include <stdlib.h>
#include <stdio.h>
#include "die.h"


int main(){
  Die* die = die_create(2);
  die_roll(die, 1, 6);
  die_print(die);
  die_roll(die, 1, 6);
  die_print(die);
  die_roll(die, 1, 6);
  die_print(die);
  die_roll(die, 1, 6);
  die_print(die);
  die_roll(die, 1, 6);
  die_print(die);
  die_roll(die, 1, 6);
  die_print(die);
  die_roll(die, 1, 6);
  die_print(die);
  die_roll(die, 1, 6);
  die_print(die);
  die_roll(die, 1, 6);
  die_print(die);
  die_destroy(die);
	return 0;
}
