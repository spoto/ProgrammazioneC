#ifndef CONTO_H
#define CONTO_H

#include "portata.h"

struct conto {
  int numero_portate;
  struct portata *portate;
};

struct conto *construct_conto(struct portata *portate[], int numero_portate);
void destroy_conto(struct conto *this);
void print_conto(struct conto *this);

#endif
