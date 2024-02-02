#include <stdio.h>

void max_array(int original[], int result[], int length) {
  if (length <= 0)
    return;

  int i, max = original[0];
  for (i = 0; i < length; i++) {
    if (original[i] > max)
      max = original[i];

    result[i] = max;
  }
}

void print_array(int arr[], int length) {
  int i;
  for (i = 0; i< length; i++)
    printf("%d ", arr[i]);

  printf("\n");
}

int main(void) {
  int original[] = { -2, 6, 7, 5, 8, -3, 0, -4, 0, -1 };
  int result[10];

  max_array(original, result, 10);
  print_array(result, 10);

  return 0;
}
