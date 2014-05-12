#include <stdlib.h>

struct persona {
  char nome[20];
  int eta;
};

int main(void) {
  struct persona *p = NULL;
  int i, j;

  for (i = 0; i < 1000000; i++)
    for (j = 0; j < 100; j++) {
      if (p) // se non è NULL
	free(p);
      p = malloc(sizeof(struct persona));
    }

  return 0;
}
