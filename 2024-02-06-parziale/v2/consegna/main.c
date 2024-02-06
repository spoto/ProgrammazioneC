#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "letters.h"

int main(void) {
  srand(time(NULL)); // inizializza la sequenza casuale
  char array[70];    // crea l'array
  init(array, 70);   // inizializza l'array in modo casuale
  printf("array prima: ");
  print(array, 70);  // stampa l'array
  invert(array, 70); // inverte maiuscole con minuscole e viceversa
  printf(" array dopo: ");
  print(array, 70);  // stampa nuovamente l'array
  return 0;
}
