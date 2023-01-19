#include <stdio.h>

void triangular(char c, int i) {
  if (i > 0) {
    for (int x = 0; x < i; x++)
      printf("%c", c);
    
    triangular(c + 1, i - 1);
  }
}

int main(void) {
  triangular('d', 5);
  printf("\n");
  triangular('g', 8);
  printf("\n");
  return 0;
}
