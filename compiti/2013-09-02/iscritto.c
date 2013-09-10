#include <stdlib.h>
#include <stdio.h>
#include "iscritto.h"

struct iscritto *construct_iscritto(const char *nome, const char *cognome, int matricola) {
  struct iscritto *this = malloc(sizeof(struct iscritto));

  this->nome = nome;
  this->cognome = cognome;
  this->matricola = matricola;
  this->voto = -1;

  return this;
}

void destroy_iscritto(struct iscritto *this) {
  free(this);
}

void print_iscritto(struct iscritto *this) {
  printf("%10s %10s   (VR%i)\t\t", this->nome, this->cognome, this->matricola);

  if (this->voto >= 18)
    printf("%i", this->voto);
  else if (this->voto >= 0)
    printf("insufficiente");
  else
    printf("assente");
}
