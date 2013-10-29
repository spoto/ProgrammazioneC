#include <stdio.h>

int main(void) {
  int n;
  int contatore;
  int contatore2;

  // leggi quanti asterischi vuoi, non negativo
  printf("Quanti asterischi vuoi? ");
  scanf("%i", &n);
  while (n < 0) {
    printf("Devi inserire un numero non negativo\n");
    printf("Quanti asterischi vuoi? ");
    scanf("%i", &n);
  }

  // stampa il numero di asterischi richiesto
  for (contatore = 1; contatore <= n; contatore++)
    printf("*");

  //contatore = 1;
  //while (contatore <= n) {
  //  printf("*");
  //  contatore++;
  //}

  //while (n > 0) {
  //  printf("*");
  //  n--;
  //}

  printf("\n");

  // considero le n - 2 righe intermedie
  for (contatore = 1; contatore <= n - 2; contatore++) {
    // stampa asterisco
    printf("*");

    // stampa n - 2 spazi
    for (contatore2 = 1; contatore2 <= n - 2; contatore2++)
      printf(" ");

    // stampa asterisco
    printf("*");

    // stampa andata a capo
    printf("\n");
  }

  // stampa una riga di n asterischi
  for (contatore = 1; contatore <= n; contatore++)
    printf("*");

  printf("\n");

  return 0;
}


