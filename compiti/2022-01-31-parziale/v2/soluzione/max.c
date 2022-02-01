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

// funzione ausiliaria che conta gli '1' di x sritto in binario
int ones(int x) {
  int n = 0;
  while (x != 0) {
    n += x % 2;
    x /= 2;
  }

  return n;
}

// restituisce l'elemento dell'array, lungo length, il cui valore,
// scritto in binario, contiene piu' '1'. Se non esistesse, ritorna -1.
// In caso di parita' fra due elementi, restituisce quello piu' a sinistra.
// Si dia per scontato che gli elementi dell'array siano non negativi
int max(int array[], int length) {
  int result = -1;
  for (int pos = 0; pos < length; pos++)
    if (result == -1 || ones(array[pos]) > ones(result))
      result = array[pos];
  
  return result;
}
