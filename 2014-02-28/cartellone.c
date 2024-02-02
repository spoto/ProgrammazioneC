#include <stdio.h>
#include <stdlib.h>
#include "cartellone.h"

struct cartellone *construct_cartellone(void) {
  struct cartellone *this = malloc(sizeof(struct cartellone));
  this->usati = 0;

  return this;
}

void destroy_cartellone(struct cartellone *this) {
  free(this);
}

void print_cartellone(struct cartellone *this) {
  int pos;
  for (pos = 0; pos < this->usati; pos++)
    printf("%4d - %s\n", this->numero_treno[pos], this->destinazione[pos]);
}

void aggiungi_treno(struct cartellone *this, int numero_treno, const char *destinazione) {
  if (this->usati < 8) {
    this->numero_treno[this->usati] = numero_treno;
    this->destinazione[this->usati++] = destinazione;
  }
}

void rimuovi_treno(struct cartellone *this) {
  int pos;

  for (pos = 0; pos < this->usati - 1; pos++) {
    this->numero_treno[pos] = this->numero_treno[pos + 1];
    this->destinazione[pos] = this->destinazione[pos + 1];
  }

  this->usati--;
}
