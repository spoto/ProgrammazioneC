#include <stdio.h>

int main(void) {
  int numero;
  int divisore;
  int primo = 1; // 1 = vero

  printf("Inserisci il numero: ");
  scanf("%i", &numero);

  for (divisore = 2; divisore < numero; divisore++)
    if (numero % divisore == 0) { // lo divide
      primo = 0; // 0 = falso
      break;
    }

  if (primo)
    printf("%i e' un numero primo\n", numero);
  else
    printf("%i non e' un numero primo\n", numero);

  return 0;
}
