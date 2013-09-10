#include <stdlib.h>
#include <stdio.h>
#include "banca.h"

int main(void) {
  struct banca *b = construct_banca();
  char *s;

  deposita(b, "Fausto", 112.14);
  deposita(b, "Samantha", 1023.03);
  deposita(b, "Fausto", 13.00);
  deposita(b, "Alessandra", 11.34);

  printf("%s\n", s = toString(b));
  free(s);

  preleva(b, "Fausto", 11.30);

  printf("%s\n", s = toString(b));
  free(s);

  destruct_banca(b);
  return 0;
}
