#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// inizializza l'array, lungo length, con numeri casuali,
// tutti pari, tra 0 e 100 inclusi
void init(int array[], int length) {
  srand(time(NULL));
  for (int pos = 0; pos < length; pos++)
    array[pos] = 2 * (rand() % 51);
}

// stampa l'array, lungo length, su una riga e poi va a capo
void print(int array[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%i ", array[pos]);
    
  printf("\n");
}

// ritorna l'elemento dell'array che e' piu' vicino alla media
// degli elementi dell'array, supponendo che l'array abbia lunghezza length
// e che length > 0
int mediano(int array[], int length) {
  int somma = 0;
  for (int pos = 0; pos < length; pos++)
    somma += array[pos];

  double media = somma / (double) length;

  int risultato = array[0];
  for (int pos = 1; pos < length; pos ++)
    if (fabs(array[pos] - media) < fabs(risultato - media))
      risultato = array[pos];

  return risultato;
}
