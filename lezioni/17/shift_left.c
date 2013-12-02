#include <stdio.h>

#define DIM 8

// spostamento a sinistra di un array monodimensionale
int main(void) {
  int array[DIM] = { 3, 5, 2, 3, 8, -2, 11, 34 };
  int pos;

  // salvaguardo il vecchio primo
  int primo = array[0];

  // sposto a sinistra dalla coordinata 1 a DIM - 1
  for (pos = 1; pos < DIM; pos++)
    array[pos - 1] = array[pos];

  // memorizzo il vecchio primo in fondo
  array[DIM - 1] = primo;

  // stampa il risultato
  for (pos = 0; pos < DIM; pos++)
    printf("%3i", array[pos]);

  printf("\n");

  return 0;
}
