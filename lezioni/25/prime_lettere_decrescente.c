#include <stdio.h>

static void stampa(int n);

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
    putchar('a' + n - 1);
    stampa(n - 1);
  }
}
