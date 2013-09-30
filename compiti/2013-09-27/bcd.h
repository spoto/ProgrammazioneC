#ifndef BCD_H
#define BCD_H

struct bcd {
  int decimal;
};

struct bcd *construct_bcd(int decimal);
void destroy_bcd(struct bcd *this);
void print_as_decimal(struct bcd *this);
void print_as_binary_string(struct bcd *this);
void print_as_list(struct bcd *this);

#endif
