#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_random(int arr[], int length) {
  srand(time(NULL));

  for (int pos = 0; pos < length; pos++)
    arr[pos] = rand() % 1000;
}

void print(int arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%i ", arr[pos]);

  printf("\n");
}

int is_pentafract(int n) {
  int divisors = 0;
  for (int d = 1; d <= n; d++)
    if (n % d == 0)
      divisors++;

  return divisors >= 5;
}

int swap_prima_pentafratti(int array[], int length) {
  int ho_fatto_scambio = 0;
  for (int pos = 0; pos < length - 1; pos++)
    if (!is_pentafract(array[pos]) && is_pentafract(array[pos + 1])) {
      // scambia(array[pos] con array[pos + 1])
      int temp = array[pos];
      array[pos] = array[pos + 1];
      array[pos + 1] = temp;
      ho_fatto_scambio = 1;
    }

  return ho_fatto_scambio;      
}

void pentafract_first(int arr[], int length) {
  while (swap_prima_pentafratti(arr, length));  
}
