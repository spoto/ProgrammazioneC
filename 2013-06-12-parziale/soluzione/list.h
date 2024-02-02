#ifndef LIST_H
#define LIST_H

// la struttura lista
struct list {
  char head;
  struct list *tail;
};

struct list *construct_list(char head, struct list *tail);
struct list *construct_list_from_string(const char *s);
struct list *doppie(struct list *this);
void print_list(struct list *this);

#endif
