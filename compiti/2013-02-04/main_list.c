#include <stdio.h>
#include "list.h"

int main(void) {
  struct list *l1 = construct_list
    (10, construct_list
     (-5, construct_list
      (23, construct_list
       (11, construct_list
	(-2, NULL)))));

  struct list *l2 = construct_list(10, NULL);

  struct list *l3 = NULL;

  printf("l1 = ");
  print_list(l1);
  printf("\n");

  printf("lastToFirst(l1) = ");
  print_list(lastToFirst(l1));
  printf("\n");

  printf("l1 = ");
  print_list(l1);
  printf("\n");

  printf("lastToFirst(l2) = ");
  print_list(lastToFirst(l2));
  printf("\n");

  printf("lastToFirst(l3) = ");
  print_list(lastToFirst(l3));
  printf("\n");

  return 0;
}
