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

struct list *camelize_list(struct list *this) {
  if (!this || !this->tail)
    return this;
  else if (this->head == ' ')
    return construct_list(this->tail->head - ('a' - 'A'), camelize_list(this->tail->tail));
  else
    return construct_list(this->head, camelize_list(this->tail));
}

int main(void) {
  struct list *l = construct_list
    ('c', construct_list
     ('a', construct_list
      ('m', construct_list
       ('e', construct_list
	('l', construct_list
	 ('s', construct_list
	  (' ', construct_list
	   ('a', construct_list
	    ('r', construct_list
	     ('e', construct_list
	      (' ', construct_list
	       ('s', construct_list
		('w', construct_list
		 ('e', construct_list
		  ('e', construct_list
		   ('t', NULL))))))))))))))));
			 
  print_list(camelize_list(l)); printf("\n");
  return 0;
}
