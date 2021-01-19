#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_random(int arr[], int length) {
  srand(time(NULL));

  for (int pos = 0; pos < length; pos++)
    arr[pos] = 2 * (rand() % 501);
}

void print(int arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%x ", arr[pos]);

  printf("\n");
}

int is_hexletter(int n) {
  do {
    if (n % 16 < 10)
      return 0;

    n /= 16;
  }
  while (n > 0);

  return 1;
}

int swap_prima_hexletters(int array[], int length) {
  int ho_fatto_scambio = 0;
  for (int pos = 0; pos < length - 1; pos++)
    if (!is_hexletter(array[pos]) && is_hexletter(array[pos + 1])) {
      // scambia(array[pos] con array[pos + 1])
      int temp = array[pos];
      array[pos] = array[pos + 1];
      array[pos + 1] = temp;
      ho_fatto_scambio = 1;
    }

  return ho_fatto_scambio;      
}

void hexletters_first(int arr[], int length) {
  while (swap_prima_hexletters(arr, length));  
}
