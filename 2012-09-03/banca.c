#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "banca.h"

struct banca *construct_banca() {
  struct banca *this = malloc(sizeof(struct banca));
  int pos;

  for (pos = 0; pos < DIM; pos++) {
    this->nome[pos] = NULL;
    this->soldi[pos] = 0.0;
  }

  return this;
}

void destruct_banca(struct banca *this) {
  int pos;

  for (pos = 0; pos < DIM && this->nome[pos]; pos++)
    free(this->nome[pos]);

  free(this);
}

void deposita(struct banca *this, char *nome, double soldi) {
  // cerchiamo il nome, forse e' gia' correntista
  int pos;

  for (pos = 0; pos < DIM && this->nome[pos]; pos++)
    if (!strcmp(this->nome[pos], nome)) {
      this->soldi[pos] += soldi;
      return;
    }

  if (pos < DIM) {
    // c'e' spazio per aggiungerlo come nuovo correntista
    this->nome[pos] = malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(this->nome[pos], nome);

    this->soldi[pos] = soldi;
  }
}

void preleva(struct banca *this, char *nome, double soldi) {
  // cerchiamo il nome
  int pos;

  for (pos = 0; pos < DIM && this->nome[pos]; pos++)
    if (!strcmp(this->nome[pos], nome)) {
      this->soldi[pos] -= soldi;
      return;
    }  
}

char *toString(struct banca *this) {
  char *s = malloc(1000 * sizeof(char));
  char *start = s;

  int pos;
  for (pos = 0; pos < DIM && this->nome[pos]; pos++)
    s += sprintf(s, "%s: %f\n", this->nome[pos], this->soldi[pos]);

  *s = '\0';

  return start;
}

