#include <stdio.h>

int main(void) {
  int num1;
  int num2;

  printf("Inserisci num1: ");
  scanf("%i", &num1);

  printf("Inserisci num2: ");
  scanf("%i", &num2);

  printf("La somma di %i e %i fa %i\n",
	 num1, num2, num1 + num2);

  return 0;
}
