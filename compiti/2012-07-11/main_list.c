#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
  struct list *l =
    construct_list
    (11, construct_list
     (13, construct_list
      (-4, construct_list
       (13, construct_list
	(-6, construct_list
	 (0, construct_list
	  (1, NULL)))))));

  struct list *p1 = construct_list(11, construct_list(13, NULL));
  struct list *p2 = construct_list(13, construct_list(-4, construct_list(13, NULL)));

  print_list(p1);
  if (!prefix(l, p1))
    printf(" non");
  printf(" e' un prefisso di ");
  print_list(l);
  printf("\n");

  print_list(p2);
  if (!prefix(l, p2))
    printf(" non");
  printf(" e' un prefisso di ");
  print_list(l);
  printf("\n");

  return 0;
}
