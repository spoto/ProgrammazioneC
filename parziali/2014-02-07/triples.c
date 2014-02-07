#include <stdio.h>

void swap(int array[], int length) {
  int pos, temp;

  for (pos = 0; pos + 2 < length; pos += 3) {
    temp = array[pos];
    array[pos] = array[pos + 2];
    array[pos + 2] = temp;
  }
}

int main(void) {
  int arr[] = { 13, 0, 34, -5, -6, 10, 34, -28, 44, 71, 9 };
  int pos;

  swap(arr, 11);

  for (pos = 0; pos < 11; pos++)
    printf("%i ", arr[pos]);

  printf("\n");

  return 0;
}
