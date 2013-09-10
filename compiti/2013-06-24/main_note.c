#include <stdio.h>
#include "note.h"

int main(void) {
  struct nota *n1 = construct_nota(5);
  struct nota *n2 = construct_nota(11);
  struct nota *n3;

  printf("n1: "); print_nota_it(n1); printf(" ");
  print_nota_uk(n1); printf("\n");
  printf("n2: "); print_nota_it(n2); printf(" ");
  print_nota_uk(n2); printf("\n");

  incrementa_nota(n1, 11);
  n3 = nota_incrementata(n2, 23);

  printf("n1: "); print_nota_it(n1); printf(" ");
  print_nota_uk(n1); printf("\n");
  printf("n2: "); print_nota_it(n2); printf(" ");
  print_nota_uk(n2); printf("\n");
  printf("n3: "); print_nota_it(n3); printf(" ");
  print_nota_uk(n3); printf("\n");

  destroy_nota(n1); destroy_nota(n2); destroy_nota(n3);

  return 0;
}
