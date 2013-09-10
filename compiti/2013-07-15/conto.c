#include <stdlib.h>
#include <stdio.h>
#include "conto.h"

struct conto *construct_conto(struct portata *portate[], int numero_portate) {
  struct conto *this = malloc(sizeof(struct conto));
  this->portate = malloc(sizeof(struct portata) * numero_portate);
  int pos;

  this->numero_portate = numero_portate;
  for (pos = 0; pos < numero_portate; pos++)
    this->portate[pos] = *portate[pos];

  return this;
}

void destroy_conto(struct conto *this) {
  free(this->portate);
  free(this);
}

void print_conto(struct conto *this) {
  struct portata *p;
  int costo = 0;
  int pos;

  printf("\t\tTRATTORIA DA NONNA PAPERA\n\n");

  for (pos = 0; pos < this->numero_portate; pos++) {
    p = &this->portate[pos];
    printf("%30s      %3i euro\n", p->nome, p->prezzo);
    costo += p->prezzo;
  }

  // aggiungiamo il coperto
  printf("%30s      %3i euro\n", "coperto", 2);
  costo += 2;

  printf("\t\t-------------------------\n");
  printf("%30s      %i euro\n", "TOTALE", costo);
  printf("%30s      %.2f euro\n", "IVA 21%", costo * 0.21);
  printf("\t\t-------------------------\n");
  printf("%30s      %.2f euro\n", "TOTALE A PAGARE", costo * 1.21);
}
