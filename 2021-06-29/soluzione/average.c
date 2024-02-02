#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// inizializza arr, lungo length, con numeri interi casuali tra -40 e 50 inclusi
// usando srand() e rand()
void init_random(int arr[], int length) {
  srand(time(NULL));
  for (int pos = 0; pos < length; pos++)
    arr[pos] = rand() % 91 - 40;
}

// stampa su un'unica riga il contenuto dell’array arr, lungo length, poi va a capo
void print_int(int arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%i ", arr[pos]);

  printf("\n");
}

// stampa su un'unica riga il contenuto dell’array arr, lungo length, poi va a capo
// stampa 3 cifre decimali dopo la virgola
void print_double(double arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%.3f ", arr[pos]);

  printf("\n");
}

// considera l'array arr diviso in blocchi consecutivi di step elementi
// e calcola per ciascun blocco la media dei suoi step elementi,
// scrivendola dentro result; quindi ogni elemento di result
// e' la media di tre elementi consecutivi di arr
//
// e' sempre vero che arr ha lunghezza length
// e' sempre vero che (la lunghezza di result) * step == length
// e' sempre vero che step > 0
void average(int arr[], int length, int step, double result[]) {
  for (int pos = 0; pos < length; pos += step) {
    int sum = 0;
    for (int pos2 = pos; pos2 < pos + step; pos2++)
      sum += arr[pos2];

    result[pos / step] = sum / (double) step;
  }
}

int main(void) {
  int arr[33];
  double result[11];
  init_random(arr, 33);
  print_int(arr, 33);

  // calcolo la media degli elementi di arr a gruppi di 3;
  // result ha infatti 11 elementi
  average(arr, 33, 3, result);
  print_double(result, 11);

  return 0;
}
