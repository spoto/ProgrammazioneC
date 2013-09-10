#include <stdlib.h>
#include "traduttore.h"

struct traduttore *construct_traduttore() {
  struct traduttore *this = malloc(sizeof(struct traduttore));
  int pos;

  for (pos = 0; pos < DIM; pos++)
    this->chiave[pos] = this->valore[pos] = NULL;

  return this;
}

void destruct_traduttore(struct traduttore *this) {
  free(this);
}

void put(struct traduttore *this, const char *k, const char *v) {
  int pos;

  for (pos = 0; pos < DIM; pos++)
    if (this->chiave[pos]) {
      if (!strcmp(this->chiave[pos], k)) {
	this->valore[pos] = v;
	return;
      }
    }
    else {
      this->chiave[pos] = k;
      this->valore[pos] = v;
      return;
    }
}

const char *get(struct traduttore *this, const char *k) {
  int pos;

  for (pos = 0; pos < DIM; pos++)
    if (this->chiave[pos] && !strcmp(this->chiave[pos], k))
      return this->valore[pos];

  return NULL;
}
