#include <stdio.h>

// calcola la sommatoria 0^2 + 1^2 + 2^2 + 3^2 + .... + n^2;
// questa funzione deve essese ricorsiva
long sum(int n) {
  // si dia per scontato che n >= 0
  // QUESTA FUNZIONE DEVE ESSERE RICORSIVA
  if (n == 0)
    return 0;
  else
    return sum(n - 1) + ((long) n)*n;
}

int main(void) {
  int n;

  do {
    printf("Inserisci n >= 0: ");
    scanf("%i", &n);
  }
  while (n < 0);

  printf("sommatoria = %li\n", sum(n));

  return 0;
}
