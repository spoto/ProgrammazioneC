#include <stdlib.h>
#include <time.h>

// riempie arr con interi casuali tra 0 e 65535 inclusi;
// arr ha lunghezza length
void init_random(int arr[], int length) {
  srand(time(NULL));
  for (int pos = 0; pos < length; pos++)
    arr[pos] = rand() % 65536;
}

// ritorna la popolazione di n, cioe' il numero di bit ad 1
// nella rappresentazione binaria di n. Si dia per scontato
// che n sia tra 0 e 65535 inclusi
int population(int n) {
  int p;
  for (p = 0; n; n /= 2)
    p += n % 2;

  return p;
}

// fa una passata sull'array indicato scambiando
// due elementi consecutivi se non rispettano l'ordinamento
int swap(int array[], int length) {
  int ho_fatto_scambio = 0;
  for (int pos = 0; pos < length - 1; pos++)
    if (population(array[pos]) > population(array[pos + 1])) {
      // scambia array[pos] con array[pos + 1]
      int temp = array[pos];
      array[pos] = array[pos + 1];
      array[pos + 1] = temp;
      ho_fatto_scambio = 1;
    }

  return ho_fatto_scambio;      
}

// ordina gli elementi di arr in ordine non decrescente per popolazione
void sort_by_population(int arr[], int length) {
  while (swap(arr, length));  
}
