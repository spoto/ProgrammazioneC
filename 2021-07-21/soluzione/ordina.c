#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// inizializza l'array lungo length con numeri casuali tra 0 e 4 inclusi
void init_random(int arr[], int length) {
  srand(time(NULL));
  for (int pos = 0; pos < length; pos++)
    arr[pos] = rand() % 5;
}

// stampa su una riga l'array lungo length e poi va a capo
void print(int arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%i ", arr[pos]);

  printf("\n");
}

// calcola quante volte value e' presente dentro l'array lungo length
int how_many(int arr[], int length, int value) {
  int count = 0;
  for (int pos = 0; pos < length; pos++)
    if (arr[pos] == value)
      count++;

  return count;
}

// determina se arr[pos] e' in ordine errato col successore arr[pos + 1],
// cioe' arr[pos] e' meno frequente di arr[pos + 1]
// oppure entrambi hanno la stessa frequenza ma arr[pos] e' maggiore di arr[pos + 1];
// si assuma che 0 <= pos < length - 1
int must_swap(int arr[], int length, int pos) {
  int how_many1 = how_many(arr, length, arr[pos]);
  int how_many2 = how_many(arr, length, arr[pos + 1]);
  return how_many1 < how_many2 ||
    (how_many1 == how_many2 && arr[pos] > arr[pos + 1]);
}

int swap_first_more_frequent(int arr[], int length) {
  int ho_fatto_scambio = 0;
  for (int pos = 0; pos < length - 1; pos++)
    if (must_swap(arr, length, pos)) {
      // scambia(array[pos] con array[pos + 1])
      int temp = arr[pos];
      arr[pos] = arr[pos + 1];
      arr[pos + 1] = temp;
      ho_fatto_scambio = 1;
    }

  return ho_fatto_scambio;      
}

// mette in ordine l'array in modo che gli elementi piu' frequenti siano
// messi al suo inizio; a parita' di frequenza, mette prima gli elementi minori
void more_frequent_first(int arr[], int length) {
  while (swap_first_more_frequent(arr, length));  
}

int main(void) {
  int arr[20];
  init_random(arr, 20);
  print(arr, 20); // stampa prima dell'ordinamento
  more_frequent_first(arr, 20);
  print(arr, 20); // stampa dopo l'ordinamento
  return 0;
}
