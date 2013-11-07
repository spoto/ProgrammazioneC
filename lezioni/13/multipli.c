#include <stdio.h>

int main(void) {
  int n;
  int m;

  // leggi m ed n devono essere
  // uno multiplo dell'altro o viceversa
  do {
    printf("inserisci n: ");
    scanf("%i", &n);

    printf("inserisci m: ");
    scanf("%i", &m);
  }
  while (!(n != 0 && m != 0 &&
	   (n % m == 0 || m % n == 0)));

  if (m >= n) {
    printf("Il massimo e' %i\n", m);
    printf("il minimo e' %i\n", n);
  }
  else {
    printf("Il massimo e' %i\n", n);
    printf("Il minimo e' %i\n", m);
  }

  printf("La media e' %f\n", (m + n) / 2.0);

  return 0;
}
