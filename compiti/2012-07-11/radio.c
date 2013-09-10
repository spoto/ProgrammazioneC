#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "radio.h"

struct radio *construct_radio() {
  struct radio *this = malloc(sizeof(struct radio));
  int i;

  for (i = 0; i < DIM; i++)
    this->nome_dei_canali[i] = NULL;

  sintonizza_su(this, 0);

  return this;
}

void destruct_radio(struct radio * this) {
  free(this);
}

void memorizza_canale(struct radio *this, int numero, char *nome, float frequenza) {
  this->nome_dei_canali[numero] = nome;
  this->frequenza_dei_canali[numero] = frequenza;
}

void sintonizza_su(struct radio *this, int numero) {
  this->canale_sintonizzato = numero;
}

char *toString(struct radio *this) {
  char *nome_canale = this->nome_dei_canali[this->canale_sintonizzato];
  char *res;

  if (!nome_canale) {
    res = malloc(sizeof(char) * 23);
    sprintf(res, "canale non memorizzato");
  }
  else {
    res = malloc(sizeof(char) * (strlen(nome_canale) + 100));
    sprintf(res, "%s: frequenza %.1f", nome_canale, this->frequenza_dei_canali[this->canale_sintonizzato]);
  }

  return res;
}

