#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

struct list *insert_ordered(char *s, struct list *this) {
  if (!this || strcmp(s, this->head) <= 0)
    return construct_list(s, this);
  else
    return construct_list(this->head, insert_ordered(s, this->tail));
}

struct list *construct_list(char *head, struct list *tail) {
  struct list *this = malloc(sizeof(struct list));
  this->head = head;
  this->tail = tail;

  return this;
}

static void print_list_aux(struct list *this, int just_started) {
  if (this) {
    if (!just_started)
      printf(", ");
    printf("%s", this->head);
    print_list_aux(this->tail, 0);
  }
}

void print_list(struct list *this) {
  printf("[");
  print_list_aux(this, 1);
  printf("]");
}

