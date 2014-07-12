#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int count_spaces(const char *s) {
  int count = 0;

  while (*s)
    if (*s++ == ' ')
      count++;

  return count;
}

char *camelize(const char *s) {
  char *res = malloc((strlen(s) - count_spaces(s)  + 1) * sizeof(char));
  char *start = res;

  while (*s) {
    if (*s == ' ')
      *res++ = *++s - ('a' - 'A');
    else
      *res++ = *s;

    s++;
  }

  *res = '\0';

  return start;
}

int main(void) {
  char *s;

  printf("%s\n", s = camelize("camels are sweet and clever animals"));
  free(s);

  return 0;
}
