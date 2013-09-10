#include <stdlib.h>
#include <stdio.h>
#include "appello.h"
#include "iscritto.h"

struct appello *construct_appello() {
  struct appello *this = malloc(sizeof(struct appello));
  this->iscritti = NULL;

  return this;
}

void destroy_appello(struct appello *this) {
  if (this->iscritti)
    destroy_list(this->iscritti);

  free(this);
}

void iscrivi(struct appello *this, struct iscritto *studente) {
  this->iscritti = construct_list(studente, this->iscritti);
}

void registra_voto(struct appello *this, int matricola, int voto) {
  struct list *iscritti = this->iscritti;
  while (iscritti) {
    if (iscritti->head->matricola == matricola) {
      iscritti->head->voto = voto;
      return;
    }

    iscritti = iscritti->tail;
  }
}

void print_appello(struct appello *this) {
  struct list *iscritti = this->iscritti;
  while (iscritti) {
    print_iscritto(iscritti->head);
    printf("\n");
    iscritti = iscritti->tail;
  }
}
