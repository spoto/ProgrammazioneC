#include <stdio.h>
#include <math.h>

static double integra(double da, double a, double dx);

int main(void) {
  double da, a, dx;

  printf("da: ");
  scanf("%lf", &da);

  printf("a: ");
  scanf("%lf", &a);

  printf("dx: ");
  scanf("%lf", &dx);

  printf("integrale di sin(x) tra %f e %f d%f = %f\n", da, a, dx, integra(da, a, dx));

  return 0;
}

static double integra(double da, double a, double dx) {
  double x;
  double risultato = 0.0;

  for (x = da; x <= a; x += dx)
    risultato += sin(x) * dx;

  return risultato;
}
