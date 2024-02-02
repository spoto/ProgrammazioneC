#ifndef LIST_H
#define LIST_H

// la struttura lista
struct list {
  int data;
  struct list *next;
};

struct list *construct_list(int data, struct list *next);
static void print_sums_aux(struct list *this, int sum);
void print_sums(struct list *this);
void destroy_list(struct list *this);
void print_list(struct list *this);

#endif
