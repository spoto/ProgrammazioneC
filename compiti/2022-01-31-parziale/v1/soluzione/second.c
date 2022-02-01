#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// inizializza l'array, lungo length, con numeri casuali tra 0 e 9 inclusi
void init(int array[], int length) {
  srand(time(NULL));

  for (int pos = 0; pos < length; pos++)
    array[pos] = rand() % 10;
}

// stampa l'array, lungolength, su una riga e poi va a capo
void print(int array[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%i ", array[pos]);
    
  printf("\n");
}

// restituisce l'elemento dell'array, lungo length, il cui valore
// e' il secondo piu' grande fra quelli contenuti nell'array;
// se non esistesse, restituisce -1
int second(int array[], int length) {
  int first = -1, second = -1;
  int found_first = 0, found_second = 0;
  for (int pos = 0; pos < length; pos++) {
    int x = array[pos];
    if (!found_first) {
      first = x;
      found_first = 1;
    }
    else if (x > first) {
      second = first;
      first = x;
      found_second = 1;
    }
    else if (!found_second && x < first) {
      second  = x;
      found_second = 1;
    }
    else if (found_second && x < first && x > second)
      second = x;
  }
  
  return second;
}
