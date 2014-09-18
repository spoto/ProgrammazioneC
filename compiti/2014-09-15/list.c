#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *construct_list(int head, struct list *tail) {
  struct list *this = malloc(sizeof(struct list));
  this->head = head;
  this->tail = tail;

  return this;
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

// si assume che this e that abbiano la stessa lunghezza
int compare_sum(struct list *this, struct list *that) {
  return this == NULL ?
    0 : (compare_sum(this->tail, that->tail) - this->head + that->head);
}

int main(void) {
  struct list *l1 = construct_list
    (2, construct_list
     (5, construct_list
      (4, construct_list
       (-3, NULL))));

  struct list *l2 = construct_list
    (-5, construct_list
     (13, construct_list
      (16, construct_list
       (26, NULL))));

  printf("The Answer to The Ultimate Question of Life: %i\n", compare_sum(l1, l2));

  return 0;
}
