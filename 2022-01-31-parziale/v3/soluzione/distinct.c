#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// inizializza l'array, lungo length, con numeri casuali,
// in modo che il primo elemento sia tra 0 e 10 inclusi
// e ogni altro elemento sia maggiore o uguale del precedente
// e minore o uguale del precedente+10
void init(int array[], int length) {
  srand(time(NULL));
  
  int previous = 0;
  for (int pos = 0; pos < length; pos++) {
    array[pos] = previous + rand() % 11;
    previous = array[pos];
  }
}

// stampa l'array, lungo length, su una riga e poi va a capo
void print(int array[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%i ", array[pos]);
    
  printf("\n");
}

// determina se gli elementi di array sono tutti distinti,
// supponendo che l'array, lungo length, sia ordinato non decrescente
int distinct(int array[], int length) {
  // si da' per scontato che l'array sia ordinato non decrescente
  for (int pos = 0; pos < length - 1; pos++)
    if (array[pos] == array[pos + 1])
      return 0; // due uguali: non sono distinti
  
  return 1; // sono tutti distinti
}
