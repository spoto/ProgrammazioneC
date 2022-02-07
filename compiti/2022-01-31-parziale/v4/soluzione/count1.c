#include <stdio.h>

// calcola il numero di bit 1 nella rappresentazione in binario di n
// questa funzione deve essese ricorsiva
int count1(int n) {
  // si dia per scontato che n >= 0
  // DA COMPLETARE: QUESTA FUNZIONE DEVE ESSERE RICORSIVA
  if (n == 0)
    return 0;
  else
    return n % 2 + count1(n / 2);
}

int main(void) {
  // DA COMPLETARE:
  // 1) legge da tastiera un intero n >= 0, se non lo fosse lo richiede ad oltranza
  int n;
  do {
    printf("Inserisci n >= 0: ");
    scanf("%i", &n);
  }
  while (n < 0);

  // 2) chiama count1(n) e ne stampa il risultato
  printf("count1(%i) = %i\n", n, count1(n));

  return 0;
}
