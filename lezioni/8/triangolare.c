#include <stdio.h>

int main(void) {
  int somma = 0;
  int max;
  int i;

  printf("Fino a dove devo arrivare? ");
  scanf("%i", &max);

  for (i = 1; i <= max; i = i + 1)
    somma = somma + i;

  printf("La somma dei primi %i interi e': %i\n",
	 max, somma);

  return 0;
}
