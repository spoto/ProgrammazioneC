#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// static significa che si può usare solo dentro questo file sorgente
static int isVocale(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int alternata(struct list *this) {
  return !this || !this->tail ||
    (isVocale(this->head) != isVocale(this->tail->head) && alternata(this->tail));
}

struct list *construct_list(char head, struct list *tail) {
  struct list *this = malloc(sizeof(struct list));
  this->head = head;
  this->tail = tail;

  return this;
}

static void print_list_aux(struct list *this, int just_started) {
  if (this) {
    if (!just_started)
      printf(", ");
    printf("%c", this->head);
    print_list_aux(this->tail, 0);
  }
}

void print_list(struct list *this) {
  printf("[");
  print_list_aux(this, 1);
  printf("]");
}

