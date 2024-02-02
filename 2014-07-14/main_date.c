#include <stdio.h>
#include "date.h"

static void compare(struct date *d1, struct date *d2) {
  int comp = compare_date(d1, d2);

  print_date(d1);

  if (comp < 0)
    printf(" < ");
  else if (comp == 0)
    printf(" = ");
  else
    printf(" > ");

  print_date(d2);

  printf("\n");
}

int main(void) {
  struct date *d1 = construct_date(14, 7, 1789);
  struct date *d2 = construct_date_alt(15, "maggio", 1789);
  struct date *d3 = construct_date_alt(15, "giugno", 2014);
  struct date *d4 = construct_date_alt(14, "luglio", 1789);

  compare(d1, d2);
  compare(d2, d3);
  compare(d1, d3);
  compare(d1, d4);

  return 0;
}
