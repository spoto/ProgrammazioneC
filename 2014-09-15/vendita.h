#ifndef VENDITA_H
#define VENDITA_H

struct vendita {
  struct casa *casa;
  int prezzo;
};

struct vendita *construct_vendita(struct casa* casa, int prezzo);
void destroy_vendita(struct vendita *this);
double prezzo_m2(struct vendita *this);

#endif
