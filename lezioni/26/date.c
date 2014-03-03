#include <stdio.h>

struct date {
  int day;
  int month;
  int year;
};

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
  printf("%i/%i/%i\n",
	 d.day, d.month, d.year);
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

int main(void) {
  struct date d;
  struct date next;

  d = read_date();
  next = next_date(d);
  print_date(next);

  return 0;
}
