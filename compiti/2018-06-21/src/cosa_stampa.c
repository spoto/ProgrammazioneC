#include <stdio.h>

int main(void) {
  int original[] = { -8, 6, 7, -5, 8, -1, 0, 4, 3, 1 };
  int counter = 0, i;

  for (i = 0; i < 10; i++) {
    int x = original[i];
    if (x < 0)
      x = -x;

    counter += x % 2;
  }

  printf("%d\n", counter);

  return 0;
}
