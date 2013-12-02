#include <stdio.h>

#define DIM 8

// spostamento a destra di un array monodimensionale
int main(void) {
  int array[DIM] = { 3, 5, 2, 3, 8, -2, 11, 34 };
  int pos;

  // salvaguardo il vecchio ultimo
  int ultimo = array[DIM - 1];

  // sposto a destra dalla coordinata 1 a DIM - 1
  for (pos = DIM - 2; pos >= 0; pos--)
    array[pos + 1] = array[pos];

  // memorizzo il vecchio ultimo all'inizio
  array[0] = ultimo;

  // stampa il risultato
  for (pos = 0; pos < DIM; pos++)
    printf("%3i", array[pos]);

  printf("\n");

  return 0;
}
