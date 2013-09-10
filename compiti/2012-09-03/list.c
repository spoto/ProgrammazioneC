#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *put0(struct list *this) {
  if (!this)
    return NULL;
  else if (this->data % 2 == 0)
    return construct_list(this->data, put0(this->next));
  else
    return construct_list(0, construct_list(this->data, put0(this->next)));
}

struct list *construct_list(int data, struct list *next) {
  struct list *this = malloc(sizeof(struct list));
  this->data = data;
  this->next = next;

  return this;
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

