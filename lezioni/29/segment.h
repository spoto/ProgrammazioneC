#ifndef SEGMENT_H
#define SEGMENT_H

#include "point.h"

struct segment {
  struct point start;
  struct point end;
};

void print_segment(struct segment this);
int equals_segment(struct segment this, struct segment that);

#endif
