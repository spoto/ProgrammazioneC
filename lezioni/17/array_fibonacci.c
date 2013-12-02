// crea un array che contiene i primi 20 numeri di fibonacci
// e poi lo stampa

// 0, 1, 1, 2, 3, 5, 8, 13, .....

#include <stdio.h>

int main(void) {
  // creazione e inizializzazione dell'array
  int fibonacci[20];
  int pos;

  fibonacci[0] = 0;
  fibonacci[1] = 1;
  for (pos = 2; pos <= 19; pos++)
    fibonacci[pos] = fibonacci[pos - 1] + fibonacci[pos - 2];

  // stampa dell'array
  for (pos = 0; pos <= 19; pos++)
    printf("%i ", fibonacci[pos]);

  printf("\n");

  return 0;
}
