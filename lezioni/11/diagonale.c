#include <stdio.h>

int main(void) {
  int n;
  int i;
  int contatore;

  // leggi quante righe vuoi, non negativo
  printf("Quante righe vuoi? ");
  scanf("%i", &n);
  while (n < 0) {
    printf("Devi inserire un numero non negativo\n");
    printf("Quante righe vuoi? ");
    scanf("%i", &n);
  }

  for (i = 1; i <= n; i++) {
    // stampa i - 1 spazi
    for (contatore = 1; contatore <= i - 1; contatore++)
      printf(" ");

    // stampa asterisco e andata a capo
    printf("*\n");
  }

  return 0;
}


