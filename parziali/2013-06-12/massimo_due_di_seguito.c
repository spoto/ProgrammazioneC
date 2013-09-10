#include <stdio.h>
#include "list.h"

int al_massimo_due_di_seguito(const char *s) {
  while (*s) {
    if (*s == *(s + 1) && *s == *(s + 2))
      return 0; // falso

    s++;
  }

  return 1; // vero
}

int main(void) {
  char buffer[100];
  struct list *l;

  printf("Inserisci una frase: ");
  scanf("%s", buffer);

  if (al_massimo_due_di_seguito(buffer)) {
    printf("Non ci sono piu' di due lettere uguali di seguito\n");
    l = construct_list_from_string(buffer);
    print_list(l);
    printf("\n");
    l = doppie(l);
    print_list(l);
    printf("\n");
  }
  else
    printf("Ci sono piu' di due lettere uguali di seguito\n");

  return 0;
}
