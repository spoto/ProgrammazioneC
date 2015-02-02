#ifndef CASA_H
#define CASA_H

struct casa {
  int metratura_casa;
  int metratura_terrazzi;
  int metratura_garage;
};

struct casa *construct_casa(int metratura_casa, int metratura_terrazzi, int metratura_garage);
void destroy_casa(struct casa *this);
double metratura_commerciale(struct casa *this);

#endif
