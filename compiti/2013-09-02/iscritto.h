#ifndef ISCRITTO_H
#define ISCRITTO_H

struct iscritto {
  const char *nome;
  const char *cognome;
  int matricola;
  int voto;
};

struct iscritto *construct_iscritto(const char *nome, const char *cognome, int matricola);
void destroy_iscritto(struct iscritto *this);
void print_iscritto(struct iscritto *this);

#endif
