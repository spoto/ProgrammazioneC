#include <stdio.h>

int included(const char *where, const char *what) {
  if (!*what)
    return 1; // true

  if (!*where)
    return 0; // false

  if (*what == *where)
    return included(where + 1, what + 1);
  else
    return included(where + 1, what);
}

int main(void) {
  const char *s = "Major Tom to Ground Control";

  printf("%i\n", included(s, "jomo"));
  printf("%i\n", included(s, "Tootro"));
  printf("%i\n", included(s, "troll"));
  printf("%i\n", included(s, ""));
  printf("%i\n", included("", "troll"));

  return 0;
}
