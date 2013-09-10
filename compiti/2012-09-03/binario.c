#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char *binario(int n);

int main(void) {
  int n;

  do {
    printf("Inserisci un numero positivo: ");
    scanf("%d", &n);
  }
  while (n <= 0);

  char *s = binario(n);
  printf("%s\n", s);
  free(s);

  return 0;
}

// si assume n > 0
char *binario(int n) {
  // calcoliamo quanti caratteri servono, incluso lo \0 in fondo
  int len = 1;
  int m = n;
  do {
    len++;
    m /= 2;
  }
  while (m > 0);

  // creiamo il risultato
  char *res = malloc(len * sizeof(char));

  // spostiamoci in fondo
  res += len;

  // scriviamo lo \0 in fondo
  *--res = '\0';

  // scriviamo le cifre binarie da destra a sinistra
  do {
    if (n % 2 == 0)
      *--res = '0';
    else
      *--res = '1';

    n /= 2;
  }
  while (n > 0);

  // a questo punto res e' ritornato all'inizio
  return res;
}
