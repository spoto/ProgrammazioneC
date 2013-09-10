#ifndef BANCA_H
#define BANCA_H

#define DIM 10

struct banca {
  char *nome[DIM];
  double soldi[DIM];
};

struct banca *construct_banca();
void destruct_banca(struct banca *this);
void deposita(struct banca *this, char *nome, double soldi);
void preleva(struct banca *this, char *nome, double soldi);
char *toString(struct banca *this);

#endif
