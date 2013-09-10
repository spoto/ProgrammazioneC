#include <stdio.h>

int max(int n, int m) {
  return n >= m ? n : m;
}

int cifra_massima(int num) {
  if (num >= 10)
    return max(cifra_massima(num / 10), num % 10);
  else
    return num % 10;
}

int main(void) {
  int n;

  do {
    printf("Inserisci un numero non negativo: ");
    scanf("%i", &n);
  }
  while (n < 0);

  printf("La cifra massima di %i e' %i\n", n, cifra_massima(n));

  return 0;
}
