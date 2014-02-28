#include <stdio.h>
#include "cartellone.h"

int main(void) {
  struct cartellone *c = construct_cartellone();

  aggiungi_treno(c, 3408, "Vicenza");
  aggiungi_treno(c, 129, "Milano");
  aggiungi_treno(c, 891, "Roma");

  print_cartellone(c);
  rimuovi_treno(c);  // fa scomparire il treno 3408 per Vicenza
  printf("\n");
  print_cartellone(c);
  destroy_cartellone(c);

  return 0;
}
