#include <stdio.h>

void pack(int array[], int length) {
  int read;

  for (read = 0; read < length; read += 2)
    array[read / 2] = array[read] + array[read + 1];
}

int main(void) {
  int a[] = { 3, 0, 8, -2, 9, 11, 23, -10, 9, 5, 4, 12 };
  int pos;

  pack(a, 12);

  for (pos = 0; pos < 6; pos++)
    printf("%i ", a[pos]);

  printf("\n");

  return 0;
}
