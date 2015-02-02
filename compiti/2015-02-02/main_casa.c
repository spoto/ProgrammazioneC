#include <stdio.h>
#include "casa.h"
#include "vendita.h"

int main(void) {
  struct casa *c1 = construct_casa(80, 20, 15);
  struct casa *c2 = construct_casa(70, 0, 0);

  printf("c1 ha una metratura commerciale di %.2f m2\n", metratura_commerciale(c1));
  printf("c2 ha una metratura commerciale di %.2f m2\n", metratura_commerciale(c2));

  // la stessa casa viene venduta due volte a prezzi diversi
  struct vendita *v1 = construct_vendita(c1, 200000);
  struct vendita *v2 = construct_vendita(c1, 250000);

  printf("c1 e' stata venduta una prima volta a %.2f euro al m2\n", prezzo_m2(v1));
  printf("c1 e' stata venduta una seconda volta a %.2f euro al m2\n", prezzo_m2(v2));

  return 0;
}
