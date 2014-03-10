#include "point.h"

int main(void) {
  // crea un array di 5 punti
  struct point points[] = {
    { 8.1, 6.45 },
    { -1.5, 7.9 },
    { 1.98, 1.99 },
    { -2.96, -9.17 },
    { -0.77, 1.89 }
  };

  // trova il piu' vicino al punto (1.2, 3.4)
  //struct point p = { 1.2, 3.4 };
  struct point result =
    closest((struct point) { 1.2, 3.4 }, points, 5);

  // stampa tale punto
  print_point(result);
  printf("\n");

  return 0;
}
