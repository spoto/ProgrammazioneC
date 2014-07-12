#ifndef DATE_H
#define DATE_H

struct date {
  int day;
  int month;
  int year;
};

struct date *construct_date(int day, int month, int year);
struct date *construct_date_alt(int day, const char *month, int year);
void print_date(struct date *this);
int equals_date(struct date *this, struct date *that);
int compare_date(struct date *this, struct date *that);

#endif
