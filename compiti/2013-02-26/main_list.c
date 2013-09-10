#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main() {
  struct list *l = construct(65, construct(77, construct(11, construct(122, construct(200, NULL)))));

  printf("inner(l) = ");
  print_list(inner(l));
  printf("\n");

  printf("l = ");
  print_list(l);
  printf("\n");

  return 0;
}
