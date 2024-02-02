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
	(-5, construct_list
	 (0, construct_list
	  (1, NULL)))))));

  print_list(l);
  printf("\n");

  print_list(put0(l));
  printf("\n");

  return 0;
}
