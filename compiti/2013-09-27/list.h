#ifndef LIST_H
#define LIST_H

// la struttura lista
struct list {
  int data;
  struct list *next;
};

struct list *construct_list(int data, struct list *next);
struct list *construct_list_bcd(int decimal);
void destroy_list(struct list *this);
void print_list(struct list *this);

#endif
