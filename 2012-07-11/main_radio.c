#include <stdlib.h>
#include <stdio.h>
#include "radio.h"

int main(void) {
  struct radio *r = construct_radio();

  char *s = toString(r);
  printf("%s\n", s);
  free(s);

  memorizza_canale(r, 3, "Radio Patchanka", 98.1);
  memorizza_canale(r, 0, "Radio Castelrotto", 100.5);
  memorizza_canale(r, 9, "Radiofutura", 105.6);

  sintonizza_su(r, 3);

  printf("%s\n", s = toString(r));
  free(s);

  memorizza_canale(r, 0, "Radio Arena", 102.5);
  sintonizza_su(r, 0);

  printf("%s\n", s = toString(r));
  free(s);

  destruct_radio(r);
  return 0;
}
