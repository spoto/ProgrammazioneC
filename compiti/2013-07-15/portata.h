#ifndef PORTATA_H
#define PORTATA_H

struct portata {
  const char *nome;
  int prezzo;
};

struct portata *construct_portata(const char *nome, int prezzo);
void destroy_portata(struct portata *this);

#endif
