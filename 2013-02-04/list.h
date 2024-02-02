#ifndef LIST_H
#define LIST_H

// la struttura lista
struct list {
  int data;
  struct list *next;
};

struct list *lastToFirst(struct list *this);
struct list *construct_list(int data, struct list *next);
void print_list(struct list *this);

#endif
