#include <stdio.h>


// dichiarazione della funzione gcd
// u ed v sono parametri formali della funzione
// di tipo intero
void gcd(int u, int v) {
  int temp;

  printf("Il gcd di %i e %i e' ", u, v);

  while (v != 0) {
    temp = u % v;
    u = v;
    v = temp;
  }

  printf("%d\n", u);
}

int main(void) {
  int v, w;

  printf("v: ");
  scanf("%i", &v);

  printf("w: ");
  scanf("%i", &w);

  // invocazione o chiamata della funzione gcd
  // con parametri attuali (espressioni) 10 e 15
  gcd(v, w);

  return 0;
}
