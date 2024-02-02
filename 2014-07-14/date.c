#include <stdlib.h>
#include <stdio.h>
#include "date.h"

static const char *months[] = {
  "gennaio", "febbraio", "marzo", "aprile",
  "maggio", "giugno", "luglio", "agosto",
  "settembre", "ottobre", "novembre", "dicembre"
};

static int is_leap_year(int year) {
  return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

struct date *construct_date(int day, int month, int year) {
  static int days[] = {
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
  };

  int max_day;

  if (day < 1 || month < 1 || month > 12)
    return NULL;

  max_day = (month == 2 && is_leap_year(year)) ? 29 : days[month];

  if (day > max_day)
    return NULL;

  struct date *this = malloc(sizeof(struct date));
  this->day = day;
  this->month = month;
  this->year = year;

  return this;
}

static int get_month_from_name(const char *name) {
  int month;

  for (month = 1; month <= 12; month++)
    if (!strcmp(months[month - 1], name))
	return month;

  return -1; // non trovato
}

struct date *construct_date_alt(int day, const char *month, int year) {
  return construct_date(day, get_month_from_name(month), year);
}

void print_date(struct date *this) {
  printf("%i %s %i", this->day, months[this->month - 1], this->year);
}

int equals_date(struct date *this, struct date *that) {
  return this->day == that->day &&
    this->month == that->month &&
    this->year == that->year;
}

int compare_date(struct date *this, struct date *that) {
  int diff = this->year - that->year;
  if (diff)
    return diff;
  else if (diff = this->month - that->month)
    return diff;
  else
    return this->day - that->day;
}

