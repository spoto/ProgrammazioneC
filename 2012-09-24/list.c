#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// si assume n >= 0
struct list *fib(int n) {
  struct list *temp;

  if (n == 0)
    return NULL;
  else if (n == 1)
    return construct_list(1, NULL);
  else if (n == 2)
    return construct_list(1, fib(1));
  else {
    temp = fib(n - 1);
    return construct_list(temp->data + temp->next->data, temp);
  }
}

struct list *construct_list(int data, struct list *next) {
  struct list *this = malloc(sizeof(struct list));
  this->data = data;
  this->next = next;

  return this;
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

