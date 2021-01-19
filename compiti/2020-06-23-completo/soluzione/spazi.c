#include <stdio.h>

int spazi(char arr[], int length) {
  for (int pos1 = 0; pos1 < length - 1; pos1++) {
    char c = arr[pos1];
    for (int pos2 = pos1 + 1; pos2 < length; pos2++)
      if (c == arr[pos2])
	arr[pos1] = arr[pos2] = ' ';
  }

  int risultato = 0;
  for (int pos = 0; pos < length; pos++)
    if (arr[pos] == ' ')
      risultato++;

  return risultato;
}

int main(void) {
  char x[] = { 'f', 'y', 'F', 'Y', 'y', 'd', '@', 'y', 'o', '3', '@' };

  int quanti = spazi(x, 11);

  for (int pos = 0; pos < 11; pos++)
    printf("%c", x[pos]);

  printf("\nquanti = %d\n", quanti);

  return 0;
}
