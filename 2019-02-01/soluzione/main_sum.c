#include <stdio.h>
#include "sum.h"

int main(void) {
  int length;

  do {
    printf("Inserisci la lunghezza dell'array, non negativa: ");
    scanf("%i", &length);
  }
  while (length < 0);

  int elements[length];
  int pos;
  for (pos = 0; pos < length; pos++) {
    printf("Inserisci l'elemento %i dell'array: ", pos);
    scanf("%i", &elements[pos]);
  }

  int s = sum(elements, length);
  printf("Somma degli elementi preceduti da un numero dispari: %i\n", s);
  
  return 0;
}
