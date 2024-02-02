#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *construct_list(char head, struct list *tail) {
  struct list *this = malloc(sizeof(struct list));
  this->head = head;
  this->tail = tail;

  return this;
}

struct list *append(struct list *this, struct list *that) {
  if (!this)
    return that;
  else
    return construct_list(this->head, append(this->tail, that));
}

struct list *reflect(struct list *this) {
  if (!this || !this->tail)
    return this;
  else
    return construct_list(this->head, append(reflect(this->tail), construct_list(this->head, NULL)));
}

static void print_list_aux(struct list *this, int just_started) {
  if (this) {
    if (!just_started)
      printf(", ");
    printf("%c", this->head);
    print_list_aux(this->tail, 0);
  }
}

void print_list(struct list *this) {
  printf("[");
  print_list_aux(this, 1);
  printf("]");
}

int main(void) {
  struct list *l = construct_list('a', construct_list('b', construct_list('c', NULL)));
  print_list(reflect(l));
  printf("\n");

  return 0;
}
