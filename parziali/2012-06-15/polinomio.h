#ifndef POLINOMIO_H
#define POLINOMIO_H

struct polinomio {
  int *coefficienti;  // un array: il primo e' il coefficiente piu' significativo
  int grado; // da 0 in su. In pratica e' la lunghezza di coefficienti - 1
};

struct polinomio *construct_polinomio(int coefficienti[], int grado);
void destruct_polinomio(struct polinomio *this);
int grado(struct polinomio *this);
struct polinomio *add(struct polinomio *this, struct polinomio *other);
int evaluate(struct polinomio *this, int x);
char *toString(struct polinomio *this);

#endif
