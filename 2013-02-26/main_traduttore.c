#include <stdio.h>
#include "traduttore.h"

int main(void) {
  struct traduttore *t = construct_traduttore();
  const char *valore;

  put(t, "ciao", "hello");
  put(t, "amico", "friend");
  put(t, "come", "how");
  put(t, "va", "goes");

  printf("%s\n", (valore = get(t, "ciao")) ? valore : "NULL");
  printf("%s\n", (valore = get(t, "amico")) ? valore : "NULL");
  printf("%s\n", (valore = get(t, "come")) ? valore : "NULL");
  printf("%s\n", (valore = get(t, "va")) ? valore : "NULL");
  printf("%s\n", (valore = get(t, "oggi")) ? valore : "NULL");
  printf("%s\n", (valore = get(t, "how")) ? valore : "NULL");

  destruct_traduttore(t);

  return 0;
}
