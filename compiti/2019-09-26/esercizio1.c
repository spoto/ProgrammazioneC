#include <stdio.h>

void f(int arr[], int length) {
  int pos, sum;
  for (pos = 0, sum = 0; pos < length; pos++)
    sum += arr[pos];

  for (pos = 0; pos < length; pos++)
    arr[pos] = arr[pos] * arr[pos] > sum;
}

int main(void) {
  int arr[] = { 3, -2, 5, 10, 3, 12, -6 };

  f(arr, 7);

  int pos;
  for (pos = 0; pos < 7; pos++)
    printf("%i ", arr[pos]);
  printf("\n");

  return 0;
}
