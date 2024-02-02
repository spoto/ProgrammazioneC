#ifndef LIST_H
#define LIST_H

// la struttura lista
struct list {
  char head;
  struct list *tail;
};

int alternata(struct list *this);
struct list *construct_list(char head, struct list *tail);
void print_list(struct list *this);

#endif
