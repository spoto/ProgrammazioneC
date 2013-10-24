#include <stdio.h>

int main(void) {
  int n;
  int candidato;
  int radice;
  
  // richiedo un numero positivo
  // altrimenti insisto a richiederlo
  printf("Inserisci un numero positivo: ");
  scanf("%i", &n);
  for ( ; n <= 0; ) {
    printf("Ti avevo detto positivo: reinseriscilo: ");
    scanf("%i", &n);
  }

  for (candidato = 1; n >= candidato * candidato; candidato++);

  radice = candidato - 1;

  printf("La radice quadrata approssimata di %i e' %i\n",
	 n, radice);

  return 0;
}
