#ifndef LIST_H
#define LIST_H

struct list {
  int head;
  struct list *tail;
};

struct list *construct_list(int head, struct list *tail);
void list_print(struct list *this);
int list_length(struct list *this);
int list_sum(struct list *this);
int list_max(struct list *this); // non vuota
int list_is_non_decreasing(struct list *this);
int list_get_first(struct list *this); // non vuota
int list_get_last(struct list *this); // non vuota
void list_increment(struct list *this);
void list_add_followers(struct list *this);
double list_mean(struct list *this); // non vuota

#endif
