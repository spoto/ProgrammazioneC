#include <math.h>
#include <stdio.h>
#include "point.h"

/*

struct point {
  double x;
  double y;
};

*/

void print_point(struct point this) {
  printf("x: %g, y: %g", this.x, this.y);
}

int equals_point(struct point this, struct point that) {
  return this.x == that.x && this.y == that.y;
}

int points_aligned(struct point p1, struct point p2, struct point p3) {
  double dx1 = p1.x - p2.x;
  double dy1 = p1.y - p2.y;
  double dx2 = p2.x - p3.x;
  double dy2 = p2.y - p3.y;
  double f;

  if (dy1 == 0.0)
    return dy2 == 0.0;

  if (dy2 == 0.0)
    return dy1 == 0.0;

  f = dx1 / dy1 - dx2 / dy2;
  if (f < 0)
    f = -f;

  return f < 0.001;
}

double distance(struct point p1, struct point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
       (p1.y - p2.y) * (p1.y - p2.y));
}

struct point closest
  (struct point this, struct point points[], int length) {

  // assumiamo inizialmente che il piu' vicino
  // sia il primo punto dell'array
  struct point result = points[0];
  int counter;

  for (counter = 1; counter < length; counter++)
    if (distance(points[counter], this) <
	distance(result, this))
      // ne ho trovato uno piu' vicino
      result = points[counter];

  return result;
}

