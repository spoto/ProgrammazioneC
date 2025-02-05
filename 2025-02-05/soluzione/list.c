#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct List *create(int head, struct List *tail) {
  struct List *this = (struct List *) malloc(sizeof(struct List));
  this->head = head;
  this->tail = tail;
  return this;
}

void print(struct List *this) {
  if (this == NULL)
    printf("\n");
  else {
    printf("%i ", this->head);
    print(this->tail);
  }
}

struct List *from(int arr[], int length) {
  struct List *result = NULL;

  for (int pos = length - 1; pos >= 0; pos--)
    result = create(arr[pos], result);

  return result;
}

struct List *filter(struct List *this, int threshold) {
  if (this == NULL)
    return NULL;
  else if (this->head >= threshold)
    return create(this->head, filter(this->tail, threshold));
  else
    return filter(this->tail, threshold);
}

struct List *duplicate(struct List *this) {
  if (this == NULL)
    return NULL;
  else
    return create(this->head, create(this->head, duplicate(this->tail)));
}

