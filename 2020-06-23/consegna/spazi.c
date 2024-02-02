#include <stdio.h>

int spazi(char arr[], int length) {
  // da completare
}

int main(void) {
  char x[] = { 'f', 'y', 'F', 'Y', 'y', 'd', '@', 'y', 'o', '3', '@' };

  int quanti = spazi(x, 11);

  for (int pos = 0; pos < 11; pos++)
    printf("%c", x[pos]);

  printf("\nquanti = %d\n", quanti);

  return 0;
}
