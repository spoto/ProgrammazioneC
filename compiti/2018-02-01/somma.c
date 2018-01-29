#include <stdio.h>

int main(void) {
  int arr[] = { 22, 10, 7, 9, -4 };
  int i, sum = 0, counter = 0;

  for (i = 1; i < 5; i += 2, counter++)
    sum += arr[i];

  float result = sum / counter;
  printf("%.2f\n", result);

  return 0;
}
