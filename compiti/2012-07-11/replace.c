#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(const char *s, const char *old, const char *new);

int main(void) {
  const char *x = "ciao, come stai?";

  char *r = replace(x, "come stai", "how are you");
  printf("%s\n", r);
  free(r);

  r = replace(x, "a", "e");
  printf("%s\n", r);
  free(r);

  r = replace(x, "", "_inizio_");
  printf("%s\n", r);
  free(r);

  r = replace(x, "hello", "ciao");
  printf("%s\n", r);
  free(r);

  return 0;
}

char *replace(const char *s, const char *old, const char *new) {
  int length_of_old = strlen(old);
  char *cursor = malloc(sizeof(char) * (strlen(s) + strlen(new) - length_of_old + 1));
  char *start = cursor;

  // scandiamo la stringa originaria, da sinistra a destra
  while (*s)
    if (strlen(s) >= length_of_old && !strncmp(s, old, length_of_old)) {
      // abbiamo trovato la prima occorrenza di old dentro s
      cursor += sprintf(cursor, "%s%s", new, s + length_of_old);
      break;
    }
    else
      // altrimenti copiamo il carattere, identico
      *cursor++ = *s++;

  *cursor = '\0';

  return start;
}
