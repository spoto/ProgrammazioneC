#include <stdio.h>
#include "second.h"

int main(void) {
  int array1[8];
  init(array1, 8);
  printf("array1: ");
  print(array1, 8);
  printf("Secondo piu' grande elemento di array1: %i\n", second(array1, 8));
  int array2[] = { 8, 8, 4, 8 };
  printf("array2: ");
  print(array2, 4);
  printf("Secondo piu' grande elemento di array2: %i\n", second(array2, 4));
  int array3[] = { 8, 8, 8 };
  printf("array3: ");
  print(array3, 3);
  printf("Secondo piu' grande elemento di array3: %i\n", second(array3, 4));
  int array4[] = { };
  printf("array4: ");
  print(array4, 0);
  printf("Secondo piu' grande elemento di array4: %i\n", second(array4, 0));
  return 0;
}
