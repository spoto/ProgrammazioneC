#include <stdio.h>
#include "point.h"
#include "triangle.h"

int main(void) {
  struct point p1 = { 3.2, 4.6 };
  struct point p2 = { 4.9, 5.1 };
  struct point p3 = { 1.6, 2.8 };

  /*
    allineati:
  struct point p4 = { 3.2, 4.6 };
  struct point p5 = { 6.4, 9.2 };
  struct point p6 = { 1.6, 2.3 };
  */

  struct triangle t = construct_triangle(p1, p2, p3);

  print_triangle(t);

  return 0;
}
