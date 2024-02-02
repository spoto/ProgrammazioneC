#ifndef LIST_H
#define LIST_H

#include "iscritto.h"

struct list {
  struct iscritto *head;
  struct list *tail;
};

struct list *construct_list(struct iscritto *head, struct list *tail);
void destroy_list(struct list *this);

#endif
