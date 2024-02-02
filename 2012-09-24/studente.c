#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "studente.h"

struct studente *construct_studente(char *nome) {
  struct studente *this = malloc(sizeof(struct studente));

  this->nome = nome;
  this->num_esami = 0;
  this->somma_voti = 0;

  return this;
}

void destruct_studente(struct studente *this) {
  free(this);
}

void fa_esame(struct studente *this, int voto) {
  if (voto >= 18 && voto <= 30) {
    this->num_esami++;
    this->somma_voti += voto;
  }
}

float media(struct studente *this) {
  if (this->num_esami == 0)
    return 0.0f;
  else
    return this->somma_voti / (float) this->num_esami;
}

char *toString(struct studente *this) {
  char *res = malloc(strlen(this->nome) + 100);
  *res = '\0';

  sprintf(res, "%s %6.2f", this->nome, media(this));

  return res;
}

