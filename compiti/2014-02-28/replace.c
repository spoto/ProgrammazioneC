#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int resulting_size(const char *where, const char *what) {
  int size = 0;

  while (*where)
    if (*where++ == '$')
      size += strlen(what);
    else
      size++;

  return size + 1;
}

char *replace(const char *where, const char *what) {
  char *cursor;
  char *result = cursor = malloc(resulting_size(where, what) * sizeof(char));

  do {
    if (*where == '$') {
      strcpy(cursor, what);
      cursor += strlen(what);
    }
    else
      *cursor++ = *where;
  }
  while (*where++);

  return result;
}

int main(void) {
  const char *s = "ciao $$ amico $";

  char *r = replace(s, "caro");

  printf("%s\n", r);

  free(r);

  return 0;
}
