#include <stdio.h>
#include <ctype.h>
#include <string.h>

static int ordered(char c1, char c2) {
  if (isalpha(c1))
    return 1; // true
  else if (isalpha(c2))
    return 0; // false
  else if (isdigit(c1))
    return 1; // true
  else if (isdigit(c2))
    return 0; // false
  else
    return 1; // true
}

static int swap(char *s) {
  char temp;
  int swapped = 0; // falso

  while (*s && *(s + 1)) {
    if (!ordered(*s, *(s + 1))) {
      temp = *s;
      *s = *(s + 1);
      *(s + 1) = temp;
      swapped = 1; // vero
    }

    s++;
  }

  return swapped;
}

// il solito bubble sort!
void split(char *s) {
  while (swap(s));
}

int main(void) {
  char buffer[100];
  strcpy(buffer, "de80f?& HY(k,;;F849=");
  split(buffer);
  printf("%s\n", buffer);

  return 0;
}
