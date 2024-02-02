#ifndef RADIO_H
#define RADIO_H

#define DIM 10

struct radio {
  char *nome_dei_canali[DIM];
  float frequenza_dei_canali[DIM];
  int canale_sintonizzato; // tra 0 e DIM-1
};

struct radio *construct_radio();
void destruct_radio(struct radio * this);
void memorizza_canale(struct radio *this, int numero, char *nome, float frequenza);
void sintonizza_su(struct radio *this, int numero);
char *toString(struct radio *this);

#endif
