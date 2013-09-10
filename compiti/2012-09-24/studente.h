#ifndef STUDENTE_H
#define STUDENTE_H

struct studente {
  char *nome;
  int num_esami;
  int somma_voti;
};

struct studente *construct_studente(char *nome);
void destruct_studente(struct studente *this);
void fa_esame(struct studente *this, int voto);
float media(struct studente *this);
char *toString(struct studente *this);

#endif
