#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_random(long arr[], int length) {
  srand(time(NULL));

  for (int pos = 0; pos < length; pos++) {
    int r;

    do {
      r = 1 + rand() % 999;
    }
    while (pos > 0 && arr[pos - 1] == r);

    arr[pos] = r;
  }
}

void print(long arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%li ", arr[pos]);

  printf("\n");
}

int is_harshad(long n) {
  if (n <= 0)
    return 0;

  int sum = 0;
  long nn = n;

  do {
    sum += nn % 10;
    nn /= 10;
  }
  while (nn > 0);

  return n % sum == 0;
}

void fill_with_harshad(long arr[], int length) {
  int pos = 0;
  long i = 0;
  while (pos < length) {
    if (is_harshad(i))
      arr[pos++] = i;

    i++;
  }
}
