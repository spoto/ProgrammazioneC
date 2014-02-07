#include <stdio.h>
#include "list.h"

int main(void) {
  struct list *l = construct_list(13, construct_list(11, construct_list(-2, construct_list(10, NULL))));

  print_list(l);
  printf("\n");

  print_sums(l);

  return 0;
}
