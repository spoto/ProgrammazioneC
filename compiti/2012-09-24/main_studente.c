#include <stdlib.h>
#include <stdio.h>
#include "studente.h"

int main(void) {
  struct studente *s1 = construct_studente("Giacomo");
  struct studente *s2 = construct_studente("Elisa");
  char *s;

  fa_esame(s1, 18);
  fa_esame(s1, 15);  // non viene registrato
  fa_esame(s2, 30);
  fa_esame(s1, 25);
  fa_esame(s2, 22);
  fa_esame(s2, 29);
  fa_esame(s2, 27);

  printf("%s\n", s = toString(s1));
  free(s);

  printf("%s\n", s = toString(s2));
  free(s);

  destruct_studente(s1);
  destruct_studente(s2);

  return 0;
}
