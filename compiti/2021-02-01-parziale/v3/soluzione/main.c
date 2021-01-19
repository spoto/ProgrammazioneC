#include <stdio.h>
#include "harshad.h"

int main(void) {
  int length;

  do {
    printf("Inserisci la lunghezza, non negativa: ");
    scanf("%i", &length);
  }
  while (length < 0);

  long elements[length];
  init_random(elements, length);
  print(elements, length);
  fill_with_harshad(elements, length);
  print(elements, length);

  return 0;
}
