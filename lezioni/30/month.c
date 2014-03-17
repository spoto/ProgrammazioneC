#include <stdio.h>
#include "month.h"

// static qui significa privato
static int is_leap_year(int year) {
  return year % 4 == 0
    && (year % 100 != 0 || year % 400 == 0);
}

struct month construct_month(int num, int year) {
  struct month result;

  switch (num) {
  case 1:
    result.days = 31;
    result.name[0] = 'j';
    result.name[1] = 'a';
    result.name[2] = 'n';
    break;
  case 2:
    result.days = is_leap_year(year) ? 29 : 28;
    result.name[0] = 'f';
    result.name[1] = 'e';
    result.name[2] = 'b';
    break;
  case 3:
    result.days = 31;
    result.name[0] = 'm';
    result.name[1] = 'a';
    result.name[2] = 'r';
    break;
  case 4:
    result.days = 30;
    result.name[0] = 'a';
    result.name[1] = 'p';
    result.name[2] = 'r';
    break;
  case 5:
    result.days = 31;
    result.name[0] = 'm';
    result.name[1] = 'a';
    result.name[2] = 'y';
    break;
  case 6:
    result.days = 30;
    result.name[0] = 'j';
    result.name[1] = 'u';
    result.name[2] = 'n';
    break;
  case 7:
    result.days = 31;
    result.name[0] = 'j';
    result.name[1] = 'u';
    result.name[2] = 'l';
    break;
  case 8:
    result.days = 31;
    result.name[0] = 'a';
    result.name[1] = 'u';
    result.name[2] = 'g';
    break;
  case 9:
    result.days = 30;
    result.name[0] = 's';
    result.name[1] = 'e';
    result.name[2] = 'p';
    break;
  case 10:
    result.days = 31;
    result.name[0] = 'o';
    result.name[1] = 'c';
    result.name[2] = 't';
    break;
  case 11:
    result.days = 30;
    result.name[0] = 'n';
    result.name[1] = 'o';
    result.name[2] = 'v';
    break;
  case 12:
    result.days = 31;
    result.name[0] = 'd';
    result.name[1] = 'e';
    result.name[2] = 'c';
    break;
  }

  return result;
}

void print_month(struct month this) {
  printf("%c%c%c: %i days",
	 this.name[0],
	 this.name[1],
	 this.name[2],
	 this.days);
}
