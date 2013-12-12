#include <stdio.h>

// definizioni o dichiarazioni delle funzioni
int main(void);
float abs_value(float x);
float square_root(float x);

// implementazioni delle funzioni
int main(void) {
  float f;

  do {
    printf("numero: ");
    scanf("%f", &f);
    if (f >= 0)
      printf("%f\n", square_root(f));
  }
  while (f >= 0.0);

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


