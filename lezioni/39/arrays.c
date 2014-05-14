#include <stdio.h>

float sum(float arr[], int length) {
  float result = 0.0;
  int pos;

  for (pos = 0; pos < length; pos++)
    result += arr[pos];

  return result;
}

float sum2(float *p, int length) {
  float result = 0.0;
  int pos;

  for (pos = 0; pos < length; pos++)
    // ++ ha precedenza rispetto a *
    result += *p++;

  return result;
}

float sum3(float *p, int length) {
  float result = 0.0;
  int pos;

  for (pos = 0; pos < length; pos++)
    result += *(p + pos);

  return result;
}

float sum4(float *p, int length) {
  float result = 0.0;
  int pos;

  for (pos = 0; pos < length; pos++)
    // il compilatore traduce in
    // result += *(p + pos)
    result += p[pos];

  return result;
}

int main(void) {
  float arr[] = {3.14, 2.71, -1.15, 0.88};
  float s = sum4(arr, 4);

  printf("%f\n", s);

  return 0;
}
