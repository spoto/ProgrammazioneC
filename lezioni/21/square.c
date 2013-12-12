#include <stdio.h>

// definizioni o dichiarazioni delle funzioni
int main(void);
float abs_value(float x);
float square_root(float x);

// implementazioni delle funzioni
int main(void) {
  float array[5] = { 3.14, 8.912, 9.98, 1.2345, 7.18 };
  int pos;

  for (pos = 0; pos < 5; pos++)
    printf("%f ", square_root(array[pos]));

  printf("\n");

  return 0;
}


float square_root(float x) {
  const float epsilon = 0.0001;
  float guess;

  guess = 1.0;

  while (abs_value(guess * guess - x) >= epsilon)
    guess = (guess + x / guess) / 2.0;

  return guess;
}

float abs_value(float x) {
  if (x < 0)
    x = -x;

  return x;
}


