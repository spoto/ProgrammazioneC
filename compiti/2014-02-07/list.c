#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *construct_list(int data, struct list *next) {
  struct list *this = malloc(sizeof(struct list));
  this->data = data;
  this->next = next;

  return this;
}

void destroy_list(struct list *this) {
  if (this) {
    destroy_list(this->next);
    free(this);
  }
}

static void print_sums_aux(struct list *this, int sum) {
  if (this == NULL) {
    printf("%3d ", sum);
    return;
  }

  // o prendiamo il primo elemento....
  print_sums_aux(this->next, sum + this->data);

  // oppure non lo prendiamo....
  print_sums_aux(this->next, sum);
}

void print_sums(struct list *this) {
  print_sums_aux(this, 0);
}

static void print_list_aux(struct list *this, int just_started) {
  if (this) {
    if (!just_started)
      printf(", ");
    printf("%d", this->data);
    print_list_aux(this->next, 0);
  }
}

void print_list(struct list *this) {
  printf("[");
  print_list_aux(this, 1);
  printf("]");
}
