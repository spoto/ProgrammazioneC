#ifndef APPELLO_H
#define APPELLO_H

#include "iscritto.h"
#include "list.h"

struct appello {
  struct list *iscritti;
};

struct appello *construct_appello();
void destroy_appello(struct appello *this);
void iscrivi(struct appello *this, struct iscritto *studente);
void registra_voto(struct appello *this, int matricola, int voto);
void print_appello(struct appello *this);

#endif
