#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// inizializza l'array lungo length con numeri casuali tra 0 e 4 inclusi
void init_random(int arr[], int length) {
  // DA COMPLETARE
}

// stampa su una riga l'array lungo length e poi va a capo
void print(int arr[], int length) {
  // DA COMPLETARE
}

// calcola quante volte value e' presente dentro l'array lungo length
int how_many(int arr[], int length, int value) {
  // DA COMPLETARE
}

// determina se arr[pos] e' in ordine errato col successore arr[pos + 1],
// cioe' arr[pos] e' meno frequente di arr[pos + 1]
// oppure entrambi hanno la stessa frequenza ma arr[pos] e' maggiore di arr[pos + 1];
// si assuma che 0 <= pos < length - 1
int must_swap(int arr[], int length, int pos) {
  // DA COMPLETARE
}

// mette in ordine l'array in modo che gli elementi piu' frequenti siano
// messi al suo inizio; a parita' di frequenza, mette prima gli elementi minori
void more_frequent_first(int arr[], int length) {
  // DA COMPLETARE
}

int main(void) {
  int arr[20];
  init_random(arr, 20);
  print(arr, 20); // stampa prima dell'ordinamento
  more_frequent_first(arr, 20);
  print(arr, 20); // stampa dopo l'ordinamento
  return 0;
}
