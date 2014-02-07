#include <stdio.h>

double e(int precision) {
  double approx = 0.0;
  int factorial = 1;
  int n;

  for (n = 0; n <= precision; n++) {
    approx += 1.0 / factorial;
    factorial *= n + 1;
  }

  return approx;
}

int main(void) {
  int precision;

  printf("precision: ");
  scanf("%i", &precision);

  printf("%.20g\n", e(precision));

  return 0;
}
