/* programma che chiede l'età dell'utente
   e continua a chiederla finché non viene inserita
   un'età maggiore o uguale a 0 */

#include <stdio.h>

int main(void) {
  // età della persona
  int eta;
 
  do {
    printf("Quanti anni hai: ");
    scanf("%i", &eta);
  }
  while (eta < 0);

  printf("Hai %i anni\n", eta);

  return 0;
}
