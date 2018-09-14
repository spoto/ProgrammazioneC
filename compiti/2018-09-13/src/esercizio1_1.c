#include <stdio.h>

int foo(int arr[], int length) {
  int counter = 0, i;
  for (i = 0; i < length - 1; i += 2)
    if (arr[i] > arr[i + 1])
      counter++;

  return counter;
}

int main(void) {
  int original[] = { -8, 6, 7, -5, 8, -1, 0, 4, 3 };
  printf("%d\n", foo(original, 9));

  return 0;
}
