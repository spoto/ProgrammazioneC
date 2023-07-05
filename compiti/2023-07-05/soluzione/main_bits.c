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
  sort_by_ripetizione2(elements, length);

  for (int pos = 0; pos < length; pos++)
    printf("%i (ripetizione2=%i)\n", elements[pos], ripetizione2(elements[pos]));

  return 0;
}
