#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int palindroma(const char *s) {
  const char *left = s;
  const char *right = left + strlen(s) - 1;

  while (left < right)
    if (*left++ != *right--)
      return 0; // falso

  return 1; // vero	
}

void ruota_destra(char *s) {
  char *cursor = s + strlen(s) - 1;
  char last;

  if (strlen(s) > 0) {
    last = *cursor;

    while (cursor > s) {
      *cursor = *(cursor - 1);
      cursor--;
    }

    *cursor = last;
  }
}

char *ruota_destra2(const char *s) {
  char *risultato = malloc(sizeof(char) * (strlen(s) + 1));
  char *start = risultato;

  while (*s)
    if (!*(s + 1)) {
      // ultimo carattere
      *start = *s++;
      risultato++;
    }
    else
      *++risultato = *s++;

  *risultato = '\0';

  return start;
}

int main(void) {
  char s[100];
  char *temp;

  scanf("%s", s);

  printf("s = %s\n", s);
  printf("s = %s\n", temp = ruota_destra2(s));
  free(temp);

  return 0;
}
