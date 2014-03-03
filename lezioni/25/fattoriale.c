#include <stdio.h>

int fattoriale(int);

int fattoriale(int n) {
  if (n == 0)
    return 1;
  else
    return n * fattoriale(n - 1);
}

int main(void) {
  int numero;

  printf("inserisci un numero non negativo: ");
  scanf("%d", &numero);

  printf("il fattoriale di %d e': %d\n",
	 numero,
	 fattoriale(numero));

  return 0;
}
