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

