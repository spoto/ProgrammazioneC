#include <stdio.h>
#include <stdlib.h>

static int fattoriale(n) {
  return n == 0 ? 1 : (n * fattoriale(n - 1));
}

static int binomiale(int n, int k) {
  return fattoriale(n) / (fattoriale(k) * fattoriale(n - k));
}

char *stringa_binomiale(int n, int k) {
  // assumiamo 10 cifre a intero al massimo
  char *res = malloc(10 * 3 + 8 + 1);

  sprintf(res, "%i su %i fa %i", n, k, binomiale(n, k));

  return res;
}

int main(void) {
  int n, k;
  char *s;

  printf("n: " );
  scanf("%i", &n);

  printf("k: " );
  scanf("%i", &k);

  printf("%s\n", s = stringa_binomiale(n, k));
  free(s);

  return 0;
}
