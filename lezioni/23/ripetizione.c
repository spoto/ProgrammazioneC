#include <stdio.h>

// determina se un array contiene almeno due elementi uguali
int contiene_ripetizione(int array[], int size);
int main(void);

int contiene_ripetizione(int array[], int size) {
  int pos, pos2;

  for (pos = 0; pos < size - 1; pos++)
    for (pos2 = pos + 1; pos2 < size; pos2++)
      if (array[pos] == array[pos2])
	return 1; // vero

  return 0; // falso
}

int main(void) {
  int elementi[5] = { 8, 11, 9, 0, 9 };

  if (contiene_ripetizione(elementi, 5))
    printf("yes\n");
  else
    printf("no\n");

  return 0;
}
