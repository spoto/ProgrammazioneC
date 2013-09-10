#include <stdio.h>
#include "television.h"

int main(void) {
  const char *names[] = {
    "raggi zero",
    "canale uno",
    "sei sul due"
  };

  struct television *t = construct_television(names, 3);

  printf("inizio:            %s\n", toString(t));
  set_channel(t, 2);
  printf("set_channel(t, 2): %s\n", toString(t));
  set_channel(t, 1);
  printf("set_channel(t, 1): %s\n", toString(t));
  set_channel(t, 2);
  printf("set_channel(t, 2): %s\n", toString(t));
  undo(t);
  printf("undo(t):           %s\n", toString(t));
  undo(t);
  printf("undo(t):           %s\n", toString(t));
  undo(t);
  printf("undo(t):           %s\n", toString(t));
  undo(t);
  printf("undo(t):           %s\n", toString(t));
  set_channel(t, 2);
  printf("set_channel(t, 2): %s\n", toString(t));
  undo(t);
  printf("undo(t):           %s\n", toString(t));

  destruct_television(t);

  return 0;
}
