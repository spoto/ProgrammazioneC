#include <stdio.h>
#include <stdlib.h>

static int size(int values[], int length) {
  int result = 0;
  int pos;

  for (pos = 0; pos < length; pos++)
    result += values[pos] + 1;

  return result + 1;
}

char *histo(int values[], int length) {
  int pos, counter;

  char *s = malloc(size(values, length) * sizeof(char));
  char *result = s;

  for (pos = 0; pos < length; pos++) {
    for (counter = values[pos]; counter > 0; counter--)
      *s++ = '*';

    *s++ = '\n';
  }

  *s = '\0';

  return result;
}

int main(void) {
  int values[] = { 3, 8, 0, 1, 5 };

  char *s = histo(values, 5);
  printf("%s", s);
  free(s);

  return 0;
}

