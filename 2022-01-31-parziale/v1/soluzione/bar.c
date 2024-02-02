#include <stdio.h>

// funzione ricorsiva che stampa n asterischi seguiti da 2*n chioccioline
void bar(int n) {
  if (n > 0) {
    printf("*");
    bar(n - 1);
    printf("@@");
  }
}

int main(void) {
  int n;

  do {
    printf("Inserisci n >= 0: ");
    scanf("%i", &n);
  }
  while (n < 0);

  bar(n);
  printf("\n");

  return 0;
}
