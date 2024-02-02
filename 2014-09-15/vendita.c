#include <stdlib.h>
#include <stdio.h>
#include "vendita.h"
#include "casa.h"

struct vendita *construct_vendita(struct casa* casa, int prezzo) {
  struct vendita *this = malloc(sizeof(struct vendita));

  this->casa = casa;
  this->prezzo = prezzo;

  return this;
}

void destroy_vendita(struct vendita *this) {
  free(this);
}

double prezzo_m2(struct vendita *this) {
  return this->prezzo / metratura_commerciale(this->casa);
}
