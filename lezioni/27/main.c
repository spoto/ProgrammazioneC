#include <stdio.h>
#include "date.h"

int main(void) {
  struct date d1, d2;

  printf("Inserisci la prima data:\n");
  d1 = read_date();

  printf("Inserisci la seconda data:\n");
  d2 = read_date();

  if (equals(d1, d2))
    printf("Sono la stessa data\n");
  else
    printf("Sono date diverse\n");

  if (compareTo(d1, d2) < 0) {
    printf("viene prima ");
    print_date(d1);
  }
  else if (compareTo(d1, d2) > 0) {
    printf("viene prima ");
    print_date(d2);
  }
  else
    printf("sono uguali");

  printf("\n");

  printf("Tra le due date si sono %i giorni\n",
	 days_between(d1, d2));

  return 0;
}
