#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pari_dispari.h"

int main(void) {
  srand(time(NULL));
  int array1[20];
  init(array1, 20);
  printf("array1: ");
  print(array1, 20);
  printf("In array1 dispari >= pari ? %i\n", dispari_almeno_quanto_i_pari(array1, 20));
  int array2[15];
  init(array2, 15);
  printf("array2: ");
  print(array2, 15);
  printf("In array2 dispari >= pari ? %i\n", dispari_almeno_quanto_i_pari(array2, 15));
  int array3[17];
  init(array3, 17);
  printf("array3: ");
  print(array3, 17);
  printf("In array3 dispari >= pari ? %i\n", dispari_almeno_quanto_i_pari(array3, 17));
  return 0;
}
