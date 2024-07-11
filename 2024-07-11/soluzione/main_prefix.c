#include <stdio.h>
#include "prefix.h"

void stampa_prefix(char *s1, char *s2) {
  printf("prefix(\"%s\",\"%s\"): %s\n", s1, s2, prefix(s1, s2) ? "vero" : "falso"); 
}

int main(void) {
  char *anno = "anno";
  char *annata = "annata";
  char *annoso = "annoso";
  char *vuoto = "";

  stampa_prefix(anno, annata);
  stampa_prefix(anno, annoso);
  stampa_prefix(annata, annoso);
  stampa_prefix(annata, anno);
  stampa_prefix(annoso, annoso);
  stampa_prefix(vuoto, annata);
  stampa_prefix(annata, vuoto);

  return 0;
}
