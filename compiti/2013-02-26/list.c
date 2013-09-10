#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"

struct list *construct(int head, struct list *tail) {
  struct list *this = malloc(sizeof(struct list));

  this->head = head;
  this->tail = tail;

  return this;
}

struct list *inner(struct list *this) {
  if (!this || !this->tail || !this->tail->tail)
    return NULL;
  else
    return construct(this->tail->head, inner(this->tail));
}

void print_list(struct list *this) {
  printf("[");

  while (this) {
    printf("%i", this->head);
    if (this->tail)
      printf(",");

    this = this->tail;
  }

  printf("]");
}
