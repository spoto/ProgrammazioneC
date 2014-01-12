#include <stdio.h>

int somma(int);

int somma(int n) {
  if (n == 0)
    return 0;
  else
    return n + somma(n - 1);
}

int main(void) {
  int numero;

  printf("inserisci un numero non negativo: ");
  scanf("%d", &numero);

  printf("la somma dei primi %d numeri e': %d\n",
	 numero,
	 somma(numero));

  return 0;
}
