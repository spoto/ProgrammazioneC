#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(void) {
  print_list(fib(10));
  printf("\n");

  print_list(fib(0));
  printf("\n");

  return 0;
}
