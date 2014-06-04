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
void list_increment(struct list *this);  // modifica this
struct list *list_increment_result(struct list *this); // non modifica this
void list_add_followers(struct list *this);
double list_mean(struct list *this); // non vuota
int equals_list(struct list *this, struct list *that);
// ritorna la concatenazione di this e poi that
// né this né that vengono modificate da questa funzione
struct list *append_list(struct list *this, struct list *that);

// ritorna l'inversione di this, che non viene modificata!
struct list *reverse_list(struct list *this);

#endif
