#ifndef TRADUTTORE_H
#define TRADUTTORE_H

#define DIM 10

struct traduttore {
  const char *chiave[DIM];
  const char *valore[DIM];
};

struct traduttore *construct_traduttore();
void destruct_traduttore(struct traduttore *this);
void put(struct traduttore *this, const char *k, const char *v);
const char *get(struct traduttore *this, const char *k);

#endif
