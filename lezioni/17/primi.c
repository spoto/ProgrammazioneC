#include <stdio.h>

#define DIM 40

int main(void) {
  int primes[DIM];
  int pos;
  int nPrimes;
  int isPrime;
  int candidato;

  // inizializza l'array con i numeri primi
  primes[0] = 2;
  primes[1] = 3;
  nPrimes = 2;

  for (candidato = 5; nPrimes < DIM; candidato += 2) {
    isPrime = 1; // vero

    // proviamo a dividere candidato per i numeri primi più piccoli
    // della radice quadrata del candidato stesso
    for (pos = 0; isPrime && primes[pos] * primes[pos] <= candidato; pos++)
      if (candidato % primes[pos] == 0)
	isPrime = 0; // falso

    // se candidato era realmente primo, lo salvo nell'array
    if (isPrime)
      primes[nPrimes++] = candidato;
  } 

  // stampa l'array sul video
  for (pos = 0; pos < DIM; pos++)
    printf("%i ", primes[pos]);

  printf("\n");

  return 0;
}
