// Calcola tutti i numeri primi da 2 al MAX indicato
#include <stdio.h>

#define MAX 1000
#define DIM 40

int main(void) {
  // questo sarebbe un array di booleani: usiamo un tipo piccolo
  // per risparmiare memoria, tanto i booleani richiederebbero solo un bit
  short isPrime[MAX];

  int primes[DIM];
  int pos, candidate = 2, nPrimes = 0;

  // inizialmente assumiamo che tutti i numeri siano primi
  for (pos = 2; pos < MAX; pos++)
    isPrime[pos] = 1;

  // prendiamo il numero più a sinistra ancora considerato primo
  while (nPrimes < DIM) {
    if (isPrime[candidate])
      primes[nPrimes++] = candidate;

    // tutti i multipli di candidate sono considerati non primi
    for (pos = candidate * 2; pos < MAX; pos += candidate)
      isPrime[pos] = 0; // falso

    candidate++;
  }

  // stampiamo l'array dei numeri primi che abbiamo calcolato
  for (pos = 0; pos < DIM; pos++)
    printf("%i ", primes[pos]);

  printf("\n");

  return 0;
}
