#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(void) {
  struct list *l = construct_list
    (5, construct_list
     (5, construct_list
      (8, NULL)));

  printf("La lista ");
  list_print(l);
  printf(" è lunga %i\n", list_length(l));
  printf("Il massimo dei suoi elementi è %i\n",
	 list_max(l));
  printf("La somma dei suoi elementi è %i\n",
	 list_sum(l));
  printf("Tale lista %sè non decrescente\n",
	 list_is_non_decreasing(l) ? "" : "non ");
  printf("Il suo primo elemento è %i\n", list_get_first(l));
  printf("Il suo ultimo elemento è %i\n", list_get_last(l));
  printf("Dopo avere incrementato i suoi elementi ottengo ");
  list_increment(l);
  list_print(l);
  printf("\n");
  printf("Dopo avere sommato a ogni elemento queli che lo seguono ottengo ");
  list_add_followers(l);
  list_print(l);
  printf("\n");
  printf("La media degli elementi è %f\n", list_mean(l));

  return 0;
}
