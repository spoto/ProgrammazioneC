#include <stdlib.h>
#include "portata.h"

struct portata *construct_portata(const char *nome, int prezzo) {
  struct portata *this = malloc(sizeof(struct portata));
  this->nome = nome;
  this->prezzo = prezzo;

  return this;
}

void destroy_portata(struct portata *this) {
  free(this);
}
