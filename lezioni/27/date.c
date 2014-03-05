#include <stdio.h>
#include "date.h"

// ritorna 0 se diverse, !=0 se uguali
int equals(struct date this, struct date that) {
  return this.day == that.day &&
    this.month == that.month &&
    this.year == that.year;
}

int compareTo(struct date this, struct date that) {
  int diff = this.year - that.year;
  if (diff != 0)
    return diff;

  // gli anni sono gli stessi
  diff = this.month - that.month;
  if (diff != 0)
    return diff;

  // gli anni e i mesi sono gli stessi
  return this.day - that.day;
}

int days_between(struct date this, struct date that) {
  if (compareTo(this, that) > 0) // viene prima that
    return days_between(that, this); // inverto

  int days1 = days_from_beginning(this);
  int days2 = days_from_beginning(that);

  if (this.year < that.year) {
    return 365 - days1 + days2
      + 365 * (that.year - this.year - 1);
  }
  else
    // qui sappiamo che hanno lo stesso anno
    return days2 - days1;
}

int days_from_beginning(struct date d) {
  int result = d.day;
  int cursor;

  static int days_per_month[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

  for (cursor = d.month - 1; cursor >= 1; cursor--)
    result += days_per_month[cursor - 1];

  return result;
}

struct date read_date(void) {
  struct date result;

  printf("day: ");
  scanf("%i", &result.day);

  printf("month: ");
  scanf("%i", &result.month);

  printf("year: ");
  scanf("%i", &result.year);

  return result;
}

void print_date(struct date d) {
  printf("%i/%i/%i\n", d.day, d.month, d.year);
}

// restituisce la data successiva di d
struct date next_date(struct date d) {
  struct date result;

  static int days_per_month[] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

  // siamo alla fine del mese?
  if (d.day == days_per_month[d.month - 1]) {
    // siamo alla fine dell'anno?
    if (d.month == 12) {
      result.day = result.month = 1;
      result.year = d.year + 1;
    }
    else {
      result.day = 1;
      result.month = d.month + 1;
      result.year = d.year;
    }
  }
  else {
    result.day = d.day + 1;
    result.month = d.month;
    result.year = d.year;
  }

  return result;
}
