#include <stdlib.h>
#include "list.h"

// ritorna un puntatore a una nuova
// lista che contiene 1, 2, 3
struct list *construct_list(void) {
  struct list *n1 = malloc(sizeof(struct list));
  struct list *n2 = malloc(sizeof(struct list));
  struct list *n3 = malloc(sizeof(struct list));

  n1->head = 1;
  n2->head = 2;
  n3->head = 3;

  n1->tail = n2;
  n2->tail = n3;
  n3->tail = NULL;

  return n1;
}

int main(void) {
  struct list *l = construct_list();

  print_list(l);

  return 0;
}
