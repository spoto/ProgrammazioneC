#include <stdio.h>

int max(int arr[], int length) {
  int result = arr[0];
  for (int pos = 1; pos < length; pos++)
    if (arr[pos] > result)
      result = arr[pos];

  return result;
}

int quasi_max(int arr[], int length) {
  int m = max(arr, length);
  int result;

  for (int pos = 0; pos < length; pos++)
    if (arr[pos] > result && arr[pos] != m)
      result = arr[pos];

  return result;
}

int main(void) {
  int arr[] = { 28, 10, 7, 9, 14, 22, 23, 28, -4, 23 };
  printf("quasi massimo: %d\n", quasi_max(arr, 10));

  return 0;
}
