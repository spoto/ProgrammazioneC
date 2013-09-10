#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// restituisce una lista ottenuta spostando l'ultimo
// elemento all'inizio. La lista this non viene modificata
struct list *lastToFirst(struct list *this) {
  struct list *temp;

  if (!this || !this->next)
    return this;
  else {
    temp = lastToFirst(this->next);
    return construct_list(temp->data, construct_list(this->data, temp->next));
  }
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

