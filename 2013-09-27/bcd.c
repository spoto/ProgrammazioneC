#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "bcd.h"

struct bcd *construct_bcd(int decimal) {
  struct bcd *this = malloc(sizeof(decimal));
  this->decimal = decimal;

  return this;
}

void destroy_bcd(struct bcd *this) {
  free(this);
}

void print_as_decimal(struct bcd *this) {
  printf("%i\n", this->decimal);
}

static char *as_string(int decimal) {
  int copy = decimal;
  int num_digits = 0;
  int digit;
  int count;

  do {
    num_digits++;
    decimal /= 10;
  }
  while (decimal > 0);

  char *res = malloc(sizeof(char) *((num_digits * 4) + 1));

  res += num_digits * 4;
  *res = '\0';

  decimal = copy;

  do {
    for (count = 0, digit = decimal % 10; count < 4; count++, digit /= 2)
      *--res = '0' + digit % 2;

    decimal /= 10;
  }
  while (decimal > 0);

  return res;
}

void print_as_binary_string(struct bcd *this) {
  char *s = as_string(this->decimal);
  printf("%s\n", s);
  free(s);
}

void print_as_list(struct bcd *this) {
  struct list *l = construct_list_bcd(this->decimal);
  print_list(l);
  printf("\n");
  destroy_list(l);
}
