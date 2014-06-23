#ifndef LIST_H
#define LIST_H

// la struttura lista
struct list {
  int head;
  struct list *tail;
};

struct list *construct_list(int head, struct list *tail);
int sempre_diversi(struct list *this);
void print_list(struct list *this);

#endif
