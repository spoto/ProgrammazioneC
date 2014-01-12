#include <stdio.h>

int fibonacci(int);

int fibonacci(int n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void) {
  int numero;

  printf("inserisci un numero non negativo: ");
  scanf("%d", &numero);

  printf("il %d-esimo numero di fibonacci e': %d\n",
	 numero,
	 fibonacci(numero));

  return 0;
}
