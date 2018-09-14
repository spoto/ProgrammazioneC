#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "registro.h"

int main(void) {
	struct registro *r = construct_registro();
	aggiungi_punti(r, "Rossi", 112); aggiungi_punti(r, "Bianchi", 1023);
	aggiungi_punti(r, "Rossi", 13); aggiungi_punti(r, "Verdi", 11);
	int pos;
	for (pos = 0; pos < 10 && r->cognome[pos]; pos++)
		printf("%s: %f\n", r->cognome[pos], r->saldo_punti[pos]);
	printf("\n");
	bonus(r, 2.50);
	for (pos = 0; pos < 10 && r->cognome[pos]; pos++)
		printf("%s: %f\n", r->cognome[pos], r->saldo_punti[pos]);
	destruct_registro(r);
	return 0;
}


struct registro *construct_registro() {
  struct registro *r= malloc(sizeof(struct registro));
  int pos;

  for (pos = 0; pos < DIM; pos++) {
    r->cognome[pos] = NULL;
    r->saldo_punti[pos] = 0.0;
  }

  return r;
}

void destruct_registro(struct registro *this) {
  int pos;

  for (pos = 0; pos < DIM && this->cognome[pos]; pos++)
    free(this->cognome[pos]);

  free(this);
}

void aggiungi_punti(struct registro *this, char *cognome, int punti) {
  // cerchiamo il nome, forse e' gia' presente
  int pos;

  for (pos = 0; pos < DIM && this->cognome[pos]; pos++)
    if (!strcmp(this->cognome[pos], cognome)) {
      this->saldo_punti[pos] += (double) punti;
      return;
    }

  if (pos < DIM) {
    // c'e' spazio per aggiungerlo come nuovo cliente
    this->cognome[pos] = malloc((strlen(cognome) + 1) * sizeof(char));
    strcpy(this->cognome[pos], cognome);

    this->saldo_punti[pos] = (double) punti;
  }
}

void bonus(struct registro *this, double percent) {
  int pos;

  for (pos = 0; pos < DIM && this->cognome[pos]; pos++)
    this->saldo_punti[pos] = this->saldo_punti[pos] * (100 + percent) / 100;
}

// gcc registro.c -o registro
// ./registro



