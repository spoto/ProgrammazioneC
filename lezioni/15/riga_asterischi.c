#include <stdio.h>

int main(void) {
  int lunghezza1, lunghezza2;
  int pos;

  printf("lunghezza1: ");
  scanf("%i", &lunghezza1);
  printf("lunghezza2: ");
  scanf("%i", &lunghezza2);

  for (pos = 1; pos <= 80; pos++)
    printf("%c", ( (pos <= lunghezza1) ? '*' :
		   ( (pos <= lunghezza1 + lunghezza2) ? '&' : '$') ) );

  printf("\n");

  return 0;
}
