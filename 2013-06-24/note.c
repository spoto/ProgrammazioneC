#include <stdlib.h>
#include <stdio.h>
#include "note.h"

struct nota *construct_nota(int semitono) {
  struct nota *this = malloc(sizeof(struct nota));
  this->semitono = semitono;

  return this;
}

void destroy_nota(struct nota *this) {
  free(this);
}

void print_nota_it(struct nota *this) {
  static char *nomi[] = { "do", "do#", "re", "re#", "mi", "fa", "fa#",
			  "sol", "sol#", "la", "la#", "si" };

  printf("%s", nomi[this->semitono]);
}

void print_nota_uk(struct nota *this) {
  static char *nomi[] = { "C", "C#", "D", "D#", "E", "F", "F#",
			  "G", "G#", "A", "A#", "B" };

  printf("%s", nomi[this->semitono]);
}

void incrementa_nota(struct nota *this, int inc) {
  this->semitono = (this->semitono + inc) % 12;
}

struct nota *nota_incrementata(struct nota *this, int inc) {
  return construct_nota((this->semitono + inc) % 12);
}
