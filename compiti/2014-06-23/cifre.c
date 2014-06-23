#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *cifra[] = {
  "zero", "uno", "due", "tre", "quattro",
  "cinque", "sei", "sette", "otto", "nove"
};

static int lunghezza_in_italiano(const char *s) {
  // contiamo lo \0 finale
  int len = 1;

  if (*s) {
    len += strlen(cifra[*s++ - '0']);    

    // dalla seconda cifra in poi contiamo lo spazio
    while (*s)
      len += strlen(cifra[*s++ - '0']) + 1;
  }

  return len;
}

char *cifre(const char *s) {
  int len = lunghezza_in_italiano(s);
  char *res = malloc((len + 1) * sizeof(char));
  *res = '\0';

  if (*s) {
    sprintf(res, "%s", cifra[*s++ - '0']);

    // dalla seconda cifra in poi mettiamo uno spazio
    while (*s)
      sprintf(res, "%s %s", res, cifra[*s++ - '0']);
  }

  return res;
}

int main(void) {
  char *temp;

  printf("%s\n", temp = cifre("1234")); free(temp);
  printf("%s\n", temp = cifre("034091")); free(temp);
  printf("%s\n", temp = cifre("")); free(temp);
  printf("%s\n", temp = cifre("9")); free(temp);

  return 0;
}
