#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "iscritto.h"
#include "list.h"

struct list *construct_list(struct iscritto *head, struct list *tail) {
  struct list *this = malloc(sizeof(struct list));
  this->head = head;
  this->tail = tail;

  return this;
}

void destroy_list(struct list *this) {
  if (this->tail)
    destroy_list(this->tail);

  destroy_iscritto(this->head);
  free(this);
}
