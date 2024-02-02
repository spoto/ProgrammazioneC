#ifndef CARTELLONE_H
#define CARTELLONE_H

struct cartellone {
  int numero_treno[8];
  const char *destinazione[8];
  int usati; // il numero di elementi degli array che sono usati
};

struct cartellone *construct_cartellone(void);
void destroy_cartellone(struct cartellone *this);
void print_cartellone(struct cartellone *this);
void aggiungi_treno(struct cartellone *this, int numero_treno,  const char *destinazione);
void rimuovi_treno(struct cartellone *this);

#endif
