#ifndef LIST_H
#define LIST_H

// la struttura lista
struct list {
  char data;
  struct list *next;
};

struct list *construct_list(char data, struct list *next);
void destroy_list(struct list *this);
void print_list(struct list *this);
struct list *append(struct list *this, struct list *other);
struct list *replace(struct list *this, struct list *what);

#endif
