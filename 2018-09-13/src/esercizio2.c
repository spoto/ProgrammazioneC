#include <stdio.h>

void divide(int original[], double destination[], int length) {
  int i;

  for (i = 0; i < length; i++)
    destination[i] = original[i] / (i + 1.0);
}

int main(void) {
  int i, original[] = { 5, 4, 3, 2, 1, 0 };
  double destination[6];

  divide(original, destination, 6);

  for (i = 0; i < 6; i++)
    printf("%.2f ", destination[i]);

  return 0;
}
