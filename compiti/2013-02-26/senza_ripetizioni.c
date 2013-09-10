#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// determina se il carattere c e' ripetuto
// almeno due volte dentro s
static int ripetuto(char c, const char *s) {
  int ripetizioni = 0;

  while (*s)
    if (*s++ == c)
      if (++ripetizioni > 1)
	return 1; // vero

  return 0; // falso
}

static int lunghezza_risultato(const char *s) {
  int res = strlen(s);
  const char *cursor = s;

  while (*cursor)
    if (ripetuto(*cursor++, s))
      res--;

  return res;
}

char *senza_ripetizioni(const char *s) {
  char *res = malloc(sizeof(char) * (lunghezza_risultato(s) + 1));
  char *start = res;
  const char *cursor = s;

  while (*cursor) {
    if (!ripetuto(*cursor, s))
      *res++ = *cursor;

    cursor++;
  }

  *res = '\0';

  return start;
}

int main(void) {
  char *buffer;

  printf("%s\n", buffer = senza_ripetizioni("ciao amico"));
  free(buffer);

  printf("%s\n", buffer = senza_ripetizioni("ciao amico come va?"));
  free(buffer);

  printf("%s\n", buffer = senza_ripetizioni("precipitevolissimevolmente"));
  free(buffer);

  return 0;
}
