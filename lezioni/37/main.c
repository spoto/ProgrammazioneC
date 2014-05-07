#include <stdlib.h>
#include "list.h"

int main(void) {
  struct list n1, n2, n3, n4, x;

  n1.head = 8;
  n2.head = -3;
  n3.head = 8;
  n4.head = 12;

  n1.tail = &n2;
  n2.tail = &n3;
  n3.tail = &n4;
  n4.tail = NULL;

  print_list(&n1);
  print_list(&n2);
  print_list(&n3);
  print_list(&n4);
  print_list(NULL);

  x.head = 5;
  x.tail = &n3;
  n2.tail = &x;

  print_list(&n1);
  print_list(&n2);
  print_list(&n3);
  print_list(&n4);
  print_list(NULL);

  n1.tail = &n3;

  print_list(&n1);
  print_list(&n2);
  print_list(&n3);
  print_list(&n4);
  print_list(NULL);

  //n4.tail = &n3; // crea un ciclo

  return 0;
}
