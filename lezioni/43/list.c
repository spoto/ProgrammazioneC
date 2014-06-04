#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct list *construct_list(int head, struct list *tail) {
  struct list *this = malloc(sizeof(struct list));
  this->head = head;
  this->tail = tail;

  return this;
}

static void list_print_aux(struct list *this) {
  if (this == NULL) {}
  else if (this->tail == NULL)
    printf("%i", this->head);
  else {
    printf("%i,", this->head);
    list_print_aux(this->tail);
  }
}

void list_print(struct list *this) {
  printf("[");
  list_print_aux(this);
  printf("]");
}

int list_get_first(struct list *this) { // non vuota
  return this->head;
}

int list_get_last(struct list *this) { // non vuota
  if (this->tail == NULL)
    return this->head;
  else
    return list_get_last(this->tail);
}

void list_increment(struct list *this) {
  if (this != NULL) {
    this->head++;
    list_increment(this->tail);
  }
}

// this non viene modificato
struct list *list_increment_result(struct list *this) {
  if (this == NULL)
    return NULL;
  else
    return construct_list
      (this->head + 1,
       list_increment_result(this->tail));
}

int equals_list(struct list *this, struct list *that) {
  if (this == NULL && that == NULL)
    return 1; // vuote e uguali
  else if (this == NULL && that != NULL)
    return 0; // diverse
  else if (this != NULL && that == NULL)
    return 0; // diverse
  else // adesso siamo sicuri che non sono vuote
    return this->head == that ->head &&
      equals_list(this->tail, that->tail);
}

struct list *append_list(struct list *this, struct list *that) {
  if (this == NULL)
    return that;
  else
    // qui sono sicuro che this != NULL
    return construct_list
      (this->head,
       // parte gialla
       append_list(this->tail, that));
}

struct list *reverse_list(struct list *this) {
  if (this == NULL)
    return NULL;
  else {
    struct list *l = reverse_list(this->tail);
    struct list *nodino = construct_list(this->head, NULL);
    
    return append_list(l, nodino);
  }
}

double list_mean(struct list *this) { // non vuota
  return ((double) list_sum(this)) / list_length(this);
}

void list_add_followers(struct list *this) {
  // schema di ricorsione 3: vuoto/un elemento/più elementi
  if (this != NULL && this->tail != NULL) {
    list_add_followers(this->tail);
    this->head += this->tail->head;
  }
}

void list_add_followers2(struct list *this) {
  if (this != NULL) {
    this->head += list_sum(this->tail);
    list_add_followers2(this->tail);
  }
}

int list_is_non_decreasing(struct list *this) {
  if (this == NULL)
    return 1; // vero
  else if (this->tail == NULL)
    return 1; // vero
  else
    return this->head <= this->tail->head
      && list_is_non_decreasing(this->tail);
}

int list_length(struct list *this) {
  if (this == NULL)
    return 0;
  else
    return 1 + list_length(this->tail);
}

int list_sum(struct list *this) {
  if (this == NULL)
    return 0;
  else
    return this->head + list_sum(this->tail);
}

int list_max(struct list *this) { // non vuota
  int temp;

  if (this->tail == NULL) // un solo elemento
    return this->head;
  else { // almeno due elementi
    temp = list_max(this->tail);
    return this->head > temp ? this->head : temp;
  }
}
