#include <stdio.h>
#include "hex.h"

int main(void) {
  int length;

  do {
    printf("Inserisci la lunghezza, non negativa: ");
    scanf("%i", &length);
  }
  while (length < 0);

  int elements[length];
  init_random(elements, length);
  print(elements, length);
  hexletters_first(elements, length);
  print(elements, length);

  return 0;
}
