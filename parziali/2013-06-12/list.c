#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *construct_list(char head, struct list *tail) {
  struct list *this = malloc(sizeof(struct list));
  this->head = head;
  this->tail = tail;

  return this;
}

struct list *construct_list_from_string(const char *s) {
  return *s ? construct_list(*s, construct_list_from_string(s + 1)) : NULL;
}

struct list *doppie(struct list *this) {
  if (!this || !this->tail)
    return NULL;
  else if (this->head == this->tail->head)
    return construct_list
      (this->head, construct_list(this->head, doppie(this->tail->tail)));
  else
    return doppie(this->tail);						    
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

