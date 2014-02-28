#include <stdlib.h>
#include "list.h"

int main(void) {
  struct list *where = construct_list
    ('d', construct_list('$', construct_list('$', construct_list('E', construct_list('$', NULL)))));
  struct list *what = construct_list('A', construct_list('3', NULL));

  struct list *r = replace(where, what);
  print_list(r);
  
  return 0;
}
