#include "penta.h"
#include <stdlib.h>
#include <stdio.h>

struct list {
  int x;
  struct list *tail;
};

struct list *construct(int x, struct list *tail) {
  struct list *result = malloc(sizeof(struct list));
  result->x = x;
  result->tail = tail;
  return result;
}

int at_least_one(struct list *l) {
  return l != NULL && (is_pentafract(l->x) || at_least_one(l->tail));
}

int main(void) {
  struct list *l = construct(15, NULL);
  l = construct(6, l);
  l = construct(12, l);
  l = construct(5, l);

  printf("%i\n", at_least_one(l));

  return 0;
}
