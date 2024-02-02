#include <stdio.h>

int main(void) {
  int size;

  do {
    printf("Inserisci la dimensione delle aste, positiva: ");
    scanf("%i", &size);
  }
  while (size <= 0);

  int x, y;
  for (y = 0; y < size; y++) {
    for (x = 0; x < size; x++)
      printf("%c", (x == 0 || y == 0 || x == y) ? '*' : ' ');

    printf("\n");
  }

  return 0;
}
