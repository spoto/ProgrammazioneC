#include <stdio.h>

/* legge una riga e la memorizza
   in s */
void read_line(char s[]) {
  int c;
  int pos = 0;

  do {
    c = getchar();
    if (c != '\n')
      s[pos++] = c;
    else
      s[pos++] = '\0';
  }
  while (c != '\n');
}

int is_alphabetical(char c) {
  return (c >= 'a' && c <= 'z') ||
    (c >= 'A' && c <= 'Z');
}

/* conta quante parole ci sono
   dentro s */
int count_words(const char s[]) {
  int waiting_for_word = 1; // vero
  int count = 0;
  int pos;

  for (pos = 0; s[pos] != '\0'; pos++)
    if (waiting_for_word &&
	is_alphabetical(s[pos])) {
      waiting_for_word = 0; // falso
      count++;
    }
    else if (!waiting_for_word &&
	     !is_alphabetical(s[pos]))
      waiting_for_word = 1; // true

  return count;
}

int main(void) {
  char s[100];

  read_line(s);
  printf("%s\n", s);
  printf("contiene %i parole\n", count_words(s));

  return 0;
}
