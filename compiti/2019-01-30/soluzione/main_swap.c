#include <stdio.h>
#include "swap.h"

int main(void) {
  int length;

  do {
    printf("Inserisci la lunghezza dell'array, non negativa: ");
    scanf("%i", &length);
  }
  while (length < 0);

  char elements[length];

  init_random(elements, length);
  print(elements, length);
  swap(elements, length);
  print(elements, length);
  
  return 0;
}
