#include <stdio.h>
#include <stdlib.h>
#include "sentence.h"

int main(void) {
  char *words[] = { "Nel", "mezzo", "del", "cammin", "di", "nostra", "vita" };

  struct sentence *s = construct_sentence(words, 7);
  printf("La lunghezza della frase e' %i\n", length_sentence(s));
  char *concat = concat_sentence(s);
  printf("La sua concatenazione e' \"%s\"\n", concat);
  free(concat);
  concat = inverse_concat_sentence(s);
  printf("La sua concatenazione inversa e' \"%s\"\n", concat);
  free(concat);
  free_sentence(s);

  return 0;
}
