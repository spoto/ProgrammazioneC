#include <stdio.h>
#include "next_prime.h"

int main(void) {
  int number;
  int c;

  printf("quanti numeri primi vuoi stampare? ");
  scanf("%d", &number);

  for (c = 0; c < number; c++)
    printf("%d\n", next_prime());

  return 0;
}
