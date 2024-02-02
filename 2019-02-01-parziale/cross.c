#include <stdio.h>

int main(void) {
  int size;

  do {
    printf("Inserisci la dimensione delle aste, dispari e non negativa: ");
    scanf("%i", &size);
  }
  while (size < 0 || size % 2 == 0);

  int x, y;
  for (y = 0; y < size; y++) {
    for (x = 0; x < size; x++)
      printf("%c", (x == size / 2 || y == size / 2) ? '*' : ' ');

    printf("\n");
  }

  return 0;
}
