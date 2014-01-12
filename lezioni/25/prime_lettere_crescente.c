#include <stdio.h>

static void stampa(int n);
static void stampa_aux(char da, int n);

int main(void) {
  int n;

  printf("n: ");
  scanf("%d", &n);

  stampa(n);

  printf("\n");

  return 0;
}

static void stampa(int n) {
  if (n == 0)
    return;
  else {
    stampa(n - 1);
    putchar('a' + n - 1);
  }
}
