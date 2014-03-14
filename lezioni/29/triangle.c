#include <stdio.h>
#include "triangle.h"
#include "segment.h"

struct triangle construct_triangle
(struct point p1, struct point p2, struct point p3) {

  struct triangle result;

  if (points_aligned(p1, p2, p3))
    printf("Non posso creare un triangolo a partire da 3 punti allineati\n");

  result.p1 = p1;
  result.p2 = p2;
  result.p3 = p3;

  return result;
}

void print_triangle(struct triangle this) {
  struct segment s1 = (struct segment) { this.p1, this.p2 };
  struct segment s2 = (struct segment) { this.p2, this.p3 };
  struct segment s3 = (struct segment) { this.p3, this.p1 };

  print_segment(s1); printf("\n");
  print_segment(s2); printf("\n");
  print_segment(s3); printf("\n");
}
