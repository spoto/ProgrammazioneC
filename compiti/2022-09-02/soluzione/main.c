#include <stdio.h>
#include "vulcaniano.h"

int main(void) {
  int length;

  do {
    printf("Inserisci la lunghezza dell'array, non negativa: ");
    scanf("%i", &length);
  }
  while (length < 0);

  char elements[length];
  init_random(elements, length);
  printf("                            Array minuscolo casuale: ");
  print(elements, length);
  ordina_vulcaniano(elements, length);
  printf("                    Array trasformato in vulcaniano: ");
  print(elements, length);
  struct element_t *l = non_ripetuti(elements, length);
  printf("Lista derivata dall'array eliminando le ripetizioni: ");
  print_list(l);

  return 0;
}
