#include <stdio.h>

#define DIM 5

// funziona tramite side-effect su z!!!
void leggi_elementi_di(int z[], int length) {
  int pos;

  for (pos = 0; pos < length; pos++)
    scanf("%i", &z[pos]);
}

int calcola_somma_di(int x[], int length) {
  int pos;
  int somma = 0;

  for (pos = 0; pos < length; pos++)
    somma += x[pos];

  return somma;
}

int calcola_minimo_di(int y[], int length) {
  int minimo = y[0];
  int pos;

  for (pos = 1; pos < length; pos++)
    if (y[pos] < minimo)
      minimo = y[pos];

  return minimo;
}

int main(void) {
  int arr[DIM]; // DIM vale 5
  int arr2[10] = {1, 5, 9, 10, 0, -2, 6, 7, 8, 1};
  int somma, minimo, pos;

  leggi_elementi_di(arr, DIM);
  somma = calcola_somma_di(arr, DIM);
  minimo = calcola_minimo_di(arr, DIM);
  printf("la somma vale %i\n", somma);
  printf("il minimo vale %i\n", minimo);

  somma = calcola_somma_di(arr2, 10);
  minimo = calcola_minimo_di(arr2, 10);
  printf("la somma vale %i\n", somma);
  printf("il minimo vale %i\n", minimo);

  return 0;
}
