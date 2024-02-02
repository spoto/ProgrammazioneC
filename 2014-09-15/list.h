#ifndef LIST_H
#define LIST_H

// la struttura lista
struct list {
  int head;
  struct list *tail;
};

struct list *construct_list(int head, struct list *tail);
void print_list(struct list *this);
int compare_sum(struct list *this, struct list *that);

#endif
