#include <stdio.h>

int main(void) {
  int num;

  printf("Inserisci il numero del carattere: ");
  scanf("%i", &num);

  printf("Il carattere %i-esimo dell'alfabeto inglese e': %c\n",
	 num,
	 'A' + num - 1);

  return 0;
}
