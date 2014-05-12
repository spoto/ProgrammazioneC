#include <stdlib.h>

struct persona {
  char nome[20];
  int eta;
};

int main(void) {
  struct persona *p = malloc(sizeof(struct persona));
  struct persona *q = p;

  free(q);

  // NO: scrive in una zona di memoria deallocata
  // p è un dangling pointer
  p->eta = 11;

  return 0;
}
