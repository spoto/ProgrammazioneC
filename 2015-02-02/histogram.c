#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *histo(int values[], int length) {
  int sum, i, c;
  for (i = sum = 0; i < length; i++)
    sum += values[i];

  char *s = malloc(81 * sizeof(char));
  static char *alternatives = "*@+#";

  int seen = *values++;
  int limit = seen * 80 / sum;
  for (i = c = 0; i < 80; i++) {
    if (i > limit) {
	c++;
	c %= strlen(alternatives);

	do {
	  seen += *values++;
	  limit = seen * 80 / sum;
	}
	while (i > limit);
    }

    s[i] = alternatives[c];
  }

  s[80] = '\0';

  return s;
}

int main(void) {
  int values[] = { 8, 12, 0, 3, 5 };

  char *s = histo(values, 5);
  printf("%s\n", s);
  free(s);

  return 0;
}

