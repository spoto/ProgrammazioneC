#include <stdio.h>

int main(void) {
  float pi_float = 3.1415;
  double pi_double = 3.1415;
  float radius;
  float area_float;
  double area_double;

  printf("Inserisci il raggio: ");
  scanf("%f", &radius);

  area_float = radius * radius * pi_float;
  printf("[sui float]  L'area di un cerchio di raggio %f e' %.20f\n", radius, area_float);

  area_double = radius * radius * pi_double;
  printf("[sui double] L'area di un cerchio di raggio %f e' %.20f\n", radius, area_double);

  printf("[sui float]  Il raggio era %.20f\n", area_float / pi_float / radius);
  printf("[sui double] Il raggio era %.20f\n", area_double / pi_double / radius);

  return 0;
}
