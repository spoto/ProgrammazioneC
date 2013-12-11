#include <stdio.h>


float abs_value(float f) {
  if (f < 0)
    f = -f;

  // qui f e' il valore assoluto dell'f iniziale

  // dico che il risultato della funzione è il valore di f
  return f;
}

int main(void) {
  float f1, f2;

  // il risultato di abs_value viene scritto in f1
  f1 = abs_value(-5.6);
  printf("f1 = %f\n", f1);

  f1 = abs_value(8.0);
  printf("f1 = %f\n", f1);

  f1 = abs_value(-8.9);
  printf("f1 = %f\n", f1);

  return 0;
}
