#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *s, char c, char *replacement);

int main(void) {
  char *s = "ciao amico";
  char *risultato;

  printf("%s\n", risultato = replace(s, 'a', "hello"));
  free(risultato);

  printf("%s\n", risultato = replace(s, 'u', "hello"));
  free(risultato);

  // si noti: il terminatore \0 non e' un carattere della stringa!
  printf("%s\n", risultato = replace(s, '\0', "hello"));
  free(risultato);

  return 0;
}

// conta quante volte c si trova dentro where
static int occurrences(char *where, char c) {
  int count = 0;

  while (*where)
    if (*where++ == c)
      count++;

  return count;
}

char *replace(char *s, char c, char *replacement) {
  // capiamo quanto e' grande la stringa risultato
  int len = strlen(s) + occurrences(s, c) * (strlen(replacement) - 1) + 1;
 
  // creiamo il risultato
  char *risultato = malloc(len * sizeof(char));
  *risultato = '\0';

  // copiamo la vecchia stringa nel risultato, rimpiazzando c con replacement
  do {
    if (*s && *s == c)
      strcat(risultato, replacement);
    else
      sprintf(risultato, "%s%c", risultato, *s);
  }
  while (*s++);

  // ritorniamo il risultato
  return risultato;
}

