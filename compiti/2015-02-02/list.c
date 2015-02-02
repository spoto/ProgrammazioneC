#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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

int *frequency(struct list *this) {
  int *res;
  if (!this)
    res = malloc(26 * sizeof(int));
  else {
    res = frequency(this->tail);
    res[this->head - 'a']++;
  }

  return res;
}

int main(void) {
  struct list *l = construct_list
    ('f', construct_list
     ('a', construct_list
      ('f', construct_list
       ('z', construct_list
	('a', construct_list
	 ('f', construct_list
	  ('k', construct_list
	   ('m', NULL))))))));

  printf("l = ");
  print_list(l);
  printf("\n");

  int *freq = frequency(l);
  int pos;
  for (pos = 0; pos < 26; pos++)
    printf("%i ", freq[pos]);
  printf("\n");

  free(freq);

  return 0;
}
