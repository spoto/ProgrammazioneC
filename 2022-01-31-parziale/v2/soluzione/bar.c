#include <stdio.h>

// funzione ricorsiva che stampa i caratteri alfabetici crescenti
// dalla lettera c alla lettera 'z' e poi da 'z' indietro fino alla lettera c
void bar(char c) {
  // si dia per scontato che c sia un carattere fra 'a' e 'z' inclusi
  if (c <= 'z') {
    printf("%c", c);
    bar(c + 1);
    printf("%c", c);
  }
}

int main(void) {
  char c;

  do {
    printf("Inserisci un carattere alfabetico minuscolo: ");
    scanf(" %c", &c);
  }
  while (c < 'a' || c > 'z');

  bar(c);
  printf("\n");

  return 0;
}
