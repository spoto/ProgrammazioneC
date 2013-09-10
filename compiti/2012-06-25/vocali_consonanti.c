#include <stdio.h>
#include <ctype.h>

void vocali_consonanti(char *s);
static int swap(char * s);
static int vocale(char c);

int main(void) {
  char s[100];

  printf("inserisci la stringa: ");
  scanf("%s", s);

  printf("prima: %s\n", s);

  vocali_consonanti(s);

  printf("dopo: %s\n", s);

  return 0;
}

void vocali_consonanti(char *s) {
  while (swap(s));
}

// cerca una consonante seguita da una vocale e le scambia di posto
// ritorna vero se e solo ha fatto almeno uno scambio
static int swap(char *s) {
  int scambio = 0; // falso
  char temp;

  while (*s && *(s + 1)) {
    if (!vocale(*s) && vocale(*(s + 1))) {
      temp = *s;
      *s = *(s + 1);
      *(s + 1) = temp;
      scambio = 1; // vero
    }

    s++;
  }

  return scambio;
}

// controlla se c e' una vocale, minuscola o maiuscola
static int vocale(char c) {
  return (c = tolower(c)) == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
