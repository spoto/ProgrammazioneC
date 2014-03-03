#include <stdio.h>

int is_prime(int n) {
  int divisor;

  if (n < 2)
    return 0;

  for (divisor = 2; divisor < n; divisor++)
    if (n % divisor == 0)
      return 0;

  return 1;
}

int count_primes(int max) {
  return max > 0 ? count_primes(max - 1) + is_prime(max) : 0;
}

int main(void) {
  int max;

  printf("max: ");
  scanf("%i", &max);

  printf("Ci sono %i numeri primi tra 0 e %i\n",
	 count_primes(max), max);

  return 0;
}
