#include <stdio.h>
#include "point.h"
#include "segment.h"

/*
struct segment {
  struct point start;
  struct point end;
};
*/

void print_segment(struct segment this) {
  printf("(");
  print_point(this.start);
  printf(")---(");
  print_point(this.end);
  printf(")");
}

int equals_segment(struct segment this, struct segment that) {
  return (equals_point(this.start, that.start) &&
	  equals_point(this.end, that.end)) 

    ||

    (equals_point(this.start, that.end) &&
     equals_point(this.end, that.start));
}
