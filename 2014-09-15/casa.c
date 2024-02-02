#include <stdlib.h>
#include "casa.h"

struct casa *construct_casa(int metratura_casa, int metratura_terrazzi, int metratura_garage) {
  struct casa *this = malloc(sizeof(struct casa));

  this->metratura_casa = metratura_casa;
  this->metratura_terrazzi = metratura_terrazzi;
  this->metratura_garage = metratura_garage;

  return this;
}

void destroy_casa(struct casa *this) {
  free(this);
}

double metratura_commerciale(struct casa *this) {
  return this->metratura_casa + this->metratura_terrazzi * 0.7 + this->metratura_garage * 0.5;
}

