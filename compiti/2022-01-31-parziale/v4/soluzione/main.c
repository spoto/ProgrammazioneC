#include <stdio.h>
#include "mediano.h"

int main(void) {
  int array1[8];
  init(array1, 8) ;
  printf("array1: ");
  print(array1, 8);
  printf("Mediano di array1 = %i\n", mediano(array1, 8));
  int array2[] = { 14, 5, 18, 8 };
  printf("array2: ");
  print(array2, 4);
  printf("Mediano di array2 = %i\n", mediano(array2, 4));
  int array3[] = { 15, 12, 15, 19 };
  printf("array3: ") ;
  print(array3, 4);
  printf("Mediano di array3 = %i\n", mediano(array3, 4));
  int array4[] = { 1, 2, 3, 4, 5, 6 };
  printf("array4: ");
  print(array4, 6);
  printf("Mediano di array4 = %i\n", mediano(array4, 6));
  return 0;
}
