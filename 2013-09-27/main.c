#include <stdio.h>
#include "bcd.h"

int main(void) {
  struct bcd *b1 = construct_bcd(209);
  struct bcd *b2 = construct_bcd(0);
  struct bcd *b3 = construct_bcd(1987);

  print_as_decimal(b1);
  print_as_binary_string(b1);
  print_as_list(b1);
  printf("\n");

  print_as_decimal(b2);
  print_as_binary_string(b2);
  print_as_list(b2);
  printf("\n");

  print_as_decimal(b3);
  print_as_binary_string(b3);
  print_as_list(b3);
  printf("\n");

  return 0;
}
