#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int valida(const char *s) {
  return !*s ||
    (isdigit(*s) && *(s + 1) && !isdigit(*(s + 1)) && valida(s + 2));
}

static int somma(const char *s) {
  int risultato = 0;

  while (*s) {
    risultato += *s - '0';
    s += 2;
  }

  return risultato;
}

char *espandi(const char *s) {
  char *res, *start;
  int i;

  if (!valida(s))
    return NULL;

  start = res = malloc((somma(s) + 1) * sizeof(char));

  while (*s) {
    i = 0;
    while (i++ < (*s - '0'))
      *res++ = *(s + 1);

    s += 2;
  }

  *res = '\0';

  return start;
}

int main(void) {
  char buffer[100];
  char *res;

  scanf("%s", buffer);
  res = espandi(buffer);

  if (res) {
    printf("%s\n", res);
    free(res);
  }
  else
    printf("formato errato\n");

  return 0;
}
