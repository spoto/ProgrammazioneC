#include <stdio.h>

double pi(int precision) {
  double sum = 0.0;
  int k;
  double fractions;
  long power = 1;

  for (k = 0; k < precision; k++) {
    fractions = 4.0 / (8 * k + 1);
    fractions -= 2.0 / (8 * k + 4);
    fractions -= 1.0 / (8 * k + 5);
    fractions -= 1.0 / (8 * k + 6);

    sum += fractions / power;

    power *= 16;
  }

  return sum;
}

int main(void) {
  int precision;

  printf("precisione: ");
  scanf("%i", &precision);

  printf("%.30f\n", pi(precision));

  return 0;
}
