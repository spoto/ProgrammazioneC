#ifndef LIST_H
#define LIST_H

// la struttura lista
struct list {
  char head;
  struct list *tail;
};

struct list *construct_list(char head, struct list *tail);
void print_list(struct list *this);
int *frequency(struct list *this);

#endif
