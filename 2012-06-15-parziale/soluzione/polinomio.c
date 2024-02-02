#include <stdio.h>
#include <stdlib.h>
#include "polinomio.h"

struct polinomio *construct_polinomio(int coefficienti[], int grado) {
  struct polinomio *this = malloc(sizeof(struct polinomio));
  this->coefficienti = coefficienti;
  this->grado = grado;

  return this;
}

void destruct_polinomio(struct polinomio *this) {
  free(this);
}

int grado(struct polinomio *this) {
  return this->grado;
}

struct polinomio *add(struct polinomio *this, struct polinomio *other) {
  // il grado del risultato è il massimo fra i due gradi
  int grado_risultato = this->grado > other->grado ? this->grado : other->grado;
  int *temp,
    *coefficienti_risultato,
    *coefficienti_this = this->coefficienti,
    *coefficienti_other = other->coefficienti;
  int i, diff;

  // allochiamo l'array per i coefficienti del risultato
  coefficienti_risultato = malloc((grado_risultato + 1) * sizeof(int));

  // spostiamo i puntatori in fondo agli array
  coefficienti_risultato += grado_risultato;
  coefficienti_this = this->coefficienti + this->grado;
  coefficienti_other = other->coefficienti + other->grado;

  // calcoliamo la somma dei coefficienti di this e other
  for (i = 0; i <= grado_risultato; i++)
    *coefficienti_risultato-- =
      (coefficienti_this >= this->coefficienti ? *coefficienti_this-- : 0) +
      (coefficienti_other >= other->coefficienti ? *coefficienti_other-- : 0);
  coefficienti_risultato++;

  // contiamo eventuali monomi nulli iniziali
  diff = 0;
  while (grado_risultato > 0 && coefficienti_risultato[diff] == 0) {
    grado_risultato--;
    diff++;
  }

  if (diff > 0) {
    // ci sono diff monomi nulli iniziali: ricopiamo in un array più piccolo
    temp = coefficienti_risultato;
    coefficienti_risultato = malloc((grado_risultato + 1) * sizeof(int));
    for (i = 0; i <= grado_risultato; i++)
      coefficienti_risultato[i] = temp[diff + i];
    free(temp);
  }

  // ritorniamo il polinomio risultante dalla somma
  return construct_polinomio(coefficienti_risultato, grado_risultato);
}

int evaluate(struct polinomio *this, int x) {
  int i, res = 0;

  for (i = 0; i <= this->grado; i++)
    res = res * x + this->coefficienti[i];

  return res;
}

char *toString(struct polinomio *this) {
  // per semplicita', allochiamo sempre 1000 caratteri
  char *cursor, *res = malloc(1000 * sizeof(char)), *start = res;
  int esponente = this->grado, coefficiente;

  while (esponente >= 0) {
    // scriviamo il monomio di grado esponente
    coefficiente =  this->coefficienti[this->grado - esponente];

    if (coefficiente > 0)
      res += sprintf(res, " + %dx^%d", coefficiente, esponente);
    else if (coefficiente < 0)
      res += sprintf(res, " - %dx^%d", -coefficiente, esponente);
    // se coefficiente == 0, non stampiamo il monomio

    esponente--;
  }

  *res = '\0';

  return start;
}

