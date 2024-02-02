#include <stdio.h>
#include "conto.h"
#include "portata.h"

int main(void) {
  struct portata *p1 = construct_portata("risotto agli asparagu", 10);
  struct portata *p2 = construct_portata("pasta alla carbonara", 6);
  struct portata *p3 = construct_portata("vitello tonnato", 12);
  struct portata *p4 = construct_portata("frutta fresca", 9);
  struct portata *p5 = construct_portata("macedonia di frutta", 7);
  struct portata *p6 = construct_portata("tiramisu", 5);
  struct portata *p7 = construct_portata("acqua naturale", 4);
  struct portata *p8 = construct_portata("caffe espresso", 2);

  struct portata *cliente1[] = { p1, p3, p4, p7, p7, p8 };
  struct portata *cliente2[] = { p2, p3, p5, p6, p7, p8, p8 };

  struct conto *conto1 = construct_conto(cliente1, 6);
  struct conto *conto2 = construct_conto(cliente2, 7);

  print_conto(conto1);
  printf("\n");
  print_conto(conto2);

  destroy_conto(conto2);
  destroy_conto(conto1);
  destroy_portata(p8);
  destroy_portata(p7);
  destroy_portata(p6);
  destroy_portata(p5);
  destroy_portata(p4);
  destroy_portata(p3);
  destroy_portata(p2);
  destroy_portata(p1);

  return 0;
}
