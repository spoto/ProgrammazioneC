#ifndef LIST_H
#define LIST_H

struct list {
  int head;
  struct list *tail;
};

void print_list(struct list *this);

#endif

