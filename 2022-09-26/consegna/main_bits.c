#include <stdio.h>
#include "bits.h"

int main(void) {
  int length;

  do {
    printf("Inserisci la lunghezza dell'array, non negativa: ");
    scanf("%i", &length);
  }
  while (length < 0);

  int elements[length];
  init_random(elements, length);
  sort_by_population(elements, length);

  for (int pos = 0; pos < length; pos++)
    printf("%i (popolazione %i)\n", elements[pos], population(elements[pos]));

  return 0;
}
