#include <stdio.h>
#include "vocabolario.h"

int main(void) {
  struct vocabolario *v = construct_vocabolario();
  add_in_vocabolario(v, "cane", "dog");
  add_in_vocabolario(v, "topo", "mouse");
  add_in_vocabolario(v, "casa", "house");
  add_in_vocabolario(v, "simpatico", "nice");
  add_in_vocabolario(v, "correre", "to run");

  print_vocabolario(v);

  printf("La traduzione in inglese di 'simpatico' e' %s\n", cerca_dallitaliano(v, "simpatico"));
  printf("La traduzione in italiano di 'house' e' %s\n", cerca_dallinglese(v, "house"));

  destroy_vocabolario(v);

  return 0;
}
