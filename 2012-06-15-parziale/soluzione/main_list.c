#include <stdlib.h>
#include "list.h"

int main() {
  struct list *l = construct_list
    (5, construct_list
     (13, construct_list
      (8, construct_list
       (9, construct_list
	(8, construct_list
	 (3, construct_list
	  (2, construct_list
	   (4, construct_list
	    (2, NULL)))))))));

  print_list(l);
  putchar('\n');
  print_list(sup(l));
  putchar('\n');

  return 0;
}
