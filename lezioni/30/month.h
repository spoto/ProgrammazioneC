#ifndef MONTH_H
#define MONTH_H

struct month {
  int days;
  char name[3];
};

struct month construct_month(int num, int year);
void print_month(struct month this);

#endif
