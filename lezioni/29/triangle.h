#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "point.h"

struct triangle {
  struct point p1;
  struct point p2;
  struct point p3;
};

struct triangle construct_triangle
  (struct point p1, struct point p2, struct point p3);
void print_triangle(struct triangle this);

#endif
