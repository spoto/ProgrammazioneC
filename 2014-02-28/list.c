#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *construct_list(char data, struct list *next) {
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

static void print_list_aux(struct list *this, int just_started) {
  if (this) {
    if (!just_started)
      printf(", ");
    printf("%c", this->data);
    print_list_aux(this->next, 0);
  }
}

void print_list(struct list *this) {
  printf("[");
  print_list_aux(this, 1);
  printf("]");
}

// vista a lezione
struct list *append(struct list *this, struct list *other) {
  if (!this)
    return other;
  else
    return construct_list(this->data, append(this->next, other));
}

struct list *replace(struct list *this, struct list *what) {
  if (!this)
    return NULL;
  else if (this->data == '$')
    return append(what, replace(this->next, what));
  else
    return construct_list(this->data, replace(this->next, what));
}
