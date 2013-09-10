#include <stdlib.h>
#include <stdio.h>
#include "snake.h"

int main(void) {
  struct snake *sn = construct_snake();
  char *s;

  printf("%s\n", s = toString(sn));
  free(s);

  goLeft(sn);
  goLeft(sn);
  goLeft(sn);
  goUp(sn);
  goUp(sn);

  printf("%s\n", s = toString(sn));
  free(s);

  goRight(sn);
  goRight(sn);
  goDown(sn);

  printf("%s\n", s = toString(sn));
  free(s);

  printf("ultima mossa eseguita: %d\n", goDown(sn));

  destruct_snake(sn);

  return 0;
}
