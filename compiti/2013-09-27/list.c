#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list *construct_list(int data, struct list *next) {
  struct list *this = malloc(sizeof(struct list));
  this->data = data;
  this->next = next;

  return this;
}

void destroy_list(struct list *this) {
  if (this) {
    destroy_list(this->next);
    free(this);
  }
}

// concatena due liste: presentata a lezione
static struct list *append_list(struct list *this, struct list *other) {
  if (this == NULL)
    return other;
  else
    return construct_list(this->data, append_list(this->next, other));
}

static struct list* digit(int d) {
  struct list *result = NULL;
  int count;

  for (count = 0; count < 4; count++, d /= 2)
    result = construct_list(d % 2, result);

  return result;
}

// ci sono modi piu' efficienti di implementarla, ma questo e' il piu' semplice da scrivere
struct list *construct_list_bcd(int decimal) {
  if (decimal < 10)
    return digit(decimal);
  else
    return append_list(construct_list_bcd(decimal / 10), digit(decimal % 10));
}

static void print_list_aux(struct list *this, int just_started) {
  if (this) {
    if (!just_started)
      printf(", ");
    printf("%d", this->data);
    print_list_aux(this->next, 0);
  }
}

void print_list(struct list *this) {
  printf("[");
  print_list_aux(this, 1);
  printf("]");
}

