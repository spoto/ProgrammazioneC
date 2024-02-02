#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

int main() {
  int coefficienti1[] = { -3, 4, 0, 0, -2 };
  int coefficienti2[] = { 5, -11, 0, 0 };

  struct polinomio *poly1 = construct_polinomio(coefficienti1, 4);
  struct polinomio *poly2 = construct_polinomio(coefficienti2, 3);
  struct polinomio *somma = add(poly1, poly2);

  char *s;

  printf("primo polinomio: %s di grado %d\n", s = toString(poly1), grado(poly1));
  free(s);

  printf("secondo polinomio: %s di grado %d\n", s = toString(poly2), grado(poly2));
  free(s);

  printf("somma: %s di grado %d\n", s = toString(somma), grado(somma));
  free(s);

  printf("la somma valutata in x = 7 vale %d\n", evaluate(somma, 7));

  destruct_polinomio(somma);
  destruct_polinomio(poly2);
  destruct_polinomio(poly1);

  return 0;
}
