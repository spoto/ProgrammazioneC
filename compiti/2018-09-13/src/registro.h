#ifndef REGISTRO_H
#define REGISTRO_H

#define DIM 10

struct registro {
  char *cognome[DIM];
  double saldo_punti[DIM];
};

struct registro *construct_registro();
void destruct_registro(struct registro *this);
void aggiungi_punti(struct registro *this, char *cognome, int punti);
void bonus(struct registro *this, double percent);

#endif
