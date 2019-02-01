#include <stdio.h>

struct coppia { 
  int *v1; 
  int v2; 
};

// Definire qui sotto le funzioni init, f, g ed h




int main(void) {
  struct coppia c;
  int i = 5;
  init(&c, &i);
  printf("Il valore della coppia e' uguale a (%d,%d)\n", *(c.v1), c.v2);
  f(c);
  printf("Il valore della coppia e' uguale a (%d,%d)\n", *(c.v1), c.v2);
  g(c);
  printf("Il valore della coppia e' uguale a (%d,%d)\n", *(c.v1), c.v2);
  h(&c);
  printf("Il valore della coppia e' uguale a (%d,%d)\n", *(c.v1), c.v2);

  return 0;
}
