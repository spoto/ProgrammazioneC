#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *somma_modulo_10(const char *s) {
  static char *cifre[] = {
    "zero", "uno", "due", "tre", "quattro", "cinque", "sei", "sette", "otto", "nove"
  };
  char *res;

  int somma = 0;
  while (*s) {
    if (isdigit(*s))
      somma += *s - '0';

    s++;
  }

  somma %= 10;
  res = malloc((strlen(cifre[somma]) + 1) * sizeof(char));
  strcpy(res, cifre[somma]);

  return res;
}

int main(void) {
  char buffer[101];
  char *s;

  scanf("%100s", buffer);
  printf("somma delle cifre modulo dieci = %s\n", s = somma_modulo_10(buffer));
  free(s);

  return 0;
}

