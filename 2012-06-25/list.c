#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *alterna(struct list *this, int pari) {
  if (!this)
    return NULL;
  else
    if (pari)
      return construct_list(this->data, alterna(this->next, 0));
    else
      return alterna(this->next, 1);
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

