#include <stdio.h>
#include "list.h"

int main(void) {
  struct list *l = construct_list
    ("domani", construct_list
     ("piove", construct_list
      ("tantissimo", NULL)));

  struct list *r;

  printf("l = ");
  print_list(l);
  printf("\n");

  r = insert_ordered("non", l);

  printf("l = ");
  print_list(l);
  printf("\n");

  printf("r = ");
  print_list(r);
  printf("\n");

  return 0;
}
