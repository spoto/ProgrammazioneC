#include <stdio.h>
#include "max.h"

int main(void) {
  int array1[8];
  init(array1, 8);
  printf("array1: ");
  print(array1, 8);
  printf("Elemento con piu' '1' in binario dentro array1: %i\n", max(array1, 8));
  int array2[] = { 4, 4, 8, 1 };
  printf("array2: ");
  print(array2, 4);
  printf("Elemento con piu' '1' in binario dentro array2: %i\n", max(array2, 4));
  int array3[] = { };
  printf("array3: ");
  print(array3, 0);
  printf("Elemento con piu' '1' in binario dentro array3: %i\n", max(array3, 0));
  return 0;
}
