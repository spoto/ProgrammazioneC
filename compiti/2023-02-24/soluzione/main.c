#include <stdio.h>
#include "marziano.h"

int main(void) {
  int length;

  do {
    printf("Inserisci la lunghezza dell'array, non negativa: ");
    scanf("%i", &length);
  }
  while (length < 0);

  char elements[length];
  init_random(elements, length);
  printf("                            Array alfabetico casuale: ");
  print(elements, length);
  ordina_marziano(elements, length);
  printf("                    Array trasformato in marziano: ");
  print(elements, length);
  struct element_t *l = vocali_non_ripetute(elements, length);
  printf("Lista derivata dall'array eliminando le consonanti e le vocali ripetute: ");
  print_list(l);

  return 0;
}
