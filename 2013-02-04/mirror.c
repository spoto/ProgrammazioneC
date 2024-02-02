#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *mirror(const char *s) {
  // la lunghezza del risultato, incluso lo \0 finale
  int length = !*s ? 1 : (strlen(s) * 2);

  char *res = malloc(length * sizeof(char));
  char *left = res, *right = res + length - 1;

  // scriviamo lo \0 finale
  *right-- = '\0';

  while (*s)
    *left++ = *right-- = *s++;

  return res;
}

int main(void) {
  char *buffer;

  printf("%s\n", buffer = mirror("ciao"));
  free(buffer);

  printf("%s\n", buffer = mirror("che bella giornata!"));
  free(buffer);

  printf("%s\n", buffer = mirror(""));
  free(buffer);

  return 0;
}
