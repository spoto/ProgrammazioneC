#include <stdio.h>

int main(void) {
  int n;
  int copia;
  int numero_cifre;
  
  // richiedo un numero positivo
  // altrimenti insisto a richiederlo
  printf("Inserisci un numero positivo: ");
  scanf("%i", &n);
  for ( ; n <= 0; ) {
    printf("Ti avevo detto positivo: reinseriscilo: ");
    scanf("%i", &n);
  }

  copia = n;

  for (numero_cifre = 0; n != 0; n /= 10)
    numero_cifre++;

  printf("Il numero %i aveva %i cifre\n",
	 copia, numero_cifre);

  return 0;
}
