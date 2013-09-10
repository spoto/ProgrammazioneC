#ifndef LIST_H
#define LIST_H

// la struttura lista
struct list {
  int data;
  struct list *next;
};

struct list *construct_list(int data, struct list *next);
void destruct_list(struct list *this);
void print_list(struct list *this);
struct list *fib(int n);

#endif
