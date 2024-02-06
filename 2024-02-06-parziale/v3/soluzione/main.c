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
  rotate_vowels(array, 70); // ruota le vocali
  printf(" array dopo: ");
  print(array, 70);  // stampa nuovamente l'array
  return 0;
}
