#include <stdio.h>
#include "list.h"

int main(void) {
  struct list *l1 = construct_list
    ('a', construct_list
     ('f', construct_list
      ('I', construct_list
       ('*', construct_list
	('e', NULL)))));

  struct list *l2 = construct_list
    ('a', construct_list
     ('f', construct_list
      ('&', NULL)));

  printf("l1 = ");
  print_list(l1);
  printf("\n");

  if (alternata(l1))
    printf("l1 è alternata\n");
  else
    printf("l1 non è alternata\n");

  printf("l2 = ");
  print_list(l2);
  printf("\n");

  if (alternata(l2))
    printf("l2 è alternata\n");
  else
    printf("l2 non è alternata\n");

  return 0;
}
