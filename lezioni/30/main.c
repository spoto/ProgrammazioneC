#include <stdio.h>
#include "month.h"

int main(void) {
  struct month calendar[] = {
    construct_month(1, 2012),
    construct_month(2, 2012),
    construct_month(3, 2012),
    construct_month(4, 2012),
    construct_month(5, 2012),
    construct_month(6, 2012),
    construct_month(7, 2012),
    construct_month(8, 2012),
    construct_month(9, 2012),
    construct_month(10, 2012),
    construct_month(11, 2012),
    construct_month(12, 2012)
  };

  int i;

  for (i = 0; i < 12; i++) {
    print_month(calendar[i]);
    printf("\n");
  }

  return 0;
}
