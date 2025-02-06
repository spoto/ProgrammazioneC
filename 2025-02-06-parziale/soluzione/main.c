#include <stdio.h>
#include "freccia.h"

int main(void) {
  int s, a;
	
  do {
    printf("Inserisci s non negativo: ");
    scanf("%i", &s);
    printf("Inserisci a positivo e dispari: ");
    scanf("%i", &a);
  }
  while (s < 0 || a < 0 || a % 2 == 0);

  freccia(s, a);

  return 0;
}
