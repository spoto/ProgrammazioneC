#include "sum.h"
#include <stdio.h>

int main(void) {
  int length;
  
  do {
    printf("Inserisci length: ");
    scanf("%i", &length);
  }
  while (length < 0);
  
  int elements[length];
  
  for (int pos = 0; pos < length; pos++) {
    printf("elements[%i]: ", pos);
    scanf("%i", &elements[pos]);
  }
  
  int r = sum(elements, length);
  printf("risultato = %i\n", r);

  return 0;
}
