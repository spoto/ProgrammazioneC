#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *construct_list(int head, struct list *tail) {
  struct list *this = malloc(sizeof(struct list));
  this->head = head;
  this->tail = tail;

  return this;
}

int sempre_diversi(struct list *this) {
  return !this || !this->tail || (this->head != this->tail->head && sempre_diversi(this->tail));
}

static void print_list_aux(struct list *this, int just_started) {
  if (this) {
    if (!just_started)
      printf(", ");
    printf("%i", this->head);
    print_list_aux(this->tail, 0);
  }
}

void print_list(struct list *this) {
  printf("[");
  print_list_aux(this, 1);
  printf("]");
}

int main(void) {}
