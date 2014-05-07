#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void print_list(struct list *this) {
  printf("[");

  while (this != NULL) {
    printf("%i", this->head);

    // se non è l'ultimo elemento
    if (this->tail != NULL)
      printf(",");

    this = this->tail;
  }

  printf("]\n");
}

