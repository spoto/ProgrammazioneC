#include <stdio.h>

int main(void) {
  int max;
  int i;

  printf("Fino a dove devo arrivare? ");
  scanf("%i", &max);

  //for (i = 1; i <= max; i = i + 1)
  //for (i = max; i >= 1; i = i - )1
  //for (i = 1; i <= max; i = i + 2)
  for (i = max; i >= 1; i = i - 2)
    printf("%i\n", i);

  return 0;
}
