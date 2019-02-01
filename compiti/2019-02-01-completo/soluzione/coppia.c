#include <stdio.h>

struct coppia { 
  int *v1; 
  int v2; 
};

void init(struct coppia *c, int *i) {
  c->v1 = i; 
  c->v2 = 10;
}

void f(struct coppia c) {
  *c.v1 = 45;
}

void g(struct coppia c) {
  c.v2 = 32;
}

void h(struct coppia *c) {
  c->v2 = 12;
}

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
