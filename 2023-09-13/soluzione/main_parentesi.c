// codice gia' completo, non modificatelo

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "parentesi.h"

void print(char arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%c", arr[pos]);
}

void descrivi(char s[], int length) {
  print(s, length);

  if (struttura_di_parentesi(s, length))
    printf(" si'\n");
  else
    printf(" no\n");
}

int main(void) {
  srand(time(NULL));
  char s[20];

  for (int i = 0; i < 10; i++) {
    int length = (rand() % 10) * 2;
    init_random(s, length);
    descrivi(s, length);
  }

  init_random(s, 20);
  s[5] = ']'; // cosi' non e' piu' una struttura di parentesi
  descrivi(s, 20);

  return 0;
}
