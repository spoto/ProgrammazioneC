#include <stdio.h>

int main(void) {
  int u, v, temp;

  printf("Inserisci u: ");
  scanf("%i", &u);

  printf("Inserisci v: ");
  scanf("%i", &v);

  printf("L'MCD di %i e %i e' ", u, v);

  while (v != 0) {
    temp = u % v;
    u = v;
    v = temp;
  }

  // stessa cosa ma con il for
  /* for ( ; v != 0; ) {
    temp = u % v;
    u = v;
    v = temp;
    }*/

  printf("%i\n", u);

  return 0;
}
