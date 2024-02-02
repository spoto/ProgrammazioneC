#include <stdio.h>
#include "distinct.h"

int main(void) {
  int array1[8];
  init(array1, 8);
  printf("array1: ");
  print(array1, 8);
  printf("Tutti distinti in array1? %i\n", distinct(array1, 8));
  int array2[] = { 4, 5, 8, 8 };
  printf("array2: ");
  print(array2, 4);
  printf("Tutti distinti in array2? %i\n", distinct(array2, 4));
  int array3[] = { 9, 12, 13, 19 };
  printf("array3: ");
  print(array3, 4);
  printf("Tutti distinti in array3? %i\n", distinct(array3, 4));
  int array4[] = { };
  printf("array4: ");
  print(array4, 0);
  printf("Tutti distinti in array4? %i\n", distinct(array4, 0));
  return 0;
}
