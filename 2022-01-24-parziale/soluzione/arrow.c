#include <stdio.h>

void arrow(int size) {
  if (size == 1)
    printf("* *\n");
  else {
    // prima riga
    int spazi = (size - 1) / 2;
    for (int i = 1; i <= spazi; i++)
      printf(" ");
    printf("* *\n");

    // righe interne    
    arrow(size - 2);
    
    // ultima riga
    for (int i = 1; i <= spazi; i++)
      printf(" ");
    printf("* *\n");
  }
}

int main(void) {
  int size;
  do {
    printf("size: ");
    scanf("%i", &size);
  }
  while (size < 0 || size % 2 == 0);

  arrow(size);
   
  return 0;
}
