#include <stdio.h>

int main(void) {
  int a;
  int b;

  printf("inserisci a: ");
  scanf("%i", &a);

  printf("inserisci b: ");
  scanf("%i", &b);

  // operazione binaria di confronto
  // il risultato è un booleano
  printf("a<b:  %i\n", a < b);
  printf("a>b:  %i\n", a > b);
  printf("a<=b: %i\n", a <= b);
  printf("a>=b: %i\n", a >= b);
  printf("a==b: %i\n", a == b);
  printf("a!=b: %i\n", a != b);

  return 0;
}
