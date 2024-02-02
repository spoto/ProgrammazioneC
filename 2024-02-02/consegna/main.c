#include <stdlib.h>
#include <time.h>
#include "cifre.h"

int main(void) {
  srand(time(NULL));
  char s[31];
  init(s, 30);
  struct list *l = create_list(s);
  print_list(l);
  free_list(l);
  l = create_list2(s);
  print_list(l);
  free_list2(l);

  return 0;
}
