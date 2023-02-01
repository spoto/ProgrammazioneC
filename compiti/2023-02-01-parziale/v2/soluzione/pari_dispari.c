#include <stdio.h>
#include <stdlib.h>

// inizializza arr, lungo length, con numeri casuali tra -5 e 25 inclusi
// in modo da non avere mai ne' due numeri pari in posizioni consecutive
// ne' due numeri dispari in posizioni consecutive;
// non randomizza la sequenza casuale con srand(time(NULL)): ci pensa il main
void init(int arr[], int length) {
  for (int pos = 0; pos < length; pos++) {
    do {
      arr[pos] = rand() % 31 - 5;
    }
    while (pos > 0 && abs(arr[pos]) % 2 == abs(arr[pos - 1]) % 2);
  }
}

int abs(int x) {
  return x < 0 ? -x : x;
}

// stampa arr, lungo length, separando gli elementi
// con uno spazio, e va a capo
void print(int arr[], int length) {
  for(int pos = 0; pos < length; pos++)
    printf("%i ", arr[pos]);

  printf("\n");
}

// determina se in arr, lungo length, la quantita' dei numeri dispari
// e' maggiore o uguale alla quantita' dei numeri pari;
// si assuma che arr non abbia mai ne' due numeri pari in posizioni consecutive
// ne' due numeri dispari in posizioni consecutive
int dispari_almeno_quanto_i_pari(int arr[], int length) {
  // ovviamente qui si puo' usare un ciclo, ma sarebbe piu' complesso
  if (length % 2 == 0)
    return 1;
  else
    return arr[0] % 2;
}
