#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(void) {
  struct list *l = construct_list
    (11, construct_list
     (-5, construct_list
      (7, construct_list
       (13, construct_list
	(17, construct_list
	 (19, construct_list
	  (-1, NULL)))))));

  printf("La lista originale: ");
  print_list(l);  // stampo la lista
  printf("\n");

  printf("I suoi elementi in posizione dispari: ");
  print_list(alterna(l, 0)); // poi stampo quelli in posizione dispari
  printf("\n");

  printf("I suoi elementi in posizione pari: ");
  print_list(alterna(l, 1)); // poi stampo quelli in posizione pari
  printf("\n");

  return 0;
}
