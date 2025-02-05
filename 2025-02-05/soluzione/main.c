#include <stdio.h>
#include "list.h"

int main(void) {
  struct List *l = create(7, create(17, create(-11, create(13, create(17, NULL)))));
  printf("l = "); print(l);
  struct List *f = filter(l, 10);
  printf("f = "); print(f);
  printf("l = "); print(l);
  struct List *g = filter(l, 40);
  printf("g = "); print(g);
  struct List *d = duplicate(l);
  printf("d = "); print(d);
  printf("l = "); print(l);
  return 0;
}
